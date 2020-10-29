#include "game.hpp"

namespace herbglitch {
    Game::Game(){
        data = new game::Data();
        data->handler = new Handler(data);

        data->window.create(sf::VideoMode(1920, 1080), "Pong", sf::Style::Close | sf::Style::Titlebar);
        Run();
    }

    Game::~Game(){
        delete data->handler;
        delete data;
    }

    void Game::Run(){

        float dt = clock.getElapsedTime().asSeconds();
        float new_dt = 0.0f, elapsed = 0.0f;


        while(data->window.isOpen()){
            sf::Event event;
            while(data->window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    data->window.close();
                }
            }

            new_dt = clock.getElapsedTime().asSeconds();
            elapsed += new_dt - dt;
            dt = new_dt;

            if(elapsed > (1.0f / 60.0f)){
                data->handler->update();
                elapsed -= (1.0f / 60.0f);
            }

            //render
            data->window.clear();
            data->handler->render();
            data->window.display();
        }
    }
}