#include "HealingPotion.h"

HealingPotion::HealingPotion():Item("Healing Potion", 30, 1)
{
    this->minHeal = 5;
    this->maxHeal = 10;
}