#include "Player.hpp"

Player::Player(const char* texture) //override
{
    //posX = 0;
   // posY = 0;

    objtexture = TextureManager::LoadTexture(texture);

    srcRect.w = 86;
    srcRect.h = 86;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = position.x;
    destRect.y = position.y;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;

    velocity.x = velocity.y = 0;

    //Vector2 dimensions;
    boundingBox.max.x = srcRect.w;
    boundingBox.max.y = srcRect.h;
    boundingBox.min.x = position.x;
    boundingBox.min.y = position.y;
    //std::cout << boundingBox.max.x << std::endl;


}

void Player::Update(bool up, bool down, bool left, bool right, bool isJumping)
{


    if (up) 
    {
        velocity.y -= speed;
    }
    if (down) 
    {
        velocity.y += speed;
    }
    if (left) 
    {
        //std::cout << "left";
        velocity.x -= speed;
    }
    if (right) 
    {
        velocity.x += speed;
    }
    if (isJumping) 
    {
        velocity.y -= 25;
    }

    position.x += velocity.x;
    position.y += velocity.y;
    destRect.x = position.x;
    destRect.y = position.y;
    boundingBox.min.x = position.x;
    boundingBox.min.y = position.y;
}
void Player::Render() 
{
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}