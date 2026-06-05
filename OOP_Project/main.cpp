#include "GameManager.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    GameManager systemController;

    systemController.runApp();

    return 0;
}