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
    Vector2 min;
    Vector2 max;
} AABB; //axis aligned bounding box.

#endif