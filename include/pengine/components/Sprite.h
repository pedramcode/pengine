#pragma once

#include <memory>
#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace pengine {
    

    class Sprite {
        public:
            struct Grid {
                sf::Vector2f dimentions;
                sf::Vector2f sectionSize;
                sf::Vector2f region;
            };

            std::shared_ptr<sf::Texture> texture;
            std::optional<Grid> spriteGrid;
            Sprite(std::shared_ptr<sf::Texture> texture, std::optional<Grid> spriteGrid): texture(texture), spriteGrid(spriteGrid){}
            Sprite(std::shared_ptr<sf::Texture> texture): texture(texture), spriteGrid(std::nullopt){}
    };
}