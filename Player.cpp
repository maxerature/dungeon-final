#include "Player.h"


Player::Player(string name, Race race, string weapon) : Character(race, 1)
{
    //this->race = race;
    this->name = name;
    this->weapon = weapon;
    level = 1;
    experience = 0;
}
