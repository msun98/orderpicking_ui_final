//https://doc.qt.io/qt-5/qtcore-ipc-sharedmemory-example.html 참고.
#include "ipc.h"

IPC::IPC(QObject *parent)
    : QObject(parent)
    , shm_cmd("slamnav_cmd")
    , shm_status("slamnav_status")
    , shm_path("slamnav_path")
    , shm_map("slamnav_map")
    , shm_obs("slamnav_obs")
    , shm_cam0("slamnav_cam0")
    , shm_cam1("slamnav_cam1")

    , shm_move("slamnav_move")
    , shm_mobile_pose("slamnav_pose")
    , shm_mobile_status("slamnav_mobile_status")
    , shm_move_success_check("slamnav_move_success_check")

    , shm_rb_5("rb_5_check")
    , shm_gripper("gripper_cmd")
    , shm_websocketON("yujin_websocketON")

    , shm_detect_img("vison_img")
    , shm_detect_point("vison_point")

    , shm_handeye_detect_flag("shm_handeye_detect_flag")

    , shm_box_center_point("box_center_point")

{
    // msg tick clear, check for new data
    tick = 0;

    // create or attach
    //프로그램 오픈시 공유 메모리 생성, 쉐어드 메모리 오픈되어있는지 확인.
    if (!shm_cmd.create(sizeof(IPC::CMD), QSharedMemory::ReadWrite) && shm_cmd.error() == QSharedMemory::AlreadyExists)

    //공유 메모리 세그먼트 생성. 공유 메모리 세그먼트가 이미 존재하는 경우 false 반환
    // 공유 메모리가 만들어지지 않았고 쉐어드 메모리가 이미 존재하고 있다고 하면
    {
        printf("attach shared memory, key: slamnav_cmd, size: %ld\n", sizeof(IPC::CMD));
        shm_cmd.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_cmd, size: %ld\n", sizeof(IPC::CMD));
    }

    if (!shm_status.create(sizeof(IPC::STATUS), QSharedMemory::ReadWrite) && shm_status.error() == QSharedMemory::AlreadyExists)
    {
//        qDebug()<<"ERROR : "<<shm_status.errorString();
        printf("attach shared memory, key: slamnav_status, size: %ld\n", sizeof(IPC::STATUS));
        shm_status.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_status, size: %ld\n", sizeof(IPC::STATUS));
    }

    if (!shm_path.create(sizeof(IPC::PATH), QSharedMemory::ReadWrite) && shm_path.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: slamnav_path, size: %ld\n", sizeof(IPC::PATH));
        shm_path.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_path, size: %ld\n", sizeof(IPC::PATH));
    }

    if (!shm_map.create(sizeof(IPC::MAP), QSharedMemory::ReadWrite) && shm_map.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: slamnav_map, size: %ld\n", sizeof(IPC::MAP));
        shm_map.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_map, size: %ld\n", sizeof(IPC::MAP));
    }

    if (!shm_obs.create(sizeof(IPC::MAP), QSharedMemory::ReadWrite) && shm_obs.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: slamnav_obs, size: %ld\n", sizeof(IPC::MAP));
        shm_obs.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_obs, size: %ld\n", sizeof(IPC::MAP));
    }

    if (!shm_cam0.create(sizeof(IPC::IMG), QSharedMemory::ReadWrite) && shm_cam0.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: slamnav_cam0, size: %ld\n", sizeof(IPC::IMG));
        shm_cam0.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_cam0, size: %ld\n", sizeof(IPC::IMG));
    }

    if (!shm_cam1.create(sizeof(IPC::IMG), QSharedMemory::ReadWrite) && shm_cam1.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: slamnav_cam1, size: %ld\n", sizeof(IPC::IMG));
        shm_cam1.attach();
    }
    else
    {
        printf("create shared memory, key: slamnav_cam1, size: %ld\n", sizeof(IPC::IMG));
    }
    if (!shm_move.create(sizeof(IPC::POSE), QSharedMemory::ReadWrite) && shm_move.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_move, size: %ld\n", sizeof(IPC::POSE));
        shm_move.attach();
    }
    else
    {
        printf("create shared memory, key: shm_move, size: %ld\n", sizeof(IPC::POSE));
    }
    if (!shm_mobile_pose.create(sizeof(IPC::MOBILE_POSE), QSharedMemory::ReadWrite) && shm_mobile_pose.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_move, size: %ld\n", sizeof(IPC::POSE));
        shm_mobile_pose.attach();
    }
    else
    {
        printf("create shared memory, key: shm_move, size: %ld\n", sizeof(IPC::POSE));
    }

    if (!shm_mobile_status.create(sizeof(IPC::ROBOT_COMMAND), QSharedMemory::ReadWrite) && shm_mobile_status.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_mobile_status, size: %ld\n", sizeof(IPC::ROBOT_COMMAND));
        shm_mobile_status.attach();
    }
    else
    {
        printf("create shared memory, key: shm_mobile_status, size: %ld\n", sizeof(IPC::ROBOT_COMMAND));
    }

    if (!shm_move_success_check.create(sizeof(IPC::SUCCESS_CHECK), QSharedMemory::ReadWrite) && shm_move_success_check.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_move_success_check, size: %ld\n", sizeof(IPC::SUCCESS_CHECK));
        shm_move_success_check.attach();
    }
    else
    {
        printf("create shared memory, key: shm_move_success_check, size: %ld\n", sizeof(IPC::SUCCESS_CHECK));
    }

    if (!shm_rb_5.create(sizeof(IPC::RB_5), QSharedMemory::ReadWrite) && shm_move_success_check.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: rb_5_check, size: %ld\n", sizeof(IPC::RB_5));
        shm_rb_5.attach();
    }
    else
    {
        printf("create shared memory, key: rb_5_check, size: %ld\n", sizeof(IPC::RB_5));
    }

    //for get gripper cmd
    if (!shm_gripper.create(sizeof(IPC::GRIPPER), QSharedMemory::ReadWrite) && shm_gripper.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: gripper cmd, size: %ld\n", sizeof(IPC::GRIPPER));
        shm_gripper.attach();
    }
    else
    {
        printf("create shared memory, key: gripper cmd, size: %ld\n", sizeof(IPC::GRIPPER));
    }

    //for check websocket
    if (!shm_websocketON.create(sizeof(IPC::SUCCESS_CHECK), QSharedMemory::ReadWrite) && shm_websocketON.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_websocketON, size: %ld\n", sizeof(IPC::SUCCESS_CHECK));
        shm_websocketON.attach();
    }
    else
    {
        printf("create shared memory, key: shm_websocketON, size: %ld\n", sizeof(IPC::SUCCESS_CHECK));
    }

    //for get vision img
    if (!shm_detect_img.create(sizeof(IPC::COLOR_MAP), QSharedMemory::ReadWrite) && shm_detect_img.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_detect_img, size: %ld\n", sizeof(IPC::COLOR_MAP));
        shm_detect_img.attach();
    }
    else
    {
        printf("create shared memory, key: shm_detect_img, size: %ld\n", sizeof(IPC::COLOR_MAP));
    }

    //for get vision point
    if (!shm_detect_point.create(sizeof(IPC::VISION_POSE), QSharedMemory::ReadWrite) && shm_detect_point.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_detect_point, size: %ld\n", sizeof(IPC::VISION_POSE));
        shm_detect_point.attach();
    }
    else
    {
        printf("create shared memory, key: shm_detect_point, size: %ld\n", sizeof(IPC::VISION_POSE));
    }

    if (!shm_handeye_detect_flag.create(sizeof(IPC::Handeye_FLAG), QSharedMemory::ReadWrite) && shm_handeye_detect_flag.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_handeye_detect_flag, size: %ld\n", sizeof(IPC::Handeye_FLAG));
        shm_handeye_detect_flag.attach();
    }
    else
    {
        printf("create shared memory, key: shm_handeye_detect_flag, size: %ld\n", sizeof(IPC::Handeye_FLAG));
    }

    if (!shm_box_center_point.create(sizeof(IPC::BOX_CENTER_POSE), QSharedMemory::ReadWrite) && shm_box_center_point.error() == QSharedMemory::AlreadyExists)
    {
        printf("attach shared memory, key: shm_handeye_detect_flag, size: %ld\n", sizeof(IPC::BOX_CENTER_POSE));
        shm_box_center_point.attach();
    }
    else
    {
        printf("create shared memory, key: shm_handeye_detect_flag, size: %ld\n", sizeof(IPC::BOX_CENTER_POSE));
    }
}

IPC::~IPC()//프로그램 종료시 연결 해제
{
    if(shm_cmd.detach())
    {
        printf("detach shared memory, key: slamnav_cmd\n");
    }

    if(shm_status.detach())
    {
        printf("detach shared memory, key: slamnav_status\n");
    }

    if(shm_path.detach())
    {
        printf("detach shared memory, key: slamnav_path\n");
    }

    if(shm_map.detach())
    {
        printf("detach shared memory, key: slamnav_map\n");
    }

    if(shm_obs.detach())
    {
        printf("detach shared memory, key: slamnav_obs\n");
    }

    if(shm_cam0.detach())
    {
        printf("detach shared memory, key: slamnav_cam0\n");
    }

    if(shm_cam1.detach())
    {
        printf("detach shared memory, key: slamnav_cam1\n");
    }

    if(shm_move.detach())
    {
        printf("detach shared memory, key: shm_move\n");
    }

    if(shm_mobile_pose.detach())
    {
        printf("detach shared memory, key: shm_mobile_pose\n");
    }

    if(shm_mobile_status.detach())
    {
        printf("detach shared memory, key: shm_mobile_status\n");
    }

    if(shm_move_success_check.detach())
    {
        printf("detach shared memory, key: shm_move_success_check\n");
    }

    if(shm_rb_5.detach())
    {
        printf("detach shared memory, key: rb_5_check\n");
    }

    if(shm_gripper.detach())
    {
        printf("detach shared memory, key: gripper_cmd\n");
    }

    if(shm_websocketON.detach())
    {
        printf("detach shared memory, key: shm_websocketON\n");
    }

    if(shm_detect_img.detach())
    {
        printf("detach shared memory, key: shm_detect_img\n");
    }

    if(shm_detect_point.detach())
    {
        printf("detach shared memory, key: shm_detect_point\n");
    }

    if(shm_handeye_detect_flag.detach())
    {
        printf("detach shared memory, key: shm_handeye_detect_flag\n");
    }

    if(shm_box_center_point.detach())
    {
        printf("detach shared memory, key: shm_box_center_point\n");
    }
}

IPC::CMD IPC::get_cmd()
{
    IPC::CMD res;

    shm_cmd.lock();
    memcpy(&res, (char*)shm_cmd.constData(), sizeof(IPC::CMD));
    shm_cmd.unlock();

    return res;
}

IPC::STATUS IPC::get_status()
{
    IPC::STATUS res;

    shm_status.lock();
    memcpy(&res, (char*)shm_status.constData(), sizeof(IPC::STATUS));
    shm_status.unlock();

    return res;
}

IPC::PATH IPC::get_path()
{
    IPC::PATH res;

    shm_path.lock();
    memcpy(&res, (char*)shm_path.constData(), sizeof(IPC::PATH));
    shm_path.unlock();

    return res;
}

IPC::MAP IPC::get_map()
{
    IPC::MAP res;

    shm_map.lock();
    memcpy(&res, (char*)shm_map.constData(), sizeof(IPC::MAP));
    shm_map.unlock();

    return res;
}

IPC::MAP IPC::get_obs()
{
    IPC::MAP res;

    shm_obs.lock();
    memcpy(&res, (char*)shm_obs.constData(), sizeof(IPC::MAP));
    shm_obs.unlock();

    return res;
}

IPC::IMG IPC::get_cam0()
{
    IPC::IMG res;

    shm_cam0.lock();
    memcpy(&res, (char*)shm_cam0.constData(), sizeof(IPC::IMG));
    shm_cam0.unlock();

    return res;
}

IPC::IMG IPC::get_cam1()
{
    IPC::IMG res;

    shm_cam1.lock();
    memcpy(&res, (char*)shm_cam1.constData(), sizeof(IPC::IMG));
    shm_cam1.unlock();

    return res;
}

IPC::POSE IPC::get_move_where()
{
    IPC::POSE res;

    shm_move.lock();
    memcpy(&res, (char*)shm_move.constData(), sizeof(IPC::POSE));
    shm_move.unlock();

    return res;
}

IPC::MOBILE_POSE IPC::get_mobile_pos()
{
    IPC::MOBILE_POSE res;

    shm_mobile_pose.lock();
    memcpy(&res, (char*)shm_mobile_pose.constData(), sizeof(IPC::MOBILE_POSE));
    shm_mobile_pose.unlock();

    return res;
}

IPC::SUCCESS_CHECK IPC::get_mobile_success_check()
{
    IPC::SUCCESS_CHECK res;

    shm_move_success_check.lock();
    memcpy(&res, (char*)shm_move_success_check.constData(), sizeof(IPC::SUCCESS_CHECK));
    shm_move_success_check.unlock();

    return res;
}

IPC::GRIPPER IPC::get_gripper()
{
    IPC::GRIPPER res;

    shm_gripper.lock();
    memcpy(&res, (char*)shm_gripper.constData(), sizeof(IPC::GRIPPER));
    shm_gripper.unlock();

    return res;
}

////////////// get detect img, point ////////////

IPC::COLOR_MAP IPC::get_img()
{
    IPC::COLOR_MAP res;

    shm_detect_img.lock();
    memcpy(&res, (char*)shm_detect_img.constData(), sizeof(IPC::COLOR_MAP));
    shm_detect_img.unlock();

    return res;
}

IPC::VISION_POSE IPC::get_point()
{
    IPC::VISION_POSE res;
    shm_detect_point.lock();
    memcpy(&res, (char*)shm_detect_point.constData(), sizeof(IPC::VISION_POSE));
    shm_detect_point.unlock();

    return res;
}

IPC::BOX_CENTER_POSE IPC::get_box_center()
{
    IPC::BOX_CENTER_POSE res;
    shm_box_center_point.lock();
    memcpy(&res, (char*)shm_box_center_point.constData(), sizeof(IPC::BOX_CENTER_POSE));
    shm_box_center_point.unlock();

    return res;
}

void IPC::set_cmd(IPC::CMD val)
{
    shm_cmd.lock();
    val.tick = ++tick;
    memcpy((char*)shm_cmd.data(), &val, sizeof(IPC::CMD));
    shm_cmd.unlock();
}

void IPC::set_status(IPC::STATUS val)
{
    shm_status.lock();
    val.tick = ++tick;
    memcpy((char*)shm_status.data(), &val, sizeof(IPC::STATUS));
    shm_status.unlock();
}

void IPC::set_path(IPC::PATH val)
{
    shm_path.lock();
    val.tick = ++tick;
    memcpy((char*)shm_path.data(), &val, sizeof(IPC::PATH));
    shm_path.unlock();
}

void IPC::set_map(IPC::MAP val)
{
    shm_map.lock();
    val.tick = ++tick;
    memcpy((char*)shm_map.data(), &val, sizeof(IPC::MAP));
    shm_map.unlock();
}

void IPC::set_obs(IPC::MAP val)
{
    shm_obs.lock();
    val.tick = ++tick;
    memcpy((char*)shm_obs.data(), &val, sizeof(IPC::MAP));
    shm_obs.unlock();
}

void IPC::set_cam0(IPC::IMG val)
{
    shm_cam0.lock();
    val.tick = ++tick;
    memcpy((char*)shm_cam0.data(), &val, sizeof(IPC::IMG));
    shm_cam0.unlock();
}

void IPC::set_cam1(IPC::IMG val)
{
    shm_cam1.lock();
    val.tick = ++tick;
    memcpy((char*)shm_cam1.data(), &val, sizeof(IPC::IMG));
    shm_cam1.unlock();
}

void IPC::set_move_where(IPC::POSE val)
{
    shm_move.lock();
    val.tick = ++tick;
    memcpy((char*)shm_move.data(), &val, sizeof(IPC::POSE));
//    printf("%f",x)
    shm_move.unlock();
}

void IPC::set_mobile_status(IPC::ROBOT_COMMAND val)
{
    shm_mobile_status.lock();
    val.tick = ++tick;
    memcpy((char*)shm_mobile_status.data(), &val, sizeof(IPC::ROBOT_COMMAND));
//    printf("%f",x)
    shm_mobile_status.unlock();
}

void IPC::set_rb_5_status(IPC::RB_5 val)
{
    shm_rb_5.lock();
    val.tick = ++tick;
    memcpy((char*)shm_rb_5.data(), &val, sizeof(IPC::RB_5));
//    printf("%f",x)
    shm_rb_5.unlock();
}

void IPC::set_gripper(IPC::GRIPPER val)
{
    shm_gripper.lock();
    val.tick = ++tick;
    memcpy((char*)shm_gripper.data(), &val, sizeof(IPC::GRIPPER));
//    printf("%f",x)
    shm_gripper.unlock();
}


void IPC::set_Yujin_CMD(IPC::WEB_commend val)
{
    shm_yujin_json.lock();
    val.tick = ++tick;
    memcpy((char*)shm_yujin_json.data(), &val, sizeof(IPC::WEB_commend));
//    printf("%f",x)
    shm_yujin_json.unlock();
}

void IPC::set_Rainbow_CMD(IPC::WEB_commend val)
{
    shm_rainbow_json.lock();
    val.tick = ++tick;
    memcpy((char*)shm_rainbow_json.data(), &val, sizeof(IPC::WEB_commend));
//    printf("%f",x)
    shm_rainbow_json.unlock();
}

void IPC::set_handeye_flag(IPC::Handeye_FLAG val){
    shm_handeye_detect_flag.lock();
    val.tick = ++tick;
    memcpy((char*)shm_handeye_detect_flag.data(), &val, sizeof(IPC::Handeye_FLAG));
//    printf("%f",x)
    shm_handeye_detect_flag.unlock();
}

void IPC::set_detected_point(IPC::VISION_POSE val)
{
    shm_detect_point.lock();
    val.tick = ++tick;
    memcpy((char*)shm_detect_point.data(), &val, sizeof(IPC::VISION_POSE));
    //    printf("%f",x)
    shm_detect_point.unlock();
}
