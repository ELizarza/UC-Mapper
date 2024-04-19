#include "griddot.h"
#include "node.h"
#include <QWidget>

gridDot::gridDot()
    : Node() {
    setNodeIcon();
}

gridDot::gridDot(int x, int y)
    : Node(x, y)
{
    setNodeIcon();
}

gridDot::gridDot(int x, int y, QString setName)
    : Node(x, y, setName)
{
    setNodeIcon();
}

void gridDot::setNodeIcon()
{
    const QSize small(20, 20);
    icon = QImage(QString(":/imgs/imgs/Red_dot"));
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = 10;
    offsetY = 10;
}
