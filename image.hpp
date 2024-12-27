// The specification file
#ifndef Image_H
#define Image_H
#include <graphics.h>
#include <string>
using namespace std;

class Image
{
private:
    int size;
	void *image;

    int imageWidth = 100;
	int imageHeight = 100;

public:
Image(int w, int h, string imageDir){
    imageWidth = w;
    imageHeight = h;

    size = imagesize(0,0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(imageDir.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage( 0, 0, imageWidth, imageHeight, image);

	// Once the image has been copied, clear it from the screen
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar( 0, 0, imageWidth, imageHeight);
}

void draw(int x, int y){
    putimage(x, y, image, COPY_PUT);
}

void updateImage(string dir){
    
}

};
 

#endif




