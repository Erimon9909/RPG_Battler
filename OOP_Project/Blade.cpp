#include "Blade.h"
#include "Character.h"

Blade::Blade(): Item("Blade", 50, 2){}

void Blade::applyEffect(Character* self, Character* enemy, bool& blade)
{
    blade = true;
    std::cout << self->getName() << " used item - blade. Next attack will deal x2 damage.\n";
}
