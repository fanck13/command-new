#pragma once

#include <string>
#include <algorithm>

class File{
public:
    File():_path(""), _directory(""), _name(""), _ext(""){}
    File(std::string path):_path(path){
        split();
    }

    ~File(){}

    std::string name(){ return this->_name;}

    std::string directory(){ return this->_directory;}

    std::string extension(){return this->_ext;}

    void set_path(std::string path){
        _path = path;
    }


private:
    void split(){
        auto ext_pos = _path.rfind('.');
        _ext = _path.substr(ext_pos, _path.size() - ext_pos);

        if(_path.find('\\') != std::string::npos){
            auto name_pos = _path.rfind('\\');
            _name = _path.substr(name_pos+1, _path.size() - (name_pos+1));
            _directory = _path.substr(0, name_pos);
        }
        else{
            auto name_pos = _path.rfind('/');
            _name = _path.substr(name_pos+1, _path.size() - (name_pos+1));
            _directory = _path.substr(0, name_pos);
        }
    }

private:
    std::string _directory;
    std::string _name;
    std::string _ext;
    std::string _path;
};