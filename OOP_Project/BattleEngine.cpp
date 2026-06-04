#include "BattleEngine.h"

BattleEngine::BattleEngine(User &u1, Character *c1, User &u2, Character *c2):
    player1(u1),
    player2(u2),
    char1(c1),
    char2(c2),
    activeBlade1(false),
    activeBlade2(false)
{
}

void BattleEngine::startBattle()
{
    std::cout << char1->getName() << " (HP: " << char1->getCurrentHp() << ") VS "
            << char2->getName() << "(HP: " << char2->getCurrentHp() << ")\n\n";

    bool player1Turn = (rand() %2 == 0);

    std::cout << (player1Turn ? player1.getUsername() : player2.getUsername()) << " won the coin toss and goes first\n\n";

    while(char1->getCurrentHp() > 0 && char2->getCurrentHp() > 0){
        if(player1Turn){
            handleTurn(player1, char1, player2, char2, activeBlade1, activeBlade2);
        }else{
            handleTurn(player2, char2, player1, char1, activeBlade2, activeBlade1);
        }

        player1Turn = !player1Turn;
    }

    if(char1->getCurrentHp() <= 0){
        std::cout << player2.getUsername() << " won the match with" << char2->getName() << std::endl;


        player2.addXp(10);
        player1.addXp(5);

        player2.incrementBattles(true);
        player1.incrementBattles(false);
    }else{
        std::cout << player1.getUsername() << " won the match with " << char1->getName() << std::endl;

        player1.addXp(10);
        player2.addXp(5);

        player1.incrementBattles(true);
        player2.incrementBattles(false);
    }

    char1->resetHp();
    char2->resetHp();
}

void BattleEngine::handleTurn(User &currentUser, Character *c1, User &enemy, Character *enemyC, bool &currentBlade, bool enemyBlade)
{
    std::cout << "\nIt is " << currentUser.getUsername() << "'s turn (" << c1->getName() << ")" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Use item" << std::endl;
    std::cout << "Choose action: " << std::endl;

    int choice;
    std::cin >> choice;

    switch(choice){
        case 1:
            processAttack(c1, enemyC, currentBlade);
            break;
        case 2:
            processItemUsage(currentUser, c1, enemyC);
    }   
}

void BattleEngine::processAttack(Character *attacker, Character *defender, bool &attackerBlade)
{
    if(attackerBlade){
        defender->setHp(defender->getCurrentHp() - (attacker->calcAttackDamage()*2));
    }else{
        defender->setHp(defender->getCurrentHp() - attacker->calcAttackDamage());
    }
}

void BattleEngine::processItemUsage(User &user, Character *self, Character *enemy)
{
    std::vector<Item*>& inventory = user.getItems();

    if(inventory.empty()){
        std::cout << "Your inventory is empty!" << std::endl;
        return;
    }

    std::cout << user.getUsername() << "'s inventory: " << std::endl;
    for(size_t i = 0; i < inventory.size(); i++){
        std::cout << (i+1) << ". " << inventory[i]->getName() << std::endl;
    }

    std::cout << "Choose item: " << std::endl;
    size_t choice;
    std::cin >> choice;

    if(choice == 0 || choice > inventory.size()){
        std::cout << "Invalid choice" << std::endl;

        bool& currentBlade = (&user == &player1) ? activeBlade1 : activeBlade2;
        processAttack(self, enemy, currentBlade);
        return;
    }

    size_t index = choice - 1;
    Item* chosenItem = inventory[index];
    int type = chosenItem->getItemType();

    if(type == 3 || type == 4 || type == 5){
        if(type == 3){
            std::optional<bool>& enemyMirror = (&user == &player1) ? activeMirror2 : activeMirror1;
            enemyMirror = true;
            chosenItem->applyEffect(self, enemy, activeBlade1);
        }else{
            std::cout << "You cannot use " << chosenItem->getName() << " during your proactive turn phase." << std::endl;
            return;
        }
    }else{
        bool& currentBlade = (&user == &player1) ? activeBlade1 : activeBlade2;
        chosenItem->applyEffect(self, enemy, currentBlade);
    }

    delete chosenItem;
    inventory.erase(inventory.begin() + index);
}

void BattleEngine::checkItems(User &defenderUser, Character *defender, int damage, bool &shield)
{
    if(damage <= 0) return;

    std::vector<Item*>& inventory = defenderUser.getItems();
    int shieldIndex = -1;

    for(size_t i = 0; i <inventory.size(); i++){
        if(inventory[i]->getItemType() == 5){
            shieldIndex = static_cast<int>(i);
            break;
        }
    }

    if(shield != -1){
        std::cout << defenderUser.getUsername() << " you are about to take " << damage
                << " damage. Would you like to use a shield? " << std::endl;
        
        int choice;
        std::cin >> choice;

        if(choice == 1){
            bool dummyBlade = false;
            inventory[shieldIndex]->applyEffect(defender, nullptr, dummyBlade);

            delete inventory[shieldIndex];
            inventory.erase(inventory.begin() + shieldIndex);

            shield = true;
        }
    }
}
