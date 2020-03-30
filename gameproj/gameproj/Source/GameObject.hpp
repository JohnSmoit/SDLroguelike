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

        Vector2* getPosition();
        Vector2* getPositionLocal(); //relative to camera for player its always (0, 0)

        //void setPosition(float x, float y);
        AABB* getBoundingBox();
    protected:

        void setPositionLocal(); // sets local position based on global position

        Vector2 position, positionLocal;
        AABB boundingBox;

        SDL_Texture* objtexture;
        SDL_Rect srcRect, destRect;


};


#endif /* GameObject.hpp */
