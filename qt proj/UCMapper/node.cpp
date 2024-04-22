#include "node.h"

Node::Node(){ //default node placed in the (sort of) center, and gives a default name, have set icon in derivated node class or in main since it doesn't like using virtual methods in constructors
    placeNode(50, 50);
    rename(QString("Untitled node"));
}

Node::Node(int x, int y, QString setName)
{
    placeNode(x, y);
    rename(setName);
}

Node::Node(int x, int y)
{
    placeNode(x, y);
}

Node::~Node()
{}

void Node::placeNode(int x, int y){ //set coordnates of node
    //NOTE: these are RELATIVE coordinates from 0-100, going above these can result in the node leaving the window
    posX = x;
    posY = y;
}

void Node::rename(QString newName) //sets name
{
    name = newName;
}

void Node::setNodeIcon() //default icon, change this in derived node class, also make sure to resize them too
{
    const QSize small(100, 100);
    icon = QImage(QString(":/imgs/imgs/defaultPing"));
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = 50;
    offsetY = 50;

}

void Node::setCustomIcon(QImage custom, int width, int height)
{
    const QSize small(width, height);
    icon = custom;
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = width/2;
    offsetY = height/2;
}

void Node::setGridCoords(int gx, int gy)
{

}

int Node::getGridX()
{

}

int Node::getGridY()
{

}


//return functions for non-friend calls
int Node::giveX()
{
    return posX;
}

int Node::giveY()
{
    return posY;
}

QString Node::giveName()
{
    return name;
}

QImage Node::giveIcon()
{
    return icon;
}

float Node::giveOffsetX()
{
    return offsetX;
}

float Node::giveOffsetY()
{
    return offsetY;
}
