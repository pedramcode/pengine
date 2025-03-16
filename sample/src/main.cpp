#include <pengine/Game.h>
#include <pengine/components.h>
#include <memory>

void initialize(pengine::Game *game){
    auto texture = std::make_shared<sf::Texture>(sf::Texture());
    texture->loadFromFile("assets/ships.png");
    game->textures.insert("ships_tile", texture);
}

void addPlayerSpirte(pengine::Game *game){
    auto player = game->reg.create();
    game->reg.emplace<pengine::Node>(player, sf::Vector2f(100, 100));
    pengine::Sprite::Grid grid;
    grid.dimentions = {4, 6};
    grid.sectionSize = {16, 16};
    grid.dimentions = {0, 0};
    game->reg.emplace<pengine::Sprite>(player, game->textures.get("ship_tile"), grid);
}

int main(){
    auto game = new pengine::Game();

    initialize(game);
    addPlayerSpirte(game);

    game->run();
    return 0;
}