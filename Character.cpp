#include "Character.h"


Character::Character()
{
    race = "";
    weapon = "";
    maxHealth = 0;
    baseDamage = 0;
    level = 0;
    health = maxHealth;
}

Character::Character(string race, string weapon, int level)
{
    this->race = race;
    this ->weapon = weapon;
    this->level = level;
    this->maxHealth = (20 * getRaceModifier(race) * getRaceModifier(race)) + (level * getRaceModifier(race) * 10);
    this->baseDamage = 20 + (getRaceModifier(race) * level);
    experience = (5 * getRaceModifier(race)) + (getRaceModifier(race) * level * level);
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
