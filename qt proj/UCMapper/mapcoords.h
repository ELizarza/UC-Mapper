#ifndef MAPCOORDS_H
#define MAPCOORDS_H

#include <QWidget>
#include "node.h"

class mapCoords : public QWidget
{
    Q_OBJECT

public slots:
    void initDestination();
    void createSource(QVector<Node *> sprites);
    void recalculateResult();
    void resultClear();

public:
    mapCoords(QSize rSize);
    ~mapCoords();
    QPixmap createPixmap();


private:
    QImage destinationImage;
    QImage sourceImage;
    QImage resultImage;
    QSize resultSize;


};

#endif // MAPCOORDS_H
