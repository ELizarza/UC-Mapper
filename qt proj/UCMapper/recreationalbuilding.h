#ifndef RECREATIONALBUILDING_H
#define RECREATIONALBUILDING_H

#include <QWidget>
#include "locationnode.h"

class recreationalBuilding : public locationNode
{
public:
    recreationalBuilding(int x, int y, QString setName, QString type, QTime dur);
    void setNodeIcon();
};

#endif // RECREATIONALBUILDING_H
