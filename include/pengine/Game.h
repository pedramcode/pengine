#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

#include "pengine/ResourceManager.hpp"
#include "pengine/System.h"

namespace pengine {
    class Game {
        private:
            std::shared_ptr<sf::RenderWindow> _win;
            void _initialize();
            void _pollEvents();
            void _update();
            void _render();
            float _delta;
            std::vector<std::unique_ptr<System>> _systems;
        public:
            ResourceManager<sf::Texture, std::string> textures;
            Game();
            const float delta() const;
            void run();
            std::shared_ptr<sf::RenderWindow> win();
            entt::registry reg;
            void addSystem(std::unique_ptr<System> sys);
    };
}