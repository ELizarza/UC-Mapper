#include "lecturebuilding.h"

lectureBuilding::lectureBuilding(int x, int y, QString setName, QString type) : locationNode(x, y, setName, type)
{}

void lectureBuilding::setTime(QTime startT, QTime endT)
{
    startTime = startT;
    endTime = endT;
    QTime temp;
    temp.setHMS(0, 0, 0);
    temp = temp.addSecs(startTime.secsTo(endTime));
    setDuration(temp);

}

void lectureBuilding::setNodeIcon()
{
    const QSize small(100, 100);
    icon = QImage(QString(":/imgs/imgs/bluePing"));
    icon = icon.scaled(small, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    offsetX = 50;
    offsetY = 50;
}
