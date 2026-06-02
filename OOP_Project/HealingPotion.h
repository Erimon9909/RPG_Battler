#pragma once
#include "Item.h"

class HealingPotion: public Item{
    private:
        int minHeal;
        int maxHeal;
    public:
        HealingPotion();
        void applyEffect() override;
};