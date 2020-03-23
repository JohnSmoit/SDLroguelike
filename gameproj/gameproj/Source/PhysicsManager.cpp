#include "PhysicsManager.hpp"
#include <cmath>
//#include "GameObject.hpp"

bool PhysicsManager::checkAABBCollisions(AABB* a, AABB* b) 
{
    float d1x = b->min.x - a->max.x;
    float d1y = b->min.y - a->max.y;
    float d2x = a->min.x - b->max.x;
    float d2y = a->min.y - b->max.y;

    std::cout << d2y << std::endl;

    if (d1x > 0.0f || d1y > 0.0f) {
        return false;
    }
    /*checks the distance between the two x positions and y positions.
    if either is greater than 0, the boxes aren't colliding.*/
    if (d2x > 0.0f || d2y > 0.0f) {
        return false;
    }
    return true;
}

void PhysicsManager::Rebound(GameObject* obj1, GameObject* obj2) //for two solid objects. Enemy Collision is different.
{
    
}