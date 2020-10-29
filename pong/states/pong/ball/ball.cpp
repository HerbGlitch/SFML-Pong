#include "ball.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace pong {
        Ball::Ball(game::Data *data): data(data){
            ball.setTexture(data->texture.getTexture("ball"));
            tools::centerOrigin(ball);
            ball.setPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
        }

        Ball::~Ball(){}

        void Ball::update(){
            if(isBoundsCollided()){
                addDirection(90);
            }
            Move();
        }

        void Ball::render(){ data->window.draw(ball); }


        void Ball::Move(){
            if(ballState != BallState::MOVING){ return; }

            sf::Vector2f temp;
            temp.x = sin(tools::degreeToRadians(direction)) * speed;
            temp.y = cos(tools::degreeToRadians(direction)) * speed;
            ball.move(temp);
        }

        bool Ball::isBoundsCollided(){
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
    }
}