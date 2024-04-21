#include "dormbuilding.h"

dormBuilding::dormBuilding(int x, int y) : locationNode(x, y)
{
    QTime temp;
    temp.setHMS(0, 0, 0);
    setDuration(temp);
    rename(QString("Dorm"));
    setBType(QString("Living space"));

}

void dormBuilding::setNodeIcon()
{
    const QSize small(100, 100);
    icon = QImage(QString(":/imgs/imgs/home"));
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = 50;
    offsetY = 50;
}
