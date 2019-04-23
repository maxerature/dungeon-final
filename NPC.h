#ifndef NPC_H
#define NPC_H

#include "Character.h"

class NPC : public Character
{
public:
    NPC();
    
private:
    bool present;
    string name;
};

#endif // NPC_H
