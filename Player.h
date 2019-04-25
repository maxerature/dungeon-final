#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

#include <string>
using namespace std;

class Player : public Character
{
public:
    Player(string name, Race race, string weapon);
    int getXP();
    int getXPToGo();
    string getName();

private:
    bool hasKey;
    string name;
    int XPToGo;
};

#endif // PLAYER_H
