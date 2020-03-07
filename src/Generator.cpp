#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif // WIN32

#include "Generator.h"
#include "Utils.h"

void Generator::create_file(){
    std::string cwd = Utils::get_current_working_directory();

    std::string target_path = Utils::combine({ cwd, _args.get_file_name() });

    if (Utils::path_exist(target_path)) {
        if (_args.is_forced()) {
            DeleteFile(target_path.c_str());
        }
        else {
            std::cout << "There is a file named " << _args.get_file_name() << std::endl;
        }
    }
}