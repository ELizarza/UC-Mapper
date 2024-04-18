#ifndef NODE_H
#define NODE_H

#include <QWidget>

class Node
{
private:
    int posX;
    int posY;
    QString name;
    QImage icon;
public:
    Node();
    Node(int x, int y, QImage img);
    ~Node();
    void placeNode(int x, int y);
    void rename(QString newName);
    virtual void setNodeIcon();
    int* giveCoords();
    friend class mapCoords;
};

#endif // NODE_H
