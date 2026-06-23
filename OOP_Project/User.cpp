#include "User.h"

User::User(const std::string& username, const std::string& pass)
{
    this->username = username;
    this->password = pass;
    this->totalXpEarned = 0;
    this->currentXp = 0;
    this->battlesPlayed = 0;
    this->battlesWon = 0;
}

User::~User()
{
    characters.clear();
    items.clear();
}

std::string User::getUsername() const
{
    return this->username;
}

std::string User::getPassword() const
{
    return this->password;
}

int User::getTotalXp() const
{
    return this->totalXpEarned;
}

int User::getCurrentXp() const
{
    return this->currentXp;
}

int User::getBattlesPlayed() const
{
    return this->battlesPlayed;
}

int User::getBattlesWon() const
{
    return this->battlesWon;
}

double User::getWinRate() const
{
    if (this->battlesPlayed == 0) return 0.0; // Prevent crash
    return static_cast<double>(this->battlesWon) / this->battlesPlayed;
}

std::vector<Character *>& User::getCharacters()
{
    return characters;
}

std::vector<Item *>& User::getItems()
{
    return items;
}

void User::addXp(int amount)
{
    this->currentXp += amount;
    this->totalXpEarned += amount;
}

bool User::spendXp(int amount)
{
    if(amount < this->currentXp){
        currentXp -= amount;
        return true;
    }

    return false;
}

void User::addCharacter(Character *c)
{
    characters.push_back(c);
}

Character *User::findCharacter(const std::function<bool(const Character &)> &pred)
{
    auto it = std::find_if(characters.begin(), characters.end(),[&pred](Character* c) { return pred(*c); });
    
    return (it != characters.end()) ? *it : nullptr;
}

Item *User::findItem(const std::function<bool(const Item &)> &pred)
{
    auto it = std::find_if(items.begin(), items.end(), [&pred](Item* i){return pred(*i);});

    return (it != items.end()) ? *it : nullptr;
}

void User::addItem(Item *i)
{
    items.push_back(i);
}

void User::removeItem(int index)
{
    if(index >= 0 && index < static_cast<int>(items.size())){
        delete items[index];
        items.erase(items.begin() + index);
    }
}

int User::countItemsIf(const std::function<bool(const Item &)> &pred) const
{
    return static_cast<int>(std::count_if(items.begin(), items.end(), [&pred](Item* i) { return pred(*i); }));
}

void User::incrementBattles(bool won)
{
    if(won){
        this->battlesPlayed++;
        this->battlesWon++;
    }else{
        this->battlesPlayed++;
    }
}
