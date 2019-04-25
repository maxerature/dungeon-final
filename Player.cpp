#include "Player.h"


Player::Player(string name, string race, string weapon)
{
    this->name = name;
    experience = 0;
    Character(race, weapon, 1);
}
