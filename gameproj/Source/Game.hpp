#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "TextureManager.hpp"
#include "BoundingBox.hpp"
//#include "Camera.hpp"
#include "Entity.hpp"
//#include "GameObject.hpp"
//#include "PhysicsManager.hpp"

class Game 
{

public:

    Game(); //constructor and deconstructor methods
    ~Game();

    void handleInput();
    void update();
    void render();

    void init(const char* texture, int xpos, int ypos, int width, int height, bool fullscreen);
    void clean();
    bool running() { return isRunning; };

    static SDL_Renderer *renderer;

    static std::vector<Entity*> entities;
    
    //static const Camera* cam = &new Camera;
    
private:
    bool isRunning;
    SDL_Window *window;
};



#endif /* Game_hpp */
