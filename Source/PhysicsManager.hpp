#pragma once
#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include "GameObject.hpp"
//#include "Game.hpp"

class PhysicsManager 
{
    public:
        static bool checkAABBCollisions(GameObject* obj1, GameObject* obj2);
        static void physicsUpdate(Vector2* v);
        static void Rebound(GameObject* obj1, GameObject* obj2);
        static void AABBCollisionRespond(GameObject* obj1, GameObject* obj2);
    private:
        static void gravity(Vector2* v);
};



#endif 
