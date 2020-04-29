#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp

#include "Entity.hpp"

class NonPlayer : public Entity 
{
    public:
        NonPlayer(const char* texture);
        ~NonPlayer();
        void spawn() {}
        void Update() {}
        void Render();
    protected:
        virtual void AI() {}
        bool isHostile;

};

#endif