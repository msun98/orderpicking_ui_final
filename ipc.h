#ifndef IPC_H
#define IPC_H

#include <QObject>
#include <QSharedMemory>
#include <QDebug>

//// Eigen
//#include <Eigen/Core>
//#include <Eigen/Dense>

////// sophus
////#define SOPHUS_USE_BASIC_LOGGING
////#include <sophus/geometry.hpp>
////#include <sophus/se2.hpp>
////#include <sophus/interpolate.hpp>


//// opencv
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/eigen.hpp>
//#include <opencv2/ximgproc.hpp>
//#include "opencv2/flann/miniflann.hpp"
//#include "cv_to_qt.h"

#include "global_defines.h"

class IPC : public QObject
{
    Q_OBJECT

public:
    struct CMD
    {
        uint32_t tick = 0;
        int32_t cmd = 0;
        uint8_t params[255] = {0,};

        CMD()
        {
        }
        CMD(const CMD& p)
        {
            tick = p.tick;
            cmd = p.cmd;
            memcpy(params, p.params, 255);
        }
    };

    struct STATUS
            // 구조체 변수 정의함과 동시에 생성자에 의해서 특정값으로 초기화됨
    {
        uint32_t   tick = 0;
        int8_t     connection_m0 = 0;
        int8_t     connection_m1 = 0;
        int8_t     status_m0 = 0;
        int8_t     status_m1 = 0;
        int8_t     temp_m0 = 0;
        int8_t     temp_m1 = 0;
        int8_t     temp_ex_m0 = 0;
        int8_t     temp_ex_m1 = 0;
        int8_t     cur_m0 = 0;
        int8_t     cur_m1 = 0;
        int8_t     status_charge = 0;
        int8_t     status_power = 0;
        int8_t     status_emo = 0;
        int8_t     status_remote = 0;
        float      bat_in = 0;
        float      bat_out = 0;
        float      bat_cur = 0;
        float      power = 0;
        float      total_power = 0;
        int8_t     ui_motor_state = 0;
        int8_t     ui_loc_state = 0;
        int8_t     ui_auto_state = 0;
        int8_t     ui_obs_state = 0;
        float      robot_pose[3] = {0,};
        float      robot_scan[360] = {0,};

        STATUS()
        {
        }
        STATUS(const STATUS& p)
        {
            tick = p.tick;
            connection_m0 = p.connection_m0;
            connection_m1 = p.connection_m1;
            status_m0 = p.status_m0;
            status_m1 = p.status_m1;
            temp_m0 = p.temp_m0;
            temp_m1 = p.temp_m1;
            temp_ex_m0 = p.temp_ex_m0;
            temp_ex_m1 = p.temp_ex_m1;
            cur_m0 = p.cur_m0;
            cur_m1 = p.cur_m1;
            status_charge = p.status_charge;
            status_power = p.status_power;
            status_emo = p.status_emo;
            status_remote = p.status_remote;
            bat_in = p.bat_in;
            bat_out = p.bat_out;
            bat_cur = p.bat_cur;
            power = p.power;
            total_power = p.total_power;
            ui_motor_state = p.ui_motor_state;
            ui_loc_state = p.ui_loc_state;
            ui_auto_state = p.ui_auto_state;
            ui_obs_state = p.ui_obs_state;
            memcpy(robot_pose, p.robot_pose, sizeof(float)*3);
            memcpy(robot_scan, p.robot_scan, sizeof(float)*360);
        }
    };

    struct PATH
    {
        uint32_t tick = 0;
        int32_t num = 0;
        float x[512] = {0,};//모든 배열의 요소를 0으로 초기화(only 0만 가느)
        float y[512] = {0,};

        PATH()
        {
        }
        PATH(const PATH& p)
        {
            tick = p.tick;
            num = p.num;
            memcpy(x, p.x, sizeof(float)*512);
            memcpy(y, p.y, sizeof(float)*512);
        }
    };

    struct MAP
    {
        //        https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kyed203&logNo=220056487775
        uint32_t tick = 0;
        uint32_t width = 1000;
        uint32_t height = 1000;
        uint8_t buf[1000*1000] = {0,};

        MAP()
        {
        }
        MAP(const MAP& p)
        {
            tick = p.tick;
            width = p.width;
            height = p.height;
            memcpy(buf, p.buf, 1000*1000);
        }
    };

    struct IMG
    {
        uint32_t tick = 0;
        uint8_t serial[255] = {0,};
        uint32_t width = 480;
        uint32_t height = 270;
        uint8_t buf[480*270] = {0,};

        IMG()
        {
        }
        IMG(const IMG& p)
        {
            tick = p.tick;
            width = p.width;
            height = p.height;
            memcpy(serial, p.serial, 255);
            memcpy(buf, p.buf, 480*270);
        }
    };

    //for yujin websocket
    struct POSE
    {
        uint32_t tick = 0;
        float x = 0;
        float y = 0;
        float theta = 0;

        POSE()
        {
        }
        POSE(const POSE& p)
        {
            tick = p.tick;
            x = p.x;
            y = p.y;
            theta = p.theta;
        }
    };


    struct MOBILE_POSE
    {
        double t;
        cv::Vec3d pose; // global (x, y, th)
        cv::Vec3d vel; // global (x_dot, y_dot, th_dot)
        cv::Vec2d vw; // local (v, w)
        uint32_t tick = 0;

        MOBILE_POSE()
        {
            t = 0;
            pose = cv::Vec3d(0,0,0);
            vel = cv::Vec3d(0,0,0);
            vw = cv::Vec2d(0,0);
        }
        MOBILE_POSE(const MOBILE_POSE& p)
        {
            tick = p.tick;
            t = p.t;
            pose = p.pose;
            vel = p.vel;
            vw = p.vw;
        }
    };

    struct ROBOT_COMMAND
    {
        uint32_t tick = 0;
        uint32_t robot_status = 0;

        ROBOT_COMMAND()
        {
        }
        ROBOT_COMMAND(const ROBOT_COMMAND& p)
        {
            tick = p.tick;
            robot_status = p.robot_status;
            //robot_status 0 = move
            //robot_status 1 = pause
            //robot_status 2 = resume
            //robot_status 3 = stop
        }
    };

    //도착 성공, 커넥션 체크 등
    struct SUCCESS_CHECK
    {
        uint32_t tick = 0;
        bool check = 0;
        //success_check = 0 -> success
        //success_check = 1 -> fail

        SUCCESS_CHECK()
        {

        }
        SUCCESS_CHECK(const SUCCESS_CHECK& p)
        {
            tick = p.tick;
            check = p.check;
        }
    };

    //for RB5
    struct RB_5
    {
        uint32_t tick = 0;
        //        float   jnt_ref[6];             // joint reference [deg]
        float   jnt_ang[6];             // joint encoder value [deg]
        float   tcp_ref[6];             // calculated tool center point from reference [mm, deg]
        RB_5()
        {

        }
        RB_5(const RB_5& p)
        {
            tick = p.tick;
            memcpy(jnt_ang, p.jnt_ang, 6);
            memcpy(tcp_ref, p.tcp_ref, 6);
        }
    };

    //그리퍼 명령어
    struct GRIPPER
    {
        uint32_t tick = 0;
        uint8_t cmd[50] = {0,};
        //success_check = 0 -> success
        //success_check = 1 -> fail

        GRIPPER()
        {

        }
        GRIPPER(const GRIPPER& p)
        {
            tick = p.tick;
            memcpy(cmd, p.cmd, 50);
        }
    };

    struct WEB_commend
    {
        uint32_t tick = 0;
        uint8_t json_cmd[1000] = {0,};
        uint32_t json_cmd_size = 0;
        uint8_t json_uuid[30]= {0,};
        uint32_t json_uuid_size = 0;

        WEB_commend()
        {

        }
        WEB_commend(const WEB_commend& p)
        {
            tick = p.tick;
            memcpy(json_cmd, p.json_cmd, 1000);
            json_cmd_size = p.json_cmd_size;
            memcpy(json_uuid, p.json_uuid, 30);
            json_uuid_size = p.json_uuid_size;
        }
    };

    // for detect img send to integrate ui
    struct COLOR_MAP

    {
        uint32_t tick = 0;
        uint32_t width = 500;
        uint32_t height = 300;
        uint8_t buf[500*300*3] = {0,};

        COLOR_MAP()

        {

        }

        COLOR_MAP(const COLOR_MAP& p)

        {

            tick = p.tick;
            width = p.width;
            height = p.height;
            memcpy(buf, p.buf, 500*300*3);

        }
    };

    //img detect point
    struct VISION_POSE
    {

        uint32_t tick = 0;
        //        bool pose_change_flag = false;
        float x = 0;
        float y = 0;
        float z = 0;
        float roll = 0;
        float pitch = 0;
        float yaw = 0;

        VISION_POSE()

        {

        }

        VISION_POSE (const VISION_POSE& p)
        {

            tick = p.tick;
            //            pose_change_flag = p.pose_change_flag;
            x = p.x;
            y = p.y;
            z = p.z;
            roll = p.roll;
            pitch = p.pitch;
            yaw = p.yaw;
        }
    };

    //img detect point
    struct BOX_CENTER_POSE
    {

        uint32_t tick = 0;
        float x = 0;
        float y = 0;
        float z = 0;
        float roll = 0;
        float pitch = 0;
        float yaw = 0;

        BOX_CENTER_POSE()

        {

        }

        BOX_CENTER_POSE (const BOX_CENTER_POSE& p)
        {

            tick = p.tick;
            x = p.x;
            y = p.y;
            z = p.z;
            roll = p.roll;
            pitch = p.pitch;
            yaw = p.yaw;
        }
    };

    //img detect cmd
    struct Handeye_FLAG
    {

        uint32_t tick = 0;
        //        uint8_t flag[18];
        bool flag;

        Handeye_FLAG()

        {

        }

        Handeye_FLAG (const Handeye_FLAG& p)
        {

            tick = p.tick;
            flag = p.flag;
            //            memcpy(flag, p.flag, 18);

        }
    };

public:
    explicit IPC(QObject *parent = nullptr);
    ~IPC();

    std::atomic<uint32_t> tick;

    QSharedMemory shm_cmd;
    QSharedMemory shm_status;
    QSharedMemory shm_path;
    QSharedMemory shm_map;
    QSharedMemory shm_obs;
    QSharedMemory shm_cam0;
    QSharedMemory shm_cam1;

    QSharedMemory shm_move;
    QSharedMemory shm_mobile_pose;
    QSharedMemory shm_box_center_point;
    QSharedMemory shm_mobile_status;
    QSharedMemory shm_move_success_check;

    QSharedMemory shm_rb_5;


    QSharedMemory shm_gripper;

    //for check websocket on
    QSharedMemory shm_websocketON;

    QSharedMemory shm_yujin_json;
    QSharedMemory shm_rainbow_json;

    QSharedMemory shm_detect_img;
    QSharedMemory shm_detect_point;

    QSharedMemory shm_handeye_detect_flag;

    CMD get_cmd();
    STATUS get_status();
    PATH get_path();
    MAP get_map();
    MAP get_obs();
    IMG get_cam0();
    IMG get_cam1();

    POSE get_move_where(); // 어디로 갈지 유진 로봇으로 부터 받는 코드.
    MOBILE_POSE get_mobile_pos(); //move, pause, resume, stop
    SUCCESS_CHECK get_mobile_success_check();//성공여부 확인을 위해 생성한 코드.

    GRIPPER get_gripper();

    COLOR_MAP get_img();
    VISION_POSE get_point();
    BOX_CENTER_POSE get_box_center();

    void set_cmd(IPC::CMD val);
    void set_status(IPC::STATUS val);
    void set_path(IPC::PATH val);
    void set_map(IPC::MAP val);
    void set_obs(IPC::MAP val);
    void set_cam0(IPC::IMG val);
    void set_cam1(IPC::IMG val);
    void set_move_where(IPC::POSE val);
    void set_mobile_status(IPC::ROBOT_COMMAND val);

    void set_rb_5_status(IPC::RB_5 val);
    void set_gripper(IPC::GRIPPER val);

    void set_Yujin_CMD(IPC::WEB_commend val);// 유진로봇 명령 통합 ui에 전달하기 위함.
    void set_Rainbow_CMD(IPC::WEB_commend val);// 내가 보낸 메시지 통합 ui에전달하기 위함.
    void set_detected_point(IPC::VISION_POSE val);// detected img point 통합 ui에 전달하기 위함.
    void set_handeye_flag(IPC::Handeye_FLAG val);




signals:

};

#endif // IPC_H
