#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

struct Race {
    string raceName;
    string defaultWeapon;
    double raceModifier;
};





Race chooseRace();
Race generateRace(int maxRace);
Race generateBossRace(int maxRace);

#endif // GLOBAL_FUNCTIONS_H
