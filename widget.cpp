#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QString>
#include <iostream>
#include <cmath>

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

    ui->L_1->setText("0");
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

    double x05 = 100 + 100 * cos(45 * M_PI/180);
    double y05 = 0;
    double z05 = 100 + 100 * sin(45 * M_PI/180);

    std::cout << x05 << std::endl <<  y05 << std::endl << z05 << std::endl << std::endl;;


    // Create hamogeneous transforms for the forward Kinematics

    Matrix4d T01;
    T01 = h_T(0, 0, theta_1_value, l_1_value);
    std::cout << "Matrix T01:" << std::endl << T01.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T12;
    double alpha_1 = (90 * M_PI/180);
    T12 = h_T(alpha_1, 0, theta_2_value, 0);
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

    Matrix4d T05;
    T05 = T01 * T12 * T23 * T34 * T45;
    std::cout << "Matrix T05:" << std::endl << T05.format(CleanFmt) << std::endl << std::endl;


    // Inverse Kinematics

    Matrix4d T15;
    T15 = T05 * T01.inverse();
    std::cout << "Matrix T15:" << std::endl << T15.format(CleanFmt) << std::endl << std::endl;

    Matrix4d T14;
    T14 = T15 * T45.inverse();
    std::cout << "Matrix T14:" << std::endl << T14.format(CleanFmt) << std::endl << std::endl;

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


    double c3;
    c3 = (pow(x14, 2) + pow(z14, 2) - pow(l_2_value, 2) - pow(l_3_value, 2))/(2*l_2_value*l_3_value);
    double s3;
    s3 = sqrt(1 - pow(c3, 2));
    double theta_3_angle;
    theta_3_angle = atan2(s3, c3) * 180/M_PI;
    ui->Theta_33->setText(QString::number(theta_3_angle));

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
