#include "Item.h"

class Beam:public Item{
    public:
        Beam();
        void applyEffect(Character* self, Character* enemy, bool& blade) override;
};