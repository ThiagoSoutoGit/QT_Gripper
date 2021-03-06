#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "C:/eigen/Eigen/Dense"
using namespace Eigen;

#include <QOpenGLWidget>


#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "serial.h"
#include "myglwidget.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    friend class serial;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Ui::Widget *ui;

    double theta_1_value;
    double theta_2_value;
    double theta_3_value;
    double theta_4_value;
    double theta_5_value;

    double l_1_value;
    double l_2_value;
    double l_3_value;
    double l_4_value;


    Matrix4d t_0_1_matrix;
    Matrix4d t_1_2_matrix;
    Matrix4d t_2_3_matrix;
    Matrix4d t_3_4_matrix;
    Matrix4d t_4_5_matrix;

    Matrix4d t_1_5_matrix;
    Matrix4d t_1_4_matrix;

    Matrix4d T;

    QString Pos_x;
    QString Pos_y;
    QString Pos_z;
    QString value;


public slots:

    void on_btn_Inverse_Kinematics_clicked();

    void on_btn_Forward_Kinematics_clicked();

    void on_send_instructions_pushButton_clicked();

};
#endif // WIDGET_H
