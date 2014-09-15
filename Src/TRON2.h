/*
UP ARROW 24
DOWN ARROW 25
RIGHT ARROW 26
LEFT ARROW 27
*/

#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "wii_main.c"
#include "wiiuse.h"
#include "graphics.h"
//positions
	int xb1 = 300;
	int xb2 = 1300;
	int yb1 = 450;
	int yb2 = 450;

	int count = 0;	//count to speed up FPS

//mouse vars
int leftclick = 0;
int rightclick = 0;

//declarations
int game(int direction1, int direction2);
int playTron(void);

void left_click(int, int); //detect click
void right_click(int, int); //detect click
void mouse_moved(int, int); //detect mouse move
void MainMenu();

void draw(int Color);


int Grid [900][1600] ={0,0,0};
int directions1 = 1;
int directions2 = 3;
int collisions = 0;


int game (int direction1, int direction2)
{
	

setcolor(YELLOW);

/*-----PLAYER-----*/

switch (direction1){

case 0://down
	yb1 = yb1+1;
	if(Grid[yb1][xb1] == 1)
	{
		return 1;
	}
Grid[yb1][xb1] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike_Down.jpg",xb1-12,yb1-26,xb1+12,yb1+26);
setcolor(9);
circle(xb1,yb1,5);


	break;

case 1://right
	xb1 = xb1+1; 
	if(Grid[yb1][xb1] == 1)
	{
		return 1;
	}
Grid[yb1][xb1] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike_Right.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(9);
circle(xb1,yb1,5);
	break;

case 2://up
	yb1 = yb1-1;
	if(Grid[yb1][xb1] == 1)
	{
		return 1;
	}
Grid[yb1][xb1] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike_Up.jpg",xb1-12,yb1-26,xb1+12,yb1+26);
setcolor(9);
circle(xb1,yb1,5);
	break;

case 3://left
	xb1 = xb1-1;
	if(Grid[yb1][xb1] == 1)
	{
		return 1;
	}
Grid[yb1][xb1] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike_Right.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(9);
circle(xb1,yb1,5);
break;

}//switch ends




/*-------ENEMY-------*/

switch (direction2){

case 0://down
	yb2 = yb2+1;
	if(Grid[yb2+10-31][xb2]==1)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2 - 31][xb2+1]==1 ||Grid[yb2 - 31][xb2+2]==1 || Grid[yb2 - 31][xb2+3]==1 || Grid[yb2 - 31][xb2+4]==1
			|| Grid[yb2 - 31][xb2+5]==1 || Grid[yb2 - 31][xb2+6]==1 || Grid[yb2 - 31][xb2+7]==1 || Grid[yb2 - 31][xb2+8]==1
			|| Grid[yb2 - 31][xb2+9]==1 || Grid[yb2 - 31][xb2+10]==1 || Grid[yb2 - 31][xb2+11]==1)
		{
			xb2 = xb2;
			yb2 = yb2 - 31;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2 - 31][xb2-1]==1 ||Grid[yb2 - 31][xb2-2]==1 || Grid[yb2 - 31][xb2-3]==1 || Grid[yb2 - 31][xb2-4]==1
			|| Grid[yb2 - 31][xb2-5]==1 || Grid[yb2 - 31][xb2-6]==1 || Grid[yb2 - 31][xb2-7]==1 || Grid[yb2 - 31][xb2-8]==1
			|| Grid[yb2 - 31][xb2-9]==1 || Grid[yb2 - 31][xb2-10]==1 || Grid[yb2 - 31][xb2-11]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 3;}
		}

		game(directions1, directions2);

		break;
		
	}

	//if approaching bottom of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2 - 31+10 == 900 && xb2+10 != 1600 && xb2-10 != 0)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2 - 31][xb2+1]==1 ||Grid[yb2 - 31][xb2+2]==1 || Grid[yb2 - 31][xb2+3]==1 || Grid[yb2 - 31][xb2+4]==1
			|| Grid[yb2 - 31][xb2+5]==1 || Grid[yb2 - 31][xb2+6]==1 || Grid[yb2 - 31][xb2+7]==1 || Grid[yb2 - 31][xb2+8]==1
			|| Grid[yb2 - 31][xb2+9]==1 || Grid[yb2 - 31][xb2+10]==1 || Grid[yb2 - 31][xb2+11]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2 - 31][xb2-1]==1 ||Grid[yb2 - 31][xb2-2]==1 || Grid[yb2 - 31][xb2-3]==1 || Grid[yb2 - 31][xb2-4]==1
			|| Grid[yb2 - 31][xb2-5]==1 || Grid[yb2 - 31][xb2-6]==1 || Grid[yb2 - 31][xb2-7]==1 || Grid[yb2 - 31][xb2-8]==1
			|| Grid[yb2 - 31][xb2-9]==1 || Grid[yb2 - 31][xb2-10]==1 || Grid[yb2 - 31][xb2-11]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 1;
		}

		////if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 - 31 - 0;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 31 - 0;			
			directions2 = 3;}
		}
			

		game(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within 10 pixels of the right boarder of screen forced to trun left
	if(yb2 - 31+10 == 900 && xb2+11 == 1600 ||yb2 - 31+10 == 900 && xb2+10 == 1600 || yb2 - 31+10 == 900 && xb2+9 == 1600 || yb2 - 31+10 == 900 && xb2+8 == 1600 || yb2 - 31+10 == 900 && xb2+7 == 1600 || yb2 - 31+10 == 900 && xb2+6 == 1600 || yb2 - 31+10 == 900 && xb2+5 == 1600 || yb2 - 31+10 == 900 && xb2+4 == 1600 || yb2 - 31+10 == 900 && xb2+3 == 1600 || yb2 - 31+10 == 900 && xb2+2 == 1600 || yb2 - 31+10 == 900 && xb2+1 == 1600 )
	{
		xb2 = xb2 + 0;
		yb2 = yb2 - 31 - 0;
		directions2 = 3;
		game(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within 10 pixels of the left boarder of screen forced to trun right
	if(yb2 - 31+10 == 900 && xb2-11 == 0 || yb2 - 31+10 == 900 && xb2-10 == 0 || yb2 - 31+10 == 900 && xb2-9 == 0|| yb2 - 31+10 == 900 && xb2-8 == 0 || yb2 - 31+10 == 900 && xb2-7 == 0 || yb2 - 31+10 == 900 && xb2-6 == 0 || yb2 - 31+10 == 900 && xb2-5 == 0 || yb2 - 31+10 == 900 && xb2-4 == 0 || yb2 - 31+10 == 900 && xb2-3 == 0 || yb2 - 31+10 == 900 && xb2-2 == 0 || yb2 - 31+10 == 900 && xb2-1 == 0)
	{
		xb2 = xb2 - 0;
		yb2 = yb2 - 31 - 0;
		directions2 = 1;
		game(directions1, directions2);
		break;
	}
	//yb2 - 31 = yb2 - 31+1;
	if(Grid[yb2 - 31-0][xb2] == 1)
	{
		return 1;
	}
	Grid[yb2 - 31-0][xb2] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike2_Down.jpg",xb2-12,yb2 - 31-26,xb2+12,yb2 - 31+26);
setcolor(12);
circle(xb2,yb2 - 31-0,5);

	break;



case 1://right
	xb2 = xb2+1;
	if(Grid[yb2][xb2-31+10-0]==1)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-1][xb2-31]==1 || Grid[yb2-2][xb2-31]==1 || Grid[yb2-3][xb2-31]==1 || Grid[yb2-4][xb2-31]==1 || Grid[yb2-5][xb2-31]==1 ||
			Grid[yb2-6][xb2-31]==1 || Grid[yb2-7][xb2-31]==1 || Grid[yb2-8][xb2-31]==1 || Grid[yb2-9][xb2-31]==1 || Grid[yb2-10][xb2-31]==1 || Grid[yb2-11][xb2-31]==1)
		{
			xb2 = xb2-31 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+1][xb2-31]==1 || Grid[yb2+2][xb2-31]==1 || Grid[yb2+3][xb2-31]==1 || Grid[yb2+4][xb2-31]==1 || Grid[yb2+5][xb2-31]==1 ||
			Grid[yb2+6][xb2-31]==1 || Grid[yb2+7][xb2-31]==1 || Grid[yb2+8][xb2-31]==1 || Grid[yb2+9][xb2-31]==1 || Grid[yb2][xb2-31]==1 ||  Grid[yb2+11][xb2-31]==1)
		{
			xb2 = xb2-31 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2-31 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

			if(r == 1){
			xb2 = xb2-31 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		game(directions1, directions2);
		break;
		
	}
	//if approaching right of screen and top and bottom boarders are not withing 10 pixles will proceed to drop down
	if(xb2-31+10 == 1600 && yb2-10 != 0 && yb2+10 != 900)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-1][xb2-31-0]==1 || Grid[yb2-2][xb2-31-0]==1 || Grid[yb2-3][xb2-31-0]==1 || Grid[yb2-4][xb2-31-0]==1 || Grid[yb2-5][xb2-31-0]==1 ||
			Grid[yb2-6][xb2-31-0]==1 || Grid[yb2-7][xb2-31-0]==1 || Grid[yb2-8][xb2-31-0]==1 || Grid[yb2-9][xb2-31-0]==1 || Grid[yb2-10][xb2-31-0]==1 || Grid[yb2-11][xb2-31-0]==1)
		{
			xb2 = xb2-31 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+1][xb2-31]==1 || Grid[yb2+2][xb2-31]==1 || Grid[yb2+3][xb2-31]==1 || Grid[yb2+4][xb2-31]==1 || Grid[yb2+5][xb2-31]==1 ||
			Grid[yb2+6][xb2-31]==1 || Grid[yb2+7][xb2-31]==1 || Grid[yb2+8][xb2-31]==1 || Grid[yb2+9][xb2-31]==1 || Grid[yb2+10][xb2-31]==1 || Grid[yb2+11][xb2-31]==1)
		{
			xb2 = xb2-31 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if both top and bottom are clear up to 10 pixles it will randomly determine to turn up or down
		else
		{
			srand( time(NULL) );
		int r = rand()%2;
		if(r == 0){
			xb2 = xb2-31 - 0;
			yb2 = yb2 + 0;				
			directions2 = 0;}

		if(r == 1){
			xb2 = xb2-31 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		game(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within 10 pixles of the top boarder forced to turn down
	if(xb2-31+10 == 1600 && yb2-11 == 0 ||xb2-31+10 == 1600 && yb2-10 == 0 || xb2-31+10 == 1600 && yb2-9 == 0 || xb2-31+10 == 1600 && yb2-8 == 0 || xb2-31+10 == 1600 && yb2-7 == 0 || 
		xb2-31+10 == 1600 && yb2-6 == 0 || xb2-31+10 == 1600 && yb2-5 == 0 || xb2-31+10 == 1600 && yb2-4 == 0 || xb2-31+10 == 1600 && yb2-3 == 0 || 
		xb2-31+10 == 1600 && yb2-2 == 0 || xb2-31+10 == 1600 && yb2-1 == 0 )
	{
		xb2 = xb2-31 - 0;
		yb2 = yb2 + 0;
		directions2 = 0;
		game(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within 10 pixles of the bottom boarder forced to turn up
	if(xb2-31+10 == 1600 && yb2+11 == 900 || xb2-31+10 == 1600 && yb2+10 == 900 || xb2-31+10 == 1600 && yb2+9 == 900 || xb2-31+10 == 1600 && yb2+8 == 900 || xb2-31+10 == 1600 && yb2+7 == 900 ||
		xb2-31+10 == 1600 && yb2+6 == 900 || xb2-31+10 == 1600 && yb2+5 == 900 || xb2-31+10 == 1600 && yb2+4 == 900 || xb2-31+10 == 1600 && yb2+3 == 900 ||
		xb2-31+10 == 1600 && yb2+3 == 900 || xb2-31+10 == 1600 && yb2+1 == 900)
	{
		xb2 = xb2-31 - 0;
		yb2 = yb2 - 0;
		directions2 = 2;
		game(directions1, directions2);
		break;
	}
	//xb2-31 = xb2-31+1;
	if(Grid[yb2][xb2-31-0] == 1)
	{
		return 1;
	}
	Grid[yb2][xb2-31-0] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike2_Right.jpg",xb2-31-26,yb2-12,xb2-31+26,yb2+12);
setcolor(12);
circle(xb2-31 - 0,yb2,5);
	break;




case 2://up
	yb2 = yb2-1;
	if(Grid[yb2 + 31-10+0][xb2]==1)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2 + 31][xb2+1]==1 ||Grid[yb2 + 31][xb2+2]==1 || Grid[yb2 + 31][xb2+3]==1 || Grid[yb2 + 31][xb2+4]==1
			|| Grid[yb2 + 31][xb2+5]==1 || Grid[yb2 + 31][xb2+6]==1 || Grid[yb2 + 31][xb2+7]==1 || Grid[yb2 + 31][xb2+8]==1
			|| Grid[yb2 + 31][xb2+9]==1 || Grid[yb2 + 31][xb2+10]==1 || Grid[yb2 + 31][xb2+11]==1)
		{
			xb2 = xb2 - 0;
			yb2  = yb2 + 31 + 0;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2 + 31][xb2-1]==1 ||Grid[yb2 + 31][xb2-2]==1 || Grid[yb2 + 31][xb2-3]==1 || Grid[yb2 + 31][xb2-4]==1
			|| Grid[yb2 + 31][xb2-5]==1 || Grid[yb2 + 31][xb2-6]==1 || Grid[yb2 + 31][xb2-7]==1 || Grid[yb2 + 31][xb2-8]==1
			|| Grid[yb2 + 31][xb2-9]==1 || Grid[yb2 + 31][xb2-10]==1 || Grid[yb2 + 31][xb2-11]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 31 + 0;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 31 + 0;	
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2  = yb2 + 31 + 0;
			directions2 = 3;}
		}

		game(directions1, directions2);

		break;
	}

	//if approaching top of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2 + 31-10 ==0 && xb2+10 != 1600 && xb2-10 != 0)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2 + 31][xb2+1]==1 ||Grid[yb2 + 31][xb2+2]==1 || Grid[yb2 + 31][xb2+3]==1 || Grid[yb2 + 31][xb2+4]==1
			|| Grid[yb2 + 31][xb2+5]==1 || Grid[yb2 + 31][xb2+6]==1 || Grid[yb2 + 31][xb2+7]==1 || Grid[yb2 + 31][xb2+8]==1
			|| Grid[yb2 + 31][xb2+9]==1 || Grid[yb2 + 31][xb2+10]==1 || Grid[yb2 + 31][xb2+11]==1)
		{
			xb2 = xb2 - 0;
			yb2  = yb2 + 31 + 0;
			directions2 = 3;;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2 + 31][xb2-1]==1 ||Grid[yb2 + 31][xb2-2]==1 || Grid[yb2 + 31][xb2-3]==1 || Grid[yb2 + 31][xb2-4]==1
			|| Grid[yb2 + 31][xb2-5]==1 || Grid[yb2 + 31][xb2-6]==1 || Grid[yb2 + 31][xb2-7]==1 || Grid[yb2 + 31][xb2-8]==1
			|| Grid[yb2 + 31][xb2-9]==1 || Grid[yb2 + 31][xb2-10]==1 || Grid[yb2 + 31][xb2-11]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 31 + 0;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 31 + 0;	
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 + 31 + 0;
			directions2 = 3;}
		}

		game(directions1, directions2);

		break;
	}

	
	//if approaching top of the screen and is within 10 pixles from the right boarder will be forced left
	if(yb2 + 31-10 == 0 && xb2+11 == 1600 || yb2 + 31-10 == 0 && xb2+10 == 1600 || yb2 + 31-10 == 0 && xb2+9 == 1600 || yb2 + 31-10 == 0 && xb2+8 == 1600 || yb2 + 31-10 == 0 && xb2+7 == 1600 ||
		yb2 + 31-10 == 0 && xb2+6 == 1600 || yb2 + 31-10 == 0 && xb2+5 == 1600 || yb2 + 31-10 == 0 && xb2+4 == 1600 || yb2 + 31-10 == 0 && xb2+3 == 1600 ||
		yb2 + 31-10 == 0 && xb2+2 == 1600 || yb2 + 31-10 == 0 && xb2+1 == 1600)
	{
		xb2 = xb2 - 0;
		yb2 = yb2 + 31 + 0;
		directions2 = 3;
		game(directions1, directions2);
		break;
	}

	//if approaching top of the screen and is within 10 pixles from the left boarder will be forced right
	if(yb2 + 31-10 == 0 && xb2-11 == 0 || yb2 + 31-10 == 0 && xb2-10 == 0 || yb2 + 31-10 == 0 && xb2-9 == 0 || yb2 + 31-10 == 0 && xb2-8 == 0 || yb2 + 31-10 == 0 && xb2-7 == 0 || yb2 + 31-10 == 0 && xb2-6 == 0 ||
		yb2 + 31-10 == 0 && xb2-5 == 0 || yb2 + 31-10 == 0 && xb2-4 == 0 || yb2 + 31-10 == 0 && xb2-3 == 0 || yb2 + 31-10 == 0 && xb2-2 == 0 || yb2 + 31-10 == 0 && xb2-1 == 0)
	{
		xb2 = xb2 + 0;
		yb2 = yb2 + 31 + 0;	
		directions2 = 1;
		game(directions1, directions2);
		break;
	}
	//yb2 + 31 = yb2 + 31-1;
	if(Grid[yb2 + 31+0][xb2] == 1)
	{
		return 1;
	}
	Grid[yb2 + 31+0][xb2] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike2_Down.jpg",xb2-12,yb2 + 31-26,xb2+12,yb2 + 31+26);
setcolor(12);
circle(xb2,yb2 + 31 + 0,5);
	break;



case 3://left
	xb2 = xb2-1;
	if(Grid[yb2][xb2+31-10+0]==1)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-1][xb2+31]==1 || Grid[yb2-2][xb2+31]==1 || Grid[yb2-3][xb2+31]==1 || Grid[yb2-4][xb2+31]==1 || Grid[yb2-5][xb2+31]==1 ||
			Grid[yb2-6][xb2+31]==1 || Grid[yb2-7][xb2+31]==1 || Grid[yb2-8][xb2+31]==1 || Grid[yb2-9][xb2+31]==1 || Grid[yb2-10][xb2+31]==1  || Grid[yb2-11][xb2+31]==1)
		{
			xb2= xb2+31 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+1][xb2+31]==1 || Grid[yb2+2][xb2+31]==1 || Grid[yb2+3][xb2+31]==1 || Grid[yb2+4][xb2+31]==1 || Grid[yb2+5][xb2+31]==1 ||
			Grid[yb2+6][xb2+31]==1 || Grid[yb2+7][xb2+31]==1 || Grid[yb2+8][xb2+31]==1 || Grid[yb2+9][xb2+31]==1 || Grid[yb2+10][xb2+31]==1 || Grid[yb2+11][xb2+31]==1)
		{
			xb2 = xb2+31 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2= xb2+31 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

			if(r == 1){
			xb2 = xb2+31 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		game(directions1, directions2);
		break;
		
	}


	//if approaching the left of the screen and top and bottom boarders not within 10 pixles will drop down
	if(xb2+31-10 == 0 && yb2+10 != 900 && yb2-10 != 0)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-1][xb2+31]==1 || Grid[yb2-2][xb2+31]==1 || Grid[yb2-3][xb2+31]==1 || Grid[yb2-4][xb2+31]==1 || Grid[yb2-5][xb2+31]==1 ||
			Grid[yb2-6][xb2+31]==1 || Grid[yb2-7][xb2+31]==1 || Grid[yb2-8][xb2+31]==1 || Grid[yb2-9][xb2+31]==1 || Grid[yb2-10][xb2+31]==1  || Grid[yb2-11][xb2+31]==1)
		{
			xb2= xb2+31 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+1][xb2+31]==1 || Grid[yb2+2][xb2+31]==1 || Grid[yb2+3][xb2+31]==1 || Grid[yb2+4][xb2+31]==1 || Grid[yb2+5][xb2+31]==1 ||
			Grid[yb2+6][xb2+31]==1 || Grid[yb2+7][xb2+31]==1 || Grid[yb2+8][xb2+31]==1 || Grid[yb2+9][xb2+31]==1 || Grid[yb2+10][xb2+31]==1 || Grid[yb2+11][xb2+31]==1)
		{
			xb2= xb2+31 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2= xb2+31 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

			if(r == 1){
			xb2= xb2+31 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		game(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within 10 pixles of the bottom boarder forced to turn up
	if(xb2+31-10 == 0 && yb2+11 == 900 || xb2+31-10 == 0 && yb2+10 == 900 || xb2+31-10 == 0 && yb2+9 == 900 || xb2+31-10 == 0 && yb2+8 == 900 || xb2+31-10 == 0 && yb2+7 == 900 ||
		xb2+31-10 == 0 && yb2+6 == 900 || xb2+31-10 == 0 && yb2+5 == 900 || xb2+31-10 == 0 && yb2+4 == 900 || xb2+31-10 == 0 && yb2+3 == 900 ||
		xb2+31-10 == 0 && yb2+2 == 900 || xb2+31-10 == 0 && yb2+1 == 900 )
	{
		xb2= xb2+31 + 0;
		yb2 = yb2 - 0;
		directions2 = 2;
		game(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within 10 pixles of the top boarder forced to turn down
	if(xb2+31-10 == 0 && yb2-11 == 0 || xb2+31-10 == 0 && yb2-10 == 0 || xb2+31-10 == 0 && yb2-9 == 0 || xb2+31-10 == 0 && yb2-8 == 0 || xb2+31-10 == 0 && yb2-7 == 0 || xb2+31-10 == 0 && yb2-6 == 0 ||
		xb2+31-10 == 0 && yb2-5 == 0 || xb2+31-10 == 0 && yb2-4 == 0 || xb2+31-10 == 0 && yb2-3 == 0 || xb2+31-10 == 0 && yb2-2 == 0 || xb2+31-10 == 0 && yb2-1 == 0 )
	{
		xb2 = xb2+31 + 0;
		yb2 = yb2 + 0;	
		directions2 = 0;
		game(directions1, directions2);
		break;
	}
	//xb2+31 = xb2+31-1;
	if(Grid[yb2][xb2+31+0] == 1)
	{
		return 1;
	}
	Grid[yb2][xb2+31+0] = 1;
//if((count % 5) == 0)readimagefile("PIX\\Tron_Bike2_Right.jpg",xb2-26,yb2-12,xb2+26,yb2+12);
setcolor(12);
circle(xb2+31 + 0,yb2,5);
break;

}//switch ends
//collision detected
if (xb1 > 1595 || yb1 > 895 || xb1 < 5 || yb1 < 5) return 1;
if (xb2 > 1595 || yb2 > 895 || xb2 < 5 || yb2 < 5) return 1;

else return 0;
}


int playTron(void)
{

readimagefile("PIX\\TRON.jpg",0,0,1600,900);

xb1 = 300;
xb2 = 1300;
yb1 = 450;
yb2 = 450;

directions1 = 1;
directions2 = 3;

//resets grid to all zeroes for next game
memset(Grid, 0, sizeof(Grid));

setbkcolor(RED);

//initialize the wii
//if(!init_wii()){printf("There was a wii error.\n"); return 0;}

while(1){

//outtextxy(750, 800, "Hit spacebar to stop.");


collisions = game(directions1, directions2);


/*wiiuse_poll(wiimotes, MAX_WIIMOTES);

if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_DOWN)){ directions = 0;}
if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_UP)){ directions = 4;}
if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_LEFT)){ directions = 6;}
if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_RIGHT)){ directions = 2;}
if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_A)){ x = 320; y = 240; readimagefile("PIX\\racetrack.jpg",0,0,640,480);}


if (wiimotes[0]->orient.a_pitch > 20 && wiimotes[0]->orient.a_roll < 20 && wiimotes[0]->orient.a_roll > -20){ directions = 0;}//go down
else if (wiimotes[0]->orient.a_pitch > 20 && wiimotes[0]->orient.a_roll > 20){ directions = 1;}//slide right down
else if (wiimotes[0]->orient.a_roll > 20 && wiimotes[0]->orient.a_pitch < 20 && wiimotes[0]->orient.a_pitch > -20){ directions = 2;}//go right
else if (wiimotes[0]->orient.a_pitch > 20 && wiimotes[0]->orient.a_roll < -20){ directions = 7;}

else if (wiimotes[0]->orient.a_pitch < -20){ directions = 4;}
else if (wiimotes[0]->orient.a_roll < -20){ directions = 6;}




printf("wiimote roll  = %f [%f]\n", wiimotes[0]->orient.roll, wiimotes[0]->orient.a_roll);
printf("wiimote pitch = %f [%f]\n", wiimotes[0]->orient.pitch, wiimotes[0]->orient.a_pitch);
printf("-------------------------------------\n");*/

if(collisions){
	readimagefile("PIX\\game_over.jpg",0,0,1600,900);
	Sleep(2000);
	break;
//PlaySound("SOUNDS\\bam.wav", NULL, SND_ASYNC);


	/*if(connected){
		wiiuse_toggle_rumble(wiimotes[0]);
		Sleep(50);
		wiiuse_toggle_rumble(wiimotes[0]);

		if(directions == 0) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_1);
		if(directions == 1) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_2);
		if(directions == 2) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_3);
		if(directions == 3) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_4);

	}*/

}
//for(int i =0; i<1999; i++){}//slow down animation speed
Sleep(11);
//cleardevice();
if (kbhit()) {
	//if(getch()==32)break;
	int ch = getch();
	if(ch == 119)		//Turn Up
		{
			if(directions1 ==  1){
				xb1 = xb1 - 0;
				yb1 = yb1 - 0;}

			if(directions1 ==  3){
				xb1 = xb1 + 0;
				yb1 = yb1 - 0;}

			directions1 = 2;
		}

	if(ch == 100)		//Turn Right
		{
		
			if(directions1 ==  2){
					xb1 = xb1 + 0;
					yb1 = yb1 + 0;}

			if(directions1 ==  0){
					xb1 = xb1 + 0;
					yb1 = yb1 - 0;}
		
		
		
			directions1 = 1;
		}
	
	if(ch == 97)		//Turn Left
		{
			
			if(directions1 ==  2){
					xb1 = xb1 - 0;
					yb1 = yb1 + 0;}

			if(directions1 ==  0){
					xb1 = xb1 - 0;
					yb1 = yb1 - 0;}
			
			
			
			
			directions1 = 3;
		}

	if(ch == 115)		//Turn Down
		{
			if(directions1 ==  1){
				xb1 = xb1 - 0;
				yb1 = yb1 + 0;}

			if(directions1 ==  3){
				xb1 = xb1 + 0;
				yb1 = yb1 + 0;}
			
			directions1 = 0;
		}



}

if(count >= 1000)count = 0;

count ++;

}//while

return 0;
}











void MainMenu(){

int prev_left = 0;
int prev_right = 0;

readimagefile("PIX\\TRON_Main_Menu.jpg",0,0,1600,900);

//draw(12);

while(1){

if(((mousex() > 451)&&( mousex()< 1084))&&(mousey()> 186)&&(mousey() < 314)){

		readimagefile("PIX\\TRON_Main_Menu(Play_Inverted).jpg",0,0,1600,900);

	if(prev_left != leftclick) {
		playTron();
		leftclick = 0;

		}//enf if leftclick
	
	}//end if mouse is on PlayButton

readimagefile("PIX\\TRON_Main_Menu.jpg",0,0,1600,900);

}//end while loop

}//end Main Menu Function






















void left_click(int, int){

	 leftclick++;
 
printf("Left Click!\n");
  
 }; //detect click



void right_click(int, int){

	 rightclick++;
 
	 printf("Right Click!\n");
 
 }; //detect click


void mouse_moved(int, int){
 
 	 //printf("Mouse Moved!\n");
 
 }; //detect mouse move

void draw(int Color){
//create two character arrays (for sprintf)
//sprintf is equivalent to printf but it prints into strings (char arrays) instead of screen
char buff1[100];
char buff2[100];

  while(1){
 	 
//read mouse x, write it into buff1 
sprintf(buff1, "X = %d\n", mousex());
//read mouse y, write it into buff2
sprintf(buff2, "Y = %d\n", mousey());
 
 outtextxy(200, 200, buff1);
 outtextxy(300, 200, buff2);
 outtextxy(200, 400, "Hit spacebar to finish drawing.");

 putpixel(mousex(), mousey(), Color);
 circle(mousex(), mousey(), 2);

 if (kbhit()) {getch(); break;}
 }//while ends

 }//draw ends