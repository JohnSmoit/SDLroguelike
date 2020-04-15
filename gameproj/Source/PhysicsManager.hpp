#pragma once
#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include "GameObject.hpp"
//#include "Game.hpp"

class PhysicsManager 
{
    public:
        static bool checkAABBCollisions(AABB* a, AABB* b);
        static void physicsUpdate(Vector2* v);
        static void Rebound(GameObject* obj1, GameObject* obj2, Vector2* vel); 
    private:
        static void gravity(Vector2* v);
};



#endif 
