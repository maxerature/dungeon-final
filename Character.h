#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
public:
    Character();
    Character(string race, int maxHealth, double baseDamage, int level);
    double getBaseDamage();
    string getRace();
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

protected:
    double health;
    int maxHealth;
    int level;
    int experience;
    double baseDamage;
    string race;
    string weapon;
};

#endif // CHARACTER_H
