// The specification file
#ifndef Boy_H
#define Boy_H
#include <graphics.h>
#include "ellipsee.hpp"

class Boy
{
private:
    Ellipsee ellipse; 
    int color;
    int lives = 5;
    void _draw(int c) const;
    void _move(int _dx);

public:

 Boy(int _x, int _y, int _rx, int _ry, int _color);

    void draw() const;
    void undraw() const;
    void move(int _dx); // use parameters for movement. To be used by the player object
    void hurt();
    bool dead() const;

Ellipsee getEllipse() const;
int width();
int getLives() const;


~Boy(); // destructor method

};

// 
#endif

















