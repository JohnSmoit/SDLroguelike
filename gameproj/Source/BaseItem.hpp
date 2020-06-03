#pragma once
#ifndef BaseItem_hpp
#define BaseItem_hpp

#include "GameObject.hpp"

class BaseItem : public GameObject 
{
    public:
        BaseItem(SDL_Texture* tex);

        //void pickUp();

    protected:
       // const float DropScaleDown = 0.5;
};



#endif