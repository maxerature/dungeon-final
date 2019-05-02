#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include "global_functions.h"
#include "Player.h"
#include "NPC.h"

struct ItemPos {
    int x_pos;
    int y_pos;

    bool operator==(ItemPos &compared);
};
struct Dungeon {
    char dungeon[27][27];
    ItemPos playerPos;
    ItemPos exitPos;
    ItemPos keyPos[5];

    void Print(Player *player, NPC *NPCS[3], int &NPC_NUM, int keys);
    void generateDungeon();
    void movePos(int direction, int &keys);
};


char generateDungeon(Dungeon &fungeon);


#endif // DUNGEONGENERATOR_H
