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

        //void setPosition(float x, float y);
        AABB* getBoundingBox();
    protected:


        Vector2 position;
        AABB boundingBox;

        SDL_Texture* objtexture;
        SDL_Rect srcRect, destRect;


};


#endif /* GameObject.hpp */
