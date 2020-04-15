#include "PhysicsManager.hpp"
#include <cmath>
//#include "GameObject.hpp"

bool PhysicsManager::checkAABBCollisions(AABB* a, AABB* b, Vector2* vel) 
{
    bool x, y;
    x = y = false;
    if (a->min.x + a->max.x > b->min.x && a->min.x < b->min.x + b->max.x) 
    {
        x = true;
    }
    if (a->min.y + a->max.y > b->min.y && a->min.y < b->min.y + b->max.y) 
    {
        y = true;
    }
    if (x && y) 
    {
        return true;
    }
    return false;

}

void PhysicsManager::Rebound(GameObject* obj1, GameObject* obj2) //for two solid objects. Enemy Collision is different.
{
    // //float dir = obj1->getDirection();
    // Vector2* vel = obj1->getVelocity();
    // Vector2* pos = obj1->getPosition();
    // //Vector2 boundOS;
    // obj1->bound(pos->x - vel->x, pos->y - vel->y);
    obj1->colliding = true;

}