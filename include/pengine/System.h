#pragma once

#include <memory>
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

namespace pengine {
    class System {
        public:
            virtual ~System() = default;
            virtual void update(float dt, entt::registry& reg) = 0;
            virtual void render(sf::RenderWindow* win, entt::registry& reg) = 0;
    };
}