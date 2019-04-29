#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"

using namespace std;

void saveGame(Player *player, NPC *party[3], int NUM_NPC) {
    ofstream saveFile;
    string saveName = "saveFile.txt";

    saveFile.open(saveName);

    saveFile << "PLAYER" << endl <<
                player->getName() << endl <<
                player->getRace().raceName << endl <<
                player->getRace().raceModifier << endl <<
                player->getRace().defaultWeapon << endl <<
                player->getXPToLevel() << endl <<
                player->getXP() << endl <<
                player->getMaxHealth() << endl <<
                player->getHealth() << endl <<
                player->getLevel() << endl <<
                player->getBaseDamage() << endl;
    saveFile << "PARTY" << endl << NUM_NPC << endl;
    for (int i = 0; i < NUM_NPC; i++) {
        saveFile << party[i]->getName() << endl <<
                    party[i]->getRace().raceName << endl <<
                    party[i]->getRace().raceModifier << endl <<
                    party[i]->getRace().defaultWeapon << endl <<
                    party[i]->getMaxHealth() << endl <<
                    party[i]->getHealth() << endl <<
                    party[i]->getLevel() << endl <<
                    party[i]->getBaseDamage() << endl;
    }

}

void loadGame(Player &player, NPC *NPCS[3], int &NPC_NUM) {
    ifstream saveFile;
    string saveName = "saveFile.txt";

    saveFile.open(saveName);

    string tempName;
    string tempRaceName;
    double tempRaceMod;
    string tempRaceWeapon;

    int tempXPToLevel;
    int tempXP;

    int tempMaxHealth;
    double tempHealth;

    int tempLevel;
    double tempBaseDamage;

    string line;

    getline(saveFile, line);
    if (line == "PLAYER") {
        getline(saveFile, tempName);
        getline(saveFile, tempRaceName);
        saveFile >> tempRaceMod;
        getline(saveFile, line);  //Gets to new line
        getline(saveFile, tempRaceWeapon);
        saveFile >> tempXPToLevel;
        getline(saveFile, line);
        saveFile >> tempXP;
        getline(saveFile, line);
        saveFile >> tempMaxHealth;
        getline(saveFile, line);
        saveFile >> tempHealth;
        getline(saveFile, line);
        saveFile >> tempLevel;
        getline(saveFile, line);
        saveFile >> tempBaseDamage;
        getline(saveFile, line);

        player = Player(tempName,{tempRaceName, tempRaceWeapon, tempRaceMod}, tempRaceWeapon);
        player.setXPToLevel(tempXPToLevel);
        player.setXP(tempXP);
        player.setMaxHealth(tempMaxHealth);
        player.setHealth(tempHealth);
        player.setLevel(tempLevel);
        player.setBaseDamage(tempBaseDamage);
    }

    saveFile >> line;
    if (line == "PARTY") {
        saveFile >> NPC_NUM;
        getline(saveFile, line);
        for (int i = 0; i < NPC_NUM; i++) {
            getline(saveFile, tempName);
            getline(saveFile, tempRaceName);
            saveFile >> tempRaceMod;
            getline(saveFile, line);
            getline(saveFile, tempRaceWeapon);
            saveFile >> tempMaxHealth;
            getline(saveFile, line);
            saveFile >> tempHealth;
            getline(saveFile, line);
            saveFile >> tempLevel;
            getline(saveFile, line);
            saveFile >> tempBaseDamage;
            getline(saveFile, line);

            NPCS[i] = new NPC(tempName, {tempRaceName, tempRaceWeapon, tempRaceMod}, tempLevel);
            NPCS[i]->setHealth(tempHealth);
            NPCS[i]->setMaxHealth(tempMaxHealth);
            NPCS[i]->setBaseDamage(tempBaseDamage);
        }
    }
}




template<typename offence, typename defence>
double calculateDamage(offence offensive, defence defensive) {
    double randValue = (((double) rand() / (RAND_MAX)) + 1) * 20;
    double damage = (randValue * offensive->getLevel() * offensive->getBaseDamage()/100 * offensive->getRace().raceModifier) /(defensive->getRace().raceModifier);
    return damage;
}

Player newPlayer() {
    string name;
    Race race;
    string weapon;
    cout << "What is your name? ";
    getline(cin, name);
    cout << "What is your race? ";
    race = chooseRace();
    cout << endl << "What is your weapon of choice? ";
    getline(cin, weapon);

    Player player = Player(name, race, weapon);

    cout << endl << endl << endl << endl << endl << endl;
    return player;
}

void enemyDefeated(Player *player, Enemy *enemy, NPC *NPCS[3], int &NPC_NUM) {
    player->setExperience(player->getExperience() +  enemy->getExperience());
    cout << endl << "You gain " << enemy->getExperience() << " EXP!" << endl;

    if (player->getXP() > player->getXPToLevel()) {
        player->levelUp();
    }


    int joinChance;

    joinChance = (3 - NPC_NUM) * (rand() % 100 + 1);
    if (joinChance >= 75) {
        NPCS[NPC_NUM] = new NPC(enemy);
        NPC_NUM++;
    }
    delete enemy;
}

template <typename allyType>
void allyDamaged(allyType *ally, Enemy *enemy, string type, NPC *party[3], int &NPC_NUM, int selection) {
    double damage = calculateDamage(enemy, ally);
    double damagedHealth = ally->getHealth();
    damagedHealth -= damage;
    ally->setHealth(damagedHealth);

    cout << "The " << enemy->getRace().raceName << " did " << damage << " damage to " << ally->getName() << " with their " << enemy->getRace().defaultWeapon << "!" << endl;

    if (damagedHealth <= 0) {
        if (type == "player") {
        cout << endl << "You have been killed.  Game over.  Press enter to exit" << endl;
        cin.ignore();
        exit(0);
        }
        else if (type == "NPC") {
            cout << endl << party[selection]->getName() << " has been critically injured!  They choose to stay behind to heal up." << endl << "They may come back later." << endl;
            for (int i = selection; i< NPC_NUM; i++) {
                party[i] = party[i+1];
            }
            NPC_NUM--;
        }
    }
}



void battle(Player *player, NPC *party[3], int &NPC_NUM) {
    int enemyCount;
    if (player->getLevel() == 1) {
        enemyCount = rand() % 2 + 1;
    }
    else if (player->getLevel() == 2) {
        enemyCount = rand() % 3 + 1;
    }
    else {
        enemyCount = rand() % 4 + 1;
    }
    int selection;
    double damage;
    double damagedHealth;
    Enemy *enemies[4] = {};
    for (int i = 0; i< enemyCount; i++) {
        enemies[i] = new Enemy(generateRace(14), player->getLevel());
    }
    while (true) {
        //bATTLE hAPPENS

        //Player always goes first

        cout << endl << endl << endl << player->getName() << "[" << player->getHealth() << "/" << player->getMaxHealth() << "]" << "       ";
        for (int i = 0; i < NPC_NUM; i++) {
            cout << party[i]->getName() << "[" << party[i]->getHealth() << "/" << party[i]->getMaxHealth() << "]        ";
            if (i == 0) cout << endl;
        }
        cout << endl;
        cout << "------ENEMIES------" << endl;
        for(int i = 0; i < enemyCount; i++) {
            cout << "[" << i << "]    " << enemies[i]->getRace().raceName << "      HP[" << fixed << setprecision(3) << enemies[i]->getHealth() << "/" << enemies[i]->getMaxHealth() << "]" << endl;
        }
        cout << endl << "Choose which enemy to attack: ";
        cin >> selection;


        damage = calculateDamage(player, enemies[selection]);
        damagedHealth = enemies[selection]->getHealth();
        damagedHealth -= damage;
        enemies[selection]->setHealth(damagedHealth);
        cout << endl << endl << "You did " << fixed << setprecision(3) << damage << " damage to the " << enemies[selection]->getRace().raceName << " with your " << player->getRace().defaultWeapon << "!" << endl;
        if (damagedHealth <= 0) {
            cout << endl << "You have killed the " << enemies[selection]->getRace().raceName << "!" << endl;
            enemyDefeated(player, enemies[selection], party, NPC_NUM);

            for (int i = selection; i< enemyCount; i++) {
                enemies[i] = enemies[i+1];
            }
            enemyCount--;
        }

        if (enemyCount == 0) {
            cout << endl << endl << "All enemies are dead!  You win!" << endl <<
                    "Experience: [" << player->getXP() << "/" << player->getXPToLevel() << "]" <<
                    endl << endl << endl;
            return;
        }

        //NPC turns

        for(int i = 0; i < NPC_NUM; i++) {
            selection = rand() % enemyCount;
            damage = calculateDamage(party[i], enemies[selection]);
            damagedHealth = enemies[selection]->getHealth();
            damagedHealth -= damage;
            enemies[selection]->setHealth(damagedHealth);
            cout << endl << party[i]->getName() << " did " << damage << " damage to the " << enemies[selection]->getRace().raceName << " with their " << party[i]->getRace().defaultWeapon << "!" << endl;
            if (damagedHealth <= 0) {
                cout << endl << "You have killed the " << enemies[selection]->getRace().raceName << "!" << endl;
                enemyDefeated(player, enemies[selection], party, NPC_NUM);

                for (int i = selection; i< enemyCount; i++) {
                    enemies[i] = enemies[i+1];
                }
                enemyCount--;
            }
            if (enemyCount == 0) {
                cout << endl << endl << "All enemies are dead!  You win!" << endl <<
                        "Experience: [" << player->getXP() << "/" << player->getXPToLevel() << "]" <<
                        endl << endl << endl;
                return;
            }
        }

        // Enemy turns

        for (int i = 0; i < enemyCount; i++) {
            if (NPC_NUM == 0) {
                allyDamaged(player, enemies[i], "player", party, NPC_NUM, -1);
            }
            if (NPC_NUM > 0) {
                selection = rand() % (NPC_NUM+1);
                if (selection != (NPC_NUM)) {
                    allyDamaged(party[selection], enemies[i], "NPC", party, NPC_NUM, selection);
                }
                else if (selection == NPC_NUM) {
                    allyDamaged(player, enemies[i], "player", party, NPC_NUM, -1);
                }
            }
        }
    }
}


int main()
{
    srand(time(0));
    NPC *CurrentNPCS[3];
    int NPC_NUM = 0;

    Player player = newPlayer();
    //Player player = Player();
    //loadGame(player, CurrentNPCS, NPC_NUM);
    Player *playerPtr = &player;
    while(true) {
        battle(playerPtr, CurrentNPCS, NPC_NUM);
    }

    return 0;
}
