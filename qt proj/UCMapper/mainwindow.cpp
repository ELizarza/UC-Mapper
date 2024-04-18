#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include "myglwidget.h"
#include "node.h"
#include "mapcoords.h"
#include <QPixmap>
#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create OpenGL widget
    //MyGLWidget* MyGLWidget = new MyGLWidget(this);

    /*
    QPixmap pm(":/imgs/imgs/UCmap");
    ui->label_2->setPixmap(pm);
    ui->label_2->setScaledContents(true);
    */

    //size of map
    static const QSize resultSize(1977, 1896);
    //create map drawing class with given map size
    mapCoords* map = new mapCoords(resultSize);

    //test node placement
    QList<Node> nodes;
    Node* testNode = new Node();
    testNode->setNodeIcon();
    nodes.append(*testNode);
    map->createSource(nodes);
    map->recalculateResult();

    //draw map with nodes onto app
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

