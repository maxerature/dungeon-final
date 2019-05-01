#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

#include <string>
#include <time.h>

using namespace std;

class Player : public Character
{
public:
    Player();
    Player(string name, Race race, string weapon);
    int getXP();
    int getXPToLevel();
    string getName();

    void setXP(int experience);
    void setXPToLevel(int XPToLevel);

    void levelUp();

private:
    bool hasKey;
    string name;
    int XPToLevel;
};

#endif // PLAYER_H
