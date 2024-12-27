#include <cmath>
#ifndef Ellipse_H
#define Ellipse_H
// all Objects 
class Ellipsee {
public:
  double x;
  double y;
  double rx;
  double ry;

 bool ellipseCollision(Ellipsee e1, Ellipsee e2);

  int getX() const;
  int getY() const;
  int getRX() const;
  int getRY() const;

  void setX(int i);
  void setY(int i);
  void setRX(int i);
  void setRY(int i);

int getLeft()const;
int getTop()const;
int getBottom()const;
int getRight()const;

};

#endif
