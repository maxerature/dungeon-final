#ifndef CHARACTER_H
#define CHARACTER_H

#include <string.h>

class Character
{
public:
    Character();

protected:
    double health;
    int level;
    int experience;
    double baseDamage;
    string race;
    string weapon;
};

#endif // CHARACTER_H
