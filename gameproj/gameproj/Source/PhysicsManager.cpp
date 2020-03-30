#include "PhysicsManager.hpp"
#include <cmath>
//#include "GameObject.hpp"

bool PhysicsManager::checkAABBCollisions(AABB* a, AABB* b) 
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
    
}