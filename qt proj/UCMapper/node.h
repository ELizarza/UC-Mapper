#ifndef NODE_H
#define NODE_H

#include <QWidget>

class Node
{
protected:
    int posX;
    int posY;
    QString name;
    QImage icon;
    float offsetX;
    float offsetY;
public:
    Node();
    Node(int x, int y, QString setName);
    Node(int x, int y);
    ~Node();
    void placeNode(int x, int y);
    void rename(QString newName);
    virtual void setNodeIcon();
    int* giveCoords();
    friend class mapCoords;
};

#endif // NODE_H
