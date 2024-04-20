#ifndef GRIDDOT_H
#define GRIDDOT_H

#include"node.h"
#include<QWidget>

class gridDot : public Node
{
public:
    gridDot();
    ~gridDot();
    gridDot(int x, int y);
    gridDot(int x, int y, QString setName);
    void setVisibility(QString color);
    QString giveVisibility();
    void setNodeIcon();

private:
    QString visibility; //"g" = show, "r" = hide, "y" = building, add more stuff later maybe

    friend class coordGrid;
};

#endif // GRIDDOT_H
