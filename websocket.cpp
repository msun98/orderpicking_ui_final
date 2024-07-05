#include "websocket.h"
// AMR <-> nuc qtcp 로 통신.
// RB <-> YUJIN websocket 으로 통신.

websocket::websocket(QObject *parent) : QObject(parent)
{
    open();
}

websocket::~websocket()
{
    qDebug()<<"웹소켓 프로그램 종료";
}

void websocket::open()
{
    server = new QWebSocketServer("rb_websocket", QWebSocketServer::NonSecureMode, this);
    if(server->listen(QHostAddress::Any, 38081)) //서버가 들어오는 연결을 수신하기 위해 listen을 호출(yujin -> client, rainbow -> server)
    {
        connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    // 주기 맞춰 보다가
    connect(timer, SIGNAL(timeout()), this, SLOT(moveCheck()));
    timer->start(500);

    feedbacktimer = new QTimer(this);
    connect(feedbacktimer, SIGNAL(timeout()), this, SLOT(Feedback()));
    feedbacktimer->start(100);

    cmd_que_timer = new QTimer(this);
    connect(cmd_que_timer, SIGNAL(timeout()), this, SLOT(cmd_loop(QWebSocket)));
    cmd_que_timer->start(100);

}

void websocket::onNewConnection(){
    QWebSocket *pSocket = server->nextPendingConnection();

    connect(pSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    clients << pSocket;

    msg = true;
    emit msgSignal(msg);
    qDebug()<<"상대방이 접속하였습니다.";
}

void websocket::onDisconnected(){
    qDebug()<<"상대방의 접속이 끊겼습니다.";
    msg = false;
    emit msgSignal(msg);

    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if(pClient){
        clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void websocket::onClosed()
{
    server->close();
}

void websocket::init(mobile_robot *_mb, MD_MOTOR *_md)
{
    mb = _mb;
    md_mot = _md;
}

void websocket::CMD_RESULT(QString result)
{
    for(int i=0; i<clients.size(); i++)
    {
        QWebSocket *pSocket = clients[i];
        //        sendNotice(pSocket);
        QJsonObject json;
        json["msg_type"] = "cmd_result";
        json["result"] = result;
        qDebug()<<"result : "<<result;

        if (result == "failure")
        {
            QJsonObject json_error_info;
            json_error_info["error_code"] = "dddd";
            json_error_info["description"] = "dddd";
            json_error_info["debug_msg"] = "dddd";
            json["error"] = json_error_info;
        }

        if (action == "pick_item")
        {
            QJsonObject json_data;
            json["result"] = "success";
            //            json["error_info"] = QJsonValue::Null;
            json_data["success_count"] = 1;
            json_data["failure_count"] = 0;
            json["data"]=json_data;
            //            json["data"]=;

            //            json_out["uuid"]=uuid;

            //            QJsonDocument doc_json(json_out);
            //            QString str_json(doc_json.toJson(QJsonDocument::Indented));
        }
        if (action == "set_position")
        {
            qDebug()<<"zzzzzzzzzzzz";
            json["msg_type"] = "cmd_result";
            json["do"] = action;
            json["result"] = "success";

            QJsonDocument doc_json(json);
            //QString str_json(doc_json.toJson(QJsonDocument::Compact));
            QString str_json(doc_json.toJson(QJsonDocument::Indented));
            emit msgSendSignal(str_json);

            //            qDebug()<<str_json;
            //    client_socket->sendTextMessage("notice");
            pSocket->sendTextMessage(str_json);
            mb->map_changed = false;

        }

        json["uuid"] = uuid;

        QJsonDocument doc_json(json);
        QString str_json(doc_json.toJson(QJsonDocument::Indented));
        emit msgSendSignal(str_json);
        pSocket->sendTextMessage(str_json);

        //        std::string rainbow_cmd(str_json.toStdString());
        //        std::string uuid_send(uuid.toStdString());
    }
}

void websocket::onTimeout()
{
    static int cnt = 0;
    cnt++;

    if(clients.size() > 0)
    {
        if(cnt%5 == 0)
        {
            for(int i=0; i<clients.size(); i++)
            {
                QWebSocket *pSocket = clients[i];
                sendNotice(pSocket);
            }
        }
    }
}

void websocket::Feedback()
{
    // lift, AMR, RB_5 working feedback

    //    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    for(int i=0; i<clients.size(); i++)
    {
        QJsonObject json;
        int mobile_status = mb->status;

        QWebSocket *pSocket = clients[i];
        if (move_flag)
        {
            QString mb_status;
            ///////////////////AMR status/////////////////////////

            if (mobile_status == 0)
            {
                //                mb_status="NOT_READY";
                seq_num = 0;
            }
            else if(mobile_status == 1)
            {
                //                mb_status="READY";
                seq_num = 0;
            }
            else if(mobile_status == 2)
            {
                //                qDebug()<<"mmmmmmmmmmmm";
                mb_status="running";
                //                json["feedback"] = "running";
                //                mobile robot 으로부터 받은 json path plan 을 넣어줌.
                json = mb->json;

                json["feedback"] = mb_status;
                //                seq_num = 1;
                seq_num++;
                json["seq_num"] = seq_num;
            }
            else if(mobile_status == 3)
            {
                //                mb_status="WAIT";
                //                seq_num = 0;
            }
            else if(mobile_status == 4)
            {
                mb_status = "pause";
                //                json["feeback"] = "pause";
                json["feedback"] = mb_status;
                //                seq_num = 0;

            }

        }
        //////////////////////////rb5//////////////////////////

        if(rb_status == "moving")
        {
            //            qDebug()<<"mmmmmmmmmmmmmmmm";
            mb_status = "running";
            json = mb->json;

            json["feedback"] = mb_status;
            rb_seq_num++;
            json["seq_num"] = rb_seq_num;
            //            json["entry"] = entry;
            json["entry"] = "cobot";
        }
        else if(rb_status == "not moving")
        {
            rb_seq_num = 0;
        }

        //////////////////////////lift//////////////////////////

        if(lift_status == "moving")
        {
            //            qDebug()<<"lift moving!!!!!!";
            mb_status = "running";
            json = mb->json;

            json["feedback"] = mb_status;
            lift_seq_num++;
            json["seq_num"] = lift_seq_num;
            json["entry"] = "lift";
        }
        else if(lift_status == "not moving")
        {
            //            qDebug()<<"lift not moving!!!!!!";
            lift_seq_num=0;
        }

        json["msg_type"] = "cmd_feedback";
        json["do"] = action;
        //        json["seq_num"] = seq_num;
        //        json["entry"] = entry;
        //

        if (mobile_status == 2 || mobile_status == 4 )
        {
            json["entry"] = entry;
            QJsonDocument doc_json(json);
            //QString str_json(doc_json.toJson(QJsonDocument::Compact));
            QString str_json(doc_json.toJson(QJsonDocument::Indented));
            emit msgSendSignal(str_json);

            //            qDebug()<<str_json;
            //    client_socket->sendTextMessage("notice");
            pSocket->sendTextMessage(str_json);
        }
        else if(rb_status == "moving" || lift_status == "moving")
        {
            //            qDebug()<<"lift or rb is working";
            QJsonDocument doc_json(json);
            //QString str_json(doc_json.toJson(QJsonDocument::Compact));
            QString str_json(doc_json.toJson(QJsonDocument::Indented));
            emit msgSendSignal(str_json);

            //            qDebug()<<str_json;
            //    client_socket->sendTextMessage("notice");
            pSocket->sendTextMessage(str_json);
        }




    }

}

void websocket::onBinaryMessageReceived(QByteArray message){
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if(pClient){
        pClient->sendBinaryMessage(message);
    }
}

//static bool move_status = false;
void websocket::moveCheck()
{
//    qDebug()<<"action : "<<action;
    if(move_flag && mb->status==2)
    {
        //        qDebug()<<"robot is running!";
        move_status = true;
    }
    else if(move_status && mb->status==1)
    {
        //        qDebug()<<"mobile robot success!!!!";
        CMD_RESULT("success");
        move_status = false;
        move_flag = false;
    }

    if(seqLoop_done_flag)
    {
        CMD_RESULT("success");
        seqLoop_done_flag = false;
    }
    else if(seqLoop_done_flag==false)
    {
        //        qDebug()<<"working now";
    }

    if (action == "set_position")
    {
//        qDebug()<<"ssssss";
        if(mb->map_changed == true)
        {
//            qDebug()<<"sssssssssssss";
            CMD_RESULT("success");
        }
    }



}

void websocket::onTextMessageReceived(QString message)
//comand msg
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    emit msgReciveSignal(message);// ui를 통해 메시지를 확인하기 위함.
    yujin_json_msg.push(message);

    cmd_loop(pClient);
}

void websocket::cmd_loop(QWebSocket *pClient_address)
{
    QWebSocket *pClient = pClient_address;
    QString message;

    if(!yujin_json_msg.empty())
    {
        message = yujin_json_msg.front();
        qDebug()<<message;
        yujin_json_msg.pop();

        if(pClient)
        {
            QJsonObject json;
            QJsonDocument doc_json = QJsonDocument::fromJson(message.toUtf8());
            json = doc_json.object();

            if(json["msg_type"] == "command")
            {
                // Command Msg
                entry = json["entry"].toString();
                action = json["do"].toString();
                QJsonObject params = json["params"].toObject();
                uuid = json["uuid"].toString();
                sendAck(uuid);

                if(action == "move")
                {
                    //4.1 Move
                    QJsonObject tempDest = params["dest"].toObject();
                    QString move_type = params["move_type"].toString();

                    QJsonObject json_output;
                    qDebug()<<"Move type : "<<move_type;

                    if(move_type == "destination")
                    {
                        x = tempDest["x"].toDouble();
                        y = tempDest["y"].toDouble();
                        theta = tempDest["theta"].toDouble();
                        ////////// send msg to mobile robot ////////////////
                        json_output["MSG_TYPE"] = "MOVE";
                        json_output["POSE_x"] = x;
                        json_output["POSE_y"] = y;
                        json_output["POSE_theta"] = theta; ///yujin 에서는 라디안으로 줌.
                    }

                    else if(move_type == "waypoint")
                    {
                        QJsonArray waypoints = params["waypoints"].toArray();
                        json_output["speed"] = params["speed"].toArray();

                        QJsonObject pose;
                        qDebug()<<"size of waypoints : "<<waypoints.size();
                        for(int p = 0; p < waypoints.size(); p++)//for 문을 통해 파싱 진행
                        {
                            cv::Vec2d path;
                            QJsonObject waypoints_obj = waypoints[p].toObject();
                            //                        qDebug()<<waypoints_obj["node_id"];
                            pose = waypoints_obj["pose"].toObject();
                            path[0] = pose["x"].toDouble();
                            path[1] = pose["y"].toDouble();
                        }


                        //                    qDebug()<<pose_pair;
                        json_output["MSG_TYPE"] = "MOVE_EXT";
                        json_output["PATH"] = waypoints;
                    }
                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);

                    mb->cmdSendData(json_string);
                    qDebug()<<"x :"<<x<<",y :"<<y<<",theta :"<<theta;
                    move_flag = true;
                }

                else if(action == "dock")
                {
                    //4.2 Dock

                    QString marker_id = params["marker_id"].toString();
                    QString direction = params["direction"].toString();

                    QJsonObject json_output;
                    json_output["MSG_TYPE"] = "DOCK";
                    json_output["marker_id"] = marker_id;
                    json_output["direction"] = direction; ///yujin 에서는 라디안으로 줌.

                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);
                    mb->cmdSendData(json_string);

                    qDebug()<<"marker_id : "<<marker_id<<"direction : "<<direction;

                    //                pMP->MoveOmron(x,y,theta);
                }

                else if(action == "pause")
                {
                    //4.4 Pause
                    //robot에 Pause 명령줘야함.

                    qDebug()<<"Pause";
                    QJsonObject json_output;
                    json_output["MSG_TYPE"] = "PAUSE";

                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);

                    if(old_mobile_status == "MOVING")
                    {
                        CMD_RESULT("success");
                        mb->cmdSendData(json_string);
                    }
                    else if(old_mobile_status!="PAUSE")
                    {
                        CMD_RESULT("cancelled");
                    }
                    else
                    {
                        CMD_RESULT("cancelled");
                    }
                }

                else if(action == "resume")
                {
                    //4.5 Resume
                    qDebug()<<"resume";
                    QJsonObject json_output;
                    json_output["MSG_TYPE"] = "RESUME";

                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);
                    //                mb->cmdSendData(json_string);

                    if(old_mobile_status=="PAUSE")
                    {
                        CMD_RESULT("success");
                        mb->cmdSendData(json_string);
                    }
                    else
                    {
                        CMD_RESULT("cancelled");
                    }
                }

                else if(action == "stop")
                {
                    //4.6 Stop
                    qDebug()<<"stop";
                    //robot에 stop 명령줘야함.
                    QJsonObject json_output;
                    json_output["MSG_TYPE"] = "STOP";

                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);
                    mb->cmdSendData(json_string);
                    CMD_RESULT("cancelled");
                }

                else if(action == "get_map_info_list")
                {
                    //4.8 Get Map Info List

                    QJsonObject json_out;
                    QJsonArray json_arr;
                    //                QJsonObject json_out;
                    json_out["msg_type"] = "cmd_result";
                    json_out["result"] = "success";
                    json_out["error_info"] = QJsonValue::Null;

                    ////////////map directory 내부에 있는 폴더 list 반환////////////

                    QDir dir("/home/rainbow/maps/");
                    foreach(QFileInfo item, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries) )
                    {
                        if(item.isDir())
                        {

                            QJsonObject json_data;
                            QString filelist = item.baseName();
                            json_data["data"] = data("Rainbow","get_map_info_list","RB200", "RB", filelist);
                            QJsonObject data = json_data["data"].toObject();

                            //                        qDebug()<<"data : "<<data;
                            json_arr.insert(0,data);//대괄호 조건에 맞추기 위함. data를 수집하여 QJsonArray 에 담아줌.
                            json_out["data"] = json_arr;
                            json_out["uuid"] = uuid;
                            QString map_info = QJsonDocument(json_out).toJson(QJsonDocument::Indented);//보낸 내용 확인용
                            emit msgSendSignal(map_info);
                            pClient->sendTextMessage(map_info);
                        }
                    }
                }

                else if(action == "get_map_info")
                {
                    //4.9 Get Map Info
                    //                QJsonObject json;
                    QJsonObject json_data;
                    QJsonObject json_out;
                    QString map_id;

                    json_out["msg_type"] = "cmd_result";
                    json_out["result"] = "success";
                    json_out["error_info"] = QJsonValue::Null;

                    ////////////map directory 내부에 있는 폴더 list 반환////////////

                    if (params["map_id"].toString() == "")
                    {
                        //for get map name
                        QString config_path = QDir::homePath()+"/robot_config.ini";
                        QFileInfo config_info(config_path);
                        if(config_info.exists() && config_info.isFile())
                        {
                            QSettings settings(config_path, QSettings::IniFormat);
                            map_id = settings.value("FLOOR/map_name").toString();
                            json_data["map_id"] = map_id;
                        }

                        //for get map info
                        map_config_path = QDir::homePath()+"/maps/"+map_id+"/map_meta.ini";
                        //                    qDebug()<<map_config_path;

                        QFileInfo map_config_info(map_config_path);
                        if(map_config_info.exists() && map_config_info.isFile())
                        {
                            QSettings map_settings(map_config_path, QSettings::IniFormat);
                            //                        map_id = settings.value("FLOOR/map_name").toString();

                            json_data["map_name"] = map_id;
                            json_data["origin_px"] = map_settings.value("map_metadata/map_origin_u").toDouble();
                            json_data["origin_py"] = map_settings.value("map_metadata/map_origin_v").toDouble();
                            json_data["width_gm"] = map_settings.value("map_metadata/map_w").toDouble();
                            json_data["height_gm"] = map_settings.value("map_metadata/map_h").toDouble();
                            double map_val = 1/map_settings.value("map_metadata/map_grid_width").toDouble();
                            double map_val_round = round(map_val);
                            //                        int val = map_val.toInt();
                            //                        qDebug()<<val;
                            json_data["scale_m2px"] = map_val_round;
                            json_data["flipped"] = false;
                        }
                    }
                    else
                    {
                        //for get map name
                        map_id = params["map_id"].toString();
                        json_data["map_id"] = map_id;

                        //for get map info
                        map_config_path = QDir::homePath()+"/maps/"+map_id+"/map_meta.ini";
                        //                    qDebug()<< map_config_path;

                        QFileInfo map_config_info(map_config_path);
                        if(map_config_info.exists() && map_config_info.isFile())
                        {
                            QSettings map_settings(map_config_path, QSettings::IniFormat);
                            //                        map_id = settings.value("FLOOR/map_name").toString();

                            json_data["map_name"] = "rainbow";
                            json_data["origin_px"] = map_settings.value("map_metadata/map_origin_u").toDouble();
                            json_data["origin_py"] = map_settings.value("map_metadata/map_origin_v").toDouble();
                            json_data["width_gm"] = map_settings.value("map_metadata/map_w").toDouble();
                            json_data["height_gm"] = map_settings.value("map_metadata/map_h").toDouble();
                            double map_val = 1/map_settings.value("map_metadata/map_grid_width").toDouble();
                            double map_val_round = round(map_val);
                            //                        int val = map_val.toInt();
                            //                        qDebug()<<val;
                            json_data["scale_m2px"] = map_val_round;
                            json_data["flipped"] = false;
                        }
                    }

                    json_out["data"] = json_data;
                    json_out["uuid"] = uuid;

                    QJsonDocument doc_json(json_out);
                    QString str_json(doc_json.toJson(QJsonDocument::Indented));
                    //                    qDebug()<<str_json;

                    emit msgSendSignal(str_json); //for debuging
                    pClient->sendTextMessage(str_json);
                }

                else if(action == "get_map_data")
                {
                    //4.10 Get Map Data
                    //                qDebug()<<params["map_id"];
                    QString id = params["map_id"].toString();//server 에서 요청한 map 의 id 파싱
                    QJsonObject json;
                    QJsonObject json_data;
                    QString fileName = params["filename"].toString();
                    //                QString filename;

                    //                qDebug()<<"yujin file name : "<<fileName;

                    int image_file_size;
                    json_data["data_type"] = params["data_type"];
                    json["msg_type"] = "cmd_result";
                    json["result"] = "success";
                    json["error_info"] = QJsonValue::Null;
                    //                json_data["map_id"] = params["map_id"];
                    //                qDebug()<<id;

                    json["uuid"] = uuid;
                    //                map_config_path = QDir::homePath()+"/maps/map_4/map_edited.png";

                    if (id == "") //현재 slam에서 사용중인 map
                    {
                        config_path = QDir::homePath()+"/robot_config.ini";
                        QFileInfo config_info(config_path);
                        if(config_info.exists() && config_info.isFile())
                        {
                            QSettings settings(config_path, QSettings::IniFormat);
                            map_id = settings.value("FLOOR/map_name").toString();

                            json_data["map_id"] = map_id;
                            //                        json_data["filename"] = map_id;
                            json_data["data_type"] = params["data_type"].toString();
                        }

                        if (params["data_type"].toString() == "map_image_png")
                        {
                            //for get map name
                            fileName = map_id+".png";
                            json_data["filename"] = map_id+".png";
                            map_config_path = QDir::homePath()+"/maps/"+map_id+"/changed_map.png";

                            file = new QFile(map_config_path);
                            qDebug()<<"path : "<<map_config_path;
                            file->open(QFile::ReadOnly);
                            fileData_byte = file->readAll();


                            //    qDebug()<<fileData_byte;

                            image_file_size = fileData_byte.size();
                        }

                        else if(params["data_type"].toString() == "map_package")
                        {
                            //for get map_package
                            fileName = map_id+".tar.xz";
                            json_data["filename"] = map_id+".tar.xz";
                            map_config_path = QDir::homePath()+"/maps/"+map_id+".tar.xz";
                            file = new QFile(map_config_path);
                            //                    qDebug()<<"path : "<<map_config_path;
                            file->open(QFile::ReadOnly);
                            fileData_byte = file->readAll();
                            image_file_size = fileData_byte.size();
                        }
                        json_data["filesize"] = image_file_size;
                        qDebug()<<"image : "<<image_file_size;

                        json["data"] = json_data;

                        QJsonDocument doc_json(json);
                        QString str_json(doc_json.toJson(QJsonDocument::Indented));
                        //                    qDebug()<<str_json;

                        emit msgSendSignal(str_json); //for debuging
                        pClient->sendTextMessage(str_json);
                        qDebug()<<"map_config_path 1 : "<<map_config_path;
                        send_img_package(map_config_path,image_file_size,params["data_type"].toString(),fileName);
                    }

                    else
                    {
                        //만약 리스트안에 없는 파일을 달라고 하면 터지지 않도록 예외처리 해주어야함.
                        map_id = id;
                        qDebug()<<"요청 받은 맵의 map id : "<<map_id;

                        QString map_path = QDir::homePath()+"/maps/";
                        //                    file = new QFile(map_path);

                        //                    file->open(QFile::ReadOnly);
                        //                    fileData_byte = file->readAll();
                        //                    image_file_size = fileData_byte.size();

                        QDir dir(map_path);
                        //                    qDebug()<<"map_path id : "<<map_path;

                        QStringList itemlist; //임시적으로 데이터 길이 늘려놓음.
                        QFileInfo map_config_info(map_path);
                        //                    QString filelist;
                        if(map_config_info.exists())
                        {
                            foreach(QFileInfo item, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries) )
                            {
                                QString filelist;
                                if(item.isDir())
                                {
                                    filelist = item.baseName();
                                    itemlist += filelist;
                                }
                            }
                            //                        qDebug()<<"itemlist : "<<itemlist;

                            if(itemlist.filter(id).count() != 0)
                            {
                                qDebug()<<"파일이 있습니다.";
                                //                        qDebug()<<"map_id : " <<params["data_type"].toString();

                                if (params["data_type"].toString() == "map_image_png")
                                {
                                    //for get map name
                                    map_config_path = QDir::homePath()+"/maps/"+map_id+"/changed_map.png";
                                    qDebug()<<"요청 받은 map의 path : "<<map_config_path;
                                    //                                qDebug()<<"map_config_path :"<<map_config_path;

                                    bool exist_img = QFile::exists(map_config_path);

                                    if(exist_img)
                                    {
                                        file = new QFile(map_config_path);
                                        //                    qDebug()<<"path : "<<map_config_path;
                                        file->open(QFile::ReadOnly);
                                        fileData_byte = file->readAll();
                                        image_file_size = fileData_byte.size();

                                        fileName = map_id+".png";
                                        json_data["map_id"] = map_id+".png";
                                        json_data["filename"] = map_id+".png";
                                        json_data["data_type"] = params["data_type"].toString();
                                        json_data["filesize"] = image_file_size;
                                        qDebug()<<"image : "<<image_file_size;

                                        json["data"] = json_data;

                                        QJsonDocument doc_json(json);
                                        QString str_json(doc_json.toJson(QJsonDocument::Indented));
                                        //                    qDebug()<<str_json;

                                        emit msgSendSignal(str_json); //for debuging
                                        pClient->sendTextMessage(str_json);
                                        send_img_package(map_config_path,image_file_size,params["data_type"].toString(),fileName);
                                    }
                                    else
                                    {
                                        qDebug()<<"흑백이미지가 없습니다.";
                                    }

                                }
                                else if (params["data_type"].toString() == "map_package")
                                {
                                    //for get map name
                                    json_data["filename"] = map_id+".tar.xz";
                                    map_config_path = QDir::homePath()+"/maps/"+map_id+".tar.xz";
                                    qDebug()<<"요청 받은 map의 path : "<<map_config_path;

                                    bool exist_file = QFile::exists(map_config_path);
                                    if(exist_file)
                                    {
                                        file = new QFile(map_config_path);
                                        //                    qDebug()<<"path : "<<map_config_path;
                                        file->open(QFile::ReadOnly);
                                        fileData_byte = file->readAll();
                                        image_file_size = fileData_byte.size();

                                        //                        map_id = id;
                                        fileName = map_id+".tar.xz";
                                        json_data["map_id"] = map_id+".tar.xz";
                                        json_data["filename"] = map_id+".tar.xz";
                                        json_data["data_type"] = params["data_type"].toString();
                                        json_data["filesize"] = image_file_size;
                                        qDebug()<<"image : "<<image_file_size;

                                        json["data"] = json_data;

                                        QJsonDocument doc_json(json);
                                        QString str_json(doc_json.toJson(QJsonDocument::Indented));
                                        //                    qDebug()<<str_json;

                                        emit msgSendSignal(str_json); //for debuging
                                        pClient->sendTextMessage(str_json);
                                        send_img_package(map_config_path,image_file_size,params["data_type"].toString(),fileName);
                                    }
                                    else
                                    {
                                        qDebug()<<"파일이 없습니다.";
                                    }
                                }
                            }
                            else
                            {
                                qDebug()<<"파일이 없습니다.";
                            }
                        }
                    }
                }

                else if(action == "set_map_data")
                {
                    //4.11 Set Map Data

                }

                else if(action == "get_robot_info")
                {
                    //4.12 Get robot info
                    QJsonObject json_out;
                    QString robot_id,map_id;
                    QJsonObject json_data;

                    json_out["msg_type"] = "cmd_result";
                    json_out["result"] = "success";
                    json_out["error_info"] = QJsonValue::Null;

                    QString config_path = QDir::homePath()+"/robot_config.ini";
                    QFileInfo config_info(config_path);
                    if(config_info.exists() && config_info.isFile())
                    {
                        QSettings settings(config_path, QSettings::IniFormat);
                        robot_id = settings.value("ROBOT_SW/robot_id").toString();
                        map_id = settings.value("FLOOR/map_name").toString();
                        QJsonObject json_map;

                        json_map["map_id"] = map_id;
                        json_map["map_name"] = map_id;
                        json_data["map"] = json_map;
                        //                    json_data =

                        //                    QJsonObject json_robot_id;
                        json_data["robot_id"] = robot_id;
                        json_data["robot_alias"] = robot_id;
                        //                    json_data["map"]=json_robot_id;

                    }


                    // check motor init
                    // 모터 상태 입력받을 구조체 (global_defines에 있음.)
                    //                MOBILE_STATUS mobile_status ;
                    //                        '= ipc.get_status();


                    QJsonObject json_pose;
                    json_pose["x"] = mb->pose_x;
                    json_pose["y"] = mb->pose_y;
                    //                double mobile_th =double(mobile_pose.pose[2]);
                    json_pose["theta"] =  mb->pose_th/180*3.14;
                    json_data["robot_pose"] = json_pose;

                    QJsonObject json_battery;
                    json_battery["level"] = mb->battery;
                    json_battery["in_charging"] = mb->charge_state;
                    json_data["battery"] = json_battery;

                    json_data["docking_direction"] = "foward";
                    json_out["data"]=json_data;

                    json_out["uuid"]=uuid;

                    QJsonDocument doc_json(json_out);
                    QString str_json(doc_json.toJson(QJsonDocument::Indented));

                    emit msgSendSignal(str_json); //for debuging
                    pClient->sendTextMessage(str_json);
                }

                else if(action == "pick_item")
                {
                    //4.13 pick item

                    QJsonObject json_out;
                    QString map_id;

                    int item_id = params["item_id"].toInt();
                    item_count = params["item_count"].toInt();
                    double shelve_height = params["shelve_height"].toDouble();//yujin [m] -> rainbow [mm]
                    double shelve_degree = params["shelve_degree"].toDouble();

                    //                    md_mot->move_position(600);
                    scene_yujin.clear();
                    scene_yujin.append("lift_down");//리프트 이동
                    scene_yujin.append(QString::number(shelve_height));//리프트 이동
                    scene_yujin.append("robot mid vision");
                    scene_yujin.append("wait");
                    scene_yujin.append("vision");
                    scene_yujin.append("wait");
                    scene_yujin.append("robot approach");
                    scene_yujin.append("robot pick");

                    scene_yujin.append("robot push");
                    scene_yujin.append("wait");
                    scene_yujin.append("robot pump on");
                    scene_yujin.append("robot pop");

                    scene_yujin.append("robot mid left");

                    QString lift_down = "lift_high,5";
                    scene_yujin.append(lift_down);//리프트 이동
                    scene_yujin.append("robot pump off");

                    if (item_id!=1)
                    {
                        QStringList msg;
                        for(int i=0;i<item_id;i++)
                        {
                            msg+=scene_yujin;
                        }
                        scene_yujin=msg;
                    }

                    //                    if(item_count>0)
                    //                    {
                    //                        flag_circle_yj = true;
                    //                    }
                    //                qDebug()<<scene_yujin;
                    cur_step = ROBOT_STATE_START;
                    //                    emit msgSendSignal(scene_yujin);
                    emit scene(scene_yujin);
                }

                else if(action == "set_position")
                {
                    //4.11 Set position (ini file 변경.)

                    QJsonObject json_out;
                    QString map_id;

                    json_out["msg_type"] = "cmd_result";

                    json_out["error_info"] = QJsonValue::Null;
                    json_out["uuid"] = uuid;

                    QString yujin_map_id = params["map_id"].toString();

                    QString config_path = QDir::homePath()+"/robot_config.ini";
                    QFileInfo config_info(config_path);
                    if(config_info.exists() && config_info.isFile())
                    {
                        QSettings settings(config_path, QSettings::IniFormat);
                        map_id = settings.value("FLOOR/map_name").toString();
                        if(map_id == yujin_map_id)
                        {
                            json_out["result"] = "success";
                        }
                        else
                        {
                            //현재 사용하고 있는 map이 아닌 다른맵을 요청한다면 -> change ini 요청.
                            QJsonObject json_output;
                            json_output["MSG_TYPE"] = "CHANGE MAP";
                            json_output["map_name"] = yujin_map_id;

                            QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);

                            mb->cmdSendData(json_string);
                        }
                    }

                    QJsonDocument doc_json(json_out);
                    //                QString str_json(doc_json.toJson(QJsonDocument::Indented));
                    QString str_json(doc_json.toJson(QJsonDocument::Indented));

                    //                std::string rainbow_cmd(str_json.toStdString());
                    //                IPC::WEB_commend RB_CMD;
                    //                memcpy((uint8_t*)RB_CMD.json_cmd, rainbow_cmd.data(), 1000);
                    //                RB_CMD.json_cmd_size = rainbow_cmd.size();
                    //                std::cout<<RB_CMD.json_cmd_size<<std::endl;

                    emit msgSendSignal(str_json); //for debuging
                    pClient->sendTextMessage(str_json);

                }

                else if(action == "ready_to_pick_item")
                {
                    //4.14 ready_to_pick_item
                    QJsonObject tempDest = params["pose"].toObject();
                    //                QString move_type = params["move_type"].toString();

                    QJsonObject json_output;

                    //                qDebug()<<"Move type : "<<move_type;
                    x = tempDest["x"].toDouble();
                    y = tempDest["y"].toDouble();
                    theta = tempDest["theta"].toDouble();
                    ////////// send msg to mobile robot ////////////////
                    json_output["MSG_TYPE"] = "MOVE";
                    json_output["POSE_x"] = x;
                    json_output["POSE_y"] = y;
                    json_output["POSE_theta"] = theta; ///yujin 에서는 라디안으로 줌.

                    //                    qDebug()<<pose_pair;
                    //                json_output["MSG_TYPE"] = "MOVE_EXT";


                    QByteArray json_string = QJsonDocument(json_output).toJson(QJsonDocument::Compact);

                    mb->cmdSendData(json_string);
                    qDebug()<<"x :"<<x<<",y :"<<y<<",theta :"<<theta;
                    move_flag = true;
                }

                else if(action == "get_robot_pose_unit")
                {
                    //4.14 get_robot_pose_unit

                    QJsonObject json_out;

                    json_out["msg_type"] = "cmd_result";
                    json_out["result"] = "success";
                    json_out["error_info"] = QJsonValue::Null;

                    //                map_id = params["map_id"].toString();
                    QJsonObject json_data;
                    json_data["xy_unit"]="meter";
                    json_data["theta_unit"]="radian";
                    json_out["data"]=json_data;

                    json_out["uuid"]=uuid;

                    QJsonDocument doc_json(json_out);
                    //                QString str_json(doc_json.toJson(QJsonDocument::Indented));
                    QString str_json(doc_json.toJson(QJsonDocument::Indented));
                    emit msgSendSignal(str_json); //for debuging
                    pClient->sendTextMessage(str_json);
                }
            }
            //    }
        }
    }
}

QJsonObject websocket::data(QString robot_manufacture, QString action,QString robot_type, QString map_id, QString map_name)
{
    QJsonObject json_data_map;
    //    QJsonArray json_arr;
    QJsonObject json_out;

    if (action == "get_map_info_list")
    {
        json_data_map["robot_manufacturer"] = robot_manufacture;
        json_data_map["robot_type"] = robot_type;
        json_data_map["map_id"] = map_name;
        json_data_map["map_name"] = map_name;

        json_out = json_data_map;
    }


    return json_out;
}

void websocket::MissionCheck(QString uuid){
    //    QJsonObject json;
    QJsonObject error_info;
    //    QString uuid = uuid;
    for(int i=0; i<clients.size(); i++)
    {
        QWebSocket *pSocket = clients[i];
    }
}

void websocket::send_img_package(QString map_config_path,int image_file_size,QString signature,QString fileName)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//    qDebug()<<"ssssssssssssss : "<<pClient;
    //for get map info

    file = new QFile(map_config_path);
    qDebug()<<"path : "<<map_config_path;
    file->open(QFile::ReadOnly);
    fileData_byte = file->readAll();

    //    qDebug()<<fileData_byte;

    image_file_size = fileData_byte.size();

    QString prifix = "FILE_DATA";
    QByteArray prifix_byte = prifix.toUtf8();

    //    QString signature = json_data["data_type"].toString();
    //    QString signature = signature;
    if (signature == "map_image_png")
    {
        signature = "MAP_IMAGE_PNG___";
    }
    else
    {
        signature = "MAP_PACKAGE_COMP";
    }

    int header_size = signature.size()+fileName.size();
    qDebug()<<"fileName :"<<fileName;
    qDebug()<<"fileName size :"<<fileName.size();
    qDebug()<<"header_size :"<<header_size;

    U_SHORT_CHAR u_headersize;
    u_headersize.data_s = header_size;
    prifix_byte.append(u_headersize.data_c[0]);
    prifix_byte.append(u_headersize.data_c[1]);

    U_INT_CHAR u_filesize;
    u_filesize.data_i = image_file_size;

    QByteArray signature_byte = signature.toUtf8();
    prifix_byte.append(signature_byte);

    QByteArray fileName_byte = fileName.toUtf8();
    prifix_byte.append(fileName_byte);
    prifix_byte.append(u_filesize.data_c[0]);
    prifix_byte.append(u_filesize.data_c[1]);
    prifix_byte.append(u_filesize.data_c[2]);
    prifix_byte.append(u_filesize.data_c[3]);

    prifix_byte.append(fileData_byte);

    //파일 잘 갔는지 디버깅용

    pClient->sendBinaryMessage(prifix_byte);
    qDebug()<<"signature : "<<signature;

    if (signature == "MAP_IMAGE_PNG___")
    {
        //이미지 잘 전송되었는지 디버깅용

        QFile file("send_IMG.bin");// bin file 생성

        file.open(QIODevice::WriteOnly);
        file.write(fileData_byte);
        file.close();
        img = cv::imread(map_config_path.toStdString(),cv::IMREAD_GRAYSCALE); // 이미지 읽기
        cv::resize(img, src, cv::Size(img.cols/3, img.rows/3), 0, 0, CV_INTER_NN); // 이미지 리사이즈 해서 보여줌.(유진 로봇에 제대로 맵 들어갔는지 확인하는 용도. 나만 보는 맵)
        imshow("지금 사용하고 있는 맵",src);
    }
}

void websocket::sendNotice(QWebSocket *client_socket){
    QJsonObject json;
    json["msg_type"] = "notice";
    int mobile_status = mb->status;
    //    qDebug()<<mobile_status;
    //    QString mb_status;
    int old_mb_status ;

    if (mobile_status == 0)
    {
        mb_status="NOT_READY";
        json_mb_status= "init";
        //        qDebug()<<"UI_AUTO_NOT_READY";
    }
    else if(mobile_status == 1)
    {
        if (old_mb_status!=mobile_status){
            mb_status="READY";
            json_mb_status= "ready";
            //            qDebug()<<"UI_AUTO_READY";
        }
    }
    else if(mobile_status == 2)
    {
        mb_status="MOVING";
        json_mb_status= "running";
        //        qDebug()<<"UI_AUTO_MOVING";
    }
    else if(mobile_status == 3)
    {
        mb_status="WAIT";
        //        qDebug()<<"UI_AUTO_WAIT";
    }
    else if(mobile_status == 4)
    {
        mb_status="PAUSE";
        json_mb_status= "paused";
        //        qDebug()<<"UI_AUTO_PAUSE";
        //        if(old_mobile_status=="MOVING")
        //        {
        //            CMD_RESULT("success");
        //        }
        //        else if(old_mobile_status!="PAUSE")
        //        {
        //            CMD_RESULT("cancelled");
        //        }
    }

    if(rb_status == "moving")
    {
        //            qDebug()<<"mmmmmmmmmmmmmmmm";
        json_mb_status= "running";
    }
    else if(rb_status == "not moving")
    {
        //            qDebug()<<"nnnnnnnnnnnnnnnnnnnnn";
    }

    //////////////////////////lift//////////////////////////

    if(lift_status == "moving")
    {
        json_mb_status= "running";
    }
    else if(lift_status == "not moving")
    {
        //
    }

    old_mobile_status=mb_status;

    json["robot_state"] = json_mb_status;
    json["navi_mode"] = "navigate";

    QString config_path = QDir::homePath()+"/robot_config.ini";
    QFileInfo config_info(config_path);
    if(config_info.exists() && config_info.isFile())
    {
        QSettings settings(config_path, QSettings::IniFormat);
        //        QString robot_id = settings.value("ROBOT_SW/robot_id").toString();
        map_id = settings.value("FLOOR/map_name").toString();

        //        QString robot_width = settings.value("ROBOT_HW/robot_width").toString();
        //        QString robot_length = settings.value("ROBOT_HW/robot_length").toString();
        //        json["robot_width"] = robot_width.toFloat();
        //        json["robot_length"] = robot_length.toFloat();

        json["robot_width"] = 0.6;
        json["robot_length"] = 0.8;
    }

    //    json["robot_op_type"] = "real_robot";
    //    json["robot_manufacturer"] = "Rainbow";

    QJsonObject json_pose;
    json_pose["x"] = mb->pose_x;
    json_pose["y"] = mb->pose_y;
    //                double mobile_th =double(mobile_pose.pose[2]);
    json_pose["theta"] =  mb->pose_th/180*M_PI;
    json["robot_pose"] = json_pose;

    QJsonObject json_map;
    json_map["map_id"] = map_id;
    json_map["map_name"] = map_id;
    json["map"] = json_map;

    QJsonObject json_battery;
    json_battery["level"] = mb->battery;
    json_battery["in_charging"] = false;
    json["battery"] = json_battery;

    json["robot_op_type"] = "real_robot";
    json["robot_manufacturer"] = "Rainbow_Robotics";
    //    json["battery"] = json_battery;

    QJsonDocument doc_json(json);
    //QString str_json(doc_json.toJson(QJsonDocument::Compact));
    QString str_json(doc_json.toJson(QJsonDocument::Indented));

    //        qDebug()<<str_json;
    //    client_socket->sendTextMessage("notice");
    client_socket->sendTextMessage(str_json);
    old_mb_status = mobile_status;
}

void websocket::sendAck(QString uuid)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    QJsonObject json;
    json["msg_type"] = "ack";
    json["result"] = "success";
    json["uuid"] = uuid;

    QJsonDocument doc_json(json);
    QString str_json(doc_json.toJson(QJsonDocument::Indented)); //QJsonDocument to QString

    emit msgSendSignal(str_json);
    pClient->sendTextMessage(str_json);

    //    client_socket->sendTextMessage(json);
}
