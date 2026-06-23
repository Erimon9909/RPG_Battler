#include "Leaderboard.h"

void Leaderboard::updateRankings(std::vector<User> &allUsers)
{
    rankingList.clear();
    for(size_t i = 0; i < allUsers.size(); i++){
        rankingList.push_back(&allUsers[i]);
    }

    size_t n = rankingList.size();

    for(size_t i = 0; i < n-1; i++){
        size_t maxId = i;

        for(size_t j = i+1; j < n; j++){
            if((*rankingList[j] <=> *rankingList[maxId]) > 0){
                maxId = j;
            }
        }

        if(maxId != i){
            User* temp = rankingList[i];
            rankingList[i] = rankingList[maxId];
            rankingList[maxId] = temp;
        }
    }
}

void Leaderboard::display() const
{
    if(rankingList.empty()){
        std::cout << "Ranking list is empty. \n";
    }else{
        for(size_t i = 0; i < rankingList.size(); i++){
            std::cout << i+1 << "\t"
                    << rankingList[i]->getUsername() << "\t\t"
                    << rankingList[i]->getBattlesWon() << "\t"
                    << rankingList[i]->getTotalXp() << "\t\t"
                    << (rankingList[i]->getWinRate()) * 100.0 << "%\n";
        }
    }
}
