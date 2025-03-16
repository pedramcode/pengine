#include "pengine/Game.h"

namespace pengine {
    void Game::_update(){
        _pollEvents();

        for (auto& system : _systems) {
            system->update(_delta, reg);
        }
    }

    void Game::_pollEvents(){
        while(auto ev = _win->pollEvent()){
            if(ev->getIf<sf::Event::Closed>()){
                _win->close();
            }
            if(auto key = ev->getIf<sf::Event::KeyPressed>()){
                if(key->code == sf::Keyboard::Key::Escape){
                    _win->close();
                }
            }
        }
    }
}