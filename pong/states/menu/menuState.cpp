#include "menuState.hpp"
#include "../../game.hpp"

#include <iostream>

namespace herbglitch {
    namespace state {
        Menu::Menu(game::Data *data) : data(data) {
            background.setTexture(data->texture.getTexture("background"));
            title.setTexture(data->texture.getTexture("title"));
            play.setTexture(data->texture.getTexture("play"));
            tools::centerOrigin(title);
            tools::centerOrigin(play);
            std::cout << "Y: " << data->window.getSize().y << " X: " << data->window.getSize().x << std::endl;
            title.setPosition(1920.0f / 2.0f, 1080.0f / 4.0f);
            play.setPosition(1920.0f / 2.0f, 1080.0f / 2.0f);
        }

        void Menu::update() {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(tools::isCollided(sf::Mouse::getPosition(), play)){
                    data->handler->AddState(new state::Game(data));
                }
            }
        }

        void Menu::render() {
            data->window.draw(background);
            data->window.draw(title);
            data->window.draw(play);
        }
    }
}