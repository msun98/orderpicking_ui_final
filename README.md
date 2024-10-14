# orderpicking_2024
```

void MainWindow::bt_order()
{
    QJsonObject json;
    QJsonObject json_parm;
    QJsonObject json_destination_box;

    QString shelf_hight = ui->le_shelf_hight->text();
    QString count = ui -> CB_gripper_num -> currentText();
    QString shelf_name = ui->CB_shelf->currentText()+"_"+ui->cb_obj_direction_2->currentText();
    QString obj_name = ui->cb_get_object_id_2->currentText();

    /*
    int index = ui->cb_get_object_id_vision->findText(obj_name);
    qDebug()<<"index : "<<index;
    //                        if index != -1;  항목이 존재하면

    if (index != -1)
    {
        ui->cb_get_object_id_vision->setCurrentIndex(index);
    }
    else
    {
        qDebug() << "항목이 존재하지 않습니다.";
    }*/

    json["msg_type"] = "command";
    json["entry"] = "manipulator";
    json["do"] = "pick_item";

    json_parm["item_count"] = count.toDouble();
    json_parm["shelve_height"] = shelf_hight.toDouble();
    json_parm["shelve_degree"] = 45;
    json_parm["shelve_name"] = shelf_name;

    //db 에 저장되어있는 내용
    json_destination_box["name"] = obj_name;
    json_destination_box["id"] = obj_name;
    json_parm["destination_box"] = json_destination_box;
    json["params"] = json_parm;

    QJsonDocument doc_json(json);
    QString str_json(doc_json.toJson(QJsonDocument::Indented));

    // order msg kipping
    mtx.lock();
    order_json_msg.push(str_json);
    mtx.unlock();

    bt_order_check();
    ui -> te_order -> append(str_json);
}

void MainWindow::bt_order_check()
{
    // order msg save -> parsing -> making parsing msg to qstringlist -> que astringlist
    //    qDebug()<<order_json_msg.front();

    //    QString shelf_hight = ui->le_shelf_hight->text();
    int count = ui -> CB_gripper_num -> currentText().toInt();
    //    QString shelf_name = ui->CB_shelf->currentText();

    for(auto& it: shelf_infos) // get from saved json
    {
        if(it.second == nullptr)
        {
            continue;
        }

        QStringList order_msg;
        QString new_msg = order_json_msg.front();
        QJsonDocument doc_json = QJsonDocument::fromJson(new_msg.toUtf8());
        QJsonObject json = doc_json.object();

        QVariantMap json_pa = json.toVariantMap();
        QVariantMap json_parm = json_pa["params"].toMap();
        QVariantMap json_destination_box = json_parm["destination_box"].toMap();

        float shelve_height = json_parm["shelve_height"].toDouble();
        //        shelf_info->RB_5_pose;

        if (order_list_msg.size() == 0)
        {
            qDebug()<<"msg order que is 0!!!";
            que_time = 0;
        }

        if (it.second->shelf_id == json_parm["shelve_name"].toString()+"_"+QString::number(shelve_height))
        {
            //            qDebug()<<it.second->shelf_id;
            // 정해진 위치에 해당하는 명령이 들어온다면.
            if (it.second->lift_pose == shelve_height)
            {
                qDebug()<<"같은 위치 찾음.";
                std::cout<<it.second->RB_5_pose[0]<<std::endl;

                // AMR pose
                QString AMR_pose = "mobile move,"+QString::number(it.second->AMR_pose[0])+","+QString::number(it.second->AMR_pose[1])+","
                        +QString::number(it.second->AMR_pose[2]);

                //임시 주석
                order_msg.append(AMR_pose);

                QString lift_high = "lift_high,"+QString::number(shelve_height);


                // vision robot pose -> robot pose blend
                QString robot_vision = "robot vision,"+QString::number(it.second->RB_5_pose[0])+","+QString::number(it.second->RB_5_pose[1])+","
                        +QString::number(it.second->RB_5_pose[2])+","+QString::number(it.second->RB_5_pose[3])+
                        ","+QString::number(it.second->RB_5_pose[4])+","+QString::number(it.second->RB_5_pose[5]);

                //                qDebug()<<"robot moving :" <<robot_vision;
                order_msg.append(robot_vision);

                order_msg.append(lift_high);//리프트 이동
                //                                order_msg.append("robot_high_vision");

                //                order_msg.append("wait");
                // 물체가 박스에 있는 경우에만 사용.
                if(shelve_height < 600)
                {
                    order_msg.append("robot vision box center");
                }

                //                order_msg.append("wait");
                order_msg.append("vision");
                //                order_msg.append("wait");
                order_msg.append("robot approach");
                order_msg.append("robot pick");
                //                order_msg.append("wait");
                //                order_msg.append("robot push");
                //                order_msg.append("wait");

                if (count != 1)
                {
                    QStringList msg;
                    for(int i=0; i<count; i++)
                    {
                        msg += order_msg;
                    }
                    qDebug()<<"msg :"<<msg;
                    order_msg = msg;
                }
            }
            else //만약 정해진 위치가 아닌 다른 위치가 들어온다면.
            {
                qDebug()<<"위치 다름.";
                QString lift_high = "lift_high," + QString::number(shelve_height);
                order_msg.append(lift_high);//리프트 이동
                //                order_msg.append("scene done");//리프트 이동
            }

            for(auto& it: object_infos) // get propreate gripping position hands data
            {
                if(it.second == nullptr)
                {
                    continue;
                }

                if (it.second->obj_id == json_destination_box["name"].toString())
                {

                    //                    obj_id;
                    //                        std::cout<<it.second->RB_5_pose[0]<<std::endl;
                    qDebug()<<"grap pose : "<<it.second->obj_grap_pose;
                    qDebug()<<"ready grap pose :"<<it.second->obj_ready_grap_pose;
                    //                        order_msg.append("");
                    //                        order_msg.append("");
                    QString grasp_ready = "grasp ready,"+it.second->obj_ready_grap_pose;

                    QString gripper_connect = ui->le_gripper_connection->styleSheet();
                    bool gripper_state = gripper_connect.contains("green", Qt::CaseInsensitive);

                    //추가된 부분
                    if (gripper_state)
                    {
                        order_msg.append(grasp_ready);
                        order_msg.append("wait");
                    }
                    order_msg.append("robot pump on");

                    QString real_grasp = "grasp real,"+it.second->obj_grap_pose;
                    //                qDebug()<<"robot moving :" <<robot_vision;

                    //추가된 부분
                    if (gripper_state)
                    {
                        order_msg.append(real_grasp);
                    }
                    order_msg.append("robot pop");
                    if(shelve_height < 600)
                    {
                        order_msg.append("robot box center");
                    }
                    //                order_msg.append("robot pump on");
                    order_msg.append("robot mid left");


                    QString lift_down = "lift_high,100";
                    order_msg.append(lift_down);//리프트 이동
                    order_msg.append("robot pump off");
                    order_msg.append("success");
                }
            }

            qDebug()<<"order_msg :"<<order_msg;
            mtx.lock();
            order_list_msg.push(order_msg);
            mtx.unlock();
            //                qDebug()<<"나는 큐의 크기를 알고싶다 : "<<order_list_msg.size();
            //                cur_step = ROBOT_STATE_START;
            flag_circle = false;
            old_msg_size = order_list_msg.size();

        }
    }
    order_json_msg.pop();// loop 안에서 pop해야함.
}
```
