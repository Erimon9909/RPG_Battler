#pragma once 
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Character.h"
#include "Item.h"

class User{
    private:
        std::string username;
        std::string password;
        int totalXpEarned;
        int currentXp;
        int battlesPlayed;
        int battlesWon;
        std::vector<Character*> characters;
        std::vector<Item*> items;
    public:
        User(const std::string& username, const std::string& pass);
        ~User();
        std::string getUsername() const;
        std::string getPassword() const;
        int getTotalXp() const;
        int getCurrentXp() const;
        int getBattlesPlayed() const;
        int getBattlesWon() const;
        double getWinRate() const;
        std::vector<Character*>& getCharacters();
        std::vector<Item*>& getItems();
        void addXp(int amount);
        bool spendXp(int amount);
        void addCharacter(Character* c);
        Character* findCharacter(const std::function<bool (const Character&)>& pred);
        Item* findItem(const std::function<bool (const Item&)>& pred);
        void addItem(Item* i);
        void removeItem(int index);
        int countItemsIf(const std::function<bool(const Item&)>& pred) const;
        void incrementBattles(bool won);
        std::partial_ordering operator<=>(const User& other)const{
            if(auto cmp = this->battlesWon <=> other.battlesWon; cmp != 0){
                return cmp;
            }
            if(auto cmp = this->totalXpEarned <=> other.totalXpEarned; cmp != 0){
                return cmp;
            }

            return this->getWinRate() <=> other.getWinRate();
        }
};