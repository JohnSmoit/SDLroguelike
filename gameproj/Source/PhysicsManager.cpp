#include "PhysicsManager.hpp"
#include <cmath>
//#include "GameObject.hpp"

bool PhysicsManager::checkAABBCollisions(GameObject* obj1, GameObject* obj2) 
{
    AABB* a = obj1->getBoundingBox(); //gets what is required for collision detection (bounding boxes)
    AABB* b = obj2->getBoundingBox();
    //Vector2* vel1 = obj1->getVelocity();
    //Vector2* vel2 = obj2->getVelocity();
    std::cout << b->min.x << std::endl;
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
        //AABBCollisionRespond(obj1, obj2);
        return true;
    }
    return false;

}

void PhysicsManager::Rebound(GameObject* obj1, GameObject* obj2) //for two solid objects. Enemy Collision is different.
{

    AABB* a = obj1->getBoundingBox();
    AABB* b = obj2->getBoundingBox();
    Vector2 response;
    Vector2* vel1;
    Vector2* vel2; // unused
   
    Vector2 pos1, pos2; //pos 1 is obj1's central position based on its bounding box and pos2 is the same with obj2.
    pos1.x = a->min.x + a->max.x / 2;
    pos1.y = a->min.y + a->max.y / 2;
    pos2.x = b->min.x + b->max.x / 2;
    pos2.y = b->min.y + b->max.y / 2;
    vel1 = obj1->getVelocity();
    //vel2 = obj2->getVelocity();
    //std::cout << vel1->x << std::endl;
    //determines whether obj1 is to the left or right of obj2's central position
    if (abs(pos1.x - pos2.x) > abs(pos1.y - pos2.y)) { //is now based on position so that collisions happen reliably.
        if (pos1.x > pos2.x) 
        {
            response.x = (b->min.x + b->max.x - a->min.x); 
        }
        else 
        {
            response.x = -(a->min.x + a->max.x - b->min.x);
        }
    }
    else if (abs(pos1.x - pos2.x) < abs(pos1.y - pos2.y)) {
        if (pos1.y < pos2.y) 
        {
            response.y = -(a->min.y + a->max.y - b->min.y);
        }
        else 
        {
            response.y = (b->min.y + b->max.y - a->min.y);
        }
    }
    /*
    todo 5/6/20 : make the response method factor in differences in height and width.
    so that when Bboxes have different widths than heights, the movable object does not glitch.
    */

    obj1->bound(a->min.x + response.x, a->min.y + response.y);

}

void PhysicsManager::gravity(GameObject* obj1) //temporary
{
    Vector2* vY = obj1->getVelocity();
    vY->y += gravity_constant;
}

void PhysicsManager::physicsUpdate(GameObject* obj1, GameObject* obj2) 
{
    if (PhysicsManager::checkAABBCollisions(obj1, obj2)) //collisions checked after movement
    {
        PhysicsManager::Rebound(obj1, obj2); // replace with generalized version once more than one enemy exists.
    }
    else 
    {
        PhysicsManager::gravity(obj1);
    }
}

/*
most of these algorthms were developed without much use of outside sources.

There are sources used for research:

https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
https://stackoverflow.com/questions/3251561/good-2d-collision-response-references

*/