#pragma once
#include <iostream>


struct Vector2f
{
    float x, y;

    Vector2f()
    :x(0.0f), y(0.0f)
    {}

    Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

    void print()
    {
        std::cout << x << " , " << y << std::endl;
    }
    
    bool operator==(const Vector2f &vector) const {

        return ((this->x == vector.x) && (this->y == vector.y));
    }
};
