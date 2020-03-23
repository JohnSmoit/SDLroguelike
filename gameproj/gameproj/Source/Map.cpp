#include "Map.hpp"
#include "TextureManager.hpp"




int testlvl[30][20] = //default map for testing
{
    {0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


Map::Map() 
{
    dirt = TextureManager::LoadTexture("assets/dirt.png");//load each texture to a texture object
    grass = TextureManager::LoadTexture("assets/grasssdadsdas.png");
    stone = TextureManager::LoadTexture("assets/stone.png");
    sand = TextureManager::LoadTexture("assets/sand.png");

    LoadMap(testlvl);

    src.x = src.y = 0;
    src.w = dest.w = 24;
    src.w = dest.h = 24;

    dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[30][20]) 
{
    for (int row = 0; row < 30; row++) 
    {
        for (int column = 0; column < 20; column++) 
        {
            map[row][column] = arr[row][column]; //assign passed array to map
        }
    }
}

void Map::DrawMap() 
{
    int type = 0;
    for (int row = 0; row < 30; row++) 
    {
        for (int column = 0; column < 20; column++) 
        {
            type = map[row][column];

            dest.x = column * 24;
            dest.y = row * 24;

            switch(type) //assign textures to corresponding ints.
            {
                case 0:
                    TextureManager::Draw(stone, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(dirt, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 3:
                    TextureManager::Draw(sand, src, dest);
                    break;
                default:
                    break;
                
            }
        }
    }
}

Map::~Map() 
{
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(stone);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(sand);
}