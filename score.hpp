// The specification file
#ifndef Score_H
#define Score_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"

class Score
{
private:
int score = 0;
int x,y;

public:
Score(int x, int y); 
void UpdateScore(int value);
int getScore() const;


};
 

#endif




