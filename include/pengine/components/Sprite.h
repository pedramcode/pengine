#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace pengine {
    class Sprite {
        public:
            std::shared_ptr<sf::Texture> texture;
            Sprite(std::shared_ptr<sf::Texture> texture): texture(texture){}
    };
}