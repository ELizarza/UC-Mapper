#ifndef PATHNODE_H
#define PATHNODE_H

#include <QWidget>
#include "node.h"

class pathNode : public Node
{
public:
    pathNode(int x, int y);
    void setDirection(float ori);
    void setNodeIcon();
    float getOrientation();

private:
    QString visibility = "g"; //"g" = show, "r" = hide, "y" = building, path nodes should always be shown
    float orientation = 0;
};

#endif // PATHNODE_H
