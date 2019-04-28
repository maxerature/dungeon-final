#include "global_functions.h"


Race chooseRace() {
    Race races[20] = {
        {"human", "sword", 1},
        {"dwarf", "war axe", 1.15},
        {"elf", "bow", 1.05},
        {"tiefling", "rapier", 1},
        {"dragonborn", "great sword", 1.05},
        {"gnome", "dirk", 0.75},
        {"half elf", "crossbow", 1},
        {"half orc", "greataxe", 1.4},
        {"kobold", "claws", 0.95},
        {"halfling", "crossbow", 0.65},
        {"beholder", "eye ray", 3},
        {"wight", "longsword", 1.05},
        {"owlbear", "claws", 1.125},
        {"mind flayer", "psionics", 2.25},
        {"stone troll", "boulder", 4},
        {"frost troll", "massive fists", 2.25},
        {"fire elemental", "fire breath", 1.55},
        {"pseudodragon", "psionics", 0.95},
        {"red dragon", "fire breath", 6},
        {"blue dragon", "claws", 6},
    };

    string chosenRace;
    while (true) {
        getline(cin, chosenRace);

        for(int i = 0; i < 21; i++) {
            if(races[i].raceName == chosenRace) {
                return races[i];
            }
        }
        cout << "Chosen race does not exist.  Please try again." << endl;
    }
}
