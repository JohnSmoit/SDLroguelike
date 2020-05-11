#pragma once
#ifndef Entity_hpp
#define Entity_hpp

#include "GameObject.hpp"


class Entity : public GameObject 
{
    public:
        Entity() {}
        ~Entity() {}
        virtual void spawn() {} //temporary essentially an init method.
        virtual void Update() {}
        virtual void Render() {}
    protected:
        int health;
        bool isAlive = true;
        int width, height; // translated to collision box
        SDL_Rect hitBox, displayBox;
        float posX, posY; //temporary positions and velocities.
        float velX, velY;

};

/*Entity:
- Base class of all entities.
needs to be displayed, needs to have a collision box, needs to be able to be destroyed
needs to be spawned.
*/

#endif /* Entity.hpp */