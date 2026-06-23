#include "Shield.h"
#include "Character.h"

Shield::Shield():Item("Shield", 100, 5){}

void Shield::applyEffect(Character *self, Character *enemy, bool &blade)
{
    std::cout << self->getName() << " raised a shield and blocked " << enemy->getName() << "'s attack.\n";
}
