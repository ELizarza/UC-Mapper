#ifndef COORDGRID_H
#define COORDGRID_H

#include"node.h"
#include"griddot.h"

class coordGrid
{
public:
    coordGrid();
    QList<gridDot*> packageNodes();
    void excludeNode(int x, int y);
private:
    gridDot* matrix[25][25];
    const int gridWidth = 25;
    const int gridHeight = 25;
};


#endif // COORDGRID_H
