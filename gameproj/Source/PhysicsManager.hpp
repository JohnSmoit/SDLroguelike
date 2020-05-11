#pragma once
#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include "GameObject.hpp"
//#include "Game.hpp"

class PhysicsManager 
{
    public:
        static bool checkAABBCollisions(GameObject* obj1, GameObject* obj2);
        static void physicsUpdate(GameObject* obj1, GameObject* obj2);
        static void Rebound(GameObject* obj1, GameObject* obj2);
        static void AABBCollisionRespond(GameObject* obj1, GameObject* obj2);
        static void gravity(GameObject* obj1);
    private:
        const float gravity_constant = 9.8; //not actually accuraate but wc

};



#endif 
