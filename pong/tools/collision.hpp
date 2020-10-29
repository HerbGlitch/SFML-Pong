#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace herbglitch {
    namespace tools {
        inline bool isCollided(sf::Sprite s1, sf::Sprite s2){
            return ((s1.getGlobalBounds().left <= s2.getGlobalBounds().left + s2.getGlobalBounds().width) && 
                    (s1.getGlobalBounds().top  <= s2.getGlobalBounds().top  + s2.getGlobalBounds().height) &&
                    (s2.getGlobalBounds().left <= s1.getGlobalBounds().left + s1.getGlobalBounds().width) && 
                    (s2.getGlobalBounds().top  <= s1.getGlobalBounds().top  + s1.getGlobalBounds().height));
        }

        inline bool isCollided(sf::Vector2f v1, sf::Sprite s1){
            return ((v1.x <= s1.getGlobalBounds().left + s1.getGlobalBounds().width) && 
                    (v1.y <= s1.getGlobalBounds().top + s1.getGlobalBounds().height) && 
                    (v1.x >= s1.getGlobalBounds().width) && 
                    (v1.y >= s1.getGlobalBounds().top));
        }

        inline bool isCollided(sf::Vector2i v1, sf::Sprite s1){
            return (((float)v1.x <= s1.getGlobalBounds().left + s1.getGlobalBounds().width) && 
                    ((float)v1.y <= s1.getGlobalBounds().top + s1.getGlobalBounds().height) && 
                    ((float)v1.x >= s1.getGlobalBounds().width) && 
                    ((float)v1.y >= s1.getGlobalBounds().top));
        }

        inline bool isCollided(sf::Vector2f v1, float radius, sf::Sprite s1){
            float x = (v1.x - s1.getGlobalBounds().left >= 0)? v1.x - s1.getGlobalBounds().left : s1.getGlobalBounds().left - v1.x;
            float y = (v1.y - s1.getGlobalBounds().top >= 0)? v1.y - s1.getGlobalBounds().top : s1.getGlobalBounds().top - v1.y;
            float h = sqrtf((x * x) + (y * y));
            float theta = sinf(x / h);
            float c = cos(theta) / (s1.getGlobalBounds().width / 2.0f);
            return h <= c + radius;
        }

        inline bool isCollided(sf::Vector2f v1, float radius, sf::Sprite s1, float &theta){
            float x = v1.x - (s1.getGlobalBounds().left + (s1.getGlobalBounds().width / 2.0f));
            float y = v1.y - (s1.getGlobalBounds().top + (s1.getGlobalBounds().height / 2.0f));
            float h = sqrt((x * x) + (y * y));
            theta = sin(x / h);
            float c = (s1.getGlobalBounds().width / 2.0f) / cos(theta);
            std::cout << "H: " << h << " <= " << c << " + " << radius << std::endl;
            return h <= c + radius;
        }
    }
}