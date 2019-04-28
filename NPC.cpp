#include "NPC.h"


NPC::NPC(string name, Race race, int level) : Character(race, level)
{
    this->name = name;
    this->race = race;
    this->level = level;

}

string NPC::getName()
{
    return name;
}
