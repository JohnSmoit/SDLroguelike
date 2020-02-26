#include "Game.hpp"

SDL_Texture* player;

Game::Game() 
{

}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
    int flags = 0;

    if (fullscreen) 
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
    {

        std::cout << "Subsystems initialized properly!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) 
        {
            std::cout << "Succesfully created SDL Window!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) 
        {
            SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
            std::cout << "Succesfully created SDL Renderer!" << std::endl;
        }
        isRunning = true;

        SDL_Surface* surfacetmp = IMG_Load("assets/player.png");
        player = SDL_CreateTextureFromSurface(renderer, surfacetmp);
        SDL_FreeSurface(surfacetmp);

    } 
    else 
    {
        std::cout << "SDL Initialization Failed!" << std::endl;
        isRunning = false;
    }
}

void Game::handleInput() 
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) 
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() 
{

}

void Game::render() 
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, player, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Game::clean() 
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Successfully Cleaned." << std::endl;
}
//void Game::Ahsfiasljfso(ajshaksdjadjakasd) {}