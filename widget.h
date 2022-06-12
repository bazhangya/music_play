#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDebug>
#include <QSound>
#include<QMediaPlayer>
#include<QSoundEffect>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;

public:
    QVector<int> flag_playing;
    QSerialPort serial;
    QSerialPort serial1;
    QSerialPort serial2;
    QSerialPort serial3;
    QVector<QString> sourceNmae;
    QVector<QString> sourceType;
    int i = 0;//source type
    int j = 0;//sound type
    QString strPlay ;
public slots:
    void serialReadreadSlots();
    void serial1ReadreadSlots();
    void serial2ReadreadSlots();
    void serial3ReadreadSlots();
private slots:
    void on_pushButton_change_clicked();
};
#endif // WIDGET_H
