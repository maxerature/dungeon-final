#include "Enemy.h"

Enemy::Enemy(string race, string weapon, int level)
{
    Character(race, weapon, level);
    alive = true;
}
