#include "coordgrid.h"
#include "griddot.h"

coordGrid::coordGrid() {
    //initialize all nodes
    //matrix = new gridDot[gridWidth][gridHeight];
    for (int i = 0; i < gridWidth; i++){
        for (int j = 0; j < gridHeight; j++){
            gridDot* temp = new gridDot(float(float(i) / float(gridWidth - 1)) * 100, float(float(j) / float(gridHeight - 1)) * 100, QString("(%1, %2)").arg(i).arg(j));
            matrix[i][j] = temp;
            matrix[i][j]->setVisibility(QString("g")); //set all nodes to show
            matrix[i][j]->setNodeIcon(); //set icon to actually be able to see it
        }
    }
}

coordGrid::~coordGrid()
{
    for (int i = 0; i < gridWidth; i++){
        for (int j = 0; j < gridHeight; j++){
            delete matrix[i][j];
        }
    }
}

QList<gridDot *> coordGrid::packageNodes()
{
    QList<gridDot*> package;
    for (int i = 0; i < gridWidth; i++){
        for (int j = 0; j < gridHeight; j++){
            if (matrix[i][j]->giveVisibility() == "g"){
                package.append(matrix[i][j]);
            }
        }
    }
    return package;
}


void coordGrid::excludeNode(int x, int y){
    matrix[x][y]->setVisibility(QString("r"));
}

/*
empty nodes to cut out [25][25]: too much work
(0,0) to (1,25)
(14,0) to (25, 13)


empty nodes to cut out [15][15]: more managable size
(0,0) to (0,14) far left
(8,0) to (14,6) empty top right
(5,0) to (7,3) northen pond

probably would be easier just to mark all the walkable node:
(1,1) to (12,12) diagonally, so (2,2), (3,3)...     Academic walk to Mineral king rd
    (3,5),(2,6)(1,7)     walkable part of Ansel Adams road
    (7,10),(8,9)    Academic to scholars lane shortcut
    (6,10),(7,9)(8,10)  ^^^^
(1,5) to (7,11) to (10,14) diagonally      Scholars lane (people in other housing units will have to start ar (10,14))
    (5,13),(6,12)   Scholar's to gym



locations[15][15]:
Gran: (10,11)       destination, not pathable (can go there but can't be used to go to other places)
GLCR: (10,10)       pathable
sentinel: (11,11)   pathable
El Portal: (13,12)  not pathable

Admin: (12,13)  pathable
SE1:(4,5)       not pathable
SE2: (5,5)      not pathable
SSM: (2,5)      not pathable
SSB: (1,6)      not pathable
COB1: (3,7)     pathable
COB2: (3,9)     pathable
BSP: (7,7)      pathable
ACS: (9,9)      pathable
SRE: (7,9)      not pathable


DC: (7,13)      not pathable
pav: (9,9)      pathable
gym: (6,12)     pathable
KL: (4,8)       pathable
Conference: (11,13) not pathable


*/
