#pragma once

#include <SFML/System.hpp>

namespace pengine {
    class Node{
        public:
            sf::Vector2f position;
            sf::Vector2f scale;
            sf::Vector2f transform;
            float rotate;
            Node(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f transform, float rotate): position(position), scale(scale), transform(transform), rotate(rotate){};
            Node(): position({0,0}), scale({1,1}), transform({0,0}), rotate(0){};
            Node(sf::Vector2f position): position(position), scale({1,1}), transform({0,0}), rotate(0){};
    };
}