#pragma once
#include <iostream>
#include <vector>
#include "User.h"

class Leaderboard{
    private:
        std::vector<User*> rankingList;
    public:
        void updateRankings(std::vector<User>& allUsers);
        void display() const;
};