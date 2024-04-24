#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QList>
#include <QListWidgetItem>
#include <QMap>
#include "mapcoords.h"
#include "dormbuilding.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lectureStartTimeEdit_userTimeChanged(const QTime &time);

    void on_lectureEndTimeEdit_userTimeChanged(const QTime &time);

    void on_locationComboBox_currentIndexChanged(int index);

    void on_locationComboBox_currentTextChanged(const QString &arg1);

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    mapCoords* map;
    QTime startTime = QTime(5, 00);
    QTime endTime = QTime(5, 00);
    int location;
    QString locationName;
    dormBuilding* dorm;
    QList<Node*> fullNodeList;
    QMap<QListWidgetItem* ,Node*> visibleNodes;
    QListWidgetItem* selectedItem;

    struct stepNode {
        QString visibility; //"r" = not pathable, "y" = available destination but not pathable, "g" = pathable
        stepNode* topLeft;
        stepNode* top;
        stepNode* topRight;
        stepNode* Left;
        stepNode* Right;
        stepNode* botLeft;
        stepNode* bottom;
        stepNode* botRight;
        int coords[2];
        bool visited;
        int orientation = 0;
        stepNode* pathedFrom;
    };

    void stepNodePather(stepNode*target, stepNode *matrix[15][15], int x, int y);
    QList<stepNode*> breadthFirstSearch(stepNode *matrix[15][15], int startX, int startY, int endX, int endY);


};
#endif // MAINWINDOW_H
