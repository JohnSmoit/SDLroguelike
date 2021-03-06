#include "Game.hpp"
//#include "GameObject.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "PhysicsManager.hpp"
#include "NonPlayer.hpp"
#include <random>

//#include "ECS.hpp"
//#include "Components.hpp"

//GameObject* player, *slime;
Player* player1;//, *player2;
NonPlayer* enemy;

SDL_Texture* backGround;
SDL_Rect src, dest;

SDL_Renderer* Game::renderer = nullptr;

bool k_W, k_A, k_S, k_D, k_Space;



Game::Game() 
{

}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
    int flags = 0;
    srand(time(NULL));

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

        player1 = new Player("gameproj/assets/player.png");
        enemy = new NonPlayer("gameproj/assets/stone.png");
        player1->bound(0, 0);
        enemy->bound(0, 580);
        src.x = src.y = dest.x = dest.y = 0;
        src.w = src.h = 200;
        dest.w = 800;
        dest.h = 800;
        backGround = TextureManager::LoadTexture("gameproj/assets/Background.png");
        //map = new Map();
        //SDL_FreeSurface(surfacetmp);
        //newPlayer.addComponent<PositionComponent>();
        //newPlayer.getComponent<PositionComponent>();

    } 
    else 
    {
        std::cout << "SDL Initialization Failed!" << std::endl;
        isRunning = false;
    }
}

void Game::handleInput() //input registering (theres gotta be a better way).
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) 
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) 
            {
                case SDLK_w:
                    k_W = true;
                    break;
                case SDLK_a:
                    k_A = true;
                    break;
                case SDLK_s:
                    k_S = true;
                    break;
                case SDLK_d:
                    k_D = true;
                    break;
                case SDLK_SPACE:
                    k_Space = true;
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym) 
            {
                case SDLK_w:
                    //std::cout << "HI";
                    k_W = false;
                    break;
                case SDLK_a:
                    k_A = false;
                    break;
                case SDLK_s:
                    k_S = false;
                    break;
                case SDLK_d:
                    k_D = false;
                    break;
                case SDLK_SPACE:
                    k_Space = false;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update() //main game loop methods.
{



    player1->zeroVelocity();
    player1->Update(k_W, k_S, k_A, k_D, k_Space);
    if (PhysicsManager::checkAABBCollisions(player1, enemy)) //collisions checked before movement
    {
        std::cout << "colliding!" << std::endl;
       // std::cout << "Colliding!!!!" << std::endl;
        //player1->colliding = true;
        PhysicsManager::Rebound(player1, enemy);
    }
    else 
    {
        std::cout << "not colliding!" << std::endl;
    }
    //player1->setVelocity(0, 0);
    //player2->Update(false, false, false, false);

}

void Game::render() //handles drawing of graphics.
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(Game::renderer, backGround, &src, &dest);
    //player1->Render();
    //enemy->Render();

    for (GameObject* obj : entities) 
    {
        obj->Render();
    } 
    //player2->Render();
    //map->DrawMap();
    // player->Render();
    // slime->Render();

    SDL_RenderPresent(renderer);
}

void Game::clean() 
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Successfully Cleaned." << std::endl;
}
