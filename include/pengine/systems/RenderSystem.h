#pragma once

#include "pengine/System.h"

namespace pengine {
    class RenderSystem: public System {
        public:
            void update(float dt, entt::registry& reg) override;
            void render(sf::RenderWindow* win, entt::registry& reg) override;
    };
}