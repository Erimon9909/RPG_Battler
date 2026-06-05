#include "InvalidSelectionException.h"

InvalidSelectionException::InvalidSelectionException(int selection):Exception(
    std::format("{} is and invalid choice", selection)){}