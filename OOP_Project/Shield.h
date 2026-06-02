#pragma once
#include "Item.h"

class Shield:public Item{
    public:
        Shield();
        void applyEffect(Character* self, Character* enemy, bool& blade) override;
};