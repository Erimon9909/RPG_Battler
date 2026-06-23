#pragma once
#include <iostream>

class Character{
    private:
        std::string name;
        std::string owner;
        int maxHp;
        int hp;
        int level;
        int minDmg;
        int maxDmg;
        int typeId;
    public:
        Character(std::string name, std::string owner, int hp, int minDmg, int maxDmg, int type);
        virtual ~Character() = default;
        std::string getName() const;
        int getMaxHp() const;
        int getCurrentHp() const;
        int getLevel() const;
        int getType() const;
        void setHp(int hp);
        void resetHp();
        void upgradeMaxHp();
        void upgradeDamage();
        void incrementLevel();
        virtual int calcAttackDamage() = 0;
        virtual int handleIncomingDamage(int rawDmg) = 0;
};