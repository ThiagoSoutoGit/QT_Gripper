#include "myglwidget.h"
#include <QSurfaceFormat>
//#include "widget.h"
//#include "ui_widget.h"



//#include <glm/mat4x4.hpp>

MyGLWidget::MyGLWidget(QWidget* parent):
    QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

}

void MyGLWidget::initializeGL()
{
    //This is compulsory
    this->initializeOpenGLFunctions();
}

void MyGLWidget::paintGL()
{

    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glMatrixMode(GL_PROJECTION);

    glBegin(GL_LINES);

        glColor3f(0,0,0);

        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(2.0f, 0.0f, 0.0f);

        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 1.0f);

    glEnd();

    double w = 490;
    double h = 600;
    double c = 320;


//    glLoadIdentity();

//    glViewport(0, 0, w, h);
//    gluOrtho2D(0, w, h, 0);
//    glMatrixMode(GL_MODELVIEW);
//    update();

    glFlush();

}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0, 0,1,0);

}
