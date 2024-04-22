#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include "myglwidget.h"
#include "node.h"
#include "mapcoords.h"
#include "coordgrid.h"
#include "pathnode.h"
#include "lecturebuilding.h"
#include "recreationalbuilding.h"
#include "dormbuilding.h"
#include <QPixmap>
#include <QList>
#include <QTime>
#include <QDebug>
#include <QQueue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //size of map
    static const QSize resultSize(1977, 1896);
    //create map drawing class with given map size
    map = new mapCoords(resultSize);

    //seperate lists of all nodes and nodes that we want the user to see


    //initialize dorm node
    //nodes are placed in RELATIVE position, to match the 15x15 coords we need to divide by 14 and multiply by 100
    dorm = new dormBuilding((11.0/14.0)*100, (11.0/14.0)*100, 11, 11);
    dorm->setNodeIcon();
    fullNodeList.append(dorm);

    //add dorm node to list
    QListWidgetItem* dormItem = new QListWidgetItem(QIcon(":/imgs/imgs/home"), "Dorm (SR)");
    visibleNodes.insert(dormItem, dorm);
    ui->listWidget->addItem(dormItem);

    //initialize map with dorm
    map->createSource(fullNodeList);
    map->recalculateResult();
    //draw map with nodes onto app
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);

    //initialize combobox
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("Sentenial Rock"));    //0
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("Glacier Point"));     //1
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("Granite Pass"));      //2
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("EL Portal"));         //3
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("Sierra Terraces"));   //4
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/home"), QString("Off campus/Summits/Half Dome/Valley Terraces"));  //5
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("Admin"));         //6
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("SE1"));           //7
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("SE2"));           //8
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("Granite Pass (classroom)"));  //9
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("SSM"));           //10
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("SSB"));           //11
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("COB1"));          //12
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("COB2"));          //13
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("BSP"));           //14
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("ACS"));           //15
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/bluePing"), QString("SRE"));           //16
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/greenPing"), QString("DC"));           //17
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/greenPing"), QString("Pavilion"));     //18
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/greenPing"), QString("Recreation and Wellness Center (gym)"));     //19
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/greenPing"), QString("KL"));           //20
    ui->locationComboBox->addItem(QIcon(":/imgs/imgs/greenPing"), QString("Conference"));   //21

    /*
    coordGrid* coordVisual = new coordGrid();
    QList<gridDot*> pack;
    pack = coordVisual->packageNodes();

    for (int i = 0; i < pack.length(); i++){
        fullNodeList.append(pack[i]);
    }
    */
    map->createSource(fullNodeList);
    map->recalculateResult();
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete selectedItem;
    delete dorm;
    delete map;
    delete ui;
}


void MainWindow::on_pushButton_clicked()    //add location button
{
    QList<QListWidgetItem*> findItem;   //finds if dorm is in the list and renames it
    if(location >= 0 && location <= 5){
        switch(location){
            case 0: //SR
                dorm->placeNode((11.0/14.0)*100,(11.0/14.0)*100);
                dorm->setGridCoords(11,11);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (SR)");
                break;


            case 1: //GLCR
                dorm->placeNode((10.0/14.0)*100,(10.0/14.0)*100);
                dorm->setGridCoords(10,10);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (GLCR)");
                break;



            case 2: //Gran
                dorm->placeNode((10.0/14.0)*100,(11.0/14.0)*100);
                dorm->setGridCoords(10,11);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (GRAN)");
                break;



            case 3: //EL Portal
                dorm->placeNode((13.0/14.0)*100,(12.0/14.0)*100);
                dorm->setGridCoords(13,12);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (Portal)");
                break;



            case 4:// SIERRA T
                dorm->placeNode((6.0/14.0)*100,(13.0/14.0)*100);
                dorm->setGridCoords(6,13);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (ST)");
                break;



            case 5:// off campus
                dorm->placeNode((10.0/14.0)*100,(14.0/14.0)*100);
                dorm->setGridCoords(10,14);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm");
                break;


        }
        //clear findItem list and rerender
        if(!findItem.empty()) findItem.pop_back();
        map->createSource(fullNodeList);
        map->recalculateResult();
        ui->label_2->setPixmap(map->createPixmap());
        ui->label_2->setScaledContents(true);
    }

    else if (location > 5 && location < 17){
        //initializes lecture node and gives name for list widget
        QListWidgetItem* newLoc;
        lectureBuilding* newNode;
        QString locName = "null";
        float tempX = 0.0;
        float tempY = 0.0;
        switch(location){
            case 6: //ADMIN
                locName = "Admin Lecture";
                tempX = 12.0;
                tempY = 13.0;
                break;

            case 7: //SE1
                locName = "SE1 Lecture";
                tempX = 4.0;
                tempY = 5.0;
                break;

            case 8: //SE2
                locName = "SE2 Lecture";
                tempX = 5.0;
                tempY = 5.0;
                break;

            case 9: //Granite
                locName = "Granite Lecture";
                tempX = 10.0;
                tempY = 11.0;
                break;

            case 10:    //SSM
                locName = "SSM Lecture";
                tempX = 2.0;
                tempY = 5.0;
                break;

            case 11:    //SSB
                locName = "SSB Lecture";
                tempX = 1.0;
                tempY = 6.0;
                break;

            case 12:    //COB1
                locName = "COB1 Lecture";
                tempX = 3.0;
                tempY = 7.0;
                break;

            case 13:    //COB2
                locName = "COB2 Lecture";
                tempX = 3.0;
                tempY = 9.0;
                break;


            case 14:    //BSP
                locName = "BSP Lecture";
                tempX = 7.0;
                tempY = 7.0;
                break;


            case 15:    //ACS
                locName = "ACS Lecture";
                tempX = 9.0;
                tempY = 9.0;
                break;


            case 16:    //SRE
                locName = "SRE Lecture";
                tempX = 7.0;
                tempY = 9.0;
                break;

        }
        //insert name and location into widgetItem and node
        newLoc = new QListWidgetItem(QIcon(":/imgs/imgs/bluePing"), QString("%1, %2-%3").arg(locName).arg(startTime.toString("h:m ap")).arg(endTime.toString("h:m ap")));
        newNode = new lectureBuilding((tempX/14.0)*100, (tempY/14.0)*100, int(tempX), int(tempY), QString("%1").arg(locName), QString("Scheduled Class"));
        //newNode->setGridCoords(int(tempX), int(tempY));
        newNode->setNodeIcon();
        newNode->setTime(startTime, endTime);
        //adds them to lists
        ui->listWidget->addItem(newLoc);
        fullNodeList.append(newNode);
        visibleNodes.insert(newLoc, newNode);
        //rerender
        map->createSource(fullNodeList);
        map->recalculateResult();
        ui->label_2->setPixmap(map->createPixmap());
        ui->label_2->setScaledContents(true);
    }

    else if (location >=17 && location < 22){
        //initializes recreation node and gives name for list widget
        QListWidgetItem* newLoc;
        recreationalBuilding* newNode;
        QString locName = "null";
        QString locType = "null";
        float tempX = 0.0;
        float tempY = 0.0;

        switch(location){
        case 17:    //DC
            locName = "Dining Center";
            locType = "food";
            tempX = 7.0;
            tempY = 13.0;
            break;

        case 18:    //Pavilion
            locName = "Pavilion";
            locType = "food";
            tempX = 9.0;
            tempY = 9.0;
            break;

        case 19:    //Gym
            locName = "Recreation and Wellness Center";
            locType = "gym";
            tempX = 6.0;
            tempY = 12.0;
            break;

        case 20:    //KL
            locName = "Kolligian Library";
            locType = "library";
            tempX = 4.0;
            tempY = 8.0;
            break;

        case 21:    //Conference center
            locName = "Conference Center";
            locType = "Misc";
            tempX = 11.0;
            tempY = 13.0;
            break;

        }
        //establishes duration as recreation activities aren't as strict with time
        QTime temp;
        temp.setHMS(0, 0, 0);
        temp = temp.addSecs(startTime.secsTo(endTime));

        newLoc = new QListWidgetItem(QIcon(":/imgs/imgs/greenPing"), QString("%1, %2-%3").arg(locName).arg(startTime.toString("h:m ap")).arg(endTime.toString("h:m ap")));
        newNode = new recreationalBuilding((tempX/14.0)*100, (tempY/14.0)*100, int(tempX), int(tempY), QString("%1").arg(locName), QString("%1").arg(locType), temp);
        //newNode->setGridCoords(int(tempX), int(tempY));
        newNode->setNodeIcon();
        //add to list
        ui->listWidget->addItem(newLoc);
        fullNodeList.append(newNode);
        visibleNodes.insert(newLoc, newNode);
        //rerender
        map->createSource(fullNodeList);
        map->recalculateResult();
        ui->label_2->setPixmap(map->createPixmap());
        ui->label_2->setScaledContents(true);
    }

    else return;

}


void MainWindow::on_pushButton_2_clicked()  //remove location button
{
    //do not remove if dorm item
    QList<QListWidgetItem*> findItems;
    findItems.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
    if (selectedItem == findItems.last()){
        findItems.pop_back(); //clear list either way
        return;
    }
    findItems.pop_back();
    //use item address to find associated node in QMap
    Node* deadNode = visibleNodes.take(selectedItem);
    qsizetype deadIndex = fullNodeList.indexOf(deadNode);
    if (deadIndex != -1) fullNodeList.removeAt(deadIndex);
    int deadRow = ui->listWidget->currentRow();
    QListWidgetItem* itemToDel = ui->listWidget->takeItem(deadRow);

    delete deadNode;
    delete itemToDel;
    //rerender
    map->createSource(fullNodeList);
    map->recalculateResult();
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);

}


void MainWindow::on_pushButton_3_clicked()  //reset map button
{
    QListWidgetItem* deadItem;
    for(int i = ui->listWidget->count() - 1; i >= 0; i--){
        //delete all items and nodes unless they are the dorm node/item
        deadItem = ui->listWidget->takeItem(i);
        Node* deadNode = visibleNodes.take(deadItem);
        if (deadNode != dorm){
            qsizetype deadIndex = fullNodeList.indexOf(deadNode);
            if (deadIndex != -1) fullNodeList.removeAt(deadIndex);

            delete deadItem;
            delete deadNode;
        }
        else{
            ui->listWidget->addItem(deadItem);
            visibleNodes.insert(deadItem, deadNode);
        }
    }

    /*
    QListWidgetItem* dormItem = new QListWidgetItem(QIcon(":/imgs/imgs/home"), "Dorm (SR)");
    visibleNodes.insert(dormItem, dorm);
    ui->listWidget->addItem(dormItem);
    */
    //rerender
    map->createSource(fullNodeList);
    map->recalculateResult();
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);
}


void MainWindow::on_lectureStartTimeEdit_userTimeChanged(const QTime &time) //starting time input
{
    qDebug() << time.toString();
    startTime = time;
}


void MainWindow::on_lectureEndTimeEdit_userTimeChanged(const QTime &time)   //ending time input
{
    qDebug() << time.toString();
    endTime = time;
}


void MainWindow::on_locationComboBox_currentIndexChanged(int index) //location selection
{
    qDebug() << index;
    location = index;

}


void MainWindow::on_locationComboBox_currentTextChanged(const QString &arg1)    //idk what this was for but I'm not using it anymore
{
    qDebug() << arg1;
    locationName = arg1;
}


void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)   //selected item for deletetion
{
    qDebug() << item->text();
    selectedItem = item;


}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)  //also selected item for deletetion but fixed bug with deleting multiple items
{
    selectedItem = current;
}

void MainWindow::on_pushButton_4_clicked()  //route button, this is where we create an optimal path to all locations and create path nodes for them
{
    //initialize matrix
    stepNode* matrix[15][15];
    int tempCoords[2];

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            tempCoords[0] = i;
            tempCoords[1] = j;
            matrix[i][j] = new stepNode;
            matrix[i][j]->coords[0] = tempCoords[0];
            matrix[i][j]->coords[1] = tempCoords[1];
            matrix[i][j]->visibility = QString("r");
            matrix[i][j]->visited = false;

            matrix[i][j]->topLeft = nullptr;
            matrix[i][j]->top = nullptr;
            matrix[i][j]->topRight = nullptr;

            matrix[i][j]->Left = nullptr;
            matrix[i][j]->Right = nullptr;

            matrix[i][j]->botLeft = nullptr;
            matrix[i][j]->bottom = nullptr;
            matrix[i][j]->botRight = nullptr;
        }
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            stepNodePather(matrix[i][j], matrix, i, j);
        }
    }

    qDebug() << "matrix created";

    //initalize walkable paths and valid locations

    int desty [] = {10, 11,     13, 12,     6, 13,  4,5,    2,5,    1,6,    7,9,    7,13,   11,13};
    for (int i = 0; i < 17; i++){
        if (i % 2 == 0){
            matrix[desty[i]][desty[i+1]]->visibility = QString("y");
        }
    }

    for (int i = 1; i < 13; i++){   //Academic walk
        matrix[i][i]->visibility = QString("g");
    }
    for (int i = 1; i < 11; i++){   //Scholars lane
        matrix[i][i+4]->visibility = QString("g");
    }

    int walkable [] = {3, 5,   2, 6,   1, 7,   7, 10,  8, 9,   6, 10,  7, 9,   8,10,   5, 13,  6, 12,    10, 4,     12, 13,  3, 7,    3, 9,   6, 12,    4, 8};
    for (int i = 0; i < 15; i++){
        if (i % 2 == 0){
            matrix[walkable[i]][walkable[i+1]]->visibility = QString("g");
        }
    }

    //QList<stepNode*> cool = breadthFirstSearch(matrix, 11, 11, 5, 5);

    int startNodeX = 0;
    int startNodeY = 0;
    int endNodeX = 0;
    int endNodeY = 0;
    int pathNodeCount = 0;
    QList<stepNode*> path;
    for (QMap<QListWidgetItem*, Node*>::const_iterator it = visibleNodes.cbegin(); it != visibleNodes.cend(); it++){
        if (it == visibleNodes.cbegin()){
            endNodeX = it.value()->getGridX();
            endNodeY = it.value()->getGridY();
        }
        else{
            startNodeX = endNodeX;
            qDebug() << "start x: " << startNodeX;
            startNodeY = endNodeY;
            qDebug() << "start y: " << startNodeY;
            endNodeX = it.value()->getGridX();
            qDebug() << "end x: " << endNodeX;
            endNodeY = it.value()->getGridY();
            qDebug() << "end y: " << endNodeY;
            path = breadthFirstSearch(matrix, startNodeX, startNodeY, endNodeX, endNodeY);
            for (int i = 0; i < path.size(); i++){
                pathNode* tempPath = new pathNode((path[i]->coords[0]/14.0)*100, (path[i]->coords[1]/14.0)*100);
                qDebug() << "a path was created";
                if (path[i]->pathedFrom == path[i]->topLeft) tempPath->setDirection(135.0); //since we're starting at the last node the direction is oppsite from direction of previous node
                else if (path[i]->pathedFrom == path[i]->topRight) tempPath->setDirection(225.0);
                else if (path[i]->pathedFrom == path[i]->Left) tempPath->setDirection(90.0);
                else if (path[i]->pathedFrom == path[i]->Right) tempPath->setDirection(270.0);
                else if (path[i]->pathedFrom == path[i]->botLeft) tempPath->setDirection(45.0);
                else if (path[i]->pathedFrom == path[i]->top) tempPath->setDirection(180.0);
                else if (path[i]->pathedFrom == path[i]->botRight) tempPath->setDirection(315.0);
                else tempPath->setDirection(0.0);
                if (pathNodeCount % 2 == 0)tempPath->setNodeIcon();
                else tempPath->setCustomIcon(QImage(":/imgs/imgs/alt arrow icon"), 50, 50);
                fullNodeList.append(tempPath);
                pathNodeCount++;
            }

        }
    }

    map->createSource(fullNodeList);
    map->recalculateResult();
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);

    for (int i = 0; i < pathNodeCount; i++){
        fullNodeList.pop_back();
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            delete matrix[i][j];
        }
    }
    qDebug() << "matrix destroyed";
}

void MainWindow::stepNodePather(stepNode* target, stepNode* matrix[15][15], int x, int y)
{
    /* //doesn't see invalid indexes as nullptrs
    if (matrix[x-1][y-1] != nullptr) target->topLeft = matrix[x-1][y-1];
    if (matrix[x][y-1] != nullptr) target->top = matrix[x][y-1];
    if (matrix[x+1][y-1] != nullptr) target->topRight = matrix[x+1][y-1];

    if (matrix[x-1][y] != nullptr) target->Left = matrix[x-1][y];
    if (matrix[x+1][y] != nullptr) target->Right = matrix[x+1][y];

    if (matrix[x-1][y+1] != nullptr) target->botLeft = matrix[x-1][y+1];
    if (matrix[x][y+1] != nullptr) target->bottom = matrix[x][y+1];
    if (matrix[x+1][y+1] != nullptr) target->botRight = matrix[x+1][y+1];
    */
    if (x != 0 && y != 0) target->topLeft = matrix[x-1][y-1];
    if (y != 0) target->top = matrix[x][y-1];
    if (x != 14 && y != 0) target->topRight = matrix[x+1][y-1];

    if (x != 0) target->Left = matrix[x-1][y];
    if (x != 14) target->Right = matrix[x+1][y];

    if (x != 0 && y != 14) target->botLeft = matrix[x-1][y+1];
    if (y != 14) target->bottom = matrix[x][y+1];
    if (x != 14 && y != 14) target->botRight = matrix[x+1][y+1];
}

QList<MainWindow::stepNode *> MainWindow::breadthFirstSearch(stepNode *matrix[15][15], int startX, int startY, int endX, int endY)
{
    QList<stepNode*> finalPath;
    stepNode* currentNode;
    stepNode* start = matrix[startX][startY];
    stepNode* end = matrix[endX][endY];
    QQueue<stepNode*> queue;
    start->visited = true;
    queue.enqueue(start);

    while(!queue.isEmpty()){

        //qDebug() << "before dequeue";
        currentNode = queue.dequeue();
        //qDebug() << "after dequeue";
        /*
        qDebug() << "test matrix";
        if (matrix[0][0]->topLeft != nullptr){
            qDebug() << "not nullptr!";
            qDebug() << matrix[0][0]->topLeft->coords[0];
        }
        qDebug() << "matrix didn't crash!";
        */

        if(currentNode->topLeft != nullptr && currentNode->topLeft->visited == false){
            currentNode->topLeft->visited = true;
            queue.enqueue(currentNode->topLeft);
            currentNode->topLeft->pathedFrom = currentNode;
            if (currentNode->topLeft == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->top != nullptr && currentNode->top->visited == false){
            currentNode->top->visited = true;
            queue.enqueue(currentNode->top);
            currentNode->top->pathedFrom = currentNode;
            if (currentNode->top == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->topRight != nullptr && currentNode->topRight->visited == false){
            currentNode->topRight->visited = true;
            queue.enqueue(currentNode->topRight);
            currentNode->topRight->pathedFrom = currentNode;
            if (currentNode->topRight == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->Left != nullptr && currentNode->Left->visited == false){
            currentNode->Left->visited = true;
            queue.enqueue(currentNode->Left);
            currentNode->Left->pathedFrom = currentNode;
            if (currentNode->Left == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->Right != nullptr && currentNode->Right->visited == false){
            currentNode->Right->visited = true;
            queue.enqueue(currentNode->Right);
            currentNode->Right->pathedFrom = currentNode;
            if (currentNode->Right == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->botLeft != nullptr && currentNode->botLeft->visited == false){
            currentNode->botLeft->visited = true;
            queue.enqueue(currentNode->botLeft);
            currentNode->botLeft->pathedFrom = currentNode;
            if (currentNode->botLeft == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->bottom != nullptr && currentNode->bottom->visited == false){
            currentNode->bottom->visited = true;
            queue.enqueue(currentNode->bottom);
            currentNode->bottom->pathedFrom = currentNode;
            if (currentNode->bottom == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        if(currentNode->botRight != nullptr && currentNode->botRight->visited == false){
            currentNode->botRight->visited = true;
            queue.enqueue(currentNode->botRight);
            currentNode->botRight->pathedFrom = currentNode;
            if (currentNode->botRight == end) {
                qDebug() << "loop broken";
                break;
            }
        }
        qDebug() << "loop";
    }
    qDebug() << "loop end";
    currentNode = end;

    while (currentNode != start){
        finalPath.push_front(currentNode);
        currentNode = currentNode->pathedFrom;
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            matrix[i][j]->visited = false;
        }
    }

    return finalPath;

}



