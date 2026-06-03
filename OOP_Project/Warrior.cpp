#include "Warrior.h"
#include <cstdlib>

Warrior::Warrior(std::string name, std::string owner): Character(name, owner, 20, 1, 8, 1)
{
}

int Warrior::calcAttackDamage()
{
    return rand() % 8 + 1;
}

int Warrior::handleIncomingDamage(int rawDmg)
{
    return rawDmg - (rand() % 4 + 1);
}
