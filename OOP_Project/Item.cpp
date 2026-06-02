#include "Item.h"

Item::Item(std::string name, int xp, int type): name(name), xpCost(xp), typeId(type){}

Item::~Item()
{
}

std::string Item::getName() const
{
    return this->name;
}

int Item::getXpCost() const
{
    return this->xpCost;
}

int Item::getItemType() const
{
    return this->typeId;
}
