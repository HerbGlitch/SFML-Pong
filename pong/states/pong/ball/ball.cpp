#include "ball.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace pong {
        Ball::Ball(game::Data *data): data(data){
            ball.setTexture(data->texture.getTexture("ball"));
            tools::centerOrigin(ball);
            Reset();
        }

        Ball::~Ball(){}

        void Ball::update(){
            if(ballState == BallState::STOPPED){
                PauseStart();
                return;
            }
            if(isBoundsCollided()){
                if(collided != lastCollided){
                    addDirection(90);
                    collided = lastCollided;
                }
            }
            Move();
            Scored();
        }

        void Ball::render(){ data->window.draw(ball); }

        void Ball::Reset(){
            ball.setPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
            speed = 5.0f;
            direction = (float)(rand() % 180);
            direction = (direction > 90)? direction + 225.0f : direction + 45.0f;
            ballState = BallState::STOPPED;
            clock.restart();
        }

        void Ball::PauseStart(){
            if(clock.getElapsedTime().asSeconds() > 1.0f){
                ballState = BallState::MOVING;
            }
        }

        bool Ball::Scored(){
            if(ball.getGlobalBounds().left <= 0.0f || ball.getGlobalBounds().left + ball.getGlobalBounds().width >= SCREEN_WIDTH){
                Reset();
                return true;
            }

            return false;
        }

        void Ball::Move(){
            if(ballState != BallState::MOVING){ return; }

            sf::Vector2f temp;
            temp.x = sin(tools::degreeToRadians(direction)) * speed;
            temp.y = cos(tools::degreeToRadians(direction)) * speed;
            ball.move(temp);
        }

        bool Ball::isBoundsCollided(){
            if(ball.getGlobalBounds().top <= 0.0f){ collided = Walls::UP; }
            if(ball.getGlobalBounds().top + ball.getGlobalBounds().height >= SCREEN_HEIGHT){ collided = Walls::DOWN; }
            return ball.getGlobalBounds().top <= 0.0f || ball.getGlobalBounds().top + ball.getGlobalBounds().height >= SCREEN_HEIGHT;
        }

        sf::Sprite &Ball::getSprite(){ return ball; }
        float Ball::getDirection(){ return direction; }
        void Ball::setDirection(float direction){ this->direction = direction; }

        void Ball::addDirection(float direction){
            if(direction >= 0){
                this->direction = (this->direction + direction > 360)? this->direction + direction - 360 : this->direction + direction;
                return;
            }
            this->direction = (this->direction + direction < 0)? this->direction + direction + 360 : this->direction + direction;
        }

        void Ball::addSpeed(float speed){ this->speed += speed; }
    }
}