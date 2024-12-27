// The implementation file
#include <sstream>
#include <string>
#include <graphics.h>
#include "score.hpp"
using namespace std;


Score::Score(int _x, int _y){
    x = _x;
    y = _y;

    UpdateScore(0);

}

void Score::UpdateScore(int value){
    score += value;

    char* buffer = new char[100];
    char bufferAppend[] = "   "; // to overwrite last digit when decreasing score

    sprintf(buffer, "%d", score);
    setcolor(RED);
    
    //buffer += bufferAppend (two char arrays)
    char * newArray = new char[strlen(buffer)+strlen(bufferAppend)+1];
    strcpy(newArray,buffer);
    strcat(newArray,bufferAppend);

    outtextxy(x, y, newArray);

}


 int Score:: getScore() const{
return score;
 }