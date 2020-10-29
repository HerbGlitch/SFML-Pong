#include "gameState.hpp"
#include "../../game.hpp"

#include <iostream>

namespace herbglitch {
    namespace state {
        Game::Game(game::Data *data): data(data) {
            background.setTexture(data->texture.getTexture("background"));
            players.push_back(new pong::Player(data, 0.0f + (SCREEN_WIDTH / 20.0f), sf::Keyboard::W, sf::Keyboard::S));
            players.push_back(new pong::Player(data, SCREEN_WIDTH - (SCREEN_WIDTH / 20.0f), sf::Keyboard::Up, sf::Keyboard::Down));
            ball = new pong::Ball(data);
        }

        Game::~Game(){
            for(pong::Player *player : players){ delete player; }
            delete ball;
        }

        void Game::update(){
            CheckCollision();
            for(pong::Player *player : players){ player->update(); }
            ball->update();
        }

        void Game::render(){
            data->window.draw(background);
            for(pong::Player *player : players){ player->render(); }
            ball->render();
        }

        void Game::CheckCollision(){
            float theta;

            for(pong::Player *player : players){
                if(tools::isCollided(ball->getSprite(), player->getSprite())){
                    ball->addDirection((rand() % 90) + 90);
                    ball->addSpeed((rand() % 3) + 2.0);
                }
            }
        }
    }
}