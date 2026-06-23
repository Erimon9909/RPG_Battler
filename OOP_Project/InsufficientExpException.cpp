#include "InsufficientExpException.h"

InsufficientExpException::InsufficientExpException():Exception(std::format("Not enough experience.")){}