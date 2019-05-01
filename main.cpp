#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"

using namespace std;

void saveGame(Player *player, NPC *party[3], int NPC_NUM) {
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
    saveFile << "PARTY" << endl << NPC_NUM << endl;
    for (int i = 0; i < NPC_NUM; i++) {
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
    cout << "What is your race? " << endl;
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
            cout << party[i]->getName() << " did " << damage << " damage to the " << enemies[selection]->getRace().raceName << " with their " << party[i]->getRace().defaultWeapon << "!" << endl;
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
        cout << endl;
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

void wait(Player *player, NPC *party[3], int NPC_NUM, int &survivors) {
    int hours;
    double addHealth;
    cout << endl << endl << "You choose to rest and tend to your wounds." << endl <<
            "How long will you choose to rest?" << endl <<
            "[Enter how many hours to rest]: ";
    cin >> hours;

    addHealth = (hours * player->getMaxHealth()) / 100;
    player->setHealth(player->getHealth()+ addHealth);
    if (player->getHealth() > player->getMaxHealth()) {
        player->setHealth(player->getMaxHealth());
    }
    for (int i = 0; i < NPC_NUM; i++) {
        addHealth = (hours * party[i]->getMaxHealth()) / 100;
        party[i]->setHealth(party[i]->getHealth()+ addHealth);
        if (party[i]->getHealth() > party[i]->getMaxHealth()) {
            party[i]->setHealth(party[i]->getMaxHealth());
        }
    }
    if (hours > 1) {
        survivors -= (((rand() % (hours/2)+1)) * survivors) / 100;
    }
    else {
        survivors -= survivors / 100;
    }
}

void tellStory() {
    cout << "The Wheel of Time turns, and Ages come and pass," << endl <<
            "leaving memories that become legend. Legend fades to myth," << endl <<
            "and even myth is long forgotten when the Age that gave it birth comes again." << endl << endl <<
            "In one age, called the Seventh Age by some, an Age yet to come, an Age long past," << endl <<
            "a wind rose in the mountains of Mordenkainen.  The wind was not the beginning." << endl <<
            "There are neither beginnings nor endings to the turning of the Wheel of Time." << endl <<
            "But it was ~a~ beginning." << endl << endl <<
            "Born in the lands of the lord who gave the mountains their name, the wind " << endl <<
            "blew west, across the Serpent Hills, once thought to be the corpse of a long dead" << endl <<
            "monster, through the dense woods of the Far Forest, and eventually into the" << endl <<
            "window of an old, seldom used inn's common room.  There, many men, all elders" << endl <<
            "above the age of 200, were gathered around an unlikely person." << endl << endl <<
            "\"Go!\" the eldest says, \"This plague will spell our doom, would you be" << endl <<
            "unable to retrieve it's cure.  You must go to the ruins of the Cursed City Riverhelm" << endl <<
            "and brave it's depths, for our town shall surely die otherwise.\n" << endl << endl <<
            "Another elder chimes in \"And be quick, for many will die in the time" << endl <<
            "it takes to retrieve the cure!  Go, and save as many of us as you can!" << endl << endl << endl << endl;
}

int gameLoop(Player *player, NPC *NPCS[3], int &NPC_NUM) {
    int survivors = 10000;
    int selection;
    int count;
    cout << "Your Town has 10,000 People alive.  You must try to save as many as possible, by being as quick as possible." << endl << endl;
    while (true) {
        cout << endl << endl <<
                player->getName() << "[" << player->getHealth() << "/" << player->getMaxHealth() << "]" << "       ";
                for (int i = 0; i < NPC_NUM; i++) {
                    cout << NPCS[i]->getName() << "[" << NPCS[i]->getHealth() << "/" << NPCS[i]->getMaxHealth() << "]        ";
                    if (i == 0) cout << endl;
                }
	
        cout << endl << endl <<
                "Will you:" << endl <<
                "[0]: Keep going" << endl <<
                "[1]: Rest" << endl <<
                "[2]: Save and Quit" << endl;
        cin >> selection;

        switch (selection) {
        case 0:
            cout << "You move forwards" << endl << endl << "Enemies ambush you!" << endl << endl;
            battle(player, NPCS, NPC_NUM);
            break;
        case 1:
            wait(player, NPCS, NPC_NUM, survivors);
            break;
        case 2:
            saveGame(player, NPCS, NPC_NUM);
            cout << "Game saved." << endl << endl << "Press any key to exit.";
            cin.ignore();
            exit(0);
            break;
        }
        cout << endl << endl << endl << "There are " << survivors << " survivors in your town!";
        if (survivors > 5000) cout << endl << "You had better hurry!" << endl;
        else if (survivors > 2500) cout << endl << "You wonder how your family is." << endl;
        else if (survivors > 1500) cout << endl << "There is little time left." << endl;
        else if (survivors > 750) cout << endl << "You know your family is dead.  What reason is there to continue?" << endl;
        else if (survivors > 250) cout << endl << "The darkness gets stronger." << endl;
        else if (survivors > 200) cout << endl << "The darkness gets deeper." << endl;
        else if (survivors > 150) cout << endl << "Maybe you should join the dead." << endl << endl << endl << "The darkness gets sweeter";
        else if (survivors > 100) cout << endl << "The darkness calls." << endl;
        else if (survivors > 50) cout << endl << "The darkness has arrived" << endl;
        else if (survivors > 25) cout << endl << "There is only darnkess" << endl;
        else if (survivors == 0) {
            cout << endl << endl << "You have failed, and your village has perished." <<
                    endl << endl << "You decide to join them." << endl <<
                    endl << endl << "GAME OVER";
            cin.ignore();
            exit(0);
        }
    }
}


int main()
{
    tellStory();
    srand(time(0));
    NPC *CurrentNPCS[3];
    int NPC_NUM = 0;

    Player player = newPlayer();
    //Player player = Player();
    //loadGame(player, CurrentNPCS, NPC_NUM);
    Player *playerPtr = &player;
    gameLoop(playerPtr, CurrentNPCS, NPC_NUM);
    while(true) {
        battle(playerPtr, CurrentNPCS, NPC_NUM);
    }

    return 0;
}
