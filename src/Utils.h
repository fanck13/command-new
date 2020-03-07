#pragma once

#include <string>
#include <initializer_list>

class Utils {
public:
    static bool path_exist(const std::string& path);
    static std::string get_current_working_directory();
    static bool end_with(const std::string& str, char c);
    static bool end_with(const std::string& str, const std::string& suffix);

    static bool start_with(const std::string& str, char c);
    static bool start_with(const std::string& str, const std::string& prefix);

    
    static std::string combine(std::initializer_list<std::string> il);

    static bool remove_file(const std::string& file_name);
};