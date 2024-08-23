# orderpicking_2024

## 10진수 -> 16진수 표기법
```
QString str = QString::number(172, 16);
const char* p = str.toStdString().c_str();
qDebug()<<"b_FILE_DATA : "<<p;
```
