#pragma once
#include "Item.h"

class Blade: public Item{
    public:
        Blade();
        void applyEffect(Character* self, Character* enemy, bool& blade) override;
};