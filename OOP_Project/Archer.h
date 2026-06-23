#pragma once
#include "Character.h"

class Archer:public Character{
    public:
        Archer(std::string name, std::string owner);
        int calcAttackDamage() override;
        int handleIncomingDamage(int rawDmg) override;
};