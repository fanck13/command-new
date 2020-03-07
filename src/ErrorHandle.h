#pragma once

#include <string>

class ErrorHandle{
public:
    ErrorHandle();
    ~ErrorHandle();

    static void handle();
private:
    std::string message;
};