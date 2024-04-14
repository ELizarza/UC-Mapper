#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include "myglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create OpenGL widget
    //MyGLWidget* MyGLWidget = new MyGLWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

