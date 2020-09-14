#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <iostream>

#include "C:/eigen/Eigen/Dense"

using namespace Eigen;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
