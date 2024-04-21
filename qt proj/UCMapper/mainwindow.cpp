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
    dorm = new dormBuilding((11.0/14.0)*100, (11.0/14.0)*100);
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
    map->createSource(fullNodeList);
    map->recalculateResult();
    ui->label_2->setPixmap(map->createPixmap());
    ui->label_2->setScaledContents(true);
    */
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
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (SR)");
                break;


            case 1: //GLCR
                dorm->placeNode((10.0/14.0)*100,(10.0/14.0)*100);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (GLCR)");
                break;



            case 2: //Gran
                dorm->placeNode((10.0/14.0)*100,(11.0/14.0)*100);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (GRAN)");
                break;



            case 3: //EL Portal
                dorm->placeNode((13.0/14.0)*100,(12.0/14.0)*100);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (Portal)");
                break;



            case 4:// SIERRA T
                dorm->placeNode((6.0/14.0)*100,(13.0/14.0)*100);
                findItem.append(ui->listWidget->findItems(QString("Dorm"), Qt::MatchContains));
                findItem.last()->setText("Dorm (ST)");
                break;



            case 5:// off campus
                dorm->placeNode((10.0/14.0)*100,(14.0/14.0)*100);
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
        newLoc = new QListWidgetItem(QIcon(":/imgs/imgs/bluePing"), QString("%1").arg(locName));
        newNode = new lectureBuilding((tempX/14.0)*100, (tempY/14.0)*100, QString("%1").arg(locName), QString("Scheduled Class"));
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

        newLoc = new QListWidgetItem(QIcon(":/imgs/imgs/greenPing"), QString("%1").arg(locName));
        newNode = new recreationalBuilding((tempX/14.0)*100, (tempY/14.0)*100, QString("%1").arg(locName), QString("%1").arg(locType), temp);
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

