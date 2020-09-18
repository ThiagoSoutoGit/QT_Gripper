#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/glu.h>


//#include "widget.h"
//#include "ui_widget.h"

#include <QWidget>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent=nullptr);

protected:
    //This is a virtual funciton
    void initializeGL() override;

    //This is also a virtual funciton
    void paintGL() override;

    void resizeGL(int w, int h);
};

#endif // MYGLWIDGET_H
