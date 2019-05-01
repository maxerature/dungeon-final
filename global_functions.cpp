#include "global_functions.h"

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
    {"fire elemental", "fire breath", 1.55},
    {"pseudodragon", "psionics", 0.95},
    {"wight", "longsword", 1.05},
    {"owlbear", "claws", 1.125},
    {"mind flayer", "psionics", 2.25},
    {"beholder", "eye ray", 3},
    {"stone troll", "boulder", 4},
    {"frost troll", "massive fists", 2.25},
    {"red dragon", "fire breath", 6},
    {"blue dragon", "claws", 6},
};

Race chooseRace() {
    int chosenRace;
    for (int i = 0; i < 8; i++) {
        cout << "[" << i << "]: " << races[i].raceName << endl;
    }
    while (true) {
        cin >> chosenRace;
        if (chosenRace >=0 && chosenRace <= 7) {
            return races[chosenRace];
        }
        cout << "Chosen race is unavailable.  Please try again." << endl;
    }
}

Race generateRace(int maxRace)
{
    int raceNum = rand() % maxRace;

    return races[raceNum];
}

Race generateBossRace(int maxRace)
{
    int raceNum = rand() % maxRace + 14;
    return races[raceNum];
}
