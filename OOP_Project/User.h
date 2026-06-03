#pragma once 
#include <iostream>
#include <vector>
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
        User(std::string username, std::string pass);
        ~User();
        std::string getUsername() const;
        std::string getPassword();
        int getTotalXp() const;
        int getCurrentXp() const;
        int getBattlesPlayed() const;
        int getBattlesWon() const;
        double getWinRate() const;
        std::vector<Character*> getCharacters();
        std::vector<Item*> getItems();
        void addXp(int amount);
        bool spendXp(int amount);
        void addCharacter(Character* c);
        void addItem(Item* i);
        void removeItem(int index);
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