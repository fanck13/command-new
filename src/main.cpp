#include <iostream>
#include "Arguments.h"
#include "ErrorHandle.h"
#include "Generator.h"
#include "Checker.h"

int main(int argc, char** argv){

    Arguments args(argc, argv);
    if(!args.resolved()){
        ErrorHandle::handle();
    }

    Generator gen(args);

    gen.create_file();

    Checker check(args);
    return 0;
}

