#ifndef LOCATIONNODE_H
#define LOCATIONNODE_H

#include <QWidget>
#include <QTime>
#include "node.h"

class locationNode : public Node
{
public:
    locationNode(int x, int y, QString setName, QString type);
    locationNode(int x, int y);
    void setDuration(QTime dur);
    QTime giveDuration();
    void setBType(QString type);
    QString giveBType();

private:
    QTime duration;
    QString buildingType;


};

#endif // LOCATIONNODE_H
