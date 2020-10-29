#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    class State {
    public:
        virtual void update() = 0;
        virtual void render() = 0;
    };
}