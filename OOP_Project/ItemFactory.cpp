#include "ItemFactory.h"
#include "Blade.h"
#include "Beam.h"
#include "Mirror.h"
#include "HealingPotion.h"
#include "Shield.h"

std::unique_ptr<Item> ItemFactory::create(ItemType type)
{
    switch(type){
        case ItemType::Blade: return std::make_unique<Blade>();
        case ItemType::Beam: return std::make_unique<Beam>();
        case ItemType::Mirror: return std::make_unique<Mirror>();
        case ItemType::HealingPotion: return std::make_unique<HealingPotion>();
        case ItemType::Shield: return std::make_unique<Shield>();
        default: return nullptr;
    };
}