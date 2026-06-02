#pragma once
#include "Item.h"

class Blade: public Item{
    public:
        Blade();
        void applyEffect() override;
};