#include "Game.hpp"

Game *game = nullptr;
int main() {

    game = new Game();

    std::cout << "oi man";

    game->init("Noice Game Bro", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()) 
    {
        game->handleInput();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}