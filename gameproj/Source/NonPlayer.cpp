#include "NonPlayer.hpp"

NonPlayer::NonPlayer(const char* texture) 
{
    objtexture = TextureManager::LoadTexture(texture);

    srcRect.w = 1000;
    srcRect.h = 1000;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = position.x;
    destRect.y = position.y;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

    //Vector2 dimensions;
    boundingBox.max.x = srcRect.w; //sets the width and height of the AABB
    boundingBox.max.y = srcRect.h;
    std::cout << boundingBox.max.x << std::endl;
    boundingBox.min = position;
}

void NonPlayer::Render() 
{

    boundingBox.min = position; // only changes the POSITION of the AABB.
    //std::cout << boundingBox.min.x << ", " << boundingBox.min.y << std::endl;
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}

