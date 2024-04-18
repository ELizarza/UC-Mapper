#include "mapcoords.h"
#include "node.h"
#include <QVector>
#include <Qpainter>

void mapCoords::initDestination()
{
    //initializes map image as the destination Image (thing to be drawn on)
    //and as result image so there is something to display
    destinationImage = QImage(QString(":/imgs/imgs/UCmap"));
    resultImage = destinationImage;
}

void mapCoords::createSource(QVector<Node> sprites)
{
    //create temp overlay that will become the source img and make it transparent
    QImage overlay = QImage(resultSize, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&overlay);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(overlay.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    //for loop goes through all nodes created in main window and adds their icon to the overlay with their respective positions
    Node temp;
    for (int i = 0; i < sprites.length(); i++){
        temp = sprites[i];
        //convert relative coordinates to coordinates in respect to the image
        //note coordniates refer to the TOP LEFT of image
        int canvasX = float(temp.posX)/100 * 1977;
        int canvasY = float(temp.posY)/100 * 1896;
        painter.drawImage(canvasX, canvasY, temp.icon);
        //painter.drawImage(0, 0, temp.icon);
    }
    painter.end();
    //copy overlay image to source image
    sourceImage = overlay;
}

void mapCoords::recalculateResult()
{
    //add source image (node icons and paths) to destination image (map)
    QPainter painter(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    //these coordinates should always be 0, 0, as they fit the full image
    painter.drawImage(0, 0, destinationImage);
    painter.drawImage(0, 0, sourceImage);
    painter.end();

}

void mapCoords::resultClear() //clears map
{
    resultImage = destinationImage;
}

mapCoords::mapCoords(QSize rSize) { //need size of map image to define size of overlay/source img
    initDestination();
    resultSize = rSize;
}

mapCoords::~mapCoords()
{

}

QPixmap mapCoords::createPixmap()//converts result to pixmap to prepare to be used in main window
{
    return QPixmap::fromImage(resultImage);
}
