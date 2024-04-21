#ifndef LECTUREBUILDING_H
#define LECTUREBUILDING_H

#include <QWidget>
#include <QTime>
#include "locationnode.h"

class lectureBuilding : public locationNode
{
public:
    lectureBuilding(int x, int y, QString setName, QString type);
    void setTime(QTime startT, QTime endT);
    void setNodeIcon();

private:
    QTime startTime;
    QTime endTime;
};

#endif // LECTUREBUILDING_H
