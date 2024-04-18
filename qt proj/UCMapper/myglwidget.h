#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include<QOpenGLBuffer>
#include<QObject>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    //using QOpenGLWidget::QOpenGLWidget;
    MyGLWidget(QWidget* parent = nullptr);
    ~MyGLWidget();

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void makeObject();

private:
    QOpenGLBuffer vbo;
    QOpenGLShaderProgram *program = nullptr;
    QOpenGLTexture *texture;

};
#endif // MYGLWIDGET_H
