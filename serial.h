#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort>
#include <iostream>

#include "widget.h"
#include "ui_widget.h"

#include <QWidget>

class Serial : public QWidget
{
    Q_OBJECT
public:
    explicit Serial(QWidget *parent = nullptr);

    void open(const QString &name);
    void write(const QString &message);

    QSerialPort *serialPort;



//    QWidget *obj = new Widget();
    Ui::Widget *ui;



signals:

    void sig_quit();

public slots:

    void slot_messageWritten();

};



#endif // SERIAL_H








