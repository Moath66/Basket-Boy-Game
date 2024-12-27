// #include <cstdlib>
#include <graphics.h>
#include "Boy.hpp"
#include "food.hpp"
#include "score.hpp"
#include "ellipsee.hpp"
#include "fruit.hpp"
#include "vegetable.hpp"
#include "image.hpp"
#include <string>
#include <time.h>

// for testing
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	char key = 0;

	// files
	string healthBarFileDirectory = "Assets/HealthBar/";
	string basketPath = "Assets/Basket1.gif";
	string boyPath = "Assets/boy.gif";
	string BackGroundPath = "Assets/BK.jpg";
	string SoundPath = "Assets/mario1.wav";

	initwindow(screenWidth, screenHeight, "Simple Animation");

	Boy boi(screenWidth / 2, screenHeight / 1.2, 90, 15, COLOR(255, 0, 0));

	Score score(90, 79 / 3);

#define FOODCOUNT 15
	Food *food[FOODCOUNT];
	Fruit fruits[FOODCOUNT];
	Vegetable vegs[FOODCOUNT];

	for (int i = 0; i < FOODCOUNT; i++)
	{
		fruits[i] = Fruit(rand() % screenWidth, -(rand() % 8000), 50, 50, COLOR(rand() % 255, rand() % 225, 0), 10);
		vegs[i] = Vegetable(rand() % screenWidth, -(rand() % 8000), 50, 50, WHITE, -30);

		if (i % 2 == 0)
			food[i] = &fruits[i];
		else
			food[i] = &vegs[i];

		food[i]->draw();
	}
	// cleardevice();

	srand(time(NULL));

	// draw green background
	//  (WHEN NO bk PHOTO)
	// setcolor(COLOR(25, 75, 22));
	// setfillstyle(SOLID_FILL, COLOR(25, 75, 22));
	// bar(0, 0, screenWidth, screenHeight);
	Image bg(getmaxwidth(), getmaxheight(), BackGroundPath);

	int BoyW = 354 / 2.5;
	int BoyH = 867 / 2.5;
	Image boiImage(BoyW, BoyH, boyPath);

	int basketW = 205;
	int basketH = 117;
	Image basketImage(basketW, basketH, basketPath);

	Image healthBarImage(582 / 3, 79 / 3, (healthBarFileDirectory + to_string(boi.getLives()) + ".jpg"));

	while (key != 27)
	{
		delay(1);
		string lines[] = {"help the boy to Eat Fruits ",
						  " and avoid the Vegetables",
						  "(Press ArrowsKeys to move)",
						  "(Press ESC to exit)"};

		bg.draw(0, 0);

		// settextstyle(0, HORIZ_DIR, 3);
		for (int i = 0, y = 200; i < 4; i++, y += 30)
			outtextxy(10, y, (char *)lines[i].c_str());


		// PlaySound( TEXT(SoundPath.c_str()) , NULL, SND_FILENAME | SND_ASYNC );
		 //PlaySound(TEXT(SoundPath.c_str()), NULL, SND_LOOP );
		// PlaySound(TEXT(SoundPath.c_str()), NULL, SND_LOOP | SND_ASYNC);
		// PlaySound(TEXT(SoundPath.c_str()), NULL, SND_FILENAME | SND_ASYNC);
		// draw back Ground
		// readimagefile(BackGroundPath.c_str(), 0, 0, screenWidth, screenHeight);

		// draw Boy
		boiImage.draw(boi.getEllipse().getLeft() -20, boi.getEllipse().getTop());
		// readimagefile(boyPath.c_str(), boi.getEllipse().getX() - BoyW / 2.5, (boi.getEllipse().getY() - BoyH / 2.5) + 150, boi.getEllipse().getX() + BoyW / 2.5, (boi.getEllipse().getY() + BoyH / 2.5) + 150);

		// draw basket
		//		readimagefile(basketPath.c_str(), boi.getEllipse().getX() - basketW / 2, boi.getEllipse().getY() - basketH / 2, boi.getEllipse().getX() + basketW / 2, boi.getEllipse().getY() + basketH / 2);
		basketImage.draw(boi.getEllipse().getLeft()-46, boi.getEllipse().getTop()-40);

		// Show score
		settextstyle(1, HORIZ_DIR, 100);
		setcolor(YELLOW);
		outtextxy(10, 79 / 3, " Score : ");
		score.UpdateScore(0);
		//boi.draw(); // ellipse player 

		// draw healthbar
		 readimagefile((healthBarFileDirectory + to_string(boi.getLives()) + ".jpg").c_str(), 0, 0, 582 / 3, 79 / 3);
		//healthBarImage.draw(0, 0);

		for (int i = 0; i < FOODCOUNT; i++)
		{
			if (&food[i] == nullptr)
				continue;
			food[i]->handleFood(&boi, &score, 25);

			if (food[i]->getEllipse().getY() > screenHeight)
			{
				food[i]->move(-screenHeight - rand() % 70);
			}
		}

		if (kbhit())
		{

			key = toupper(getch());

			if (key == 0)
				key = toupper(getch());

			switch (key)
			{
			case KEY_LEFT:
				boi.move(-50);
				break;
			case KEY_RIGHT:
				boi.move(50);
				break;
			}
		}

		// move from the edge
		if (boi.getEllipse().getX() >= screenWidth + boi.getEllipse().getRX())
		{
			boi.move(-screenWidth);
		}
		else if (boi.getEllipse().getX() <= -boi.getEllipse().getRX())
		{

			boi.move(screenWidth);
		}

		// repeat the Food
		for (int i = 0; i < FOODCOUNT; i++)
		{

			if (food[i]->getEllipse().getY() > screenHeight)
			{
				food[i]->move(rand() % 2000);
			}
		}

		if (boi.getLives() <= 0)
			break;
	}

	// game over
	int bgColor = LIGHTGREEN;
	setcolor(bgColor);
	setfillstyle(SOLID_FILL, bgColor);
	bar(screenWidth / 4, screenHeight / 4, screenWidth - screenWidth / 4, screenHeight / 1.2);

	setcolor(YELLOW);
	settextstyle(0, HORIZ_DIR, 3);
	outtextxy(screenWidth / 3.5, screenHeight / 2, " Game Over , Your Highest Score is  ");

	char *buffer = new char[100];
	sprintf(buffer, "%d", score.getScore());
	outtextxy(screenWidth / 2, screenHeight / 1.8, buffer);

	getch();

	return 0;
}

// string lines[] = { "Eat Fruits and avoid the Vegetable",
//                    "Press ArrowsKeys  to move to the right",
//                    "Press Up Arrow Key or W or w to move to the top",
//                    "Press Down Arrow Key or S or s to move to the bottom",
//                    "Press F1 to move to the center of the screen",
//                    "Press ESC to exit"
//                  };

// for (int i=0, y=10; i<6; i++, y+=30)
// 	outtextxy (10,y, (char*)lines[i].c_str());