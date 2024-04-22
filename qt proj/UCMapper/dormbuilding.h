#ifndef DORMBUILDING_H
#define DORMBUILDING_H

#include <QWidget>
#include "locationnode.h"

class dormBuilding : public locationNode
{
public:
    dormBuilding(int x, int y, int gx, int gy);
    void setNodeIcon();
};

#endif // DORMBUILDING_H
