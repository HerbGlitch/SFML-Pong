#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    namespace pong {
        enum class Direction { UP, DOWN, NONE };

        class Player {
        public:
            Player(game::Data *data, float xPosition, sf::Keyboard::Key up, sf::Keyboard::Key down);
            ~Player();

            void update();
            void render();

            sf::Sprite &getSprite();
        private:
            void GetKeyPress();
            void Move();
            bool isBoundsCollided();

            game::Data *data;
            sf::Sprite player;

            sf::Keyboard::Key up;
            sf::Keyboard::Key down;

            Direction direction = Direction::NONE;
            float playerSpeed = 5.0f;
        };
    }
}