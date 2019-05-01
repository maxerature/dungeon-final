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
}


void Dungeon::movePos(int direction)
{
    switch (direction) {
    case 0:
        playerPos.y_pos++;
        break;
    case 1:
        playerPos.y_pos--;
        break;
    case 2:
        playerPos.x_pos--;
        break;
    case 3:
        playerPos.x_pos++;
    }

    if (playerPos == exitPos) {
        cout << endl << endl << "You've reached the next level!" << endl << endl;
        generateDungeon();
    }
}

void Dungeon::Print()
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
