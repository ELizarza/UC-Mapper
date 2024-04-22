#include "locationnode.h"

locationNode::locationNode(int x, int y, int gx, int gy, QString setName, QString type) : Node(x, y, setName)
{
    setBType(type);
    gridX = gx;
    gridY = gy;
}

locationNode::locationNode(int x, int y, int gx, int gy) : Node(x, y)
{
    gridX = gx;
    gridY = gy;
}

void locationNode::setDuration(QTime dur)
{
    duration = dur;
}

QTime locationNode::giveDuration()
{
    return duration;
}

void locationNode::setBType(QString type)
{
    buildingType = type;
}

QString locationNode::giveBType()
{
    return buildingType;
}

void locationNode::setGridCoords(int gx, int gy)
{
    gridX = gx;
    gridY = gy;
}

int locationNode::getGridX()
{
    return gridX;
}

int locationNode::getGridY()
{
    return gridY;
}

