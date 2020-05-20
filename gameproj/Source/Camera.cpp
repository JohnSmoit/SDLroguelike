#include "Camera.hpp"
#include "PhysicsManager.hpp"

Camera::Camera(GameObject* obj, SDL_Rect v) 
{
    view = v;
    anchor = obj;
    position = *anchor->getPosition();
}

void Camera::follow() 
{
    Vector2* pos = anchor->getPosition();
    pos->x -= view.w / 2;
    pos->y -= view.h / 2;
    position = *pos;
    
}

void Camera::GetObjectsForRendering(std::vector<GameObject*> objList) 
{
    std::vector<GameObject*> renderList;
    for (int i = 0; i < objList.size(); i++) 
    {
        if (PhysicsManager::checkAABBCollisions(this, objList[i])) 
        {
            renderList.push_back(objList[i]);
        }
    }
}

void Camera::RenderObjects(std::vector<GameObject*> list) 
{
    for (int i = 0; i < list.size(); i++) 
    {
        float offsetX, offsetY;

        offsetX = list[i]->getPosition()->x - position.x;
        offsetY = list[i]->getPosition()->y - position.y;

        AABB* a = list[i]->getBoundingBox();

        SDL_Rect src, dest;
        src.w = dest.w = a->max.x;
        src.h = dest.h = a->max.y;

        dest.x = offsetX;
        dest.y = offsetY;

        SDL_RenderCopy(Game::renderer, list[i]->objtexture, &src, &dest);
    }
}