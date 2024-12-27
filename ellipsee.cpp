#include <cmath>
#include "ellipsee.hpp"

// all Objects 


bool Ellipsee:: ellipseCollision(Ellipsee e1, Ellipsee e2) {
  double dx = e1.x - e2.x;
  double dy = e1.y - e2.y;
  double sumRx = e1.rx + e2.rx;
  double sumRy = e1.ry + e2.ry;

  return dx * dx / (sumRx * sumRx) + dy * dy / (sumRy * sumRy) <= 1;
}

  int Ellipsee:: getX() const {return x;};
  int Ellipsee:: getY() const {return y;};
  int Ellipsee:: getRX() const {return rx;};
  int Ellipsee:: getRY() const {return ry;};

  void Ellipsee:: setX(int i)  {x = i;};
  void Ellipsee:: setY(int i)  {y = i;};
  void Ellipsee:: setRX(int i)  {rx = i;};
  void Ellipsee:: setRY(int i)  {ry = i;};


int Ellipsee::getLeft()const {return x-rx/2;}
int Ellipsee::getRight()const {return x+rx/2;}
int Ellipsee::getTop()const {return y-ry/2;}
int Ellipsee::getBottom()const {return y+ry/2;}




