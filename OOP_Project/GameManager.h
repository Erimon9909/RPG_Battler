#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"
#include "Leaderboard.h"

class GameManager{
    private:
        std::vector<User> registeredUsers;
        User* loggedIn;
        Leaderborad leaderboard;
        const std::string saveFileName;
    public:
        GameManager();
        void runApp();
        void handleRegistration();
        void handleLogin();
        void handleLogout();
        void handleShop();
        void initiateBattle();
        void load();
        void save();
};