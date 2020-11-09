//
// Created by Luke on 02/11/2020.
//

#ifndef UNI_C___CIRCLE_H
#define UNI_C___CIRCLE_H

#include <cmath>
#include <iostream>
#include <cstdio>

class Circle
{
private:
    static const float DEFAULT = 0.0;
    static const double PI = 3.14159265;
    float radius;
    float xpos;
    float ypos;
public:
    // Constructors
    Circle( float r, float x, float y ) {radius = r; xpos = x; ypos = y;}
    explicit Circle( float r ) {radius = r; xpos = DEFAULT, ypos = DEFAULT;}
    Circle() {radius = DEFAULT; xpos = DEFAULT; ypos = DEFAULT;}
    // Copy Constructor
    Circle( const Circle& c) {radius = c.radius; xpos = c.xpos; ypos = c.ypos;}

    // Functions
    float getRadius(){ return radius; };
    float getX(){ return xpos; };
    float getY(){ return ypos; };
    double getArea(){ return PI * (radius * radius); };
    Circle operator+(Circle& c)
    {
        float cRadius = c.getRadius();
        float myRadius = this->getRadius();
        float newRadius = sqrtf((cRadius * cRadius) + (myRadius * myRadius));
        float newX = (c.getX() + this->getX()) / 2;
        float newY = (c.getY() + this->getY()) / 2;
        return Circle (newRadius, newX, newY);
    }
    friend std::ostream& operator<<(std::ostream& os, Circle c)
    {
        std::cout << "Radius = " << c.getRadius() << " at (x, y) = (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    }
    bool operator>(Circle c)
    {
        return this->getRadius() > c.getRadius();
    }



};


#endif //UNI_C___CIRCLE_H
