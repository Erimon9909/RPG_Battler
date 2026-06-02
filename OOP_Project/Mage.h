#pragma once
#include "Character.h"

class Mage:public Character{
    public:
        Mage(std::string name, std::string owner);
        int calcAttackDamage() override;
        int handleIncomingDamage(int rawDmg) override;
};