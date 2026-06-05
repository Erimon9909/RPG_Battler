#pragma once
#include "Exception.h"

class InvalidSelectionException:public Exception{
    public:
        InvalidSelectionException(int selection);
};