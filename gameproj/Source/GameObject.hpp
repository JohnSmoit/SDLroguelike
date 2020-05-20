#pragma once
#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"
class GameObject 
{
    public:

        GameObject() {}
        ~GameObject() {}

        virtual void Update() {}
        virtual void Render() {}
        void bound(float x, float y);
        void invertVelocity();
        void zeroVelocity();
        //SDL_Texture* getTexture();

        Vector2* getPosition();
        Vector2* getVelocity();
        Vector2* getPositionLocal(); //relative to camera for player its always (0, 0)
        float getDirection();
        bool colliding = false;

        SDL_Texture* objtexture;

        //void setPosition(float x, float y);
        AABB* getBoundingBox();
    protected:

        void setPositionLocal(); // sets local position based on global position
        float calculateDirection();

        Vector2 position, positionLocal, velocity;
        float direction;
        AABB boundingBox;

        SDL_Rect srcRect, destRect;


};


#endif /* GameObject.hpp */
