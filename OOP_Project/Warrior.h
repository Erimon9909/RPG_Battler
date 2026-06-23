#pragma once
#include "Character.h"

class Warrior:public Character{
    public:
        Warrior(std::string name, std::string owner);
        int calcAttackDamage() override;
        int handleIncomingDamage(int rawDmg) override;
};