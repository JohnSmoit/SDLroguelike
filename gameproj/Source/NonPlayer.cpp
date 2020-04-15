#include "NonPlayer.hpp"

NonPlayer::NonPlayer(const char* texture) 
{
    objtexture = TextureManager::LoadTexture(texture);

    srcRect.w = 43;
    srcRect.h = 43;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = position.x;
    destRect.y = position.y;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    //Vector2 dimensions;
    boundingBox.max.x = position.x + srcRect.w;
    boundingBox.max.y = position.y + srcRect.h;
    std::cout << boundingBox.max.x << std::endl;
    boundingBox.min = position;
}

void NonPlayer::Render() 
{
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}

