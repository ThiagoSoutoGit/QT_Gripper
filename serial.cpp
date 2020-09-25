#include "serial.h"



Serial::Serial(QWidget *parent) : QWidget(parent)
{

    serialPort = new QSerialPort();

    QObject::connect(serialPort, SIGNAL(bytesWritten(qint64)), this, SLOT(slot_messageWritten()));

}



void Serial::open(const QString &name)
{
    serialPort->setPortName(name);
    serialPort->setBaudRate(115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if(!serialPort->isOpen())
    {
        serialPort->close();
    }
    std::cout << "Serial Port " << name.toStdString() << " opened!" << std::endl;


    ui->communication_textEdit->append("Hello World");
    ui->data_to_be_sent_textEdit->append("Hello World");

//    QWidget *obj = new Widget();

//    obj->ui->data_to_be_sent_textEdit->append("hello");
//    obj->ui->communication_textEdit->setText("Hello");

//    QByteArray buffer;
//    buffer = "Hello World";
//    ui->data_to_be_sent_textEdit->append("buffer");
//    ui->communication_textEdit->append("buffer");
//    QTextEdit *text_Edit_data1 = new QTextEdit();
//    text_Edit_data1->append("Success");






    serialPort->open(QIODevice::ReadWrite);
}

void Serial::write(const QString &message)
{
    QString Theta1_sent;

    int bytesWritten = serialPort->write(message.toUtf8());

    std::cout << "Bytes written: " << bytesWritten << std::endl;

}

void Serial::slot_messageWritten()
{
    std::cout << "Serial Port closed!" << std::endl;

    serialPort->close();

    emit sig_quit();
}
