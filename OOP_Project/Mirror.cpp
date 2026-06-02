#include "Mirror.h"
#include "Character.h"

Mirror::Mirror():Item("Mirror", 80, 3){}

void Mirror::applyEffect(Character *self, Character *enemy, bool &blade)
{
    std::cout << self->getName() << " used a mirror. The next attack will be reflected.\n";
}
