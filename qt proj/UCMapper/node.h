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
    int gridX;
    int gridY;
public:
    Node();
    Node(int x, int y, QString setName);
    Node(int x, int y);
    virtual ~Node();
    void placeNode(int x, int y);
    void rename(QString newName);
    virtual void setNodeIcon();
    virtual void setCustomIcon(QImage custom, int width, int height);
    virtual void setGridCoords(int gx, int gy);
    virtual int getGridX();
    virtual int getGridY();

    int giveX();
    int giveY();
    QString giveName();
    QImage giveIcon();
    float giveOffsetX();
    float giveOffsetY();
    //friend class mapCoords;
};

#endif // NODE_H
