#ifndef NPC_H
#define NPC_H

#include <string>
#include "Character.h"
#include "Enemy.h"

using namespace std;

class NPC : public Character
{
public:
    NPC(string name, Race race, int level);
    NPC(Enemy *Copied);
    string getName();
    
private:
    string name;
};

#endif // NPC_H
