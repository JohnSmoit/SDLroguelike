#include "GameObject.hpp"
#include "TextureManager.hpp"




Vector2* GameObject::getPosition() // gets position
{
    return &position;
}
AABB* GameObject::getBoundingBox() 
{
    return &boundingBox;
}

// SDL_Texture* getTexture() 
// {
//     return objtexture;
// }

void GameObject::bound(float x, float y) 
{
    position.x = x;
    position.y = y;
    destRect.x = position.x;
    destRect.y = position.y;
}
void GameObject::invertVelocity() 
{
    velocity.x *= -1;
    velocity.y *= -1;
    destRect.x = position.x;
    destRect.y = position.y;
}

void GameObject::zeroVelocity() 
{
    velocity.x = 0;
    velocity.y = 0;
}

Vector2* GameObject::getPositionLocal() 
{
    return &positionLocal; // the offset based on camera
}

Vector2* GameObject::getVelocity() 
{
    return &velocity; // the velocity 
}

void GameObject::setPositionLocal() 
{
    
}

float GameObject::getDirection() 
{
    return direction;
}

float GameObject::calculateDirection() 
{
    float dir = atan2f(velocity.y, velocity.x);
    return dir;
}
// GameObject::GameObject(const char* texturesheet, int x, int y) 
// {
//     objtexture = TextureManager::LoadTexture(texturesheet);

//     xpos = x;
//     ypos = y;
// }

/*void GameObject::Update() 
{
    xpos++;

    srcRect.w = 43;
    srcRect.h = 43;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() 
{
    SDL_RenderCopy(Game::renderer, objtexture, &srcRect, &destRect);
}*/