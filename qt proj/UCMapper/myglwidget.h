#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include<QObject>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent = nullptr);
    ~MyGLWidget();

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

private:


};
#endif // MYGLWIDGET_H
