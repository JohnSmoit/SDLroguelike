#include "TextureManager.hpp"
//#include "Game.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture) 
{
    std::cout << "Loading ";
    std::cout << texture << std::endl;

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest) 
{
    //std::cout << "we are drawing!";
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
