#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

#include <string>
using namespace std;

class Player : public Character
{
public:
    Player(string name, string race, string weapon);
    
private:
    bool hasKey;
    string name;
};

#endif // PLAYER_H
