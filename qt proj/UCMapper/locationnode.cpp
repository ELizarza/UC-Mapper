#include "locationnode.h"

locationNode::locationNode(int x, int y, QString setName, QString type) : Node(x, y, setName)
{
    setBType(type);
}

locationNode::locationNode(int x, int y) : Node(x, y)
{}

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

