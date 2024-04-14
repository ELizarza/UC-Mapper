#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{

}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()
{
    // Set up the rendering context, load shaders and other resources, etc.:
    /*
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    f->glEnable(GL_DEPTH_TEST);
    f->glEnable(GL_LIGHT0);
    f->glEnable(GL_LIGHTING);
    f->glEnable(GL_COLOR_MATERIAL);
    */
}

void MyGLWidget::resizeGL(int w, int h)
{
    // Update projection matrix and other size related settings:
    /*
    m_projection.setToIdentity();
    m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
    */

    initializeOpenGLFunctions();

    //clear to cyan
    glClearColor(0.5, 1, 1, 1);
}

void MyGLWidget::paintGL()
{
    // Draw the scene:
    /*
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);
    */
    //set every pixel to current clear color
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.0f, 0.707f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();

}

//test





