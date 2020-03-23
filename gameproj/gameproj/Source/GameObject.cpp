#include "GameObject.hpp"
#include "TextureManager.hpp"




Vector2* GameObject::getPosition() 
{
    return &position;
}
AABB* GameObject::getBoundingBox() 
{
    return &boundingBox;
}

void GameObject::bound(float x, float y) 
{
    position.x = x;
    position.y = y;
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