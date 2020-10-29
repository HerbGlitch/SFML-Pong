#include <SFML/Graphics.hpp>
namespace herbglitch {
    namespace tools {
        inline void centerOrigin(sf::Sprite &sprite){
            sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);
        }
    }
}