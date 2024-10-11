# orderpicking_2024

```
; it is just about AMR 8 setting
[CALIB]
EXP=38961
HEIGHT=720
KITECH_TF_SENSOR="0.10000,0.16000,-0.030000,21.000000,-90.000000,90.000000"
RB_TF_SENSOR="0.080000,0.10000,-0.030000,21.000000,-90.000000,90.000000"
WIDTH=1280
```

```
; it is just about AMR 7 setting
[CALIB]
EXP=38961
HEIGHT=720
KITECH_TF_SENSOR="0.08000,0.16000,-0.030000,21.000000,-90.000000,90.000000"
RB_TF_SENSOR="0.080000,0.10000,-0.030000,21.000000,-90.000000,90.000000"
WIDTH=1280
```
```
void Cobot::MoveL_rel(float x, float y, float z, float rx, float ry, float rz, float spd, float acc, int user_coordinate)
{
    QString text;
    text.sprintf("move_l_rel(pnt[%.3f, %.3f, %.3f, %.3f, %.3f], %.3f, %.3f, %.3f)", spd, acc, x, y, z, rx, ry, rz,user_coordinate);
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3; //run
}
```
