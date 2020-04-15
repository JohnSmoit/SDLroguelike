#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"

class Map 
{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[30][20]);
        void DrawMap();
    private:

        SDL_Rect src, dest;

        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* stone;
        SDL_Texture* sand;

        int map[30][20];
};

#endif /* Map.hpp */
