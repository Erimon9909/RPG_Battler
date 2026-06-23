#include "CharacterFactory.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
std::unique_ptr<Character> CharacterFactory::create(CharacterType type, const std::string &name, const std::string &owner)
{
    switch(type){
        case CharacterType::Warrior:
            return std::make_unique<Warrior>(name, owner);
        case CharacterType::Mage:
            return std::make_unique<Mage>(name, owner);
        case CharacterType::Archer:
            return std::make_unique<Archer>(name, owner);
        default:
            return nullptr;
    }
}