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
    }
}