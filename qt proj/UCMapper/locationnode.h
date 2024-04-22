#ifndef LOCATIONNODE_H
#define LOCATIONNODE_H

#include <QWidget>
#include <QTime>
#include "node.h"

class locationNode : public Node
{
public:
    locationNode(int x, int y, int gx, int gy, QString setName, QString type);
    locationNode(int x, int y, int gx, int gy);
    void setDuration(QTime dur);
    QTime giveDuration();
    void setBType(QString type);
    QString giveBType();
    void setGridCoords(int gx, int gy);
    int getGridX();
    int getGridY();

private:
    QTime duration;
    QString buildingType;
    int gridX;
    int gridY;


};

#endif // LOCATIONNODE_H
