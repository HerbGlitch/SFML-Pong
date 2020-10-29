#pragma once
#include <iostream>
#include <fstream>
#include "setting.hpp"

namespace herbglitch {
    namespace config {
        inline void load(std::string filepath, Setting &setting){
            std::filebuf fb;
            if(fb.open(filepath, std::ios::in)){
                std::istream is(&fb);
                while(is){
                    std::string temp;
                    std::getline(is, temp);
                    if(temp.find(':') == std::string::npos){ continue; }
                    setting.load(temp.substr(temp.find(':') + 2, temp.size() - 1), temp.substr(0, temp.find(':')));
                }

                fb.close();
            }
        }
    }
}