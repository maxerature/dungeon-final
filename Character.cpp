#include "Character.h"


Character::Character()
{
    race = "";
    maxHealth = 0;
    baseDamage = 0;
    level = 0;
    experience = 0;
    health = 0;
}

Character::Character(string race, int maxHealth, double baseDamage, int level)
{
    this->race = race;
    this->maxHealth = maxHealth;
    this->baseDamage = baseDamage;
    this->level = level;
    experience = 0;
    health = maxHealth;
}

double Character::getBaseDamage()
{
    return baseDamage;
}

string Character::getRace()
{
    return race;
}

string Character::getWeapon()
{
    return weapon;
}

int Character::getLevel()
{
    return level;
}

int Character::getMaxHealth()
{
    return maxHealth;
}

double Character::getHealth()
{
    return health;
}

int Character::getExperience()
{
    return experience;
}

void Character::setLevel(int tempLevel)
{
    level = tempLevel;
}

void Character::setHealth(double tempHealth)
{
    health = tempHealth;
}

void Character::setMaxHealth(int tempMaxHealth)
{
    maxHealth = tempMaxHealth;
}

void Character::setWeapon(string tempWeapon)
{
    weapon = tempWeapon;
}

void Character::setExperience(int tempExperience)
{
    experience = tempExperience;
}
