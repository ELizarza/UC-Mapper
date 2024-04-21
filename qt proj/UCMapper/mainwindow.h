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

private:
    Ui::MainWindow *ui;
    mapCoords* map;
    QTime startTime;
    QTime endTime;
    int location;
    QString locationName;
    dormBuilding* dorm;
    QList<Node*> fullNodeList;
    QMap<QListWidgetItem* ,Node*> visibleNodes;
    QListWidgetItem* selectedItem;


};
#endif // MAINWINDOW_H
