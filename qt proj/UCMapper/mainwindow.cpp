#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include "myglwidget.h"
#include "node.h"
#include "mapcoords.h"
#include "coordgrid.h"
#include "pathnode.h"
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
    QList<Node*> nodes;
    Node* testNode = new Node();
    testNode->setNodeIcon();

    //gridDot* testNode2 = new gridDot(20, 30);
    //testNode2->setNodeIcon();

    pathNode* testNode3 = new pathNode(40, 20);
    testNode3->setDirection(180);
    testNode3->setNodeIcon();
    nodes.append(testNode3);

    nodes.append(testNode);
    map->createSource(nodes);
    map->recalculateResult();

    /*
    coordGrid* coordVisual = new coordGrid();
    QList<gridDot*> pack;
    pack = coordVisual->packageNodes();

    for (int i = 0; i < pack.length(); i++){
        nodes.append(pack[i]);
    }
    map->createSource(nodes);
    map->recalculateResult();
    */


    //draw map with nodes onto app
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

