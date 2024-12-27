// The implementation file

#include <iostream>
#include <graphics.h>
#include "Boy.hpp"

// (Defining a Member Function) using class name and scope resolution operator (::)

void Boy::_draw(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(ellipse.x, ellipse.y, ellipse.rx, ellipse.ry);
}

void Boy::_move(int _dx)
{
    undraw();
    ellipse.x += _dx;
    draw();
}

Boy::Boy(int _x, int _y, int _rx, int _ry, int _color)
{
    ellipse.x = _x;
    ellipse.y = _y;
    ellipse.rx = _rx;
    ellipse.ry = _ry;
    color = _color;
}
void Boy::draw() const
{// _draw(color);
}
void Boy::undraw() const
{
    //_draw(BLACK);
}
void Boy::move(int _dx) { _move(_dx); }
int Boy::getLives() const { return lives; }
void Boy::hurt()
{
    lives--;
}

Ellipsee Boy::getEllipse() const { return ellipse; }

int Boy::width() { return ellipse.x; };
bool Boy::dead() const
{
    return lives <= 0;
}
Boy::~Boy()
{
}
