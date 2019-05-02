#include "dungeonGenerator.h"


void Dungeon::generateDungeon() {

    for(int i = 0; i < 27; i++){
        for(int j = 0; j < 27; j++) {
            dungeon[i][j] = 219;
        }
        cout << endl;
    }

    int row;
    int column;
    int moveDir;
    int counter = 0;

    row = rand() % 24+1;
    column = rand() % 24+1;

    dungeon[row][column] = ' ';
    playerPos.x_pos = column;
    playerPos.y_pos = row;

    while(counter < 300) {
        moveDir = rand() % 4;

        switch (moveDir) {
        case 0:  //Move Up
            if (row != 1) {
                row--;
                if (dungeon [row][column] != ' ' && dungeon [row][column] != '@') {
                    dungeon[row][column] = ' ';
                    counter++;
                    break;
                }
            }
            break;
        case 1: //Move down
            if (row != 25) {
                row++;
                if (dungeon [row][column] != ' ' && dungeon [row][column] != '@') {
                    dungeon[row][column] = ' ';
                    counter++;
                    break;
                }
            }
            break;
        case 2: //Move left
            if (column != 1) {
                column--;
                if (dungeon [row][column] != ' ' && dungeon [row][column] != '@') {
                    dungeon[row][column] = ' ';
                    counter++;
                    break;
                }
            }
            break;
        case 3: //Move right
            if (column != 24) {
                column++;
                if (dungeon [row][column] != ' ' && dungeon [row][column] != '@') {
                    dungeon[row][column] = ' ';
                    counter++;
                    break;
                }
            }
        case 4:
            while (true) {
                row = rand() % 25;
                column = rand() % 25;
                if (dungeon[row][column] == ' ' && dungeon [row][column] != '@') {
                    counter++;
                    break;
                }
            }
        }
    }

    dungeon[row][column] = 239;
    exitPos.x_pos = column;
    exitPos.y_pos = row;

    for (int i = 0; i < 5; i++) {
        row = rand() % 24 + 1;
        column = rand() % 24 + 1;
        if (dungeon[row][column] == ' ') {
            dungeon[row][column] = 157;
            keyPos[i].x_pos = column;
            keyPos[i].y_pos = row;
        }
    }
}


void Dungeon::movePos(int direction, int & keys)
{
    switch (direction) {
    case 0:
        if(dungeon[playerPos.y_pos + 1][playerPos.x_pos] != dungeon[0][0]) {
            playerPos.y_pos++;
        }
        break;
    case 1:
        if(dungeon[playerPos.y_pos- 1][playerPos.x_pos] != dungeon[0][0]) {
            playerPos.y_pos--;
        }
        break;
    case 2:
        if(dungeon[playerPos.y_pos][playerPos.x_pos - 1] != dungeon[0][0]) {
            playerPos.x_pos--;
        }
        break;
    case 3:
        if(dungeon[playerPos.y_pos][playerPos.x_pos + 1] != dungeon[0][0]) {
            playerPos.x_pos++;
        }
        break;
    }

    if (playerPos == exitPos) {
        cout << endl << endl << "You've reached the next level!" << endl << endl;
        generateDungeon();
    }
    for (int i = 0; i < 5; i++) {
        if (playerPos == keyPos[i]) {
            keys++;
            dungeon[playerPos.y_pos][playerPos.x_pos] = ' ';
        }
    }
}

void Dungeon::Print(Player *player, NPC *NPCS[3], int &NPC_NUM, int keys)
{
    for(int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            if (i == playerPos.y_pos && j == playerPos.x_pos) {
                cout << '@';
            }
            else {
                cout << dungeon[i][j];
            }
        }
        if(i == 0) {
            cout << "           " << player->getName() << "[" << player->getHealth() << "/" << player->getMaxHealth() << "]" << "       ";
            if (NPC_NUM >= 1) {
                cout << "           " << NPCS[0]->getName() << "[" << NPCS[0]->getHealth() << "/" << NPCS[0]->getMaxHealth() << "]        ";
            }
        }
        if (i == 1) {
            if (NPC_NUM >= 2) {
                cout << "           " << NPCS[1]->getName() << "[" << NPCS[1]->getHealth() << "/" << NPCS[1]->getMaxHealth() << "]        ";
            }
            if (NPC_NUM >= 3) {
                cout << "           " << NPCS[2]->getName() << "[" << NPCS[2]->getHealth() << "/" << NPCS[2]->getMaxHealth() << "]        ";
            }
        }
        if (i == 3) {
            cout << "           KEY FRAGMENTS: [" << keys << "/200]";
        }
        if (i == 3) {
            cout << "           --INSTRUCTIONS--";
        }
        if (i == 4) {
            cout << "           [ARROW KEYS]: Move";
        }
        if (i == 5) {
            cout << "           [ENTER]: Rest";
        }
        if (i == 6) {
            cout << "           [ESCAPE]: Save and quit";
        }
        if (i == 7) {
            cout << "           " << (char)239 << " = Stairs to next floor";
        }
        if (i == 8) {
            cout << "           @ = Player";
        }
        if (i == 9) {
            cout << "           " << char(157) << " = Key Fragment";
        }
        cout << endl;
    }
}

bool ItemPos::operator==(ItemPos &compared)
{
    if (compared.x_pos == this->x_pos && compared.y_pos == this->y_pos) {
        return true;
    }
    return false;
}
