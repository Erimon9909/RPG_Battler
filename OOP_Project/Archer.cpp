#include "Archer.h"
#include <cstdlib>

Archer::Archer(std::string name, std::string owner):Character(name, owner, 15, 1, 8, 3)
{
}

int Archer::calcAttackDamage()
{
    int dmg = rand() % 8 + 1;
    int selectDouble;
    if(dmg <= 4){
        std::cout << "Do you wanna double your attack. Current attack - " << dmg << "(1. Yes/2. No)" << std::endl;
        std::cin >> selectDouble;
        if(selectDouble == 1){
            dmg *= 2;
        }
    }

    return dmg;
}

int Archer::handleIncomingDamage(int rawDmg)
{
    this->setHp(this->getCurrentHp() - rawDmg);
    return this->getCurrentHp();
}
