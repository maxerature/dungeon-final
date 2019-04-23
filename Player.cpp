#include "Player.h"


Player::Player(string name, string race, string weapon, int health, int level)
{
    this->name = name;
    this->race = race;
    this->weapon = weapon;
    this->maxHealth = health;
    this->level = level;
    this->health = health;
}
