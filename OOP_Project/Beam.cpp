#include "Beam.h"
#include "Character.h"

Beam::Beam():Item("Beam", 90, 4)
{
}

void Beam::applyEffect(Character *self, Character *enemy, bool &blade)
{
    std::cout << self->getName() << " fired a beam and broke " << enemy->getName() << "'s shield.\n";
}
