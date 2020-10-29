#pragma once
#include <string>

namespace herbglitch {
    class Setting {
    public:
        virtual void load(std::string, std::string) = 0;
    };
}