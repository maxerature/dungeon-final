#include "Player.h"


Player::Player() :Character({"", "", 0}, 0)
{
    name = "";
    level = 0;
    experience = 0;
    XPToLevel = 0;
    hasKey = false;
}

Player::Player(string name, Race race, string weapon) : Character(race, 1)
{
    //this->race = race;
    this->name = name;
    this->race.defaultWeapon = weapon;
    level = 1;
    experience = 0;
    XPToLevel = 25;
    hasKey = false;
}

int Player::getXP()
{
    return experience;
}

int Player::getXPToLevel()
{
    return XPToLevel;
}

string Player::getName()
{
    return name;
}

void Player::setXP(int experience)
{
    this->experience = experience;
}


void Player::setXPToLevel(int XPToLevel)
{
    this->XPToLevel = XPToLevel;
}
