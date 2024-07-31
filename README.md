# orderpicking_2024

## usb 포트 고정하기
```
[ 3 ] udevadm 규칙을 reload/restart한다. 아래 명령어로 규칙을 재로딩했다가, 장치를 제거하고 다시 연결한다.

$ sudo service udev reload
$ sudo service udev restart
```

```
[ 4 ] 장치명이 어떻게 바뀌어 있는지 다시 확인한다.

(1) 개별로 확인하고 싶을 때 예
$ sudo ls -l /dev/ttyLiDAR

(2) tty만 확인하고 싶을 때 예
또는 ls -al /dev/tty*
```
![image](https://github.com/user-attachments/assets/485302f4-6901-40e3-bf26-2e83825dabed)

## rb5 업데이트 후 아래대로 스트럭쳐 바꾸어야함
```
typedef union{
    struct{
        char    header[4];
        // 0
        float   time;                   // time [sec]
        float   jnt_ref[6];             // joint reference [deg]
        float   jnt_ang[6];             // joint encoder value [deg]
        float   cur[6];                 // joint current value [mA]
        // 19
        float   tcp_ref[6];             // calculated tool center point from reference [mm, deg]
        float   tcp_pos[6];             // calculated tool center point from encoder [mm, deg]
        // 31
        float   analog_in[4];           // analog input value of control box [V]
        float   analog_out[4];          // analog output value of control box [V]
        int     digital_in[16];         // digital input value of control box [0 or 1]
        int     digital_out[16];        // digital input value of control box [0 or 1]
        // 71
        float   temperature_mc[6];      // board temperature of each joint [celcius]
        // 77
        int     task_pc;                // (ignore)
        int     task_repeat;            // (ignore)
        int     task_run_id;            // (ignore)
        int     task_run_num;           // (ignore)
        float   task_run_time;          // (ignore)
        int     task_state;             // (ignore)
        // 83
        float   default_speed;          // overriding speed [0~1]
        int     robot_state;            // state of robot motion [1:idle  2:paused or stopped by accident  3: moving]
        int     power_state;            // power state
        //        int information_chunk_1;//information bit combination

        // 86
        float   tcp_target[6];          // (ignore)
        int     jnt_info[6];            // joint information (look mSTAT)
        // 98
        int     collision_detect_onoff; // collision detect onoff [0:off  1:on]
        int     is_freedrive_mode;      // current freedrive status [0:off  1:on]
        int     program_mode;           // current program mode [0:real mode  1:simulation mode]
        // 101
        int     init_state_info;        // status information of robot initialization process
        int     init_error;             // error code of robot initialization process
        // 103
        float   tfb_analog_in[2];       // analog input value of tool flange board [V]
        int     tfb_digital_in[2];      // digital input value of tool flange board [0 or 1]
        int     tfb_digital_out[2];     // digital output value of tool flange board [0 or 1]
        float   tfb_voltage_out;        // reference voltage of tool flange board [0, 12, 24]
        // 110
        int     op_stat_collision_occur;
        int     op_stat_sos_flag;
        int     op_stat_self_collision;
        int     op_stat_soft_estop_occur;
        int     op_stat_ems_flag;
        ///////////////////////////////////////////////////////////
        // 115
        // Byte count ~: 464
        int information_chunk_2;
        int information_chunk_3;

        // Byte count ~: 472
        int inbox_trap_flag[2];
        int inbox_check_mode[2];

        // Byte count ~: 488
        float eft_fx;
        float eft_fy;
        float eft_fz;
        float eft_mx;
        float eft_my;
        float eft_mz;

        // Byte count ~: 512
        int information_chunk_4;

        // Byte count ~: 516
        float extend_io1_analog_in[4];
        float extend_io1_analog_out[4];
        unsigned int extend_io1_digital_info;

        // Byte count ~: 552
        float aa_joint_ref[6];

        // Byte count ~: 576
        unsigned int safety_board_stat_info;

        // Byte count ~: 580
    }sdata;
    float fdata[MAX_SHARED_DATA];
    int idata[MAX_SHARED_DATA];
}systemSTAT;
```
