#include "HealingPotion.h"
#include "Character.h"

HealingPotion::HealingPotion():Item("Healing Potion", 30, 1)
{
    this->minHeal = 5;
    this->maxHeal = 10;
}

void HealingPotion::applyEffect(Character* self, Character* enemy, bool& blade)
{
    int healAmount = 5 + (rand() % 6);

    int newHp = self->getCurrentHp() + healAmount;
    if(newHp > self->getMaxHp()){
        newHp = self->getMaxHp();
    }

    self->setHp(newHp);
    std::cout << self->getName() << " used a healing potion. It restored - " << healAmount << "HP.\n";
}
