#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QString>
#include <iostream>
#include <cmath>

#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

QT_CHARTS_USE_NAMESPACE

using namespace Eigen;

#include "C:/eigen/Eigen/Dense"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);





    // Defining intial values for the fields

//    ui->L_1->setText("230");
//    ui->L_2->setText("500");
//    ui->L_3->setText("500");
//    ui->L_4->setText("180");

    ui->L_1->setText("100");
    ui->L_2->setText("100");
    ui->L_3->setText("100");
    ui->L_4->setText("100");

    ui->Theta_1->setText("0");
    ui->Theta_2->setText("0");
    ui->Theta_3->setText("45");
    ui->Theta_4->setText("45");
    ui->Theta_5->setText("0");


//    theta_1_value = (ui->Theta_1->text()).toDouble()* M_PI/180;
//    theta_2_value = (ui->Theta_2->text()).toDouble()* M_PI/180;
//    theta_3_value = (ui->Theta_3->text()).toDouble()* M_PI/180;
//    theta_4_value = (ui->Theta_4->text()).toDouble()* M_PI/180;

//    l_1_value = ((ui->L_1->text()).toDouble());
//    l_2_value = ((ui->L_2->text()).toDouble());
//    l_3_value = ((ui->L_3->text()).toDouble());
//    l_4_value = ((ui->L_4->text()).toDouble());

//    IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
//    std::cout.precision(3);


//    std::cout << std::endl <<  "Transform Matrices:" << std::endl << std::endl;;

//    t_0_1_matrix << cos(theta_1_value), -sin(theta_1_value), 0, 0,
//                    sin(theta_1_value), cos(theta_1_value), 0, 0,
//                    0, 0, 1, l_1_value,
//                    0, 0, 0, 1;
//    std::cout <<  "T 0-1:" << std::endl << t_0_1_matrix.format(CleanFmt) << std::endl << std::endl;

//    t_1_2_matrix << cos(theta_2_value), -sin(theta_2_value), 0, 0,
//                    0, 0, -1, 0,
//                    sin(theta_2_value), cos(theta_2_value), 0, 0,
//                    0, 0, 0, 1;
//    std::cout <<  "T 1-2:" << std::endl << t_1_2_matrix.format(CleanFmt) << std::endl << std::endl;

//    t_2_3_matrix << cos(theta_3_value), -sin(theta_3_value), 0, l_2_value,
//                    sin(theta_3_value), cos(theta_3_value), 0, 0,
//                    0, 0, 1, 0,
//                    0, 0, 0, 1;
//    std::cout <<  "T 2-3:" << std::endl << t_2_3_matrix.format(CleanFmt) << std::endl << std::endl;

//    t_3_4_matrix << cos(theta_4_value), -sin(theta_4_value), 0, l_3_value,
//                    sin(theta_4_value), cos(theta_4_value), 0, 0,
//                    0, 0, 1, 0,
//                    0, 0, 0, 1;
//    std::cout <<  "T 3-4:" << std::endl << t_3_4_matrix.format(CleanFmt) << std::endl << std::endl;

//    t_4_5_matrix << 1, 0, 0, l_4_value,
//                    0, 1, 0, 0,
//                    0, 0, 1, 0,
//                    0, 0, 0, 1;
//    std::cout <<  "T 4-5:" << std::endl << t_4_5_matrix.format(CleanFmt) << std::endl << std::endl;



//    std::cout << std::endl <<  "T:" << std::endl << std::endl;;

//    T = t_0_1_matrix * t_1_2_matrix * t_2_3_matrix * t_3_4_matrix * t_4_5_matrix;

//    std::cout <<  "T:" << std::endl << T.format(CleanFmt) << std::endl << std::endl;

//    Pos_x = QString::number(T(0,3));
//    ui->X_Pos->setText(Pos_x);

//    Pos_y = QString::number(T(1,3));
//    ui->Y_Pos->setText(Pos_y);

//    Pos_z = QString::number(T(2,3));
//    ui->Z_Pos->setText(Pos_z);


//    // Verifying the size of the matrix
//    QString s;
//    s = QString::number(T.size());
//    qDebug() <<  s << Qt::endl;
//    ui->matrixSize_label->setText(s);
//    ui->matrixTextEdit->appendPlainText("T Matrix: \n");
//    for(int i = 0; i <= 3 ; ++i){
//        QString row_String;
//        for(int j = 0; j <= 3; ++j){
//            value = QString::number(T(i,j));
//            row_String.append(value);
//            if(j!=3){
//                row_String.append(",  ");
//            }
//        }
//        ui->matrixTextEdit->appendPlainText(row_String);
//    }

}

Widget::~Widget()
{
    delete ui;

}

Matrix4d rot_x(double alpha){
    Matrix4d T;
    T << 1, 0, 0, 0,
         0, cos(alpha), -sin(alpha), 0,
         0, sin(alpha), cos(alpha), 0,
         0, 0, 0, 1;
    return T;
}

Matrix4d trans_x(double a){
    Matrix4d T;
    T << 1, 0, 0, a,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1;
    return T;
}

//Matrix4d rot_y(double beta){
//    Matrix4d T;
//    T << cos(beta), 0, sin(beta), 0,
//         0, 1, 0, 0,
//         -sin(beta), 0, cos(beta), 0,
//         0, 0, 0, 1;
//    return T;
//}

Matrix4d rot_z(double theta){
    Matrix4d T;
    T << cos(theta), -sin(theta), 0, 0,
         sin(theta), cos(theta), 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1;
    return T;
}

Matrix4d trans_z(double d){
    Matrix4d T;
    T << 1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, d,
         0, 0, 0, 1;
    return T;
}

Matrix4d h_T(double alpha, double a, double theta, double d){
    Matrix4d T;
    T = rot_x(alpha) * trans_x(a) * rot_z(theta) * trans_z(d);
    return T;
}




void Widget::on_btn_Inverse_Kinematics_clicked()
{
    ui->matrixTextEdit->clear();

    theta_1_value = (ui->Theta_1->text()).toDouble()* M_PI/180;
    theta_2_value = (ui->Theta_2->text()).toDouble()* M_PI/180;
    theta_3_value = (ui->Theta_3->text()).toDouble()* M_PI/180;
    theta_4_value = (ui->Theta_4->text()).toDouble()* M_PI/180;
    theta_5_value = (ui->Theta_5->text()).toDouble()* M_PI/180;

    l_1_value = ((ui->L_1->text()).toDouble());
    l_2_value = ((ui->L_2->text()).toDouble());
    l_3_value = ((ui->L_3->text()).toDouble());
    l_4_value = ((ui->L_4->text()).toDouble());


    IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
    std::cout.precision(3);

    std::cout << std::endl <<  "Transform Matrices:" << std::endl << std::endl;;

    double x05test = 100 + 100 * cos(45 * M_PI/180);
    double y05test = 0;
    double z05test = 100 + 100 * sin(45 * M_PI/180);

    std::cout << x05test << std::endl <<  y05test << std::endl << z05test << std::endl << std::endl;;


    // Create hamogeneous transforms for the forward Kinematics

//    Matrix4d T00;
//    T00 = h_T(0, 0, 0, 0);
//    std::cout << "Matrix T01:" << std::endl << T00.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T01;
    double alpha_1 = (90 * M_PI/180);
    T01 = h_T(alpha_1, 0, 0, l_1_value);
    std::cout << "Matrix T01:" << std::endl << T01.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T12;
    T12 = h_T(0, 0, theta_2_value, 0);
    std::cout << "Matrix T12:" << std::endl << T12.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T23;
    T23 = h_T(0, l_2_value, theta_3_value, 0);
    std::cout << "Matrix T12:" << std::endl << T23.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T34;
    T34 = h_T(0, l_3_value, theta_4_value, 0);
    std::cout << "Matrix T12:" << std::endl << T34.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T45;
    T45 = h_T(0, l_4_value, theta_5_value, 0);
    std::cout << "Matrix T45:" << std::endl << T45.format(CleanFmt) << std::endl << std::endl;


//    T01 = T00 * T01;

    double x01 = T01(0,3);
    double y01 = T01(1,3);
    double z01 = T01(2,3);

    //Printing T01
    ui->matrixTextEdit->appendPlainText("\n T01 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T01(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    Matrix4d T02;
//    T02 = T00 * T01 * T12;
    T02 = T01 * T12;

    double x02 = T02(0,3);
    double y02 = T02(1,3);
    double z02 = T02(2,3);

    //Printing T02
    ui->matrixTextEdit->appendPlainText("\n T02 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T02(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    Matrix4d T03;
//    T03 = T00 * T01 * T12 * T23;
    T03 = T01 * T12 * T23;

    double x03 = T03(0,3);
    double y03 = T03(1,3);
    double z03 = T03(2,3);

    //Printing T03
    ui->matrixTextEdit->appendPlainText("\n T03 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T03(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    Matrix4d T04;
//    T04 = T00 * T01 * T12 * T23 * T34;
    T04 = T01 * T12 * T23 * T34;


    double x04 = T04(0,3);
    double y04 = T04(1,3);
    double z04 = T04(2,3);

    //Printing T04
    ui->matrixTextEdit->appendPlainText("\n T04 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T04(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    Matrix4d T05;
//    T05 = T00 * T01 * T12 * T23 * T34 * T45;
    T05 = T01 * T12 * T23 * T34 * T45;
    std::cout << "Matrix T05:" << std::endl << T05.format(CleanFmt) << std::endl << std::endl;


    //Printing T05
    ui->matrixTextEdit->appendPlainText("\n T05 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T05(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    double x05 = T05(0,3);
    double y05 = T05(1,3);
    double z05 = T05(2,3);



//    Matrix4d T05_no_base_rotation;
//    T05_no_base_rotation = T01 * T12 * T23 * T34 * T45;

    // Inverse Kinematics

    Matrix4d T15;
    T15 = T05 * T01.inverse();
    std::cout << "Matrix T15:" << std::endl << T15.format(CleanFmt) << std::endl << std::endl;

    //Printing T15
    ui->matrixTextEdit->appendPlainText("\n T15 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T15(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    double x15 = T15(0,3);
    double y15 = T15(1,3);
    double z15 = T15(2,3);


    Matrix4d T14;
    T14 = T15 * T45.inverse();
    std::cout << "Matrix T14:" << std::endl << T14.format(CleanFmt) << std::endl << std::endl;

    //Printing T14
    ui->matrixTextEdit->appendPlainText("\n T14 : \n");
    for(int i = 0; i <= 3 ; ++i){
        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T14(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }

    double x14 = T14(0,3);
    double y14 = T14(1,3);
    double z14 = T14(2,3);

    std::cout << x14 << std::endl <<  y14 << std::endl << z14 << std::endl << std::endl;

    double B;
    B = atan2(z14, x14);

    double c2;
    c2 = (pow(l_3_value, 2) - pow(l_2_value, 2) - pow(x14, 2) - pow(z14, 2) ) / (-2*l_2_value*sqrt(pow(x14, 2) + pow(z14, 2)));
    double s2;
    s2 = sqrt(1 - pow(c2, 2));
    double W;
    W = atan2(s2, c2);
    double theta_2_angle;
    theta_2_angle = (B - W) * 180/M_PI;
    ui->Theta_22->setText(QString::number(theta_2_angle));

    QString Theta2_data;
    Theta2_data.append("Theta 2 :");
    Theta2_data.append(QString::number(theta_2_angle));
    ui->data_to_be_sent_textEdit->append(Theta2_data);



    double c3;
    c3 = (pow(x14, 2) + pow(z14, 2) - pow(l_2_value, 2) - pow(l_3_value, 2))/(2*l_2_value*l_3_value);
    double s3;
    s3 = sqrt(1 - pow(c3, 2));
    double theta_3_angle;
    theta_3_angle = atan2(s3, c3) * 180/M_PI;
    ui->Theta_33->setText(QString::number(theta_3_angle));

    QString Theta3_data;
    Theta3_data.append("Theta 3 :");
    Theta3_data.append(QString::number(theta_3_angle));
    ui->data_to_be_sent_textEdit->append(Theta3_data);

    Matrix4d T35;

    T35 = T34 * T45;
    std::cout << "Matrix T35:" << std::endl << T35 << std::endl << std::endl;

    double x35 = T35(0,3);
    double y35 = T35(1,3);
    double z35 = T35(2,3);

    std::cout << x35 << std::endl <<  y35 << std::endl << z35 << std::endl << std::endl;

    double c4;
    c4 = (x35 - l_3_value) / l_4_value;
    double s4;
    s4 = sqrt(1 - pow(c4, 2));
    double theta_4_angle;
    theta_4_angle = atan2(s4, c4) * 180/M_PI;
    ui->Theta_44->setText(QString::number(theta_4_angle));

    QString Theta4_data;
    Theta4_data.append("Theta 4 :");
    Theta4_data.append(QString::number(theta_4_angle));
    ui->data_to_be_sent_textEdit->append(Theta4_data);

    // Aditional transform

    // Base transform

    //Theta 1

//    Matrix4d Trot;
//    Trot = T15 * h_T(-alpha_1, 0, 0, 0);

//    double xTrot = Trot(0,3);
//    double yTrot = Trot(1,3);
//    double zTrot = Trot(2,3);


//    double theta_1_angle;
//    theta_1_angle = atan2(zTrot, xTrot) * 180/M_PI;
//    ui->Theta_11->setText(QString::number(theta_1_angle));


//    Matrix4d T_Theta1;
//    alpha_1 = (90 * M_PI/180);
//    T_Theta1 = T05 * h_T(-alpha_1, 0, 0, 0);
    double theta_1_angle;

//    double t1x35 = T_Theta1(0,3);
//    double t1y35 = T_Theta1(1,3);
//    double t1z35 = T_Theta1(2,3);

    theta_1_angle = atan2(y15, z15) * 180/M_PI;
    ui->Theta_11->setText(QString::number(theta_1_angle));









    // Inverse Kinematics
//    t_1_5_matrix = T * (t_0_1_matrix.inverse());

//    std::cout << "T 1_5:" << std::endl;
//    std::cout << t_1_5_matrix.format(CleanFmt) << std::endl;
//    std::cout << "T 1_5:" << std::endl;

//    t_1_4_matrix = t_1_5_matrix * t_4_5_matrix.inverse();

//    std::cout << "T 1_4:" << std::endl;
//    std::cout << t_1_4_matrix.format(CleanFmt) << std::endl;
//    std::cout << "T 1_4:" << std::endl;

//    float x14 = t_1_4_matrix(0,3);
//    float y14 = t_1_4_matrix(1,3);
//    float z14 = t_1_4_matrix(2,3);






    //Graphic


//    series->append(0, 0);
//    series->append(T01(0, 3), T01(2, 3));
//    series->append(T12(0, 3), T12(2, 3));
//    series->append(T23(0, 3), T23(2, 3));
//    series->append(T34(0, 3), T34(2, 3));
//    series->append(T45(0, 3), T45(2, 3));

//    *series << QPointF(0, 0) << QPointF(T01(0, 3), T01(2, 3)) << QPointF(T12(0, 3), T12(2, 3)) << QPointF(T23(0, 3), T23(2, 3)) <<
//               QPointF(T34(0, 3), T34(2, 3)) << QPointF(T45(0, 3), T45(2, 3));




    QLineSeries *series = new QLineSeries();

//    series->append(0, 6);
//    series->append(2, 4);
//    series->append(3, 8);
//    series->append(7, 4);
//    series->append(10, 5);

//    series->append(0, 0);
    int tx01 = T01(0, 3);
    int tx12 = T12(0, 3);
    int tx23 = T23(0, 3);
    int tx34 = T34(0, 3);
    int tx45 = T45(0, 3);

    int ty01 = T01(2, 3);
    int ty12 = T12(2, 3);
    int ty23 = T23(2, 3);
    int ty34 = T34(2, 3);
    int ty45 = T45(2, 3);

    std::cout << tx01 << tx12 << tx23 << tx34 << tx45 << ty01 << ty12 << ty23 << ty34 << ty45 << std::endl;
    std::cout << std::endl;

    std::cout << T01(0, 3) << std::endl;
    std::cout << T12(0, 3) << std::endl;
    std::cout << T23(0, 3) << std::endl;
    std::cout << T34(0, 3) << std::endl;
    std::cout << T45(0, 3) << std::endl;

    std::cout << T01(2, 3) << std::endl;
    std::cout << T12(2, 3) << std::endl;
    std::cout << T23(2, 3) << std::endl;
    std::cout << T34(2, 3) << std::endl;
    std::cout << T45(2, 3) << std::endl;


    Matrix4d T13 = T14 * T34.inverse();

    double x13 = T13(0,3);
    double y13 = T13(2,3);


//    series->append((int)tx01, (int)ty01);
//    series->append((int)tx12, (int)ty12);
//    series->append((int)x13, (int)y13);
//    series->append((int)x14, (int)z14);
//    series->append((int)x05, (int)z05);

    *series << QPointF(0, -(int)l_1_value) <<
               QPointF(0, 0) <<
               QPointF((int)x02, (int)z02) <<
               QPointF((int)x03, (int)z03) <<
               QPointF((int)x04, (int)z04) <<
               QPointF((int)x05, (int)z05);
    series->setPointsVisible();

    std::cout << "01: x = " << (int)tx01 << std::endl;
    std::cout << "01: y = " << (int)ty01 << std::endl;

    std::cout << "12: x = " << (int)tx12 << std::endl;
    std::cout << "12: y = " << (int)ty12 << std::endl;

    std::cout << "13: x = " << (int)x13 << std::endl;
    std::cout << "13: y = " << (int)y13 << std::endl;

    std::cout << "14: x = " << (int)x14 << std::endl;
    std::cout << "14: y = " << (int)y14 << std::endl;

    std::cout << "05: x = " << (int)x05 << std::endl;
    std::cout << "05: y = " << (int)y05 << std::endl;



//    *series << QPointF(0, 0) << QPointF(T01(0, 3), T01(2, 3)) << QPointF(T12(0, 3), T12(2, 3)) << QPointF(T23(0, 3), T23(2, 3)) <<
//               QPointF(T34(0, 3), T34(2, 3)) << QPointF(T45(0, 3), T45(2, 3));


    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chartFrame);

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(-1200, 1200);
    axisX->setTickCount(10);
    axisX->setLabelFormat("%.2f");
    chartView->chart()->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1200, 1200);
    axisY->setTickCount(10);
    axisY->setLabelFormat("%.2f");
    chartView->chart()->setAxisY(axisY, series);
}

void Widget::on_btn_Forward_Kinematics_clicked()
{
    ui->matrixTextEdit->clear();
    theta_1_value = (ui->Theta_1->text()).toDouble()* M_PI/180;
    theta_2_value = (ui->Theta_2->text()).toDouble()* M_PI/180;
    theta_3_value = (ui->Theta_3->text()).toDouble()* M_PI/180;
    theta_4_value = (ui->Theta_4->text()).toDouble()* M_PI/180;

    l_1_value = ((ui->L_1->text()).toDouble());
    l_2_value = ((ui->L_2->text()).toDouble());
    l_3_value = ((ui->L_3->text()).toDouble());
    l_4_value = ((ui->L_4->text()).toDouble());

    IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
    std::cout.precision(3);


    std::cout << std::endl <<  "Transform Matrices:" << std::endl << std::endl;;

    t_0_1_matrix << cos(theta_1_value), -sin(theta_1_value), 0, 0,
                    sin(theta_1_value), cos(theta_1_value), 0, 0,
                    0, 0, 1, l_1_value,
                    0, 0, 0, 1;
    std::cout <<  "T 0-1:" << std::endl << t_0_1_matrix.format(CleanFmt) << std::endl << std::endl;

    t_1_2_matrix << cos(theta_2_value), -sin(theta_2_value), 0, 0,
                    0, 0, -1, 0,
                    sin(theta_2_value), cos(theta_2_value), 0, 0,
                    0, 0, 0, 1;
    std::cout <<  "T 1-2:" << std::endl << t_1_2_matrix.format(CleanFmt) << std::endl << std::endl;

    t_2_3_matrix << cos(theta_3_value), -sin(theta_3_value), 0, l_2_value,
                    sin(theta_3_value), cos(theta_3_value), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1;
    std::cout <<  "T 2-3:" << std::endl << t_2_3_matrix.format(CleanFmt) << std::endl << std::endl;

    t_3_4_matrix << cos(theta_4_value), -sin(theta_4_value), 0, l_3_value,
                    sin(theta_4_value), cos(theta_4_value), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1;
    std::cout <<  "T 3-4:" << std::endl << t_3_4_matrix.format(CleanFmt) << std::endl << std::endl;

    t_4_5_matrix << 1, 0, 0, l_4_value,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1;
    std::cout <<  "T 4-5:" << std::endl << t_4_5_matrix.format(CleanFmt) << std::endl << std::endl;



    std::cout << std::endl <<  "T:" << std::endl << std::endl;;

    T = t_0_1_matrix * t_1_2_matrix * t_2_3_matrix * t_3_4_matrix * t_4_5_matrix;

    std::cout <<  "T:" << std::endl << T.format(CleanFmt) << std::endl << std::endl;

    Pos_x = QString::number(T(0,3));
    ui->X_Pos->setText(Pos_x);


    Pos_y = QString::number(T(1,3));
    ui->Y_Pos->setText(Pos_y);


    Pos_z = QString::number(T(2,3));
    ui->Z_Pos->setText(Pos_z);

    ui->data_to_be_sent_textEdit->clear();

    QString data_to_be_sent;
    data_to_be_sent.append("Position (x,y,z): (");
    data_to_be_sent.append(Pos_x);
    data_to_be_sent.append(" ,");
    data_to_be_sent.append(Pos_y);
    data_to_be_sent.append(" ,");
    data_to_be_sent.append(Pos_z);
    data_to_be_sent.append(")");


    ui->data_to_be_sent_textEdit->append(data_to_be_sent);

//    std::cout << "Row size is: " << T.rows();

    ui->matrixTextEdit->appendPlainText("T Matrix: \n");

    for(int i = 0; i <= 3 ; ++i){

        QString row_String;
        for(int j = 0; j <= 3; ++j){
            value = QString::number(T(i,j));
            row_String.append(value);
            if(j!=3){
                row_String.append(", ");
            }
        }
        ui->matrixTextEdit->appendPlainText(row_String);
    }
}


void Widget::on_send_instructions_pushButton_clicked()
{

    Serial *s = new Serial();

    s->open("COM7");

    s->write("Hello world!");


    ui->communication_textEdit->append("Data Successfully sent");

////    s->sayhello("hello");

}
