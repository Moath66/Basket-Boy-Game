// The specification file
#ifndef Fruit_H
#define Fruit_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"
#include "food.hpp"

#include<string>
using namespace std;

class Fruit : public Food
{
protected:
    string applePath = "Assets/apple.jpg";
	string bananasPath = "Assets/bananas.jpg";
	string dorianPath = "Assets/dorian.jpeg";
	string orangePath = "Assets/orange.jpg";
    // file paths of four images
    string fruitPath;


    int size;
	void *image;

    int imageWidth = 100;
	int imageHeight = 100;

	int x = 0;
	int y = 0;

public:
Fruit() : Food(){};
Fruit(int _x, int _y, int _rx, int _ry, int _color = WHITE, int _score = 1) : Food(_x, _y, _rx, _ry, _color){
    score = _score;

    string fruitPaths[4] = {applePath, bananasPath, dorianPath, orangePath};
    fruitPath = fruitPaths[rand() % 4];

    size = imagesize(0,0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(fruitPath.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage( 0, 0, imageWidth, imageHeight, image);

	// Once the image has been copied, clear it from the screen
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar( 0, 0, imageWidth, imageHeight); // behavior of image 

}


void draw(){
    x = getEllipse().getLeft() - imageWidth / 3.5;
    y = getEllipse().getTop() - imageHeight / 3.5;
    putimage(x, y, image, COPY_PUT);
}


 //draws a rectangle of the specified color and fill style over the object to be erased, 
// effectively erasing it from the screen.

void undraw() { 
    int extention = 0; //changed here
    setcolor(COLOR(25, 75, 22));
	setfillstyle(SOLID_FILL, COLOR(25, 75, 22));
	bar( getEllipse().getLeft() - extention, getEllipse().getTop()- extention, getEllipse().getRight()+ extention, getEllipse().getBottom()+ extention);
    }

void handleFood(Boy* boi, Score* _score, int fruitSpeed)
{
    move(fruitSpeed);   //pdates the position and state of a piece of food
    if(inBasket(boi)){
        _score->UpdateScore(score); // when its true
        
        //remove the previous representation of the fruit  from the screen.
        undraw();
        ellipse.setX(rand() % getmaxwidth());
        ellipse.setY(-200);
    } 
}
};

// 
#endif























//Boy(int _x=0 , int _w=0, int _p=0 , int m = 0);



// second Class
// class Boy
// {

// public:

// Boy(int _x=0 , int _w=0, int _p=0 , int _m = 0); // constructor  method

// void draw();
// void undraw();
// void collectFood();

// ~Boy(); // destructor method

// };
