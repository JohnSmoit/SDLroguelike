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

    velocity.x = velocity.y = 0;

    //Vector2 dimensions;
    boundingBox.max.x = srcRect.w;
    boundingBox.max.y = srcRect.h;
    boundingBox.min.x = position.x;
    boundingBox.min.y = position.y;
    //std::cout << boundingBox.max.x << std::endl;


}

void Player::Update(bool up, bool down, bool left, bool right)
{

    //std::cout << destRect.x<< std::endl;
    if (colliding) 
    {
        colliding = false;
        invertVelocity();
        //zeroVelocity();
    }
    else 
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
    }
    position.x += velocity.x;
    position.y += velocity.y;
    destRect.x = position.x;
    destRect.y = position.y;
    boundingBox.min.x = position.x;
    boundingBox.min.y = position.y;
    velocity.x = 0;
    velocity.y = 0;
}
void Player::Render() 
{
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}