#include "GameManager.h"
#include "BattleEngine.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "HealingPotion.h"
#include "Blade.h"
#include "Mirror.h"
#include "Beam.h"
#include "Shield.h"

GameManager::GameManager(): loggedIn(nullptr), saveFileName("game_data.txt")
{
    load();
}

void GameManager::runApp()
{
    int choice = -1;
    while(true){
        if(loggedIn == nullptr){
            std::cout << "Welcome to RPG-Battler" << std::endl;
            std::cout << "1. Register" << std::endl;
            std::cout << "2. Login" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "Enter choice: " << std::endl;
            std::cin >> choice;

            switch(choice){
                case 1:
                    handleRegistration();
                    break;
                case 2:
                    handleLogin();
                    break;
                case 3:
                    save();
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        }else{
            std::cout << "Main menu (Logged in as:" << loggedIn->getUsername() << ")\n";
            std::cout << "Current xp balance: " << loggedIn->getCurrentXp() << std::endl;
            std::cout << "1. Initiate battle" << std::endl;
            std::cout << "2. Open shop & manage characters" << std::endl;
            std::cout << "3. Leaderboard" << std::endl;
            std::cout << "4. Logout" << std::endl;
            std::cin >> choice;

            switch(choice){
                case 1:
                    initiateBattle();
                    break;
                case 2:
                    handleShop();
                    break;
                case 3:
                    leaderboard.updateRankings(registeredUsers);
                    leaderboard.display();
                case 4:
                    handleLogout();
                    break;
                default:
                    std::cout << "Invalid Choice" << std::endl;
                    break;
            }
        }
    }
}

void GameManager::handleRegistration()
{
    std::string username, password;
    std::cout << "Enter new username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter new password: " << std::endl;
    std::cin >> password;

    for(size_t i = 0; i < registeredUsers.size(); i++){
        if(registeredUsers[i].getUsername() == username){
            std::cout << "Error: Username already exists" << std::endl;
            return;
        }
    }

    User newUser(username, password);

    std::cout << "Choose your free starting character: " << std::endl;
    std::cout << "1. Warrior\n2. Mage\n3. Archer\nChoice:";
    int charChoice;
    std::cin >> charChoice;
    std::string charName;
    std::cout << "Enter character name: ";
    std::cin >> charName;
    
    switch(charChoice){
        case 2:
            newUser.addCharacter(new Mage(charName, username));
            break;
        case 3:
            newUser.addCharacter(new Archer(charName, username));
            break;
        default:
            newUser.addCharacter(new Warrior(charName, username));
            break;
    }

    std::cout << "Choose your free starting item: " << std::endl;
    std::cout << "1. Healing potion\n2. Blade\n3. Mirror\n4.Beam\n5. Shield\nChoice: ";
    int itemChoice;
    std::cin >> itemChoice;

    switch(itemChoice){
        case 2:
            newUser.addItem(new Blade());
            break;
        case 3:
            newUser.addItem(new Mirror());
            break;
        case 4:
            newUser.addItem(new Beam());
            break;
        case 5:
            newUser.addItem(new Shield());
            break;
        default:
            newUser.addItem(new HealingPotion());
            break;
    }

    registeredUsers.push_back(newUser);
    std::cout << "Registration complete!" << std::endl;
    save();
}

void GameManager::handleLogin()
{
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << std::endl << "Enter password: ";
    std::cin >>password;

    for(size_t i = 0; i < registeredUsers.size(); i++){
        if(registeredUsers[i].getUsername() == username && registeredUsers[i].getPassword() == password){
            loggedIn = &registeredUsers[i];
            std::cout << "Login successful. Welcome back, " << username << std::endl;
            return;
        }
    }
    std::cout << "Invalid username or password" << std::endl;
}

void GameManager::handleLogout()
{
    std::cout << "Logged out from account: " << loggedIn->getUsername() << std::endl;
    loggedIn = nullptr;
    save();
}

void GameManager::handleShop()
{
    std::cout << "Welcome to the shop" << std::endl;
    std::cout << "Your current Xp: " << loggedIn->getCurrentXp() << std::endl
                << "1. Purchase item\n" 
                << "2. Purchase character (50xp)\n"
                << "3. Level up a character (100xp)\n"
                << "4. Return to main menu\n"
                << "Choice: ";
    int shopChoice;
    std::cin >> shopChoice;

    switch(shopChoice){
        case 4:
            break;
        case 1:
            std::cout << "1. Healing potion (30xp)\n2. Blade (50xp)\n3. Mirror (80xp)\n4. Beam(90xp)\n5. Shield (100xp)\nSelect item: ";
            int itemType;
            std::cin >> itemType;

            int cost = 0;
            switch(itemType){
                case 1:
                    cost = 30;
                    break;
                case 2:
                    cost = 50;
                    break;
                case 3:
                    cost = 80;
                    break;
                case 4:
                    cost = 90;
                    break;
                case 5:
                    cost = 100;
                    break;
            }

            if(cost > 0 && loggedIn->spendXp(cost)){
                switch(itemType){
                    case 1:
                        loggedIn->addItem(new HealingPotion());
                        break;
                    case 2:
                        loggedIn->addItem(new Blade());
                        break;
                    case 3:
                        loggedIn->addItem(new Mirror());
                        break;
                    case 4:
                        loggedIn->addItem(new Beam());
                        break;
                    case 5:
                        loggedIn->addItem(new Shield());
                        break;
                    default:
                        std::cout << "Invalid Choice" << std::endl;
                }
            }
            break;
        case 2:
            int cost = 50;
            std::cout << "Choose Character type: " << std::endl
                    << "1. Warrior" << std::endl
                    << "2. Mage" << std::endl
                    << "3. Archer" << std::endl
                    << "Select: " << std::endl;
            int charChoice;
            std::cin >> charChoice;

            if(loggedIn->spendXp(cost)){
                std::cout << "Please name you character: ";
                std::string charName;
                std::cin >> charName;
                std::cout << "\n";
                switch(charChoice){
                    case 1:
                        loggedIn->addCharacter(new Warrior(charName, loggedIn->getUsername()));
                        break;
                    case 2:
                        loggedIn->addCharacter(new Mage(charName, loggedIn->getUsername()));
                        break;
                    case 3:
                        loggedIn->addCharacter(new Archer(charName, loggedIn->getUsername()));
                        break;
                    default:
                        std::cout << "Invalid choice." << std::endl;
                        break;
                }
            }
        case 3:
            int cost = 100;
            auto& heroes = loggedIn->getCharacters();

            if(heroes.empty()){
                std::cout << "You don't own any characters." << std::endl;
                return;
            }

            std::cout << "Select a character to level up.\n";
            for(size_t i = 0; i < heroes.size(); i++){
                std::cout << i+1 << ". " << heroes[i]->getName() << "(lvl:" << heroes[i]->getLevel() << ")\n";
            }
            size_t targetIndex;
            std::cin >> targetIndex;

            if(targetIndex > 0 && targetIndex <= heroes.size()){
                if(loggedIn->spendXp(cost)){
                    Character* targetChar = heroes[targetIndex+1];
                    targetChar->incrementLevel();

                    std::cout << "Choose upgrade path: " << std::endl
                            << "1. Increase HP" << std::endl
                            << "2. Increase damage" << std::endl;
                    int path;
                    std::cin >> path;
                    switch(path){
                        case 1:
                            targetChar->upgradeMaxHp();
                            break;
                        case 2:
                            targetChar->upgradeDamage();
                            break;
                    }
                }else{
                    std::cout << "Not enough XP" << std::endl;
                }
            }else{
                std::cout << "Invalid index" << std::endl;
            }
    }
    save();
}

void GameManager::initiateBattle()
{
    if(registeredUsers.size() < 2){
        std::cout << "Matchmaking failed." << std::endl;
        return;
    }

    std::cout << "Registered opponents: " << std::endl;
    for(size_t i = 0; i < registeredUsers.size(); i++){
        if(registeredUsers[i].getUsername() != loggedIn->getUsername()){
            std::cout << " -" << registeredUsers[i].getUsername() << std::endl;
        }
    }
    std::string oppName;
    std::cout << "Enter your opponent's name: ";
    std::cin >> oppName;

    User* opponent = nullptr;
    for(size_t i = 0; i < registeredUsers.size(); i++){
        if(registeredUsers[i].getUsername() == oppName && oppName != loggedIn->getUsername()){
            opponent = &registeredUsers[i];
            break;
        }
    }

    if(!opponent){
        std::cout << "Opponent's target profile not found\n";
        return;
    }

    auto& myHeroes = loggedIn->getCharacters();
    auto& oppHeroes = opponent->getCharacters();

    std::cout << "Select combatant character: " << std::endl;
    for(size_t i = 0; i < myHeroes.size(); i++){
        std::cout << (i+1) << ". " << myHeroes[i]->getName() << "[lvl: " << myHeroes[i]->getLevel() << "]" << std::endl;
    }
    size_t myChoice;
    std::cin >> myChoice;

    std::cout << "Select opponents's combatant character: " << std::endl;
    for(size_t i = 0; i < oppHeroes.size(); i++){
        std::cout << (i+1) << ". " << oppHeroes[i]->getName() << "[lvl: " << oppHeroes[i]->getLevel() << "]" << std::endl;
    }
    size_t oppChoice;
    std::cin >> oppChoice;

    if(myChoice > 0 && myChoice <= myHeroes.size() &&
        oppChoice > 0 && oppChoice <= oppHeroes.size()){
            BattleEngine match(*loggedIn, myHeroes[myChoice-1], *opponent, oppHeroes[oppChoice-1]);
            match.startBattle();
            save();
        }else{
            std::cout << "Invalid Character selection." << std::endl;
        }
}

void GameManager::load()
{
   std::ifstream inFile(saveFileName);
   if(!inFile) return;

    registeredUsers.clear();
    size_t userCount;
    if(!(inFile >> userCount)) return;

    for(size_t i = 0; i < userCount; i++){
        std::string uName, pass;
        int totalXp, curXp, played, won;
        inFile >> uName >> pass >> totalXp >> curXp >> played >> won;

        User tempUser(uName, pass);
        tempUser.addXp(totalXp);

        size_t charCount;
        inFile >> charCount;
        for(size_t j = 0; j < charCount; j++){
            int typeId, lvl, maxHp;
            std::string cName;
            inFile >> typeId >> cName >> maxHp >> lvl;

            Character* c = nullptr;
            switch(typeId){
                case 2:
                    c = new Mage(cName, uName);
                    break;
                case 3:
                    c = new Archer(cName, uName);
                    break;
                default:
                    c = new Warrior(cName, uName);
                    break;
            }

            for(int k = 1; k < lvl; k++){
                c->incrementLevel();
            }

            tempUser.addCharacter(c);
        }

        
        size_t itemCount;
        inFile >> itemCount;
        for(size_t j = 0; j < itemCount; j++){
            int typeId;
            inFile >> typeId;
            switch(typeId){
                case 1:
                    tempUser.addItem(new HealingPotion());
                    break;
                case 2:
                    tempUser.addItem(new Blade());
                    break;
                case 3:
                    tempUser.addItem(new Mirror());
                    break;
                case 4:
                    tempUser.addItem(new Beam());
                    break;
                case 5:
                    tempUser.addItem(new Shield());
                    break;
            }
        }
        registeredUsers.push_back(tempUser);
    }
    inFile.close();

}

void GameManager::save()
{
     std::ofstream outFile(saveFileName);
    if(!outFile) return;

    outFile << registeredUsers.size() << "\n";
    for(const auto& user : registeredUsers){
        outFile << user.getUsername() << " " << user.getPassword() << " "
                << user.getTotalXp() << " " << user.getCurrentXp() << " "
                << user.getBattlesPlayed() << " " << user.getBattlesWon() << "\n";

        auto& chars = const_cast<User&>(user).getCharacters();
        outFile << chars.size() << "\n";
        for(auto* c : chars){
            outFile << c->getType() << " " << c->getName() << " "
                    << c->getMaxHp() << " " << c->getLevel() << "\n";
        }

        auto& items = const_cast<User&>(user).getItems();
        outFile << items.size() << "\n";
        for(auto* item : items){
            outFile << item->getItemType() << "\n";
        }        
    }

    outFile.close();
}
