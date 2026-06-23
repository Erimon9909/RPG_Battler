#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include "User.h"
#include "Character.h"

class BattleEngine{
    private:
        User& player1;
        User& player2;
        Character* char1;
        Character* char2;
        bool activeBlade1;
        bool activeBlade2;
        std::optional<bool> activeMirror1;
        std::optional<bool> activeMirror2;
    public:
        BattleEngine(User& u1, Character* c1, User& u2, Character* c2);
        void startBattle();
        void handleTurn(User& currentUser, Character* c1, User& enemy, Character* enemyC, bool& currentBlade, bool enemyBlade);
        void processAttack(Character* attacker, Character* defender, bool& attackerBlade);
        void processItemUsage(User& user, Character* self, Character* enemy);
        void checkItems(User& defenderUser, Character* defender, int damage, bool& shield);
        
};