#include "NPC.h"


NPC::NPC(string name, Race race, int level) : Character(race, level)
{
    this->name = name;

}

NPC::NPC(Enemy *Copied) : Character(Copied->getRace(), Copied->getLevel())
{
    string tempName;
    cout << endl << endl <<
            "A defeated monster would like to join you!" << endl <<
            "It needs a name.  What will you name it? ";
    cin >> tempName;

    this->name = tempName;

    cout << endl << name << " joined the party!" << endl << endl;

}

string NPC::getName()
{
    return name;
}
