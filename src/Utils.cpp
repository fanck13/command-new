#include <algorithm>
#ifdef WIN32
#include <Windows.h>
#elif define linux
#include <stdio.h>
#endif // WIN32

#include "Utils.h"


/*static*/ 
bool Utils::path_exist(const std::string& path) {
    return false;
}

/*static*/ 
std::string Utils::get_current_working_directory() {
    return std::string();
}

/*static*/ 
bool Utils::end_with(const std::string& str, char c) {
    if (str.size() == 0) return false;
    return str[str.size() - 1] == c;
}

/*static*/ 
bool Utils::end_with(const std::string& str, const std::string& suffix) {
    if (str.size() == 0) return false;
    if (suffix.size() > str.size()) return false;

    for (int i = 1; i <= suffix.size(); i++) {
        if (suffix[suffix.size() - 1] != str[str.size() - 1]) {
            return false;
        }
    }
    return true;
}

/*static*/ 
bool Utils::start_with(const std::string& str, char c) {
    if (str.size() <= 0) return false;
    return str[0] == c;
}

/*static*/ 
bool Utils::start_with(const std::string& str, const std::string& prefix) {
    if (str.size() <= 0) return false;
    if (prefix.size() > str.size()) return false;

    for (size_t i = 0; i < prefix.size(); i++) {
        if (str[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}

/*static*/ 
std::string Utils::combine(std::initializer_list<std::string> il) {
    std::string retVal;
    std::for_each(std::begin(il), std::end(il), [&retVal](std::string str) {

        str.replace('\\', '/');

        if (Utils::end_with(retVal, '/') && Utils::start_with(str, '/')) {
            retVal[retVal.size() - 1] = '\0';
            retVal = retVal + str;
        }
        else if (Utils::end_with(retVal, '/') && !Utils::start_with(str, '/')) {
            retVal = retVal + str;
        }
        else if (!Utils::end_with(retVal, '/') && Utils::start_with(str, '/')) {
            retVal = retVal + str;
        }
        else {
            retVal = retVal + '/' + str;
        }
    });

    return retVal;
}

/*static*/ 
bool Utils::remove_file(const std::string& file_name) {
#ifdef WIN32
    return TRUE == DeleteFile(file_name.c_str())?true:false;
#elif define linux
    return remove(file_name.c_str()) == 0 ? true : false;
#endif // WIN32

}
