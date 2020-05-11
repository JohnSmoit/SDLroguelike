#pragma once
#ifndef Player_hpp
#define Player_hpp

#include "Entity.hpp"

class Player : public Entity 
{
    public:
        Player(const char* texture);
        ~Player();
        void Update(bool up, bool down, bool left, bool right, bool isJumping);
        void Render();
    private:
        void RegisterInput();
        void move();
        const int speed = 4; //make sure to un-const this later

        //SDL_Rect source, dest;

};

#endif