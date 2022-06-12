#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    flag_playing.resize(10);
    QSound::play("/home/pi/qtcode/14sound/1C3Amara/1/5duSound/5.wav");
    sourceNmae ={"C3Amara","C3Annaziska","C3Integral","C3Pygmy","B2Hijaz","B2Mystic","C3Celtic","D3Kurd","DChinaShang","E3Akebono","E3Equinox","E3LaSirena","E3Sabye","F2Pygmy"};
    sourceType = {"5duSound","8duSound","baseSound"};
    ///////////////////////////////////////////////////find available uart list -> ////////////////////////
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            QSerialPort serial;
            serial.setPort(info);
            if(serial.open(QIODevice::ReadWrite))
            {
                qDebug()<<serial.portName();
                serial.close();
            }
        }
    //////////////////////////////////uart init->///////////////////////////////////////<-/////////////////////////
    serial.setPortName("ttyAMA0");//设置串口名
    serial.open(QIODevice::ReadWrite);//打开串口
    serial.setBaudRate(115200);//设置波特率
    serial.setDataBits(QSerialPort::Data8);//设置数据位数
    serial.setParity(QSerialPort::NoParity);//设置奇偶校验
    serial.setStopBits(QSerialPort::OneStop);//设置停止位
    serial.setFlowControl(QSerialPort::NoFlowControl);//设置流控制

    //serial.clearError();
    //serial.clear();
    connect(&serial, &QSerialPort::readyRead, this,&Widget::serialReadreadSlots);
    ////////////////////////////////////////////////////////////////////////

}

Widget::~Widget()
{
    delete ui;
}
void Widget::serialReadreadSlots(){
    QByteArray arr = serial.readAll();
    QString str = QString(arr);
    QStringList list = str.split(",");
    QString a = list[0];
    QString b = list[1];
    QString c = list[2];
    qDebug()<<a<<b<<c;
    strPlay = "/home/pi/qtcode/14sound/";//"/1/5duSound/5.wav"
    strPlay = strPlay + QString::number(i+1) + sourceNmae[i] + "/"+a+"/"+sourceType[b.toInt() - 1]+"/"+c+".wav";
    switch (a.toInt()) {
    case 1:
        QSound::play(strPlay);
        break;
    case 2:
        QSound::play(strPlay);
        break;
    case 3:
        QSound::play(strPlay);
        break;
    case 4:
        QSound::play(strPlay);
        break;
    case 5:
        QSound::play(strPlay);
        break;
    case 6:
        QSound::play(strPlay);
        break;
    case 7:
        QSound::play(strPlay);
        break;
    case 8:
        QSound::play(strPlay);
        break;
    case 9:
        QSound::play(strPlay);
        break;
    }
}
void Widget::on_pushButton_change_clicked()
{
    i++;
    i = i%14;
    QString str = "/home/pi/qtcode/14sound/";
    str = str + QString::number(i+1) + sourceNmae[i] + "/1/5duSound/5.wav";//
    qDebug()<<str;
    QSound::play(str);
    ui->pushButton_change->setText(sourceNmae[i]);
}
