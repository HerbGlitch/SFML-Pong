#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    namespace pong {
        enum class BallState { MOVING, STOPPED };

        class Ball {
        public:
            Ball(game::Data *data);
            ~Ball();

            void update();
            void render();

            sf::Sprite &getSprite();
            float getDirection();
            void setDirection(float direction);
            void addDirection(float direction);

        private:
            void GetKeyPress();
            void Move();
            bool isBoundsCollided();

            game::Data *data;
            sf::Sprite ball;

            BallState ballState = BallState::MOVING;
            float speed = 5.0f;
            //this angle is in degrees
            float direction = 45.0f;
        };
    }
}