#include <iostream>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
using namespace std;

double getRaceModifier(string race) {
    if(race == "human"){
        return 1;
    }
    if (race == "dwarf"){
        return 0.85;
    }
    if (race == "elf") {
        return 1.15;
    }
    if (race == "tiefling") {
        return 1;
    }
    if (race == "halfling") {
        return 0.65;
    }
    if (race == "dragonborn") {
        return 0.95;
    }
    if (race == "gnome") {
        return 0.75;
    }
    if (race == "half-elf") {
        return 1;
    }
    if (race == "half-orc") {
        return 1.5;
    }
    if (race == "kobold") {
        return 0.95;
    }
    if (race == "beholder") {
        return 3;
    }
    if (race == "wight") {
        return 1.05;
    }
    if (race == "owlbear") {
        return 1.115;
    }
    if (race == "mind flayer") {
        return 2.25;
    }
    if (race == "stone troll") {
        return 4;
    }
    if (race == "frost troll") {
        return 2.25;
    }
    if (race == "fire elemental") {
        return 1.55;
    }
    if (race == "pseudodragon") {
        return 0.95;
    }
    if (race == "red dragon") {
        return 6;
    }
    if (race == "blue dragon") {
        return 6;
    }
}

double calculateDamage(Character &offensive, Character &defensive) {
    srand(time(0));
    double randValue = (((double) rand() / (RAND_MAX)) + 1) * 20;
    double damage = (randValue * offensive.getLevel() * offensive.getBaseDamage()/100 * (getRaceModifier(offensive.getRace()) /getRaceModifier(defensive.getRace())));
    return damage;
}

Character newPlayer() {
    string name;
    string race;
    string weapon;
    int health;
    cout << "What is your name? ";
    getline(cin, name);
    cout << endl << "What race are you? ";
    getline(cin, race);
    cout << endl << "What is your weapon of choice? ";
    getline(cin, weapon);

    health = 20 * getRaceModifier(race);

    Character player = Character(race, health, 20, 1);
    player.setWeapon(weapon);
    return player;
}

void enemyDefeated(Character *player, Character &enemy) {
    player->setExperience(player->getExperience() + enemy.getExperience());
}

int main()
{
    Character player = newPlayer();
    Character enemy = Character("kobold", 20, 15, 1);
    cout << calculateDamage(player, enemy) << endl;
    return 0;
}
