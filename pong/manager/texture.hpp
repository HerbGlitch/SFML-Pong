#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "setting.hpp"

namespace herbglitch {
    namespace manager {
        class Texture : public Setting {
        public:
            Texture();
            ~Texture();

            void load(std::string filepath, std::string name);

            sf::Texture &getTexture(std::string name);
            std::map<std::string, sf::Texture> &getTextures();

        private:
            std::map<std::string, sf::Texture> textures;
        };
    }
}