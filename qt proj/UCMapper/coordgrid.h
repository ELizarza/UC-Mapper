#ifndef COORDGRID_H
#define COORDGRID_H

#include"node.h"
#include"griddot.h"

class coordGrid
{
public:
    coordGrid();
    ~coordGrid();
    QList<gridDot*> packageNodes();
    void excludeNode(int x, int y);
private:
    gridDot* matrix[15][15];
    const int gridWidth = 15;
    const int gridHeight = 15;
};


#endif // COORDGRID_H
