#ifndef NPC_H
#define NPC_H

#include "Character.h"

class NPC : public Character
{
public:
    NPC(string name, Race race, int level);
    string getName();
    
private:
    string name;
};

#endif // NPC_H
