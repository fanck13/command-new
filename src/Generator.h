#pragma once 

#include "Arguments.h"

class Generator{
public:
    Generator(Arguments args):_args(args){}
    ~Generator(){}
    void create_file();

private:
    Arguments _args;
};