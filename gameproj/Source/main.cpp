#include "Game.hpp"

Game *game = nullptr;
int main() {

    game = new Game();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    std::cout << "oi man";

    game->init("Noice Game Bro", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while(game->running()) 
    {

        frameStart = SDL_GetTicks();

        game->handleInput();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) 
        {
            SDL_Delay(frameDelay - frameTime);//frameStart = 0;
        }

    }

    game->clean();

    return 0;
}