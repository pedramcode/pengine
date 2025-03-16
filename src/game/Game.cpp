#include "pengine/Game.h"

namespace pengine {
    Game::Game(){
        _initialize();
    }

    void Game::run(){
        sf::Clock clock;
        while(_win->isOpen()){
            _delta = clock.reset().asSeconds();
            _update();
            _render();
        }
    }

    const float Game::delta() const {
        return _delta;
    }

    std::shared_ptr<sf::RenderWindow> Game::win(){
        return _win;
    }

    void Game::addSystem(std::unique_ptr<System> sys){
        _systems.push_back(sys);
    }
}