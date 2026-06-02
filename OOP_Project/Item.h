#pragma once
#include <iostream>

class Item{
    private:
        std::string name;
        int xpCost;
        int typeId;
    public:
        Item(std::string name, int xp, int type);
        virtual ~Item();
        std::string getName() const;
        int getXpCost() const;
        int getItemType() const;
        virtual void applyEffect() = 0;
};