#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{
public:
    Enemy(Race race, int level);
};

#endif // ENEMY_H
