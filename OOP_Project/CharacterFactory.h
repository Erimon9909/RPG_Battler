#pragma once
#include <memory>
#include <string>
#include "Character.h"
#include "CharacterType.h"

class CharacterFactory{
    public:
        static std::unique_ptr<Character> create(CharacterType type, const std::string& name, const std::string& owner);
};