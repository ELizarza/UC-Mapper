#include "coordgrid.h"
#include "griddot.h"

coordGrid::coordGrid() {
    //initialize all nodes
    //matrix = new gridDot[gridWidth][gridHeight];
    for (int i = 0; i < gridWidth; i++){
        for (int j = 0; j < gridHeight; j++){
            gridDot* temp = new gridDot(float(float(i) / float(gridWidth - 1)) * 100, float(float(j) / float(gridHeight - 1)) * 100, QString("(%1, %2)").arg(i).arg(j));
            matrix[i][j] = temp;
            matrix[i][j]->visibility = "g"; //set all nodes to show
        }
    }
}

QList<gridDot *> coordGrid::packageNodes()
{
    QList<gridDot*> package;
    for (int i = 0; i < gridWidth; i++){
        for (int j = 0; j < gridHeight; j++){
            if (matrix[i][j]->visibility == "g"){
                package.append(matrix[i][j]);
            }
        }
    }
    return package;
}


void coordGrid::excludeNode(int x, int y){
    matrix[x][y]->visibility = "r";
}
