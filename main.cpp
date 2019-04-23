#include <iostream>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
using namespace std;

double getRaceModifier(string race) {
if(race == "human"):
        return 1;
        break;
    case "dwarf":
        return 0.85;
        break;
    case "elf":
        return 1.15;
        break;
    case "tiefling":
        return 1;
        break;
    case "halfling":
        return 0.65;
        break;
    case "dragonborn":
        return 0.95;
        break;
    case "gnome":
        return 0.75;
        break;
    case "half-elf":
        return 1;
        break;
    case "half-orc":
        return 1.5;
        break;
    case "kobold":
        return ;
        break;
    case "beholder":
        return ;
        break;
    case "wight":
        return ;
        break;
    case "owlbear":
        return ;
        break;
    case "mind flayer":
        return ;
        break;
    case "stone troll":
        return ;
        break;
    case "frost troll":
        return ;
        break;
    case "fire elemental":
        return ;
        break;
    case "pseudodragon":
        return ;
        break;
    case "red dragon":
        return ;
        break;
    case "blue dragon":
        return ;
        break;
    }
}

int calculateDamage(Character &offensive, Character &defensive) {
    double base = offensive.getBaseDamage();
    string offensiveRace = offensive.getRace();
    string defensiveRace = defensive.getRace();
    double offensiveRaceModifier = getRaceModifier(offensiveRace);
    double defensiveRaceModifier = getRaceModifier(defensiveRace);
    
    

    
}



int main()
{
    cout << "Hello World!" << endl;
    return 1;
}
