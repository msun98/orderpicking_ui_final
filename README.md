# orderpicking_2024

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
