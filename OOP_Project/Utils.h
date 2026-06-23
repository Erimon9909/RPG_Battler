#pragma once
#include <cstdlib>
#include <iostream>

namespace Utils{
    inline void clearScreen(){
        std::system("cls");
    }

    inline void pauseAndClear(){
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        clearScreen();
    }
};