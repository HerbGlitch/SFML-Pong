#include "player.hpp"
#include "../../../game.hpp"

namespace herbglitch {
    namespace pong {
        Player::Player(game::Data *data, float xPosition, sf::Keyboard::Key up, sf::Keyboard::Key down): data(data), up(up), down(down){
            player.setTexture(data->texture.getTexture("player"));
            tools::centerOrigin(player);
            player.setPosition(xPosition, SCREEN_HEIGHT / 2.0f);
        }

        Player::~Player(){}

        void Player::update(){
            GetKeyPress();
            Move();
        }

        void Player::render(){
            data->window.draw(player);
        }

        void Player::GetKeyPress(){
            if(sf::Keyboard::isKeyPressed(down)){
                direction = Direction::DOWN;
                return;
            }
            if(sf::Keyboard::isKeyPressed(up)){
                direction = Direction::UP;
                return;
            }
            direction = Direction::NONE;
        }

        void Player::Move(){
            if(isBoundsCollided()){ return; }

            switch(direction){
                case Direction::UP:
                    player.move(0, -playerSpeed);
                    break;
                case Direction::DOWN:
                    player.move(0, playerSpeed);
                    break;
            }
        }

        bool Player::isBoundsCollided(){
            if(direction == Direction::UP){ return player.getGlobalBounds().top <= 0.0f;}
            if(direction == Direction::DOWN){ return player.getGlobalBounds().top + player.getGlobalBounds().height >= SCREEN_HEIGHT; }
            return true;
        }

        sf::Sprite &Player::getSprite(){ return player; }
    }
}