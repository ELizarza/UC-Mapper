#include "node.h"

Node::Node(){ //default node placed in the (sort of) center, and gives a default name, have set icon in derivated node class or in main since it doesn't like using virtual methods in constructors
    placeNode(50, 50);
    rename(QString("Untitled node"));
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

}
