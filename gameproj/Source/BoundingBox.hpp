#pragma once
#ifndef BoundingBox_hpp
#define BoundingBox_hpp

typedef struct 
{
    float x;
    float y;
} Vector2; //a simple vector struct.

typedef struct 
{
    Vector2 min; //position
    Vector2 max; //widht and height
} AABB; //axis aligned bounding box.

#endif