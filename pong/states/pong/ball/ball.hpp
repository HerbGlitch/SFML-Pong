#pragma once

#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    namespace pong {
        enum class BallState { MOVING, STOPPED };
        enum class Walls { UP, DOWN, LEFT, RIGHT, NONE };

        class Ball {
        public:
            Ball(game::Data *data);
            ~Ball();

            void update();
            void render();

            void Reset();
            void PauseStart();
            bool Scored();

            sf::Sprite &getSprite();
            float getDirection();
            void setDirection(float direction);
            void addDirection(float direction);
            void addSpeed(float speed);


        private:
            void GetKeyPress();
            void Move();
            bool isBoundsCollided();

            game::Data *data;
            sf::Sprite ball;
            sf::Clock clock;

            BallState ballState = BallState::STOPPED;
            Walls collided = Walls::NONE;
            Walls lastCollided = Walls::NONE;
            
            float speed;
            //this angle is in degrees
            float direction;
        };
    }
}