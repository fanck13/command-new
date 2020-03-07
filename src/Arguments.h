#pragma once 
#include <string>
#include <tuple>
#include <vector>
#include "File.h"

class Arguments{
public:
    Arguments(int argc, char** argv):resolve_status(false){
        resolve_status = resolve(argc, argv);
    }

    ~Arguments(){}

    void reset() {
        template_path = std::make_tuple<bool, std::string>(false, "");
        force_del = std::make_tuple<bool, bool>(false, false);
    }
    void set_template_path(const std::string& template_path){
        if(std::get<0>(this->template_path)){
            std::get<1>(this->template_path) = template_path;
        }
    }

    std::string get_template_path(){
        if(std::get<0>(this->template_path)){
            return std::get<1>(this->template_path);
        }
        return std::string();
    }

    bool resolved(){
        return resolve_status;
    } 

    std::string get_file_name() const {
        return file_name;
    }

    bool is_forced() const{
        return std::get<1>(force_del);
    }

private:
    bool resolve(int argc, char** argv){
        std::vector<std::string> args;

        int i = 1;
        while(i<argc){
            std::string temp(argv[i]);
            if(temp == "-t"){
                std::get<0>(template_path) = true;
                std::get<1>(template_path) = argv[i+1];
                i++;
                continue;
            }
            else if (temp == "-f") {
                std::get<0>(force_del) = true;
                std::get<1>(force_del) = true;
            }
            else{
                //file.set_path(std::string(argv[i]));
                file_name = argv[i];
            }
        }
        for(int i = 0; i<argc; i++){
            args.push_back(*argv);
        }

        return false;
    }

private:
    bool resolve_status;
    std::tuple<bool, std::string> template_path;
    std::tuple<bool, bool> force_del;
    std::string file_name;
    File file;
    
};