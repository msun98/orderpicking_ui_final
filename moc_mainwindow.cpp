/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[146];
    char stringdata0[3012];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "onSystemCheck"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "lift_ui"
QT_MOC_LITERAL(4, 34, 11), // "status_loop"
QT_MOC_LITERAL(5, 46, 5), // "print"
QT_MOC_LITERAL(6, 52, 20), // "UI_Connection_Update"
QT_MOC_LITERAL(7, 73, 3), // "msg"
QT_MOC_LITERAL(8, 77, 25), // "UI_Connection_Update_Lift"
QT_MOC_LITERAL(9, 103, 8), // "onUpdate"
QT_MOC_LITERAL(10, 112, 15), // "keti_showUI_msg"
QT_MOC_LITERAL(11, 128, 12), // "connect_flag"
QT_MOC_LITERAL(12, 141, 17), // "kitech_showUI_msg"
QT_MOC_LITERAL(13, 159, 19), // "barcode1_showUI_msg"
QT_MOC_LITERAL(14, 179, 19), // "barcode2_showUI_msg"
QT_MOC_LITERAL(15, 199, 17), // "barcode_ON_showUI"
QT_MOC_LITERAL(16, 217, 21), // "BTN_GRIPPER_CMD_WRITE"
QT_MOC_LITERAL(17, 239, 19), // "BTN_GRIPPER_ALLFOLD"
QT_MOC_LITERAL(18, 259, 17), // "BTN_GRIPPER_GRASP"
QT_MOC_LITERAL(19, 277, 18), // "BTN_GRIPPER_VISION"
QT_MOC_LITERAL(20, 296, 23), // "CB_GRIPPER_GE_CMD_WRITE"
QT_MOC_LITERAL(21, 320, 12), // "Pinch12_FOLD"
QT_MOC_LITERAL(22, 333, 11), // "bt_usb1_con"
QT_MOC_LITERAL(23, 345, 11), // "bt_usb2_con"
QT_MOC_LITERAL(24, 357, 11), // "bt_usb1_dis"
QT_MOC_LITERAL(25, 369, 11), // "bt_usb2_dis"
QT_MOC_LITERAL(26, 381, 27), // "UI_Connection_Update_mobile"
QT_MOC_LITERAL(27, 409, 7), // "rb_pose"
QT_MOC_LITERAL(28, 417, 20), // "bt_cobot_move2object"
QT_MOC_LITERAL(29, 438, 23), // "set_ui_item_from_unimap"
QT_MOC_LITERAL(30, 462, 13), // "bt_save_annot"
QT_MOC_LITERAL(31, 476, 17), // "bt_save_all_annot"
QT_MOC_LITERAL(32, 494, 15), // "bt_delete_annot"
QT_MOC_LITERAL(33, 510, 15), // "bt_save_annot_2"
QT_MOC_LITERAL(34, 526, 19), // "bt_save_all_annot_2"
QT_MOC_LITERAL(35, 546, 17), // "bt_delete_annot_2"
QT_MOC_LITERAL(36, 564, 8), // "bt_order"
QT_MOC_LITERAL(37, 573, 10), // "kitech_msg"
QT_MOC_LITERAL(38, 584, 11), // "LE_KETI_IMG"
QT_MOC_LITERAL(39, 596, 7), // "cv::Mat"
QT_MOC_LITERAL(40, 604, 7), // "map_img"
QT_MOC_LITERAL(41, 612, 16), // "auto_homming_seq"
QT_MOC_LITERAL(42, 629, 11), // "yujin_order"
QT_MOC_LITERAL(43, 641, 4), // "json"
QT_MOC_LITERAL(44, 646, 17), // "yujin_order_check"
QT_MOC_LITERAL(45, 664, 13), // "tf_any_change"
QT_MOC_LITERAL(46, 678, 9), // "bt_tcp_on"
QT_MOC_LITERAL(47, 688, 10), // "bt_connect"
QT_MOC_LITERAL(48, 699, 14), // "bt_lift_status"
QT_MOC_LITERAL(49, 714, 10), // "bt_rpmZero"
QT_MOC_LITERAL(50, 725, 9), // "bt_homing"
QT_MOC_LITERAL(51, 735, 14), // "bt_auto_homing"
QT_MOC_LITERAL(52, 750, 11), // "bt_move_pos"
QT_MOC_LITERAL(53, 762, 16), // "bt_lift_pos_move"
QT_MOC_LITERAL(54, 779, 11), // "sb_lift_pos"
QT_MOC_LITERAL(55, 791, 17), // "bt_set_maxVel_pos"
QT_MOC_LITERAL(56, 809, 18), // "bt_lift_maxVel_pos"
QT_MOC_LITERAL(57, 828, 11), // "bt_move_rpm"
QT_MOC_LITERAL(58, 840, 9), // "write_log"
QT_MOC_LITERAL(59, 850, 3), // "str"
QT_MOC_LITERAL(60, 854, 13), // "readyRead_udp"
QT_MOC_LITERAL(61, 868, 24), // "timer_shared_memory_loop"
QT_MOC_LITERAL(62, 893, 17), // "newConnection_tcp"
QT_MOC_LITERAL(63, 911, 15), // "BTN_CONNECT_COM"
QT_MOC_LITERAL(64, 927, 16), // "BTN_CONNECT_DATA"
QT_MOC_LITERAL(65, 944, 7), // "homeEnd"
QT_MOC_LITERAL(66, 952, 25), // "on_BTN_COBOT_INIT_clicked"
QT_MOC_LITERAL(67, 978, 24), // "on_BTN_MODE_REAL_clicked"
QT_MOC_LITERAL(68, 1003, 30), // "on_BTN_MODE_SIMULATION_clicked"
QT_MOC_LITERAL(69, 1034, 20), // "on_BTN_CLEAR_clicked"
QT_MOC_LITERAL(70, 1055, 27), // "on_BTN_MOTION_PAUSE_clicked"
QT_MOC_LITERAL(71, 1083, 28), // "on_BTN_MOTION_RESUME_clicked"
QT_MOC_LITERAL(72, 1112, 26), // "on_BTN_MOTION_HALT_clicked"
QT_MOC_LITERAL(73, 1139, 31), // "on_BTN_COLLISION_RESUME_clicked"
QT_MOC_LITERAL(74, 1171, 30), // "on_BTN_MOVE_JOINT_HIGH_clicked"
QT_MOC_LITERAL(75, 1202, 39), // "on_BTN_MOVE_JOINT_READY_GRIPP..."
QT_MOC_LITERAL(76, 1242, 39), // "on_BTN_MOVE_JOINT_GRAPS_GRIPP..."
QT_MOC_LITERAL(77, 1282, 29), // "on_HS_BASE_SPEED_valueChanged"
QT_MOC_LITERAL(78, 1312, 5), // "value"
QT_MOC_LITERAL(79, 1318, 19), // "BTN_CONNECT_GRIPPER"
QT_MOC_LITERAL(80, 1338, 35), // "on_BTN_MOVE_JOINT_HIGH_LEFT_c..."
QT_MOC_LITERAL(81, 1374, 32), // "on_BTN_MOVE_JOINT_INIT_3_clicked"
QT_MOC_LITERAL(82, 1407, 32), // "on_BTN_MOVE_JOINT_INIT_4_clicked"
QT_MOC_LITERAL(83, 1440, 32), // "on_BTN_MOVE_JOINT_INIT_5_clicked"
QT_MOC_LITERAL(84, 1473, 13), // "bt_png_change"
QT_MOC_LITERAL(85, 1487, 6), // "bt_zip"
QT_MOC_LITERAL(86, 1494, 10), // "showUI_msg"
QT_MOC_LITERAL(87, 1505, 17), // "showUI_recive_msg"
QT_MOC_LITERAL(88, 1523, 7), // "message"
QT_MOC_LITERAL(89, 1531, 15), // "showUI_send_msg"
QT_MOC_LITERAL(90, 1547, 22), // "on_bt_rb5_mode_clicked"
QT_MOC_LITERAL(91, 1570, 29), // "on_sld_rb5_speed_valueChanged"
QT_MOC_LITERAL(92, 1600, 8), // "btn_pump"
QT_MOC_LITERAL(93, 1609, 28), // "on_sb_rb5_speed_valueChanged"
QT_MOC_LITERAL(94, 1638, 4), // "arg1"
QT_MOC_LITERAL(95, 1643, 22), // "bt_get_map_from_mobile"
QT_MOC_LITERAL(96, 1666, 9), // "lb_sn_map"
QT_MOC_LITERAL(97, 1676, 34), // "on_BTN_MOVE_JOINT_Rotation_cl..."
QT_MOC_LITERAL(98, 1711, 24), // "on_bt_cobot_push_clicked"
QT_MOC_LITERAL(99, 1736, 21), // "on_btn_pump_2_clicked"
QT_MOC_LITERAL(100, 1758, 23), // "on_bt_TCP_Blend_clicked"
QT_MOC_LITERAL(101, 1782, 29), // "on_BTN_MOVE_JOINT_LOW_clicked"
QT_MOC_LITERAL(102, 1812, 32), // "on_BTN_MOVE_JOINT_INIT_7_clicked"
QT_MOC_LITERAL(103, 1845, 22), // "on_bt_lift_top_clicked"
QT_MOC_LITERAL(104, 1868, 22), // "on_bt_lift_MID_clicked"
QT_MOC_LITERAL(105, 1891, 22), // "on_bt_lift_Low_clicked"
QT_MOC_LITERAL(106, 1914, 25), // "on_bt_low_get_out_clicked"
QT_MOC_LITERAL(107, 1940, 26), // "on_bt_vision_water_clicked"
QT_MOC_LITERAL(108, 1967, 33), // "on_bt_vision_high_get_out_cli..."
QT_MOC_LITERAL(109, 2001, 29), // "on_BTN_MOVE_JOINT_MID_clicked"
QT_MOC_LITERAL(110, 2031, 35), // "on_bt_vision_rael_more_move_c..."
QT_MOC_LITERAL(111, 2067, 25), // "on_BTN_MOVE_TOTAL_clicked"
QT_MOC_LITERAL(112, 2093, 21), // "on_pb_shutter_clicked"
QT_MOC_LITERAL(113, 2115, 32), // "on_bt_vision_cmd_capture_clicked"
QT_MOC_LITERAL(114, 2148, 34), // "on_BTN_MOVE_JOINT_MID_LEFT_cl..."
QT_MOC_LITERAL(115, 2183, 35), // "on_BTN_MOVE_JOINT_MID_RIGHT_c..."
QT_MOC_LITERAL(116, 2219, 7), // "seqLoop"
QT_MOC_LITERAL(117, 2227, 19), // "on_ALL_STOP_clicked"
QT_MOC_LITERAL(118, 2247, 27), // "on_BTN_MOVE_TOTAL_2_clicked"
QT_MOC_LITERAL(119, 2275, 27), // "on_BTN_MOVE_TOTAL_3_clicked"
QT_MOC_LITERAL(120, 2303, 27), // "on_BTN_MOVE_TOTAL_4_clicked"
QT_MOC_LITERAL(121, 2331, 25), // "on_pb_file_choose_clicked"
QT_MOC_LITERAL(122, 2357, 23), // "on_bt_rb5_pause_clicked"
QT_MOC_LITERAL(123, 2381, 24), // "on_bt_rb5_resume_clicked"
QT_MOC_LITERAL(124, 2406, 22), // "on_bt_rb5_halt_clicked"
QT_MOC_LITERAL(125, 2429, 10), // "yujin_loop"
QT_MOC_LITERAL(126, 2440, 24), // "on_bt_sn_cmd_set_clicked"
QT_MOC_LITERAL(127, 2465, 17), // "bt_amr_motor_init"
QT_MOC_LITERAL(128, 2483, 19), // "on_BTN_show_clicked"
QT_MOC_LITERAL(129, 2503, 18), // "vision_img_capture"
QT_MOC_LITERAL(130, 2522, 23), // "BTN_GRIPPER_recog_WRITE"
QT_MOC_LITERAL(131, 2546, 29), // "on_BTN_MOVE_JOINT_POP_clicked"
QT_MOC_LITERAL(132, 2576, 36), // "on_BTN_MOVE_JOINT_BOX_CENTER_..."
QT_MOC_LITERAL(133, 2613, 30), // "on_BTN_TCP_MOTION_TEST_clicked"
QT_MOC_LITERAL(134, 2644, 32), // "on_BTN_JOINT_MOTION_TEST_clicked"
QT_MOC_LITERAL(135, 2677, 20), // "on_pb_reload_clicked"
QT_MOC_LITERAL(136, 2698, 25), // "on_bt_scen_resume_clicked"
QT_MOC_LITERAL(137, 2724, 13), // "lb_keti_point"
QT_MOC_LITERAL(138, 2738, 41), // "on_BTN_MOVE_JOINT_BOX_CENTER_..."
QT_MOC_LITERAL(139, 2780, 40), // "on_bt_cobot_move2object_appro..."
QT_MOC_LITERAL(140, 2821, 24), // "on_BTN_MOVEL_rel_clicked"
QT_MOC_LITERAL(141, 2846, 27), // "on_BTN_quick_return_clicked"
QT_MOC_LITERAL(142, 2874, 30), // "on_BTN_GRIPPER_SUCTION_clicked"
QT_MOC_LITERAL(143, 2905, 27), // "on_BTN_GRIPPER_OPEN_clicked"
QT_MOC_LITERAL(144, 2933, 34), // "on_BTN_MOVE_JOINT_LOW_LEFT_cl..."
QT_MOC_LITERAL(145, 2968, 43) // "on_BTN_RETURN_MOVE_JOINT_BOX_..."

    },
    "MainWindow\0onSystemCheck\0\0lift_ui\0"
    "status_loop\0print\0UI_Connection_Update\0"
    "msg\0UI_Connection_Update_Lift\0onUpdate\0"
    "keti_showUI_msg\0connect_flag\0"
    "kitech_showUI_msg\0barcode1_showUI_msg\0"
    "barcode2_showUI_msg\0barcode_ON_showUI\0"
    "BTN_GRIPPER_CMD_WRITE\0BTN_GRIPPER_ALLFOLD\0"
    "BTN_GRIPPER_GRASP\0BTN_GRIPPER_VISION\0"
    "CB_GRIPPER_GE_CMD_WRITE\0Pinch12_FOLD\0"
    "bt_usb1_con\0bt_usb2_con\0bt_usb1_dis\0"
    "bt_usb2_dis\0UI_Connection_Update_mobile\0"
    "rb_pose\0bt_cobot_move2object\0"
    "set_ui_item_from_unimap\0bt_save_annot\0"
    "bt_save_all_annot\0bt_delete_annot\0"
    "bt_save_annot_2\0bt_save_all_annot_2\0"
    "bt_delete_annot_2\0bt_order\0kitech_msg\0"
    "LE_KETI_IMG\0cv::Mat\0map_img\0"
    "auto_homming_seq\0yujin_order\0json\0"
    "yujin_order_check\0tf_any_change\0"
    "bt_tcp_on\0bt_connect\0bt_lift_status\0"
    "bt_rpmZero\0bt_homing\0bt_auto_homing\0"
    "bt_move_pos\0bt_lift_pos_move\0sb_lift_pos\0"
    "bt_set_maxVel_pos\0bt_lift_maxVel_pos\0"
    "bt_move_rpm\0write_log\0str\0readyRead_udp\0"
    "timer_shared_memory_loop\0newConnection_tcp\0"
    "BTN_CONNECT_COM\0BTN_CONNECT_DATA\0"
    "homeEnd\0on_BTN_COBOT_INIT_clicked\0"
    "on_BTN_MODE_REAL_clicked\0"
    "on_BTN_MODE_SIMULATION_clicked\0"
    "on_BTN_CLEAR_clicked\0on_BTN_MOTION_PAUSE_clicked\0"
    "on_BTN_MOTION_RESUME_clicked\0"
    "on_BTN_MOTION_HALT_clicked\0"
    "on_BTN_COLLISION_RESUME_clicked\0"
    "on_BTN_MOVE_JOINT_HIGH_clicked\0"
    "on_BTN_MOVE_JOINT_READY_GRIPPER_clicked\0"
    "on_BTN_MOVE_JOINT_GRAPS_GRIPPER_clicked\0"
    "on_HS_BASE_SPEED_valueChanged\0value\0"
    "BTN_CONNECT_GRIPPER\0"
    "on_BTN_MOVE_JOINT_HIGH_LEFT_clicked\0"
    "on_BTN_MOVE_JOINT_INIT_3_clicked\0"
    "on_BTN_MOVE_JOINT_INIT_4_clicked\0"
    "on_BTN_MOVE_JOINT_INIT_5_clicked\0"
    "bt_png_change\0bt_zip\0showUI_msg\0"
    "showUI_recive_msg\0message\0showUI_send_msg\0"
    "on_bt_rb5_mode_clicked\0"
    "on_sld_rb5_speed_valueChanged\0btn_pump\0"
    "on_sb_rb5_speed_valueChanged\0arg1\0"
    "bt_get_map_from_mobile\0lb_sn_map\0"
    "on_BTN_MOVE_JOINT_Rotation_clicked\0"
    "on_bt_cobot_push_clicked\0on_btn_pump_2_clicked\0"
    "on_bt_TCP_Blend_clicked\0"
    "on_BTN_MOVE_JOINT_LOW_clicked\0"
    "on_BTN_MOVE_JOINT_INIT_7_clicked\0"
    "on_bt_lift_top_clicked\0on_bt_lift_MID_clicked\0"
    "on_bt_lift_Low_clicked\0on_bt_low_get_out_clicked\0"
    "on_bt_vision_water_clicked\0"
    "on_bt_vision_high_get_out_clicked\0"
    "on_BTN_MOVE_JOINT_MID_clicked\0"
    "on_bt_vision_rael_more_move_clicked\0"
    "on_BTN_MOVE_TOTAL_clicked\0"
    "on_pb_shutter_clicked\0"
    "on_bt_vision_cmd_capture_clicked\0"
    "on_BTN_MOVE_JOINT_MID_LEFT_clicked\0"
    "on_BTN_MOVE_JOINT_MID_RIGHT_clicked\0"
    "seqLoop\0on_ALL_STOP_clicked\0"
    "on_BTN_MOVE_TOTAL_2_clicked\0"
    "on_BTN_MOVE_TOTAL_3_clicked\0"
    "on_BTN_MOVE_TOTAL_4_clicked\0"
    "on_pb_file_choose_clicked\0"
    "on_bt_rb5_pause_clicked\0"
    "on_bt_rb5_resume_clicked\0"
    "on_bt_rb5_halt_clicked\0yujin_loop\0"
    "on_bt_sn_cmd_set_clicked\0bt_amr_motor_init\0"
    "on_BTN_show_clicked\0vision_img_capture\0"
    "BTN_GRIPPER_recog_WRITE\0"
    "on_BTN_MOVE_JOINT_POP_clicked\0"
    "on_BTN_MOVE_JOINT_BOX_CENTER_clicked\0"
    "on_BTN_TCP_MOTION_TEST_clicked\0"
    "on_BTN_JOINT_MOTION_TEST_clicked\0"
    "on_pb_reload_clicked\0on_bt_scen_resume_clicked\0"
    "lb_keti_point\0on_BTN_MOVE_JOINT_BOX_CENTER_KETI_clicked\0"
    "on_bt_cobot_move2object_approach_clicked\0"
    "on_BTN_MOVEL_rel_clicked\0"
    "on_BTN_quick_return_clicked\0"
    "on_BTN_GRIPPER_SUCTION_clicked\0"
    "on_BTN_GRIPPER_OPEN_clicked\0"
    "on_BTN_MOVE_JOINT_LOW_LEFT_clicked\0"
    "on_BTN_RETURN_MOVE_JOINT_BOX_CENTER_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     135,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  689,    2, 0x0a /* Public */,
       3,    0,  690,    2, 0x0a /* Public */,
       4,    0,  691,    2, 0x0a /* Public */,
       5,    0,  692,    2, 0x0a /* Public */,
       6,    1,  693,    2, 0x0a /* Public */,
       8,    1,  696,    2, 0x0a /* Public */,
       9,    0,  699,    2, 0x0a /* Public */,
      10,    1,  700,    2, 0x0a /* Public */,
      12,    1,  703,    2, 0x0a /* Public */,
      13,    1,  706,    2, 0x0a /* Public */,
      14,    1,  709,    2, 0x0a /* Public */,
      15,    1,  712,    2, 0x0a /* Public */,
      16,    0,  715,    2, 0x0a /* Public */,
      17,    0,  716,    2, 0x0a /* Public */,
      18,    0,  717,    2, 0x0a /* Public */,
      19,    0,  718,    2, 0x0a /* Public */,
      20,    0,  719,    2, 0x0a /* Public */,
      21,    0,  720,    2, 0x0a /* Public */,
      22,    0,  721,    2, 0x0a /* Public */,
      23,    0,  722,    2, 0x0a /* Public */,
      24,    0,  723,    2, 0x0a /* Public */,
      25,    0,  724,    2, 0x0a /* Public */,
      26,    1,  725,    2, 0x0a /* Public */,
      27,    1,  728,    2, 0x0a /* Public */,
      28,    0,  731,    2, 0x0a /* Public */,
      29,    0,  732,    2, 0x0a /* Public */,
      30,    0,  733,    2, 0x0a /* Public */,
      31,    0,  734,    2, 0x0a /* Public */,
      32,    0,  735,    2, 0x0a /* Public */,
      33,    0,  736,    2, 0x0a /* Public */,
      34,    0,  737,    2, 0x0a /* Public */,
      35,    0,  738,    2, 0x0a /* Public */,
      36,    0,  739,    2, 0x0a /* Public */,
      37,    1,  740,    2, 0x0a /* Public */,
      38,    1,  743,    2, 0x0a /* Public */,
      41,    0,  746,    2, 0x0a /* Public */,
      42,    1,  747,    2, 0x0a /* Public */,
      44,    0,  750,    2, 0x0a /* Public */,
      45,    0,  751,    2, 0x08 /* Private */,
      46,    0,  752,    2, 0x08 /* Private */,
      47,    0,  753,    2, 0x08 /* Private */,
      48,    0,  754,    2, 0x08 /* Private */,
      49,    0,  755,    2, 0x08 /* Private */,
      50,    0,  756,    2, 0x08 /* Private */,
      51,    0,  757,    2, 0x08 /* Private */,
      52,    0,  758,    2, 0x08 /* Private */,
      53,    0,  759,    2, 0x08 /* Private */,
      54,    0,  760,    2, 0x08 /* Private */,
      55,    0,  761,    2, 0x08 /* Private */,
      56,    0,  762,    2, 0x08 /* Private */,
      57,    0,  763,    2, 0x08 /* Private */,
      58,    1,  764,    2, 0x08 /* Private */,
      60,    0,  767,    2, 0x08 /* Private */,
      61,    0,  768,    2, 0x08 /* Private */,
      62,    0,  769,    2, 0x08 /* Private */,
      63,    0,  770,    2, 0x08 /* Private */,
      64,    0,  771,    2, 0x08 /* Private */,
      65,    1,  772,    2, 0x08 /* Private */,
      66,    0,  775,    2, 0x08 /* Private */,
      67,    0,  776,    2, 0x08 /* Private */,
      68,    0,  777,    2, 0x08 /* Private */,
      69,    0,  778,    2, 0x08 /* Private */,
      70,    0,  779,    2, 0x08 /* Private */,
      71,    0,  780,    2, 0x08 /* Private */,
      72,    0,  781,    2, 0x08 /* Private */,
      73,    0,  782,    2, 0x08 /* Private */,
      74,    0,  783,    2, 0x08 /* Private */,
      75,    0,  784,    2, 0x08 /* Private */,
      76,    0,  785,    2, 0x08 /* Private */,
      77,    1,  786,    2, 0x08 /* Private */,
      79,    0,  789,    2, 0x08 /* Private */,
      80,    0,  790,    2, 0x08 /* Private */,
      81,    0,  791,    2, 0x08 /* Private */,
      82,    0,  792,    2, 0x08 /* Private */,
      83,    0,  793,    2, 0x08 /* Private */,
      84,    0,  794,    2, 0x08 /* Private */,
      85,    0,  795,    2, 0x08 /* Private */,
      86,    1,  796,    2, 0x08 /* Private */,
      87,    1,  799,    2, 0x08 /* Private */,
      89,    1,  802,    2, 0x08 /* Private */,
      90,    0,  805,    2, 0x08 /* Private */,
      91,    1,  806,    2, 0x08 /* Private */,
      92,    0,  809,    2, 0x08 /* Private */,
      93,    1,  810,    2, 0x08 /* Private */,
      95,    0,  813,    2, 0x08 /* Private */,
      96,    1,  814,    2, 0x08 /* Private */,
      97,    0,  817,    2, 0x08 /* Private */,
      98,    0,  818,    2, 0x08 /* Private */,
      99,    0,  819,    2, 0x08 /* Private */,
     100,    0,  820,    2, 0x08 /* Private */,
     101,    0,  821,    2, 0x08 /* Private */,
     102,    0,  822,    2, 0x08 /* Private */,
     103,    0,  823,    2, 0x08 /* Private */,
     104,    0,  824,    2, 0x08 /* Private */,
     105,    0,  825,    2, 0x08 /* Private */,
     106,    0,  826,    2, 0x08 /* Private */,
     107,    0,  827,    2, 0x08 /* Private */,
     108,    0,  828,    2, 0x08 /* Private */,
     109,    0,  829,    2, 0x08 /* Private */,
     110,    0,  830,    2, 0x08 /* Private */,
     111,    0,  831,    2, 0x08 /* Private */,
     112,    0,  832,    2, 0x08 /* Private */,
     113,    0,  833,    2, 0x08 /* Private */,
     114,    0,  834,    2, 0x08 /* Private */,
     115,    0,  835,    2, 0x08 /* Private */,
     116,    0,  836,    2, 0x08 /* Private */,
     117,    0,  837,    2, 0x08 /* Private */,
     118,    0,  838,    2, 0x08 /* Private */,
     119,    0,  839,    2, 0x08 /* Private */,
     120,    0,  840,    2, 0x08 /* Private */,
     121,    0,  841,    2, 0x08 /* Private */,
     122,    0,  842,    2, 0x08 /* Private */,
     123,    0,  843,    2, 0x08 /* Private */,
     124,    0,  844,    2, 0x08 /* Private */,
     125,    0,  845,    2, 0x08 /* Private */,
     126,    0,  846,    2, 0x08 /* Private */,
     127,    0,  847,    2, 0x08 /* Private */,
     128,    0,  848,    2, 0x08 /* Private */,
     129,    0,  849,    2, 0x08 /* Private */,
     130,    0,  850,    2, 0x08 /* Private */,
     131,    0,  851,    2, 0x08 /* Private */,
     132,    0,  852,    2, 0x08 /* Private */,
     133,    0,  853,    2, 0x08 /* Private */,
     134,    0,  854,    2, 0x08 /* Private */,
     135,    0,  855,    2, 0x08 /* Private */,
     136,    0,  856,    2, 0x08 /* Private */,
     137,    1,  857,    2, 0x08 /* Private */,
     138,    0,  860,    2, 0x08 /* Private */,
     139,    0,  861,    2, 0x08 /* Private */,
     140,    0,  862,    2, 0x08 /* Private */,
     141,    0,  863,    2, 0x08 /* Private */,
     142,    0,  864,    2, 0x08 /* Private */,
     143,    0,  865,    2, 0x08 /* Private */,
     144,    0,  866,    2, 0x08 /* Private */,
     145,    0,  867,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString,   88,
    QMetaType::Void, QMetaType::QString,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   94,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSystemCheck(); break;
        case 1: _t->lift_ui(); break;
        case 2: _t->status_loop(); break;
        case 3: _t->print(); break;
        case 4: _t->UI_Connection_Update((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->UI_Connection_Update_Lift((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onUpdate(); break;
        case 7: _t->keti_showUI_msg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->kitech_showUI_msg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->barcode1_showUI_msg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->barcode2_showUI_msg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->barcode_ON_showUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->BTN_GRIPPER_CMD_WRITE(); break;
        case 13: _t->BTN_GRIPPER_ALLFOLD(); break;
        case 14: _t->BTN_GRIPPER_GRASP(); break;
        case 15: _t->BTN_GRIPPER_VISION(); break;
        case 16: _t->CB_GRIPPER_GE_CMD_WRITE(); break;
        case 17: _t->Pinch12_FOLD(); break;
        case 18: _t->bt_usb1_con(); break;
        case 19: _t->bt_usb2_con(); break;
        case 20: _t->bt_usb1_dis(); break;
        case 21: _t->bt_usb2_dis(); break;
        case 22: _t->UI_Connection_Update_mobile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->rb_pose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->bt_cobot_move2object(); break;
        case 25: _t->set_ui_item_from_unimap(); break;
        case 26: _t->bt_save_annot(); break;
        case 27: _t->bt_save_all_annot(); break;
        case 28: _t->bt_delete_annot(); break;
        case 29: _t->bt_save_annot_2(); break;
        case 30: _t->bt_save_all_annot_2(); break;
        case 31: _t->bt_delete_annot_2(); break;
        case 32: _t->bt_order(); break;
        case 33: _t->kitech_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->LE_KETI_IMG((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 35: _t->auto_homming_seq(); break;
        case 36: _t->yujin_order((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 37: _t->yujin_order_check(); break;
        case 38: _t->tf_any_change(); break;
        case 39: _t->bt_tcp_on(); break;
        case 40: _t->bt_connect(); break;
        case 41: _t->bt_lift_status(); break;
        case 42: _t->bt_rpmZero(); break;
        case 43: _t->bt_homing(); break;
        case 44: _t->bt_auto_homing(); break;
        case 45: _t->bt_move_pos(); break;
        case 46: _t->bt_lift_pos_move(); break;
        case 47: _t->sb_lift_pos(); break;
        case 48: _t->bt_set_maxVel_pos(); break;
        case 49: _t->bt_lift_maxVel_pos(); break;
        case 50: _t->bt_move_rpm(); break;
        case 51: _t->write_log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 52: _t->readyRead_udp(); break;
        case 53: _t->timer_shared_memory_loop(); break;
        case 54: _t->newConnection_tcp(); break;
        case 55: _t->BTN_CONNECT_COM(); break;
        case 56: _t->BTN_CONNECT_DATA(); break;
        case 57: _t->homeEnd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 58: _t->on_BTN_COBOT_INIT_clicked(); break;
        case 59: _t->on_BTN_MODE_REAL_clicked(); break;
        case 60: _t->on_BTN_MODE_SIMULATION_clicked(); break;
        case 61: _t->on_BTN_CLEAR_clicked(); break;
        case 62: _t->on_BTN_MOTION_PAUSE_clicked(); break;
        case 63: _t->on_BTN_MOTION_RESUME_clicked(); break;
        case 64: _t->on_BTN_MOTION_HALT_clicked(); break;
        case 65: _t->on_BTN_COLLISION_RESUME_clicked(); break;
        case 66: _t->on_BTN_MOVE_JOINT_HIGH_clicked(); break;
        case 67: _t->on_BTN_MOVE_JOINT_READY_GRIPPER_clicked(); break;
        case 68: _t->on_BTN_MOVE_JOINT_GRAPS_GRIPPER_clicked(); break;
        case 69: _t->on_HS_BASE_SPEED_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->BTN_CONNECT_GRIPPER(); break;
        case 71: _t->on_BTN_MOVE_JOINT_HIGH_LEFT_clicked(); break;
        case 72: _t->on_BTN_MOVE_JOINT_INIT_3_clicked(); break;
        case 73: _t->on_BTN_MOVE_JOINT_INIT_4_clicked(); break;
        case 74: _t->on_BTN_MOVE_JOINT_INIT_5_clicked(); break;
        case 75: _t->bt_png_change(); break;
        case 76: _t->bt_zip(); break;
        case 77: _t->showUI_msg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 78: _t->showUI_recive_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 79: _t->showUI_send_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 80: _t->on_bt_rb5_mode_clicked(); break;
        case 81: _t->on_sld_rb5_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->btn_pump(); break;
        case 83: _t->on_sb_rb5_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: _t->bt_get_map_from_mobile(); break;
        case 85: _t->lb_sn_map((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 86: _t->on_BTN_MOVE_JOINT_Rotation_clicked(); break;
        case 87: _t->on_bt_cobot_push_clicked(); break;
        case 88: _t->on_btn_pump_2_clicked(); break;
        case 89: _t->on_bt_TCP_Blend_clicked(); break;
        case 90: _t->on_BTN_MOVE_JOINT_LOW_clicked(); break;
        case 91: _t->on_BTN_MOVE_JOINT_INIT_7_clicked(); break;
        case 92: _t->on_bt_lift_top_clicked(); break;
        case 93: _t->on_bt_lift_MID_clicked(); break;
        case 94: _t->on_bt_lift_Low_clicked(); break;
        case 95: _t->on_bt_low_get_out_clicked(); break;
        case 96: _t->on_bt_vision_water_clicked(); break;
        case 97: _t->on_bt_vision_high_get_out_clicked(); break;
        case 98: _t->on_BTN_MOVE_JOINT_MID_clicked(); break;
        case 99: _t->on_bt_vision_rael_more_move_clicked(); break;
        case 100: _t->on_BTN_MOVE_TOTAL_clicked(); break;
        case 101: _t->on_pb_shutter_clicked(); break;
        case 102: _t->on_bt_vision_cmd_capture_clicked(); break;
        case 103: _t->on_BTN_MOVE_JOINT_MID_LEFT_clicked(); break;
        case 104: _t->on_BTN_MOVE_JOINT_MID_RIGHT_clicked(); break;
        case 105: _t->seqLoop(); break;
        case 106: _t->on_ALL_STOP_clicked(); break;
        case 107: _t->on_BTN_MOVE_TOTAL_2_clicked(); break;
        case 108: _t->on_BTN_MOVE_TOTAL_3_clicked(); break;
        case 109: _t->on_BTN_MOVE_TOTAL_4_clicked(); break;
        case 110: _t->on_pb_file_choose_clicked(); break;
        case 111: _t->on_bt_rb5_pause_clicked(); break;
        case 112: _t->on_bt_rb5_resume_clicked(); break;
        case 113: _t->on_bt_rb5_halt_clicked(); break;
        case 114: _t->yujin_loop(); break;
        case 115: _t->on_bt_sn_cmd_set_clicked(); break;
        case 116: _t->bt_amr_motor_init(); break;
        case 117: _t->on_BTN_show_clicked(); break;
        case 118: _t->vision_img_capture(); break;
        case 119: _t->BTN_GRIPPER_recog_WRITE(); break;
        case 120: _t->on_BTN_MOVE_JOINT_POP_clicked(); break;
        case 121: _t->on_BTN_MOVE_JOINT_BOX_CENTER_clicked(); break;
        case 122: _t->on_BTN_TCP_MOTION_TEST_clicked(); break;
        case 123: _t->on_BTN_JOINT_MOTION_TEST_clicked(); break;
        case 124: _t->on_pb_reload_clicked(); break;
        case 125: _t->on_bt_scen_resume_clicked(); break;
        case 126: _t->lb_keti_point((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 127: _t->on_BTN_MOVE_JOINT_BOX_CENTER_KETI_clicked(); break;
        case 128: _t->on_bt_cobot_move2object_approach_clicked(); break;
        case 129: _t->on_BTN_MOVEL_rel_clicked(); break;
        case 130: _t->on_BTN_quick_return_clicked(); break;
        case 131: _t->on_BTN_GRIPPER_SUCTION_clicked(); break;
        case 132: _t->on_BTN_GRIPPER_OPEN_clicked(); break;
        case 133: _t->on_BTN_MOVE_JOINT_LOW_LEFT_clicked(); break;
        case 134: _t->on_BTN_RETURN_MOVE_JOINT_BOX_CENTER_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 135)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 135;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 135)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 135;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
