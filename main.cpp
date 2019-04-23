#include <iostream>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
using namespace std;

int calculateDamage(Character &offensive) {
    double base = offensive.getBaseDamage();
    string race = offensive.getRace();
    double raceModifier;

    switch (race) {
        case "human":
            raceModifier = 1;
            break;
        case "dwarf":
            raceModifier = 0.85;
            break;
        case "elf":
            raceModifier = 1.15;
            break;
        case "tiefling":
            raceModifier = 1;
            break;
        case "halfling":
            raceModifier = 0.65;
            break;
        case "dragonborn":
            raceModifier = 0.95;
            break;
        case "gnome":
            raceModifier = 0.75;
            break;
        case "half-elf":
            raceModifier = 1;
            break;
        case "half-orc":
            raceModifier = 1.5;
            break;
    }
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
