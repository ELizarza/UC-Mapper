#include "recreationalbuilding.h"

recreationalBuilding::recreationalBuilding(int x, int y, QString setName, QString type, QTime dur) : locationNode(x, y, setName, type)
{
    setDuration(dur);
}

void recreationalBuilding::setNodeIcon()
{
    const QSize small(150, 150);
    icon = QImage(QString(":/imgs/imgs/greenPing"));
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = 75;
    offsetY = 75;
}
