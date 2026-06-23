#pragma once
#include <memory>
#include "Item.h"
#include "ItemType.h"

class ItemFactory{
    public:
        static std::unique_ptr<Item> create(ItemType type);
};