#include "Mage.h"
#include <cstdlib>

Mage::Mage(std::string name, std::string owner):Character(name, owner, 12, 1, 12, 2){}

int Mage::calcAttackDamage()
{
    int amount = rand() % 12 + 1;
    int specialAttack;
    std::cout << "Do you wanna apply special attack(12-current damage). Current damage is " << amount << "1.Yes/2.No" << std::endl;
    std::cin >> specialAttack;
    if(specialAttack == 1){
        return 12-amount;
    }
    
    return amount;
}

int Mage::handleIncomingDamage(int rawDmg)
{
    this->setHp(this->getMaxHp()-rawDmg);
    return this->getCurrentHp();
}
