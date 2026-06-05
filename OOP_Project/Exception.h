#pragma once
#include <exception>
#include <iostream>

class Exception{
    private:
        std::string message;
    public:
        Exception(const std::string& msg);
        const char* what() const noexcept;
};  