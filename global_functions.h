#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H

#include <string>
#include <iostream>
using namespace std;

struct Race {
    string raceName;
    string defaultWeapon;
    double raceModifier;
};

Race chooseRace();

#endif // GLOBAL_FUNCTIONS_H
