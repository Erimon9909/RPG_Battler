#pragma once
#include "Item.h"

class Mirror:public Item{
    public:
        Mirror();
        void applyEffect() override;
};