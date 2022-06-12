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
    serial.setPortName("ttyUSB0");//设置串口名
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

    //////////////////////////////////uart1 init->///////////////////////////////////////<-/////////////////////////
    serial1.setPortName("ttyUSB1");//设置串口名
    serial1.open(QIODevice::ReadWrite);//打开串口
    serial1.setBaudRate(115200);//设置波特率
    serial1.setDataBits(QSerialPort::Data8);//设置数据位数
    serial1.setParity(QSerialPort::NoParity);//设置奇偶校验
    serial1.setStopBits(QSerialPort::OneStop);//设置停止位
    serial1.setFlowControl(QSerialPort::NoFlowControl);//设置流控制

    //serial.clearError();
    //serial.clear();
    connect(&serial1, &QSerialPort::readyRead, this,&Widget::serial1ReadreadSlots);
    ////////////////////////////////////////////////////////////////////////


    //////////////////////////////////uart2 init->///////////////////////////////////////<-/////////////////////////
    serial2.setPortName("ttyUSB2");//设置串口名
    serial2.open(QIODevice::ReadWrite);//打开串口
    serial2.setBaudRate(115200);//设置波特率
    serial2.setDataBits(QSerialPort::Data8);//设置数据位数
    serial2.setParity(QSerialPort::NoParity);//设置奇偶校验
    serial2.setStopBits(QSerialPort::OneStop);//设置停止位
    serial2.setFlowControl(QSerialPort::NoFlowControl);//设置流控制

    //serial.clearError();
    //serial.clear();
    connect(&serial2, &QSerialPort::readyRead, this,&Widget::serial2ReadreadSlots);
    ////////////////////////////////////////////////////////////////////////


    //////////////////////////////////uart3 init->///////////////////////////////////////<-/////////////////////////
    serial3.setPortName("ttyUSB3");//设置串口名
    serial3.open(QIODevice::ReadWrite);//打开串口
    serial3.setBaudRate(115200);//设置波特率
    serial3.setDataBits(QSerialPort::Data8);//设置数据位数
    serial3.setParity(QSerialPort::NoParity);//设置奇偶校验
    serial3.setStopBits(QSerialPort::OneStop);//设置停止位
    serial3.setFlowControl(QSerialPort::NoFlowControl);//设置流控制

    //serial.clearError();
    //serial.clear();
    connect(&serial3, &QSerialPort::readyRead, this,&Widget::serial3ReadreadSlots);
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
void Widget::serial1ReadreadSlots(){
    QByteArray arr = serial1.readAll();
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

void Widget::serial2ReadreadSlots(){
    QByteArray arr = serial2.readAll();
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

void Widget::serial3ReadreadSlots(){
    QByteArray arr = serial3.readAll();
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
