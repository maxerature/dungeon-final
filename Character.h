#ifndef CHARACTER_H
#define CHARACTER_H

#include <global_functions.h>
using namespace std;

class Character
{
public:
    Character();
    Character(Race race, int level);
    double getBaseDamage();
    Race getRace();
    string getWeapon();
    int getLevel();
    int getMaxHealth();
    double getHealth();
    int getExperience();

    void setLevel(int);
    void setHealth(double);
    void setMaxHealth(int);
    void setWeapon(string);
    void setExperience(int);

    void takeDamage(int);

    bool alive = true;
protected:
    double health;
    int maxHealth;
    int level;
    int experience;
    double baseDamage;
    Race race;
    string weapon;

};

#endif // CHARACTER_H
