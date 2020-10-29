#ifndef GAME_H
#define GAME_H

#define WINDOW_WIDTH 1920.0f
#define WINDOW_HEIGHT 1080.0f
#define SCREEN_WIDTH WINDOW_WIDTH
#define SCREEN_HEIGHT (WINDOW_HEIGHT - 40.0f)

#include <SFML/Graphics.hpp>
#include "handler/handler.hpp"
#include "manager/texture.hpp"

namespace herbglitch {
    namespace game {
        struct Data {
            sf::RenderWindow window;
            manager::Texture texture;
            Handler *handler;
        };
    }

    class Game {
    public:
        Game();
        ~Game();

        void Run();

    private:
        game::Data *data;
 
        sf::Clock clock;
    };
}

#endif //GAME_H