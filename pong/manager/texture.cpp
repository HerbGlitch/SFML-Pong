#include "texture.hpp"

namespace herbglitch {
    namespace manager {
        Texture::Texture(){}

        Texture::~Texture(){
            textures.clear();
        }
    
        void Texture::load(std::string filepath, std::string name){
            sf::Texture texture;

            // if(textures.find(name) != textures.end()){
            //     std::cout << "Error: name '" << name << "' already defined" << std::endl;
            //     std::exit(-1);
            // }

            if(!texture.loadFromFile(filepath)){
                std::cout << "Error: filepath '" << filepath << "' failed to load" << std::endl;
                std::exit(-1);
            }

            textures.insert({name, texture});
        }
        
        sf::Texture &Texture::getTexture(std::string name){ return textures[name]; }
        std::map<std::string, sf::Texture> &Texture::getTextures(){ return textures; }
    }
}  // namespace tribyte