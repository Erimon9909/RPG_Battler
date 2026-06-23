#pragma once
#include "Item.h"

class Mirror:public Item{
    public:
        Mirror();
        void applyEffect(Character* self, Character* enemy, bool& blade) override;
};