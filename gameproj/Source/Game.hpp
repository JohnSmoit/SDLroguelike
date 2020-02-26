#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game 
{

public:

    Game(); //constructor and deconstructor methods
    ~Game();

    void handleInput();
    void update();
    void render();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void clean();
    bool running() { return isRunning; };
    
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /* Game_hpp */
