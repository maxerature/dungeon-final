#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h".

class Enemy : public Character
{
public:
    Enemy(string race, string weapon, int level);
private:
    bool alive;
};

#endif // ENEMY_H
