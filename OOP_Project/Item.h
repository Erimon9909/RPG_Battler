#pragma once
#include <iostream>
#include <cstdlib>

class Character;

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
        virtual void applyEffect(Character* self, Character* enemy, bool& blade) = 0;
};