#include "Player.hpp"

Player::Player(const char* texture) //override
{
    //posX = 0;
   // posY = 0;

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

void Player::Update(bool up, bool down, bool left, bool right)
{
    if (up) 
    {
        position.y -= speed;
    }
    if (down) 
    {
        position.y += speed;
    }
    if (left) 
    {
        //std::cout << "left";
        position.x -= speed;
    }
    if (right) 
    {
        position.x += speed;
    }
    //std::cout << destRect.x<< std::endl;
    destRect.x = position.x;
    destRect.y = position.y;
}
void Player::Render() 
{
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}