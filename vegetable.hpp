// The specification file
#ifndef Vegetable_H
#define Vegetable_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"
#include "food.hpp"

class Vegetable : public Food
{
protected:
	string tomatoPath = "Assets/tomato.jpg";
	string peaPath = "Assets/pea.jpg";
	string potatoPath = "Assets/potato.jpg";
    string vegPath;

    int size;
	void *image;

    int imageWidth = 100;
	int imageHeight = 100;

	int x = 0;
	int y = 0;

public:
Vegetable() : Food(){};
Vegetable(int _x, int _y, int _rx, int _ry, int _color, int _score) : Food(_x, _y, _rx, _ry, _color){
    score = _score;

    string vegPaths[3] = {tomatoPath, peaPath, potatoPath};
    vegPath = vegPaths[rand() % 3];

    size = imagesize(0,0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(vegPath.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage( 0, 0, imageWidth, imageHeight, image);

	 //remove the previous representation of the food from the screen.
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar( 0, 0, imageWidth, imageHeight); 
    // to draw a rectangle with a specified position and size in a graphics context. 

}
void draw(){
    x = getEllipse().getLeft() - imageWidth / 3.5;
    y = getEllipse().getTop() - imageHeight / 3.5;
    putimage(x, y, image, COPY_PUT);
}

void undraw() { 
    int extention = 30;
    setcolor(COLOR(25, 75, 22));
	setfillstyle(SOLID_FILL, COLOR(25, 75, 22));
	bar( getEllipse().getLeft() - extention, getEllipse().getTop()- extention, getEllipse().getRight()+ extention, getEllipse().getBottom()+ extention);
    }


 //overriding   
void handleFood(Boy* boi, Score* _score, int fruitSpeed)
{
    move(fruitSpeed); 
    if(inBasket(boi)){
        boi->hurt();

        //respawn
        undraw();
        ellipse.setX(rand() % getmaxwidth());
        ellipse.setY(-200);
    } 
}
};

// 
#endif


