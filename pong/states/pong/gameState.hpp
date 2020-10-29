#pragma once

#include "../states.hpp"
#include "../../tools/tools.hpp"
#include "player/player.hpp"
#include "ball/ball.hpp"

namespace herbglitch {
    namespace game { struct Data; }

    namespace state {
        class Game : public State {
        public:
            Game(game::Data *data);
            ~Game();

            void update();
            void render();

        private:
            void CheckCollision();

            game::Data *data;

            std::vector<pong::Player *> players;
            pong::Ball *ball;

            sf::Sprite background;
        };
    }
}