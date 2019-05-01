#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include "global_functions.h"

struct ItemPos {
    int x_pos;
    int y_pos;

    bool operator==(ItemPos &compared);
};
struct Dungeon {
    char dungeon[27][27];
    ItemPos playerPos;
    ItemPos exitPos;

    void Print();
    void generateDungeon();
    void movePos(int direction);
};


char generateDungeon(Dungeon &fungeon);


#endif // DUNGEONGENERATOR_H
