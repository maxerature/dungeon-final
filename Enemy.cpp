#include "Enemy.h"

Enemy::Enemy(Race race, int level)
{
    Character(race, level);
    alive = true;
}
