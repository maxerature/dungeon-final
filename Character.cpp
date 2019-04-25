#include "Character.h"


Character::Character()
{
    race = {"none", "none", 0};
    weapon = "";
    maxHealth = 0;
    baseDamage = 0;
    level = 0;
    health = maxHealth;
}

Character::Character(Race race, int level)
{
    this->race = race;
    this ->weapon = race.defaultWeapon;
    this->level = level;
    this->maxHealth = (20 * race.raceModifier * race.raceModifier) + (level * race.raceModifier * 10);
    this->baseDamage = 20 + (race.raceModifier * level);
    experience = (5 * race.raceModifier) + (race.raceModifier * level * level);
    health = maxHealth;
}

double Character::getBaseDamage()
{
    return baseDamage;
}

Race Character::getRace()
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

