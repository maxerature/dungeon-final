#include <iostream>
#include <ctime>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
using namespace std;


double calculateDamage(Character &offensive, Character &defensive) {
    srand(time(0));
    double randValue = (((double) rand() / (RAND_MAX)) + 1) * 20;
    double damage = (randValue * offensive.getLevel() * offensive.getBaseDamage()/100 * (getRaceModifier(offensive.getRace()) /getRaceModifier(defensive.getRace())));
    return damage;
}

Player newPlayer() {
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

    Player player = Player(name, race, weapon);
    return player;
}

void enemyDefeated(Player &player, Character &enemy) {
    player.setExperience(player.getExperience() +  enemy.getExperience());
}

int main()
{
    NPC NPCS[3];

    Player player = newPlayer();
    Character enemy = Character("kobold", "claws", 1);

    enemyDefeated(player, enemy);
    cout << player.getExperience();
    return 0;
}

void battle(Player &player, NPC NPCS) {
    srand(time(0));
    int enemyCount = rand() % 4 + 1;
    Enemy *enemies[enemyCount] = {};
    for (int i = 0; i< enemyCount; i++) {
        //enemies[i] = Enemy();
    }
    while (true) {
        //bATTLE hAPPENS
    }



}
