#include "pathnode.h"
#include <QPainter>

pathNode::pathNode(int x, int y)
    :Node(x, y)
{
    //create node at (x,y) and rename to (x,y)
    rename(QString("(%1, %2)").arg(x).arg(y));
}

void pathNode::setDirection(float ori)
{
    orientation = ori;
    //may not need this, scratch that we definitely need this, nevermind nevermind actually don't need this at all, just keeping to remember angles
    /*
    switch(dir){
        case "up":
            orientation = 0;
            break;

        case "left":
            orientation = 270;
            break;

        case "right":
            orientation = 90;
            break;

        case "down":
            orientation = 180;
            break;

        case "uleft":
            orientation = 315;
            break;

        case "uright":
            orientation = 45;
            break;

        case "dleft":
            orientation = 225;
            break;

        case "dright":
            orientation = 135;
            break;
    }
    */
    offsetX = 50;
    offsetY = 50;
}

float pathNode::getOrientation()
{
    return orientation;
}

void pathNode::setNodeIcon()
{
    const QSize small(50, 50);
    QImage temp;
    temp = QImage(QString(":/imgs/imgs/pathNode"));
    temp = temp.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    icon = temp;
    if (orientation == 0){
        return;
    }
    QPainter painter(&icon);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(icon.rect(), Qt::transparent);
    painter.translate(25, 25);
    painter.rotate(orientation);
    painter.drawImage(-25, -25, temp);
    painter.end();

}
