#pragma once
#ifndef Camera_hpp
#define Camera_hpp

#include "GameObject.hpp"
#include <vector>

class Camera : public GameObject 
{
    public:

        Camera(GameObject* obj, SDL_Rect v); //takes in the thing its supposed to be following
        ~Camera();

        void follow(); //possible add offsets and the like for dynamic movement.
        SDL_Rect view;

        //vector<Gameobject*> ViewQuery(v); // takes in an optimized (at some point) list of what to render and returns the array for rendering.
        // arguments: List of all objects.
        // returns: list of objects that need rendering
        //only called in a public camera Update method.

        void GetObjectsForRendering(std::vector<GameObject*> objList);
        
    private:

        std::vector<GameObject*> renderList;
        GameObject* anchor;

        void RenderObjects(std::vector<GameObject*> objList);

};

#endif
