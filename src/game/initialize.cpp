#include "pengine/Game.h"

namespace pengine {
    void Game::_initialize(){
        // initialize the window
        _win = std::make_shared<sf::RenderWindow>(sf::VideoMode({800,600}), "game", sf::Style::Close | sf::Style::Titlebar);
        auto screenPos = sf::VideoMode::getDesktopMode().size;
        _win->setPosition({(int)screenPos.x / 2 - (int)_win->getSize().x / 2, (int)screenPos.y / 2 - (int)_win->getSize().y / 2});
    }
}