#include "Player.h"
#include <iostream>

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
    this->name = name;
    this->race.defaultWeapon = weapon;
    this->baseDamage = 20 + (race.raceModifier * level);
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

bool Player::getHasKey()
{
	return hasKey;
}

void Player::levelUp()
{
    experience -= XPToLevel;
    level++;
    XPToLevel *= level;

    int choice;

    cout << endl << endl << "Increase Health or damage?" <<
            endl <<         "Health:  [0]    Damage [1]" <<
            endl << endl;

    while(true) {
        cin >> choice;
        if (choice == 0) {
            maxHealth += (level * race.raceModifier * 10);
            break;
        }
        else if (choice == 1) {
            baseDamage += (race.raceModifier * level);
            break;
        }
    }
    health = maxHealth;
    srand(time(0));
    choice = level + (rand() % 10);
    if (choice >= 12) {
        hasKey = true;
    }
}
