#include "Character.h"

Character::Character(std::string name, std::string owner, int hp, int minDmg, int maxDmg, int type)
{
    this->name = name;
    this->owner = owner;
    this->maxHp = hp;
    this->hp = this->maxHp;
    this->level = 1;
    this->minDmg = minDmg;
    this->maxDmg = maxDmg;
    this->typeId = type;
}

std::string Character::getName() const
{
    return this->name;
}

int Character::getMaxHp() const
{
    return this->maxHp;
}

int Character::getCurrentHp() const
{
    return this->hp;
}

int Character::getLevel() const
{
    return this->level;
}

int Character::getType() const
{
    return this->typeId;
}

void Character::setHp(int hp)
{
    this->hp = hp;
}

void Character::resetHp()
{
    this->hp = this->maxHp;
}

void Character::upgradeMaxHp()
{
    this->maxHp += 2;
}

void Character::upgradeDamage()
{
    this->maxDmg += 1;
}

void Character::incrementLevel()
{
    this->level += 1;
    this->upgradeDamage();
    this->upgradeMaxHp();
}
