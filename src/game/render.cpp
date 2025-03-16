#include "pengine/Game.h"

namespace pengine {
    void Game::_render(){
        _win->clear();

        for (auto& system : _systems) {
            system->render(_win.get(), reg);
        }

        _win->display();
    }
}