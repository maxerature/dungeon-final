#include "Player.h"


Player::Player(string name, Race race, string weapon) : Character(race, 1)
{
    //this->race = race;
    this->name = name;
    this->weapon = weapon;
    level = 1;
    experience = 0;
    XPToGo = 25;
    hasKey = false;
}

int Player::getXP()
{
    return experience;
}

int Player::getXPToGo()
{
    return XPToGo;
}

string Player::getName()
{
    return name;
}
