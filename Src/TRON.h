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
#include "graphics.h"

//positions
int xb1 = 300;
int xb2 = 1300;
int yb1 = 450;
int yb2 = 450;

//count to speed up FPS
int count = 0;

//difficulty setting
int dif = 10;

//mouse vars
int leftclick = 0;
int rightclick = 0;

//Graphics variable
int graphics = 1;

//declarations
int Tron_LowRes(int direction1, int direction2);	//Low Graphics Capabilities
int Tron_HighRes(int direction1, int direction2);	//High Graphics Capabilities
int playTron(int);



void left_click(int, int); //detect click
void right_click(int, int); //detect click
void mouse_moved(int, int); //detect mouse move
void MainMenu();


void draw(int Color);


int Grid [900][1600] ={0,0,0};
int directions1 = 1;
int directions2 = 3;
int collisions = 0;


int Tron_HighRes (int direction1, int direction2)
{
	
/*-----PLAYER-----*/

switch (direction1){

case 0://down
	yb1 = yb1+1;
	if(Grid[yb1-31][xb1] != 0)
	{
		return 1;
	}
Grid[yb1-31][xb1] = 1;

if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Down.jpg",xb1-12,yb1-26,xb1+12,yb1+26);
setcolor(11);
circle(xb1,yb1-31,5);


	break;

case 1://right
	xb1 = xb1+1; 
	if(Grid[yb1][xb1-31] != 0)
	{
		return 1;
	}
Grid[yb1][xb1-31] = 1;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Right.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(11);
circle(xb1-31,yb1,5);
	break;

case 2://up
	yb1 = yb1-1;
	if(Grid[yb1+31][xb1] != 0)
	{
		return 1;
	}
Grid[yb1+31][xb1] = 1;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Up.jpg",xb1-12,yb1-26,xb1+12,yb1+26);
setcolor(11);
circle(xb1,yb1+31,5);
	break;

case 3://left
	xb1 = xb1-1;
	if(Grid[yb1][xb1+31] != 0)
	{
		return 1;
	}
Grid[yb1][xb1+31] = 1;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Right.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(11);
circle(xb1+31,yb1,5);
break;

}//switch ends




/*-------ENEMY-------*/

switch (direction2){

case 0://down
	yb2 = yb2+1;
	if(Grid[yb2+dif-31][xb2]!=0)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2-31][xb2+dif-9]==1 ||Grid[yb2-31][xb2+dif-8]==1 || Grid[yb2-31][xb2+dif-7]==1 || Grid[yb2-31][xb2+dif-6]==1
			|| Grid[yb2-31][xb2+dif-5]==1 || Grid[yb2-31][xb2+dif-4]==1 || Grid[yb2-31][xb2+dif-3]==1 || Grid[yb2-31][xb2+dif-2]==1
			|| Grid[yb2-31][xb2+dif-1]==1 || Grid[yb2-31][xb2+dif]==1 || Grid[yb2-31][xb2+dif+1]==1 ||
			Grid[yb2-31][xb2+dif-9]==2 ||Grid[yb2-31][xb2+dif-8]==2 || Grid[yb2-31][xb2+dif-7]==2 || Grid[yb2-31][xb2+dif-6]==2
			|| Grid[yb2-31][xb2+dif-5]==2 || Grid[yb2-31][xb2+dif-4]==2 || Grid[yb2-31][xb2+dif-3]==2 || Grid[yb2-31][xb2+dif-2]==2
			|| Grid[yb2-31][xb2+dif-1]==2 || Grid[yb2-31][xb2+dif]==2 || Grid[yb2-31][xb2+dif+1]==2)
		{
			xb2 = xb2 - 31;
			yb2 = yb2 - 31;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2-31][xb2-dif-9]==1 ||Grid[yb2-31][xb2-dif-8]==1 || Grid[yb2-31][xb2-dif-7]==1 || Grid[yb2-31][xb2-dif-6]==1
			|| Grid[yb2-31][xb2-dif-5]==1 || Grid[yb2-31][xb2-dif-4]==1 || Grid[yb2-31][xb2-dif-3]==1 || Grid[yb2-31][xb2-dif-2]==1
			|| Grid[yb2-31][xb2-dif-1]==1 || Grid[yb2-31][xb2-dif]==1 || Grid[yb2-31][xb2-dif+1]==1 ||
			Grid[yb2-31][xb2-1]==2 ||Grid[yb2-31][xb2-2]==2 || Grid[yb2-31][xb2-3]==2 || Grid[yb2-31][xb2-4]==2
			|| Grid[yb2-31][xb2-5]==2 || Grid[yb2-31][xb2-6]==2 || Grid[yb2-31][xb2-7]==2 || Grid[yb2-31][xb2-8]==2
			|| Grid[yb2-31][xb2-9]==2 || Grid[yb2-31][xb2-10]==2 || Grid[yb2-31][xb2-11]==2)
		{
			xb2 = xb2 + 31;
			yb2 = yb2 - 31 ;
			directions2 = 1;
		}

		//if there is a line ahead and the left boarder is within the bikes given buffer it will be forced right
		else if(xb2-dif-9==0 || xb2-dif-8==0 || xb2-dif-7==0 || xb2-dif-6==0 || xb2-dif-5==0
			|| xb2-dif-4==0 || xb2-dif-3==0 || xb2-dif-2==0 || xb2-dif-1==0 || xb2-dif==0 ||
			xb2-dif+1==0)
		{
			xb2 = xb2 + 31;
			yb2 = yb2 - 31;
			directions2 = 1;
		}

		//if there is a line ahead and the right boarder is within the bikes given buffer it will be forced left
		else if (xb2+dif-9 == 1600 || xb2+dif-8==1600 || xb2+dif-7==1600 ||xb2+dif-6==1600 || xb2+dif-5==1600
			|| xb2+dif-4==1600 || xb2+dif-3==1600 ||xb2+dif-2==1600 || xb2+dif-1==1600 || xb2+dif==1600 ||
			xb2+dif+1==1600)
		{
			xb2 = xb2+31;
			yb2 = yb2-31;
			directions2 = 3;
		}


		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 31;
			yb2 = yb2 - 31 ;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 31;
			yb2 = yb2 - 31 ;
			directions2 = 3;}
		}

		Tron_HighRes(directions1, directions2);

		break;
		
	}

	//if approaching bottom of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2 - 31+dif == 900 && xb2+dif != 1600 && xb2-dif != 0)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2-31][xb2+dif-9]==1 ||Grid[yb2-31][xb2+dif-8]==1 || Grid[yb2-31][xb2+dif-7]==1 || Grid[yb2-31][xb2+dif-6]==1
			|| Grid[yb2-31][xb2+dif-5]==1 || Grid[yb2-31][xb2+dif-4]==1 || Grid[yb2-31][xb2+dif-3]==1 || Grid[yb2-31][xb2+dif-2]==1
			|| Grid[yb2-31][xb2+dif-1]==1 || Grid[yb2-31][xb2+dif]==1 || Grid[yb2-31][xb2+dif+1]==1  ||
			Grid[yb2-31][xb2+1]==2 ||Grid[yb2-31][xb2+2]==2 || Grid[yb2-31][xb2+3]==2 || Grid[yb2-31][xb2+4]==2
			|| Grid[yb2-31][xb2+5]==2 || Grid[yb2-31][xb2+6]==2 || Grid[yb2-31][xb2+7]==2 || Grid[yb2-31][xb2+8]==2
			|| Grid[yb2-31][xb2+9]==2 || Grid[yb2-31][xb2+10]==2 || Grid[yb2-31][xb2+11]==2)
		{
			xb2 = xb2 - 31;
			yb2 = yb2 - 31 ;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2-31][xb2-dif-9]!=0 ||Grid[yb2-31][xb2-dif-8]!=0 || Grid[yb2-31][xb2-dif-7]!=0 || Grid[yb2-31][xb2-dif-6]!=0
			|| Grid[yb2-31][xb2-dif-5]!=0 || Grid[yb2-31][xb2-dif-4]!=0 || Grid[yb2-31][xb2-dif-3]!=0 || Grid[yb2-31][xb2-dif-2]!=0
			|| Grid[yb2-31][xb2-dif-1]!=0 || Grid[yb2-31][xb2-dif]!=0 || Grid[yb2-31][xb2-dif+1]!=0 )
		{
			xb2 = xb2 + 31;
			yb2 = yb2 - 31 ;
			directions2 = 1;
		}

		////if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 + 31;
			yb2 = yb2 - 31 ;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 31;
			yb2 = yb2 - 31 ;			
			directions2 = 3;}
		}
			

		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within 10 pixels of the right boarder of screen forced to trun left
	if(yb2-31+dif == 900 && xb2+dif+1 == 1600 ||yb2-31+dif == 900 && xb2+dif == 1600 || yb2-31+dif == 900 && xb2+dif-1 == 1600 || yb2-31+dif == 900 && xb2+dif-2 == 1600 ||
		yb2-31+dif == 900 && xb2+dif-3 == 1600 || yb2-31+dif == 900 && xb2+dif-4 == 1600 || yb2-31+dif == 900 && xb2+dif-5 == 1600 || yb2-31+dif == 900 && xb2+dif-6 == 1600 || 
		yb2-31+dif == 900 && xb2+dif-7 == 1600 || yb2-31+dif == 900 && xb2+dif-8 == 1600 || yb2-31+dif == 900 && xb2+dif-9 == 1600 )
	{
		xb2 = xb2 + 31;
		yb2 = yb2 - 31 ;
		directions2 = 3;
		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within dif pixels of the left boarder of screen forced to trun right
	if(yb2-31+dif == 900 && xb2-dif+1 == 0 || yb2-31+dif == 900 && xb2-dif == 0 || yb2-31+dif == 900 && xb2-dif-1 == 0|| yb2-31+dif == 900 && xb2-dif-2 == 0 || 
		yb2-31+dif == 900 && xb2-dif-3 == 0 || yb2-31+dif == 900 && xb2-dif-4 == 0 || yb2-31+dif == 900 && xb2-dif-5 == 0 || yb2-31+dif == 900 && xb2-dif-6 == 0 || 
		yb2-31+dif == 900 && xb2-dif-7 == 0 || yb2-31+dif == 900 && xb2-dif-8 == 0 || yb2-31+dif == 900 && xb2-dif-9 == 0)
	{
		xb2 = xb2 - 31;
		yb2 = yb2 - 31 ;
		directions2 = 1;
		Tron_HighRes(directions1, directions2);
		break;
	}
	//yb2 - 31 = yb2 - 31+1;
	if(Grid[yb2 - 31-0][xb2] !=0)
	{
		return 2;
	}
	Grid[yb2 - 31-0][xb2] = 2;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Down.jpg",xb2-12,yb2 - 31-26,xb2+12,yb2 - 31+26);
setcolor(COLOR(252,246,2));
circle(xb2,yb2 - 62,5);

	break;



case 1://right
	xb2 = xb2+1;
	if(Grid[yb2][xb2-31+dif]!=0)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2-31]!=0 || Grid[yb2-dif-8][xb2-31]!=0 || Grid[yb2-dif-7][xb2-31]!=0 || Grid[yb2-dif-6][xb2-31]!=0 || Grid[yb2-dif-5][xb2-31]!=0 ||
			Grid[yb2-dif-4][xb2-31]!=0 || Grid[yb2-dif-3][xb2-31]!=0 || Grid[yb2-dif-2][xb2-31]!=0 || Grid[yb2-dif-1][xb2-31]!=0 || Grid[yb2-dif][xb2-31]!=0 || Grid[yb2-dif+1][xb2-31]!=0)
		{
			xb2 = xb2-31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2-31]!=0 || Grid[yb2+dif-8][xb2-31]!=0 || Grid[yb2+dif-7][xb2-31]!=0 || Grid[yb2+dif-6][xb2-31]!=0 || Grid[yb2+dif-5][xb2-31]!=0 ||
			Grid[yb2+dif-4][xb2-31]!=0 || Grid[yb2+dif-3][xb2-31]!=0 || Grid[yb2+dif-2][xb2-31]!=0 || Grid[yb2+dif-1][xb2-31]!=0 || Grid[yb2+dif][xb2-31]!=0 ||  Grid[yb2+dif+1][xb2-31]!=0)
		{
			xb2 = xb2 - 31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if there is a line ahead and the bottom boarder is within the bikes given buffer it will be forced up
		else if(yb2+dif-9==900 || yb2+dif-8==900 ||yb2+dif-7==900 || yb2+dif-6==900 || yb2+dif-5==900 ||
			yb2+dif-4==900 || yb2+dif-3==900 || yb2+dif-2==900 || yb2+dif-1==900 || yb2+dif==900 ||
			yb2+dif+1==900 )
		{
			xb2 = xb2 - 31;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if there is a line ahead and the top boarder is within the bikes given buffer it will be forced down
		else if(yb2-dif-9==0 || yb2-dif-8==0 || yb2-dif-7==0 || yb2-dif-6==0 || yb2-dif-5==0 ||
			yb2-dif-4==0 || yb2-dif-3==0 || yb2-dif-2==0 || yb2-dif-1==0 || yb2-dif==0 || yb2-dif+1==0)
		{
			xb2 = xb2 - 31;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2-31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;}

			if(r == 1){
			xb2 = xb2-31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;}
		}

		Tron_HighRes(directions1, directions2);
		break;
		
	}
	//if approaching right of screen and top and bottom boarders are not withing 10 pixles will proceed to drop down
	if(xb2-31+dif == 1600 && yb2-dif != 0 && dif+dif != 900)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2-31-0]!=0 || Grid[yb2-dif-8][xb2-31-0]!=0 || Grid[yb2-dif-7][xb2-31-0]!=0 || Grid[yb2-dif-6][xb2-31-0]!=0 || Grid[yb2-dif-5][xb2-31-0]!=0 ||
			Grid[yb2-dif-4][xb2-31-0]!=0 || Grid[yb2-dif-3][xb2-31-0]!=0 || Grid[yb2-dif-2][xb2-31-0]!=0 || Grid[yb2-dif-1][xb2-31-0]!=0 || Grid[yb2-dif][xb2-31-0]!=0 || Grid[yb2-dif+1][xb2-31-0]!=0)
		{
			xb2 = xb2-31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2-31]!=0 || Grid[yb2+dif-8][xb2-31]!=0 || Grid[yb2+dif-7][xb2-31]!=0 || Grid[yb2+dif-6][xb2-31]!=0 || Grid[yb2+dif-5][xb2-31]!=0 ||
			Grid[yb2+dif-4][xb2-31]!=0 || Grid[yb2+dif-3][xb2-31]!=0 || Grid[yb2+dif-2][xb2-31]!=0 || Grid[yb2+dif-1][xb2-31]!=0 || Grid[yb2+dif][xb2-31]!=0 || Grid[yb2+dif+1][xb2-31]!=0)
		{
			xb2 = xb2-31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if both top and bottom are clear up to 10 pixles it will randomly determine to turn up or down
		else
		{
			srand( time(NULL) );
		int r = rand()%2;
		if(r == 0){
			xb2 = xb2-31 ;
			yb2 = yb2 + 31;				
			directions2 = 0;}

		if(r == 1){
			xb2 = xb2-31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;}
		}

		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within 10 pixles of the top boarder forced to turn down
	if(xb2-31+dif == 1600 && yb2-11 == 0 ||xb2-31+dif == 1600 && yb2-dif == 0 || xb2-31+dif == 1600 && yb2-9 == 0 || xb2-31+dif == 1600 && yb2-8 == 0 || xb2-31+dif == 1600 && yb2-7 == 0 || 
		xb2-31+dif == 1600 && yb2-6 == 0 || xb2-31+dif == 1600 && yb2-5 == 0 || xb2-31+dif == 1600 && yb2-4 == 0 || xb2-31+dif == 1600 && yb2-3 == 0 || 
		xb2-31+dif == 1600 && yb2-2 == 0 || xb2-31+dif == 1600 && yb2-1 == 0 )
	{
		xb2 = xb2-31 ;
		yb2 = yb2 + 31;
		directions2 = 0;
		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within dif pixles of the bottom boarder forced to turn up
	if(xb2-31+dif == 1600 && yb2+11 == 900 || xb2-31+dif == 1600 && yb2+dif == 900 || xb2-31+dif == 1600 && yb2+9 == 900 || xb2-31+dif == 1600 && yb2+8 == 900 || xb2-31+dif == 1600 && yb2+7 == 900 ||
		xb2-31+dif == 1600 && yb2+6 == 900 || xb2-31+dif == 1600 && yb2+5 == 900 || xb2-31+dif == 1600 && yb2+4 == 900 || xb2-31+dif == 1600 && yb2+3 == 900 ||
		xb2-31+dif == 1600 && yb2+3 == 900 || xb2-31+dif == 1600 && yb2+1 == 900)
	{
		xb2 = xb2-31 ;
		yb2 = yb2 - 31;
		directions2 = 2;
		Tron_HighRes(directions1, directions2);
		break;
	}
	//xb2-31 = xb2-31+1;
	if(Grid[yb2][xb2-31-0] !=0)
	{
		return 2;
	}
	Grid[yb2][xb2-31-0] = 2;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Right.jpg",xb2-31-26,yb2-12,xb2-31+26,yb2+12);
setcolor(COLOR(252,246,2));
circle(xb2-62,yb2,5);
	break;




case 2://up
	yb2 = yb2-1;
	if(Grid[yb2 + 31-dif+0][xb2]!=0)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2+31][xb2+dif-9]!=0 ||Grid[yb2+31][xb2+dif-8]!=0 || Grid[yb2+31][xb2+dif-7]!=0 || Grid[yb2+31][xb2+dif-6]!=0
			|| Grid[yb2+31][xb2+dif-5]!=0 || Grid[yb2+31][xb2+dif-4]!=0 || Grid[yb2+31][xb2+dif-3]!=0 || Grid[yb2+31][xb2+dif-2]!=0
			|| Grid[yb2+31][xb2+dif-1]!=0 || Grid[yb2+31][xb2+dif]!=0 || Grid[yb2+31][xb2+dif+1]!=0)
		{
			xb2 = xb2 - 31;
			yb2  = yb2 + 31 ;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2+31][xb2-dif-9]!=0 ||Grid[yb2+31][xb2-dif-8]!=0 || Grid[yb2+31][xb2-dif-7]!=0 || Grid[yb2+31][xb2-dif-6]!=0
			|| Grid[yb2+31][xb2-dif-5]!=0 || Grid[yb2+31][xb2-dif-4]!=0 || Grid[yb2+31][xb2-dif-3]!=0 || Grid[yb2+31][xb2-dif-2]!=0
			|| Grid[yb2+31][xb2-dif-1]!=0 || Grid[yb2+31][xb2-dif]!=0 || Grid[yb2+31][xb2-dif+1]!=0)
		{
			xb2 = xb2 + 31;
			yb2 = yb2 + 31 ;	
			directions2 = 1;
		}

		//if there is a line ahead and the right boarder is within the bikes given buffer it will be forced left
		else if(xb2+dif-9==1600 || xb2+dif-8==1600 || xb2+dif-7==1600 || xb2+dif-6==1600 || xb2+dif-5==1600 || xb2+dif-4==1600 || xb2+dif-3==1600 ||
			xb2+dif-2==1600 || xb2+dif-1==1600 || xb2+dif==1600 || xb2+dif+1==1600 )
		{
			xb2 = xb2 - 31;
			yb2 = yb2 + 31;
			directions2 = 3;
		}

		//if there is a line ahead and the left boarder is within the bikes given buffer it will be forced right
		else if(xb2-dif-9==0 || xb2-dif-8==0 || xb2-dif-7==0 || xb2-dif-6==0 || xb2-dif-5==0 || xb2-dif-4==0 || xb2-dif-3==0 ||
			xb2-dif-2==0 || xb2-dif-1==0 || xb2-dif==0 || xb2-dif+1==0)
		{
			xb2 = xb2 + 31;
			yb2 = yb2 + 31;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 31;
			yb2 = yb2 + 31 ;	
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 31;
			yb2  = yb2 + 31 ;
			directions2 = 3;}
		}

		Tron_HighRes(directions1, directions2);

		break;
	}

	//if approaching top of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2 + 31-dif ==0 && xb2+dif != 1600 && xb2-dif != 0)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2+31][xb2+dif-9]!=0 ||Grid[yb2+31][xb2+dif-8]!=0 || Grid[yb2+31][xb2+dif-7]!=0 || Grid[yb2+31][xb2+dif-6]!=0
			|| Grid[yb2+31][xb2+dif-5]!=0 || Grid[yb2+31][xb2+dif-4]!=0 || Grid[yb2+31][xb2+dif-3]!=0 || Grid[yb2+31][xb2+dif-2]!=0
			|| Grid[yb2+31][xb2+dif-1]!=0 || Grid[yb2+31][xb2+dif]!=0 || Grid[yb2+31][xb2+dif+1]!=0)
		{
			xb2 = xb2 - 31;
			yb2  = yb2 + 31 ;
			directions2 = 3;;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2+31][xb2-dif-9]!=0 ||Grid[yb2+31][xb2-dif-8]!=0 || Grid[yb2+31][xb2-dif-7]!=0 || Grid[yb2+31][xb2-dif-6]!=0
			|| Grid[yb2+31][xb2-dif-5]!=0 || Grid[yb2+31][xb2-dif-4]!=0 || Grid[yb2+31][xb2-dif-3]!=0 || Grid[yb2+31][xb2-dif-2]!=0
			|| Grid[yb2+31][xb2-dif-1]!=0 || Grid[yb2+31][xb2-dif]!=0 || Grid[yb2+31][xb2-dif+1]!=0)
		{
			xb2 = xb2 + 31;
			yb2 = yb2 + 31 ;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 31;
			yb2 = yb2 + 31 ;	
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 31;
			yb2 = yb2 + 31 ;
			directions2 = 3;}
		}

		Tron_HighRes(directions1, directions2);

		break;
	}

	
	//if approaching top of the screen and is within 10 pixles from the right boarder will be forced left
	if(yb2 + 31-dif == 0 && xb2+11 == 1600 || yb2 + 31-dif == 0 && xb2+dif == 1600 || yb2 + 31-dif == 0 && xb2+9 == 1600 || yb2 + 31-dif == 0 && xb2+8 == 1600 || yb2 + 31-dif == 0 && xb2+7 == 1600 ||
		yb2 + 31-dif == 0 && xb2+6 == 1600 || yb2 + 31-dif == 0 && xb2+5 == 1600 || yb2 + 31-dif == 0 && xb2+4 == 1600 || yb2 + 31-dif == 0 && xb2+3 == 1600 ||
		yb2 + 31-dif == 0 && xb2+2 == 1600 || yb2 + 31-dif == 0 && xb2+1 == 1600)
	{
		xb2 = xb2 - 31;
		yb2 = yb2 + 31 ;
		directions2 = 3;
		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching top of the screen and is within dif pixles from the left boarder will be forced right
	if(yb2 + 31-dif == 0 && xb2-11 == 0 || yb2 + 31-dif == 0 && xb2-dif == 0 || yb2 + 31-dif == 0 && xb2-9 == 0 || yb2 + 31-dif == 0 && xb2-8 == 0 || yb2 + 31-dif == 0 && xb2-7 == 0 || yb2 + 31-dif == 0 && xb2-6 == 0 ||
		yb2 + 31-dif == 0 && xb2-5 == 0 || yb2 + 31-dif == 0 && xb2-4 == 0 || yb2 + 31-dif == 0 && xb2-3 == 0 || yb2 + 31-dif == 0 && xb2-2 == 0 || yb2 + 31-dif == 0 && xb2-1 == 0)
	{
		xb2 = xb2 + 31;
		yb2 = yb2 + 31 ;	
		directions2 = 1;
		Tron_HighRes(directions1, directions2);
		break;
	}
	//yb2 + 31 = yb2 + 31-1;
	if(Grid[yb2 + 31+0][xb2] !=0)
	{
		return 2;
	}
	Grid[yb2 + 31+0][xb2] = 2;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Up.jpg",xb2-12,yb2 + 31-26,xb2+12,yb2 + 31+26);
setcolor(COLOR(252,246,2));
circle(xb2,yb2 + 62,5);
	break;



case 3://left
	xb2 = xb2-1;
	if(Grid[yb2][xb2+31-dif+0]!=0)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2+31]!=0 || Grid[yb2-dif-8][xb2+31]!=0 || Grid[yb2-dif-7][xb2+31]!=0 || Grid[yb2-dif-6][xb2+31]!=0 || Grid[yb2-dif-5][xb2+31]!=0 ||
			Grid[yb2-dif-4][xb2+31]!=0 || Grid[yb2-dif-3][xb2+31]!=0 || Grid[yb2-dif-2][xb2+31]!=0 || Grid[yb2-dif-1][xb2+31]!=0 || Grid[yb2-dif][xb2+31]!=0  || Grid[yb2-dif+1][xb2+31]!=0)
		{
			xb2= xb2+31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2+31]!=0 || Grid[yb2+dif-8][xb2+31]!=0 || Grid[yb2+dif-7][xb2+31]!=0 || Grid[yb2+dif-6][xb2+31]!=0 || Grid[yb2+dif-5][xb2+31]!=0 ||
			Grid[yb2+dif-4][xb2+31]!=0 || Grid[yb2+dif-3][xb2+31]!=0 || Grid[yb2+dif-2][xb2+31]!=0 || Grid[yb2+dif-1][xb2+31]!=0 || Grid[yb2+dif][xb2+31]!=0 || Grid[yb2+dif+1][xb2+31]!=0)
		{
			xb2 = xb2+31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if there is a line ahead and the bottom boarder is within the bikes given buffer it will be forced up
		else if(yb2+dif-9==900 || yb2+dif-8==900 ||yb2+dif-7==900 || yb2+dif-6==900 || yb2+dif-5==900 ||
			yb2+dif-4==900 || yb2+dif-3==900 || yb2+dif-2==900 || yb2+dif-1==900 || yb2+dif==900 ||
			yb2+dif+1==900 )
		{
			xb2 = xb2 + 31;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if there is a line ahead and the top boarder is within the bikes given buffer it will be forced down
		else if(yb2-dif-9==0 || yb2-dif-8==0 || yb2-dif-7==0 || yb2-dif-6==0 || yb2-dif-5==0 ||
			yb2-dif-4==0 || yb2-dif-3==0 || yb2-dif-2==0 || yb2-dif-1==0 || yb2-dif==0 || yb2-dif+1==0)
		{
			xb2 = xb2 - 31;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2= xb2+31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;}

			if(r == 1){
			xb2 = xb2+31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;}
		}

		Tron_HighRes(directions1, directions2);
		break;
		
	}


	//if approaching the left of the screen and top and bottom boarders not within 10 pixles will drop down
	if(xb2+31-dif == 0 && yb2+dif != 900 && yb2-dif != 0)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2+31]!=0 || Grid[yb2-dif-8][xb2+31]!=0 || Grid[yb2-dif-7][xb2+31]!=0 || Grid[yb2-dif-6][xb2+31]!=0 || Grid[yb2-dif-5][xb2+31]!=0 ||
			Grid[yb2-dif-4][xb2+31]!=0 || Grid[yb2-dif-3][xb2+31]!=0 || Grid[yb2-dif-2][xb2+31]!=0 || Grid[yb2-dif-1][xb2+31]!=0 || Grid[yb2-dif][xb2+31]!=0  || Grid[yb2-dif+1][xb2+31]!=0)
		{
			xb2= xb2+31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2+31]!=0 || Grid[yb2+dif-8][xb2+31]!=0 || Grid[yb2+dif-7][xb2+31]!=0 || Grid[yb2+dif-6][xb2+31]!=0 || Grid[yb2+dif-5][xb2+31]!=0 ||
			Grid[yb2+dif-4][xb2+31]!=0 || Grid[yb2+dif-3][xb2+31]!=0 || Grid[yb2+dif-2][xb2+31]!=0 || Grid[yb2+dif-1][xb2+31]!=0 || Grid[yb2+dif][xb2+31]!=0 || Grid[yb2+dif+1][xb2+31]!=0)
		{
			xb2= xb2+31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2= xb2+31 ;
			yb2 = yb2 + 31;			
			directions2 = 0;}

			if(r == 1){
			xb2= xb2+31 ;
			yb2 = yb2 - 31;			
			directions2 = 2;}
		}

		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within 10 pixles of the bottom boarder forced to turn up
	if(xb2+31-dif == 0 && yb2+11 == 900 || xb2+31-dif == 0 && yb2+dif == 900 || xb2+31-dif == 0 && yb2+9 == 900 || xb2+31-dif == 0 && yb2+8 == 900 || xb2+31-dif == 0 && yb2+7 == 900 ||
		xb2+31-dif == 0 && yb2+6 == 900 || xb2+31-dif == 0 && yb2+5 == 900 || xb2+31-dif == 0 && yb2+4 == 900 || xb2+31-dif == 0 && yb2+3 == 900 ||
		xb2+31-dif == 0 && yb2+2 == 900 || xb2+31-dif == 0 && yb2+1 == 900 )
	{
		xb2= xb2+31 ;
		yb2 = yb2 - 31;
		directions2 = 2;
		Tron_HighRes(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within dif pixles of the top boarder forced to turn down
	if(xb2+31-dif == 0 && yb2-11 == 0 || xb2+31-dif == 0 && yb2-dif == 0 || xb2+31-dif == 0 && yb2-9 == 0 || xb2+31-dif == 0 && yb2-8 == 0 || xb2+31-dif == 0 && yb2-7 == 0 || xb2+31-dif == 0 && yb2-6 == 0 ||
		xb2+31-dif == 0 && yb2-5 == 0 || xb2+31-dif == 0 && yb2-4 == 0 || xb2+31-dif == 0 && yb2-3 == 0 || xb2+31-dif == 0 && yb2-2 == 0 || xb2+31-dif == 0 && yb2-1 == 0 )
	{
		xb2 = xb2+31 ;
		yb2 = yb2 + 31;	
		directions2 = 0;
		Tron_HighRes(directions1, directions2);
		break;
	}
	//xb2+31 = xb2+31-1;
	if(Grid[yb2][xb2+31+0] ==1)
	{
		return 2;
	}
	Grid[yb2][xb2+31+0] = 2;
if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Left.jpg",xb2-26,yb2-12,xb2+26,yb2+12);
setcolor(COLOR(252,246,2));
circle(xb2+ 31 ,yb2,5);
break;

}//switch ends
//collision detected
if (xb1 - 31 > 1595  || yb1 - 31 > 895 || xb1 + 31 < 5 || yb1 + 31 < 5) return 1;
if (xb2 - 31 > 1595 || yb2  - 31> 895  || xb2 + 31 < 5 || yb2 + 31 < 5) return 2;

else return 0;
}

int Tron_LowRes (int direction1, int direction2)
{
	
/*-----PLAYER-----*/

switch (direction1){

case 0://down
	yb1 = yb1+1;
	if(Grid[yb1-0][xb1] == 1)
	{
		return 1;
	}
Grid[yb1-0][xb1] = 1;

//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Down.jpg",xb1-12,yb1-26,xb1+12,yb1+26);

setcolor(11);
circle(xb1,yb1-0,5);


	break;

case 1://right
	xb1 = xb1+1; 
	if(Grid[yb1][xb1-0] == 1)
	{
		return 1;
	}
Grid[yb1][xb1-0] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Right.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(11);
circle(xb1-0,yb1,5);
	break;

case 2://up
	yb1 = yb1-1;
	if(Grid[yb1+0][xb1] == 1)
	{
		return 1;
	}
Grid[yb1+0][xb1] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Up.jpg",xb1-12,yb1-26,xb1+12,yb1+26);
setcolor(11);
circle(xb1,yb1+0,5);
	break;

case 3://left
	xb1 = xb1-1;
	if(Grid[yb1][xb1+0] == 1)
	{
		return 1;
	}
Grid[yb1][xb1+0] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike_Left.jpg",xb1-26,yb1-12,xb1+26,yb1+12);
setcolor(11);
circle(xb1+0,yb1,5);
break;

}//switch ends




/*-------ENEMY-------*/

switch (direction2){

case 0://down
	yb2 = yb2+1;
	if(Grid[yb2+dif-0][xb2]==1 || Grid[yb2+dif-0][xb2]==2)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2][xb2+dif-9]==1 ||Grid[yb2][xb2+dif-8]==1 || Grid[yb2][xb2+dif-7]==1 || Grid[yb2][xb2+dif-6]==1
			|| Grid[yb2][xb2+dif-5]==1 || Grid[yb2][xb2+dif-4]==1 || Grid[yb2][xb2+dif-3]==1 || Grid[yb2][xb2+dif-2]==1
			|| Grid[yb2][xb2+dif-1]==1 || Grid[yb2][xb2+dif]==1 || Grid[yb2][xb2+dif+1]==1 ||
			Grid[yb2][xb2+dif-9]==2 ||Grid[yb2][xb2+dif-8]==2 || Grid[yb2][xb2+dif-7]==2 || Grid[yb2][xb2+dif-6]==2
			|| Grid[yb2][xb2+dif-5]==2 || Grid[yb2][xb2+dif-4]==2 || Grid[yb2][xb2+dif-3]==2 || Grid[yb2][xb2+dif-2]==2
			|| Grid[yb2][xb2+dif-1]==2 || Grid[yb2][xb2+dif]==2 || Grid[yb2][xb2+dif+1]==2)
		{
			xb2 = xb2+0;
			yb2 = yb2-0;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2][xb2-dif-9]==1 ||Grid[yb2][xb2-dif-8]==1 || Grid[yb2][xb2-dif-7]==1 || Grid[yb2][xb2-dif-6]==1
			|| Grid[yb2][xb2-dif-5]==1 || Grid[yb2][xb2-dif-4]==1 || Grid[yb2][xb2-dif-3]==1 || Grid[yb2][xb2-dif-2]==1
			|| Grid[yb2][xb2-dif-1]==1 || Grid[yb2][xb2-dif]==1 || Grid[yb2][xb2-dif+1]==1 ||
			Grid[yb2][xb2-1]==2 ||Grid[yb2][xb2-2]==2 || Grid[yb2][xb2-3]==2 || Grid[yb2][xb2-4]==2
			|| Grid[yb2][xb2-5]==2 || Grid[yb2][xb2-6]==2 || Grid[yb2][xb2-7]==2 || Grid[yb2][xb2-8]==2
			|| Grid[yb2][xb2-9]==2 || Grid[yb2][xb2-10]==2 || Grid[yb2][xb2-11]==2)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;
			directions2 = 1;
		}

		//if there is a line ahead and the left boarder is within the bikes given buffer it will be forced right
		else if(xb2-dif-9==0 || xb2-dif-8==0 || xb2-dif-7==0 || xb2-dif-6==0 || xb2-dif-5==0
			|| xb2-dif-4==0 || xb2-dif-3==0 || xb2-dif-2==0 || xb2-dif-1==0 || xb2-dif==0 ||
			xb2-dif+1==0)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;
			directions2 = 1;
		}

		//if there is a line ahead and the right boarder is within the bikes given buffer it will be forced left
		else if (xb2+dif-9 == 1600 || xb2+dif-8==1600 || xb2+dif-7==1600 ||xb2+dif-6==1600 || xb2+dif-5==1600
			|| xb2+dif-4==1600 || xb2+dif-3==1600 ||xb2+dif-2==1600 || xb2+dif-1==1600 || xb2+dif==1600 ||
			xb2+dif+1==1600)
		{
			xb2 = xb2+0;
			yb2 = yb2-0;
			directions2 = 3;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;
			directions2 = 3;}
		}

		Tron_LowRes(directions1, directions2);

		break;
		
	}

	//if approaching bottom of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2+dif == 900 && xb2+dif != 1600 && xb2-dif != 0)
	{
		//if there is a line also within 10 pixels to the right it is forced to go left
		if(Grid[yb2][xb2+dif-9]==1 ||Grid[yb2][xb2+dif-8]==1 || Grid[yb2][xb2+dif-7]==1 || Grid[yb2][xb2+dif-6]==1
			|| Grid[yb2][xb2+dif-5]==1 || Grid[yb2][xb2+dif-4]==1 || Grid[yb2][xb2+dif-3]==1 || Grid[yb2][xb2+dif-2]==1
			|| Grid[yb2][xb2+dif-1]==1 || Grid[yb2][xb2+dif]==1 || Grid[yb2][xb2+dif+1]==1  ||
			Grid[yb2][xb2+1]==2 ||Grid[yb2][xb2+2]==2 || Grid[yb2][xb2+3]==2 || Grid[yb2][xb2+4]==2
			|| Grid[yb2][xb2+5]==2 || Grid[yb2][xb2+6]==2 || Grid[yb2][xb2+7]==2 || Grid[yb2][xb2+8]==2
			|| Grid[yb2][xb2+9]==2 || Grid[yb2][xb2+10]==2 || Grid[yb2][xb2+11]==2)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2][xb2-dif-9]==1 ||Grid[yb2][xb2-dif-8]==1 || Grid[yb2][xb2-dif-7]==1 || Grid[yb2][xb2-dif-6]==1
			|| Grid[yb2][xb2-dif-5]==1 || Grid[yb2][xb2-dif-4]==1 || Grid[yb2][xb2-dif-3]==1 || Grid[yb2][xb2-dif-2]==1
			|| Grid[yb2][xb2-dif-1]==1 || Grid[yb2][xb2-dif]==1 || Grid[yb2][xb2-dif+1]==1 )
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;
			directions2 = 1;
		}

		////if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 3;}
		}
			

		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within 10 pixels of the right boarder of screen forced to trun left
	if(yb2+dif == 900 && xb2+dif+1 == 1600 ||yb2+dif == 900 && xb2+dif == 1600 || yb2+dif == 900 && xb2+dif-1 == 1600 || yb2+dif == 900 && xb2+dif-2 == 1600 ||
		yb2+dif == 900 && xb2+dif-3 == 1600 || yb2+dif == 900 && xb2+dif-4 == 1600 || yb2+dif == 900 && xb2+dif-5 == 1600 || yb2+dif == 900 && xb2+dif-6 == 1600 || 
		yb2+dif == 900 && xb2+dif-7 == 1600 || yb2+dif == 900 && xb2+dif-8 == 1600 || yb2+dif == 900 && xb2+dif-9 == 1600 )
	{
		xb2 = xb2 + 0;
		yb2 = yb2 - 0;
		directions2 = 3;
		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching the bottom of the screen and within 10 pixels of the left boarder of screen forced to trun right
	if(yb2+dif == 900 && xb2-dif+1 == 0 || yb2+dif == 900 && xb2-dif == 0 || yb2+dif == 900 && xb2-dif-1 == 0|| yb2+dif == 900 && xb2-dif-2 == 0 || 
		yb2+dif == 900 && xb2-dif-3 == 0 || yb2+dif == 900 && xb2-dif-4 == 0 || yb2+dif == 900 && xb2-dif-5 == 0 || yb2+dif == 900 && xb2-dif-6 == 0 || 
		yb2+dif == 900 && xb2-dif-7 == 0 || yb2+dif == 900 && xb2-dif-8 == 0 || yb2+dif == 900 && xb2-dif-9 == 0)
	{
		xb2 = xb2 - 0;
		yb2 = yb2 - 0;
		directions2 = 1;
		Tron_LowRes(directions1, directions2);
		break;
	}
	//yb2 = yb2+1;
	if(Grid[yb2-0][xb2] == 1)
	{
		return 2;
	}
	Grid[yb2-0][xb2] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Down.jpg",xb2-12,yb2-26,xb2+12,yb2+26);
setcolor(COLOR(252,246,2));
circle(xb2,yb2-0,5);

	break;



case 1://right
	xb2 = xb2+1;
	if(Grid[yb2][xb2+dif-0]==1)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2]==1 || Grid[yb2-dif-8][xb2]==1 || Grid[yb2-dif-7][xb2]==1 || Grid[yb2-dif-6][xb2]==1 || Grid[yb2-dif-5][xb2]==1 ||
			Grid[yb2-dif-4][xb2]==1 || Grid[yb2-dif-3][xb2]==1 || Grid[yb2-dif-2][xb2]==1 || Grid[yb2-dif-1][xb2]==1 || Grid[yb2-dif][xb2]==1 || Grid[yb2-dif+1][xb2]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2]==1 || Grid[yb2+dif-8][xb2]==1 || Grid[yb2+dif-7][xb2]==1 || Grid[yb2+dif-6][xb2]==1 || Grid[yb2+dif-5][xb2]==1 ||
			Grid[yb2+dif-4][xb2]==1 || Grid[yb2+dif-3][xb2]==1 || Grid[yb2+dif-2][xb2]==1 || Grid[yb2+dif-1][xb2]==1 || Grid[yb2+dif][xb2]==1 ||  Grid[yb2+dif+1][xb2]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if there is a line ahead and the bottom boarder is within the bikes given buffer it will be forced up
		else if(yb2+dif-9==900 || yb2+dif-8==900 ||yb2+dif-7==900 || yb2+dif-6==900 || yb2+dif-5==900 ||
			yb2+dif-4==900 || yb2+dif-3==900 || yb2+dif-2==900 || yb2+dif-1==900 || yb2+dif==900 ||
			yb2+dif+1==900 )
		{
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if there is a line ahead and the top boarder is within the bikes given buffer it will be forced down
		else if(yb2-dif-9==0 || yb2-dif-8==0 || yb2-dif-7==0 || yb2-dif-6==0 || yb2-dif-5==0 ||
			yb2-dif-4==0 || yb2-dif-3==0 || yb2-dif-2==0 || yb2-dif-1==0 || yb2-dif==0 || yb2-dif+1==0)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

		if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		Tron_LowRes(directions1, directions2);
		break;
		
	}
	//if approaching right of screen and top and bottom boarders are not withing 10 pixles will proceed to drop down
	if(xb2+dif == 1600 && yb2-dif != 0 && yb2+dif != 900)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2-0]==1 || Grid[yb2-dif-8][xb2-0]==1 || Grid[yb2-dif-7][xb2-0]==1 || Grid[yb2-dif-6][xb2-0]==1 || Grid[yb2-dif-5][xb2-0]==1 ||
			Grid[yb2-dif-4][xb2-0]==1 || Grid[yb2-dif-3][xb2-0]==1 || Grid[yb2-dif-2][xb2-0]==1 || Grid[yb2-dif-1][xb2-0]==1 || Grid[yb2-dif][xb2-0]==1 || Grid[yb2-dif+1][xb2-0]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2]==1 || Grid[yb2+dif-8][xb2]==1 || Grid[yb2+dif-7][xb2]==1 || Grid[yb2+dif-6][xb2]==1 || Grid[yb2+dif-5][xb2]==1 ||
			Grid[yb2+dif-4][xb2]==1 || Grid[yb2+dif-3][xb2]==1 || Grid[yb2+dif-2][xb2]==1 || Grid[yb2+dif-1][xb2]==1 || Grid[yb2+dif][xb2]==1 || Grid[yb2+dif+1][xb2]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if both top and bottom are clear up to 10 pixles it will randomly determine to turn up or down
		else
		{
			srand( time(NULL) );
		int r = rand()%2;
		if(r == 0){
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;				
			directions2 = 0;}

		if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within 10 pixles of the top boarder forced to turn down
	if(xb2+dif == 1600 && yb2-dif+1 == 0 ||xb2+dif == 1600 && yb2-dif == 0 || xb2+dif == 1600 && yb2-dif-1 == 0 || xb2+dif == 1600 && yb2-dif-2 == 0 || xb2+dif == 1600 && yb2-dif-3 == 0 || 
		xb2+dif == 1600 && yb2-dif-4 == 0 || xb2+dif == 1600 && yb2-dif-5 == 0 || xb2+dif == 1600 && yb2-dif-6 == 0 || xb2+dif == 1600 && yb2-dif-7 == 0 || 
		xb2+dif == 1600 && yb2-dif-8 == 0 || xb2+dif == 1600 && yb2-dif-9 == 0 )
	{
		xb2 = xb2 - 0;
		yb2 = yb2 + 0;
		directions2 = 0;
		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching right boarder of screen and within 10 pixles of the bottom boarder forced to turn up
	if(xb2+dif == 1600 && yb2+dif+1 == 900 || xb2+dif == 1600 && yb2+dif == 900 || xb2+dif == 1600 && yb2+dif-1 == 900 || xb2+dif == 1600 && yb2+dif-2 == 900 || xb2+dif == 1600 && yb2+dif-3 == 900 ||
		xb2+dif == 1600 && yb2+dif-4 == 900 || xb2+dif == 1600 && yb2+dif-5 == 900 || xb2+dif == 1600 && yb2+dif-6 == 900 || xb2+dif == 1600 && yb2+dif-7 == 900 ||
		xb2+dif == 1600 && yb2+dif-8 == 900 || xb2+dif == 1600 && yb2+dif-9 == 900)
	{
		xb2 = xb2 - 0;
		yb2 = yb2 - 0;
		directions2 = 2;
		Tron_LowRes(directions1, directions2);
		break;
	}
	//xb2 = xb2+1;
	if(Grid[yb2][xb2-0] == 1)
	{
		return 2;
	}
	Grid[yb2][xb2-0] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Right.jpg",xb2-26,yb2-12,xb2+26,yb2+12);
setcolor(COLOR(252,246,2));
circle(xb2 - 0,yb2,5);
	break;




case 2://up
	yb2 = yb2-1;
	if(Grid[yb2-dif+0][xb2]==1)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2][xb2+dif-9]==1 ||Grid[yb2][xb2+dif-8]==1 || Grid[yb2][xb2+dif-7]==1 || Grid[yb2][xb2+dif-6]==1
			|| Grid[yb2][xb2+dif-5]==1 || Grid[yb2][xb2+dif-4]==1 || Grid[yb2][xb2+dif-3]==1 || Grid[yb2][xb2+dif-2]==1
			|| Grid[yb2][xb2+dif-1]==1 || Grid[yb2][xb2+dif]==1 || Grid[yb2][xb2+dif+1]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;
			directions2 = 3;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2][xb2-dif-9]==1 ||Grid[yb2][xb2-dif-8]==1 || Grid[yb2][xb2-dif-7]==1 || Grid[yb2][xb2-dif-6]==1
			|| Grid[yb2][xb2-dif-5]==1 || Grid[yb2][xb2-dif-4]==1 || Grid[yb2][xb2-dif-3]==1 || Grid[yb2][xb2-dif-2]==1
			|| Grid[yb2][xb2-dif-1]==1 || Grid[yb2][xb2-dif]==1 || Grid[yb2][xb2-dif+1]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;	
			directions2 = 1;
		}

		//if there is a line ahead and the right boarder is within the bikes given buffer it will be forced left
		else if(xb2+dif-9==1600 || xb2+dif-8==1600 || xb2+dif-7==1600 || xb2+dif-6==1600 || xb2+dif-5==1600 || xb2+dif-4==1600 || xb2+dif-3==1600 ||
			xb2+dif-2==1600 || xb2+dif-1==1600 || xb2+dif==1600 || xb2+dif+1==1600 )
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;
			directions2 = 3;
		}

		//if there is a line ahead and the left boarder is within the bikes given buffer it will be forced right
		else if(xb2-dif-9==0 || xb2-dif-8==0 || xb2-dif-7==0 || xb2-dif-6==0 || xb2-dif-5==0 || xb2-dif-4==0 || xb2-dif-3==0 ||
			xb2-dif-2==0 || xb2-dif-1==0 || xb2-dif==0 || xb2-dif+1==0)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;	
			directions2 = 1;}

			if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;
			directions2 = 3;}
		}

		Tron_LowRes(directions1, directions2);

		break;
	}

	//if approaching top of screen and left and right boarders are not withing 10 pixles will proceed to drop down
	if(yb2-dif ==0 && xb2+dif != 1600 && xb2-dif != 0)
	{
		//if ther is a line also within 10 pixles to the right it is forced to go left
		if(Grid[yb2][xb2+dif-9]==1 ||Grid[yb2][xb2+dif-8]==1 || Grid[yb2][xb2+dif-7]==1 || Grid[yb2][xb2+dif-6]==1
			|| Grid[yb2][xb2+dif-5]==1 || Grid[yb2][xb2+dif-4]==1 || Grid[yb2][xb2+dif-3]==1 || Grid[yb2][xb2+dif-2]==1
			|| Grid[yb2][xb2+dif-1]==1 || Grid[yb2][xb2+dif]==1 || Grid[yb2][xb2+dif+1]==1)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;
			directions2 = 3;;
		}

		//if there is a line also within 10 pixels to the left it is forced to go right
		else if(Grid[yb2][xb2-dif-9]==1 ||Grid[yb2][xb2-dif-8]==1 || Grid[yb2][xb2-dif-7]==1 || Grid[yb2][xb2-dif-6]==1
			|| Grid[yb2][xb2-dif-5]==1 || Grid[yb2][xb2-dif-4]==1 || Grid[yb2][xb2-dif-3]==1 || Grid[yb2][xb2-dif-2]==1
			|| Grid[yb2][xb2-dif-1]==1 || Grid[yb2][xb2-dif]==1 || Grid[yb2][xb2-dif+1]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;	
			directions2 = 1;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction left or right
		else
		{
			srand( time(NULL) );
			int r = rand()%2;
			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;	
			directions2 = 1;}

		if(r == 1){
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;				
			directions2 = 3;}
		}

		Tron_LowRes(directions1, directions2);

		break;
	}

	
	//if approaching top of the screen and is within 10 pixles from the right boarder will be forced left
	if(yb2-dif == 0 && xb2+dif+1 == 1600 || yb2-dif == 0 && xb2+dif == 1600 || yb2-dif == 0 && xb2+dif-1 == 1600 || yb2-dif == 0 && xb2+dif-2 == 1600 || yb2-dif == 0 && xb2+dif-3 == 1600 ||
		yb2-dif == 0 && xb2+dif-4 == 1600 || yb2-dif == 0 && xb2+dif-5 == 1600 || yb2-dif == 0 && xb2+dif-6 == 1600 || yb2-dif == 0 && xb2+dif-7 == 1600 ||
		yb2-dif == 0 && xb2+dif-8 == 1600 || yb2-dif == 0 && xb2+dif-9 == 1600)
	{
		xb2 = xb2 - 0;
		yb2 = yb2 + 0;
		directions2 = 3;
		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching top of the screen and is within 10 pixles from the left boarder will be forced right
	if(yb2-dif == 0 && xb2-dif+1 == 0 || yb2-dif == 0 && xb2-dif == 0 || yb2-dif == 0 && xb2-dif-1 == 0 || yb2-dif == 0 && xb2-dif-2 == 0 || yb2-dif == 0 && xb2-dif-3 == 0 ||
		yb2-dif == 0 && xb2-dif-4 == 0 || yb2-dif == 0 && xb2-dif-5 == 0 || yb2-dif == 0 && xb2-dif-6 == 0 || yb2-dif == 0 && xb2-dif-7 == 0 || yb2-dif == 0 && xb2-dif-8 == 0 ||
		yb2-dif == 0 && xb2-dif-9 == 0)
	{
		xb2 = xb2 + 0;
		yb2 = yb2 + 0;	
		directions2 = 1;
		Tron_LowRes(directions1, directions2);
		break;
	}
	//yb2 = yb2-1;
	if(Grid[yb2+0][xb2] == 1)
	{
		return 2;
	}
	Grid[yb2+0][xb2] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Up.jpg",xb2-12,yb2-26,xb2+12,yb2+26);
setcolor(COLOR(252,246,2));
circle(xb2,yb2 + 0,5);
	break;



case 3://left
	xb2 = xb2-1;
	if(Grid[yb2][xb2-dif+0]==1)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2]==1 || Grid[yb2-dif-8][xb2]==1 || Grid[yb2-dif-7][xb2]==1 || Grid[yb2-dif-6][xb2]==1 || Grid[yb2-dif-5][xb2]==1 ||
			Grid[yb2-dif-4][xb2]==1 || Grid[yb2-dif-3][xb2]==1 || Grid[yb2-dif-2][xb2]==1 || Grid[yb2-dif-1][xb2]==1 || Grid[yb2-dif][xb2]==1  || Grid[yb2-dif+1][xb2]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2]==1 || Grid[yb2+dif-8][xb2]==1 || Grid[yb2+dif-7][xb2]==1 || Grid[yb2+dif-6][xb2]==1 || Grid[yb2+dif-5][xb2]==1 ||
			Grid[yb2+dif-4][xb2]==1 || Grid[yb2+dif-3][xb2]==1 || Grid[yb2+dif-2][xb2]==1 || Grid[yb2+dif-1][xb2]==1 || Grid[yb2+dif][xb2]==1 || Grid[yb2+dif+1][xb2]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if there is a line ahead and the bottom boarder is within the bikes given buffer it will be forced up
		else if(yb2+dif-9==900 || yb2+dif-8==900 ||yb2+dif-7==900 || yb2+dif-6==900 || yb2+dif-5==900 ||
			yb2+dif-4==900 || yb2+dif-3==900 || yb2+dif-2==900 || yb2+dif-1==900 || yb2+dif==900 ||
			yb2+dif+1==900 )
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if there is a line ahead and the top boarder is within the bikes given buffer it will be forced down
		else if(yb2-dif-9==0 || yb2-dif-8==0 || yb2-dif-7==0 || yb2-dif-6==0 || yb2-dif-5==0 ||
			yb2-dif-4==0 || yb2-dif-3==0 || yb2-dif-2==0 || yb2-dif-1==0 || yb2-dif==0 || yb2-dif+1==0)
		{
			xb2 = xb2 - 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}


		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

		if(r == 1){
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		Tron_LowRes(directions1, directions2);
		break;
		
	}


	//if approaching the left of the screen and top and bottom boarders not within 10 pixles will drop down
	if(xb2-dif == 0 && yb2+dif != 900 && yb2-dif != 0)
	{
		//if there is a line also within 10 pixles above it is forced to go down
		if(Grid[yb2-dif-9][xb2]==1 || Grid[yb2-dif-8][xb2]==1 || Grid[yb2-dif-7][xb2]==1 || Grid[yb2-dif-6][xb2]==1 || Grid[yb2-dif-5][xb2]==1 ||
			Grid[yb2-dif-4][xb2]==1 || Grid[yb2-dif-3][xb2]==1 || Grid[yb2-dif-2][xb2]==1 || Grid[yb2-dif-1][xb2]==1 || Grid[yb2-dif][xb2]==1  || Grid[yb2-dif+1][xb2]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;
		}

		//if there is a line also within 10 pixles below it is forced to go up
		else if(Grid[yb2+dif-9][xb2]==1 || Grid[yb2+dif-8][xb2]==1 || Grid[yb2+dif-7][xb2]==1 || Grid[yb2+dif-6][xb2]==1 || Grid[yb2+dif-5][xb2]==1 ||
			Grid[yb2+dif-4][xb2]==1 || Grid[yb2+dif-3][xb2]==1 || Grid[yb2+dif-2][xb2]==1 || Grid[yb2+dif-1][xb2]==1 || Grid[yb2+dif][xb2]==1 || Grid[yb2+dif+1][xb2]==1)
		{
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;
		}

		//if it is clear to both sides up to 10 pixels the bike will randomly select it's direction up or down
		else
		{
			srand( time(NULL) );
			int r = rand()%2;

			if(r == 0){
			xb2 = xb2 + 0;
			yb2 = yb2 + 0;			
			directions2 = 0;}

			if(r == 1){
			xb2 = xb2 + 0;
			yb2 = yb2 - 0;			
			directions2 = 2;}
		}

		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within 10 pixles of the bottom boarder forced to turn up
	if(xb2-dif == 0 && yb2+dif+1 == 900 || xb2-dif == 0 && yb2+dif == 900 || xb2-dif == 0 && yb2+dif-1 == 900 || xb2-dif == 0 && yb2+dif-2 == 900 || xb2-dif == 0 && yb2+dif-3 == 900 ||
		xb2-dif == 0 && yb2+dif-4 == 900 || xb2-dif == 0 && yb2+dif-5 == 900 || xb2-dif == 0 && yb2+dif-6 == 900 || xb2-dif == 0 && yb2+dif-7 == 900 ||
		xb2-dif == 0 && yb2+dif-8 == 900 || xb2-dif == 0 && yb2+dif-9 == 900 )
	{
		xb2 = xb2 + 0;
		yb2 = yb2 - 0;
		directions2 = 2;
		Tron_LowRes(directions1, directions2);
		break;
	}

	//if approaching left boarder of screen and within 10 pixles of the top boarder forced to turn down
	if(xb2-dif == 0 && yb2-dif+1 == 0 || xb2-dif == 0 && yb2-dif == 0 || xb2-dif == 0 && yb2-dif-1 == 0 || xb2-dif == 0 && yb2-dif-2 == 0 || xb2-dif == 0 && yb2-dif-3 == 0 || xb2-dif == 0 && yb2-dif-4 == 0 ||
		xb2-dif == 0 && yb2-dif-5 == 0 || xb2-dif == 0 && yb2-dif-6 == 0 || xb2-dif == 0 && yb2-dif-7 == 0 || xb2-dif == 0 && yb2-dif-8 == 0 || xb2-dif == 0 && yb2-dif-9 == 0 )
	{
		xb2 = xb2 + 0;
		yb2 = yb2 + 0;	
		directions2 = 0;
		Tron_LowRes(directions1, directions2);
		break;
	}
	//xb2 = xb2-1;
	if(Grid[yb2][xb2+0] == 1)
	{
		return 2;
	}
	Grid[yb2][xb2+0] = 1;
//if((count % 10) == 0)readimagefile("PIX\\Tron_Bike2_Left.jpg",xb2-26,yb2-12,xb2+26,yb2+12);
setcolor(COLOR(252,246,2));
circle(xb2 + 0,yb2,5);
break;

}//switch ends
//collision detected
if (xb1 > 1595 || yb1 > 895 || xb1 < 5 || yb1 < 5) return 1;
if (xb2 > 1595 || yb2 > 895 || xb2 < 5 || yb2 < 5) return 2;

else return 0;
}

int playTron(int n)
{

dif = n;

readimagefile("PIX\\controls.jpg",0,0,1600,900);

Sleep(2000);



readimagefile("PIX\\TRON.jpg",0,0,1600,900);

memset(Grid, 0, sizeof(Grid));

xb1 = 300;
xb2 = 1300;
yb1 = 450;
yb2 = 450;

directions1 = 1;
directions2 = 3;


setbkcolor(RED);


while(1){

//outtextxy(750, 800, "Hit spacebar to stop.");

if(graphics == 1)collisions = Tron_LowRes(directions1, directions2);
else if (graphics == 2)collisions = Tron_HighRes(directions1, directions2);



if(collisions == 1){
	PlaySound("SOUNDS\\explosion.wav", NULL, SND_ASYNC);
	readimagefile("PIX\\Explosion2.jpg", xb1 - 500, yb1 - 300, xb1 + 500, yb1 + 300);
	//readimagefile("PIX\\Explosion2.jpg", 0, 0,1600,900);
	Sleep(1000);
	readimagefile("PIX\\game_over.jpg",0,0,1600,900);
	Sleep(2000);
	break;}




if(collisions == 2){
	PlaySound("SOUNDS\\explosion.wav", NULL, SND_ASYNC);
	readimagefile("PIX\\Explosion1.jpg", xb2 - 500, yb2 - 300, xb2 + 500, yb2 + 300);
	//readimagefile("PIX\\Explosion1.jpg",0,0,1600,900);
	Sleep(1000);
	readimagefile("PIX\\Winning.jpg",0,0,1600,900);
	Sleep(2000);
	break;}
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


//for(int i =0; i<1999; i++){}//slow down animation speed
Sleep(dif/5);
//cleardevice();

if (kbhit() && graphics == 1) {			//input calculations for LowRes


	//if(getch()==32)break;
	int ch = getch();
	if(ch == 119)		//Turn Up
		{
			if(directions1 ==  1){
				xb1 = xb1 ;
				yb1 = yb1 ;}

			if(directions1 ==  3){
				xb1 = xb1 ;
				yb1 = yb1 ;}

			directions1 = 2;
		}

	if(ch == 100)		//Turn Right
		{
		
			if(directions1 ==  2){
					xb1 = xb1 ;
					yb1 = yb1 ;}

			if(directions1 ==  0){
					xb1 = xb1 ;
					yb1 = yb1 ;}
		
		
		
			directions1 = 1;
		}
	
	if(ch == 97)		//Turn Left
		{
			
			if(directions1 ==  2){
					xb1 = xb1 ;
					yb1 = yb1 ;}

			if(directions1 ==  0){
					xb1 = xb1 ;
					yb1 = yb1 ;}
			
			
			
			
			directions1 = 3;
		}

	if(ch == 115)		//Turn Down
		{
			if(directions1 ==  1){
				xb1 = xb1 ;
				yb1 = yb1 ;}

			if(directions1 ==  3){
				xb1 = xb1 ;
				yb1 = yb1 ;}
			
			directions1 = 0;
		}


}


if (kbhit() && graphics == 2 ){			//input calculations for HighRes


	//if(getch()==32)break;
	int ch = getch();
	if(ch == 119)		//Turn Up
		{
			if(directions1 ==  1){
				xb1 = xb1 - 31;
				yb1 = yb1 - 31;}

			if(directions1 ==  3){
				xb1 = xb1 + 31;
				yb1 = yb1 - 31;}

			cleardevice();
			readimagefile("PIX\\TRON.jpg",0,0,1600,900);
			
			for(int i = 0; i <= 900; i ++){

				for(int j =0; j <= 1600; j++){
					if(Grid[i][j] == 1){
						setcolor(11);
						circle(j,i, 5);}
					if(Grid[i][j] == 2){
						setcolor(COLOR(252,246,2));
						circle(j,i, 5);}
				}

			}
			directions1 = 2;
	}//end turn up 

	if(ch == 100)		//Turn Right
		{
		
			if(directions1 ==  2){
					xb1 = xb1 + 31;
					yb1 = yb1 + 31;}

			if(directions1 ==  0){
					xb1 = xb1 + 31;
					yb1 = yb1 - 31;}
		
		
			cleardevice();
			readimagefile("PIX\\TRON.jpg",0,0,1600,900);
			for(int i = 0; i <= 900; i ++){

				for(int j =0; j <= 1600; j++){
					if(Grid[i][j] == 1){
						setcolor(11);
						circle(j,i, 5);}
					if(Grid[i][j] == 2){
						setcolor(COLOR(252,246,2));
						circle(j,i, 5);}
				}

			}
			directions1 = 1;
		}
	
	if(ch == 97)		//Turn Left
		{
			
			if(directions1 ==  2){
					xb1 = xb1 - 31;
					yb1 = yb1 + 31;}

			if(directions1 ==  0){
					xb1 = xb1 - 31;
					yb1 = yb1 - 31;}
			
			
			
			cleardevice();
			readimagefile("PIX\\TRON.jpg",0,0,1600,900);
			for(int i = 0; i <= 900; i ++){

				for(int j =0; j <= 1600; j++){
					if(Grid[i][j] == 1){
						setcolor(11);
						circle(j,i, 5);}
					if(Grid[i][j] == 2){
						setcolor(COLOR(252,246,2));
						circle(j,i, 5);}
				}

			}
			directions1 = 3;
		}

	if(ch == 115)		//Turn Down
		{
			if(directions1 ==  1){
				xb1 = xb1 - 31;
				yb1 = yb1 + 31;}

			if(directions1 ==  3){
				xb1 = xb1 + 31;
				yb1 = yb1 + 31;}
			
			cleardevice();
			readimagefile("PIX\\TRON.jpg",0,0,1600,900);
			for(int i = 0; i <= 900; i ++){

				for(int j =0; j <= 1600; j++){
					if(Grid[i][j] == 1){
						setcolor(11);
						circle(j,i, 5);}
					if(Grid[i][j] == 2){
						setcolor(COLOR(252,246,2));
						circle(j,i, 5);}
				}

			}
			directions1 = 0;
		}

}


if(count >= 1000)count = 0;

count ++;

}//while

return 0;
}


void MainMenu(){

PlaySound("SOUNDS\\Derezzed.wav", NULL, SND_ASYNC);

int prev_left = 0;
int prev_right = 0;

int variable = 3;

readimagefile("PIX\\TRON_Main_Menu_LowDef.jpg",0,0,1600,900);

//draw(12);

while(1){

if(prev_left != rightclick) {		//Right Click to show credits
		
		readimagefile("PIX\\Credits.jpg",0,0,1600,900);
		Sleep(2000);

		//choosing which image to read for the low graphics option

if(variable == 0 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_LowDef.jpg",0,0,1600,900);
if(variable == 1 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Easy_LowDef.jpg",0,0,1600,900);
if(variable == 2 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Medium_LowDef.jpg",0,0,1600,900);
if(variable == 3 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Hard_LowDef.jpg",0,0,1600,900);
if(variable == 4 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_ChooseDifficulty.jpg",0,0,1600,900);


//choosing which image to read for the high  graphics option

if(variable == 0 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_HighDef.jpg",0,0,1600,900);
if(variable == 1 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Easy_HighDef.jpg",0,0,1600,900);
if(variable == 2 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Medium_HighDef.jpg",0,0,1600,900);
if(variable == 3 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Hard_HighDef.jpg",0,0,1600,900);

rightclick = 0;

}

while(((mousex() > 451)&&( mousex()< 1084))&&(mousey()> 186)&&(mousey() < 314)){

		//if(variable == 0)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_LowDef.jpg",0,0,1600,900);
		//if(variable == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Easy_LowDef.jpg",0,0,1600,900);
		//if(variable == 2)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Medium_LowDef.jpg",0,0,1600,900);
		//if(variable == 3)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Hard_LowDef.jpg",0,0,1600,900);


		//choosing which image to read for the low graphics option


		if(variable == 0 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_LowDef.jpg",0,0,1600,900);
		if(variable == 1 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Easy_LowDef.jpg",0,0,1600,900);
		if(variable == 2 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Medium_LowDef.jpg",0,0,1600,900);
		if(variable == 3 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Hard_LowDef.jpg",0,0,1600,900);
		if(variable == 4 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_ChooseDifficulty.jpg",0,0,1600,900);


		//choosing which image to read for the high  graphics option

		if(variable == 0 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_HighDef.jpg",0,0,1600,900);
		if(variable == 1 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Easy_HighDef.jpg",0,0,1600,900);
		if(variable == 2 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Medium_HighDef.jpg",0,0,1600,900);
		if(variable == 3 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu(Play_Inverted)_Hard_HighDef.jpg",0,0,1600,900);


	if(prev_left != leftclick) {
		if(variable == 0){
			readimagefile("PIX\\TRON_Main_Menu_ChooseDifficulty.jpg",0,0,1600,900);
			variable = 4;
			leftclick = 0;
			continue;}
			
		else if(variable == 1){

			playTron(50);
			PlaySound("SOUNDS\\Derezzed.wav", NULL, SND_ASYNC);
			leftclick = 0;
			continue;
		}

		else if(variable == 2){

			playTron(25);
			PlaySound("SOUNDS\\Derezzed.wav", NULL, SND_ASYNC);
			leftclick = 0;
			continue;
		}

		else if(variable == 3){

			playTron(10);
			PlaySound("SOUNDS\\Derezzed.wav", NULL, SND_ASYNC);
			leftclick = 0;
			continue;
		}

		else{
		playTron(100);
		PlaySound("SOUNDS\\Derezzed.wav", NULL, SND_ASYNC);
		leftclick = 0;}
		variable = 0;
		}//enf if leftclick
	
	}//end if mouse is on PlayButton

		if(prev_left != leftclick) {

			//Choosing Difficulty
			if(((mousex() > 203)&&( mousex()< 553))&&(mousey()> 398)&&(mousey() < 519)){
				variable = 1;
				leftclick = 0;}
			if(((mousex() > 618)&&( mousex()< 967))&&(mousey()> 398)&&(mousey() < 517)){
				variable = 2;
				leftclick = 0;}
			if(((mousex() > 1043)&&( mousex()< 1394))&&(mousey()> 401)&&(mousey() < 518)){
				variable = 3;
				leftclick = 0;}

			//Choosing Graphics
			if(((mousex() > 456)&&( mousex()< 699))&&(mousey()> 624)&&(mousey() < 731)){

				graphics = 1;
				leftclick = 0;}

			if(((mousex() > 876)&&( mousex()< 1118))&&(mousey()> 629)&&(mousey() < 733)){
				graphics = 2;
				leftclick = 0;}
		}

//choosing which image to read for the low graphics option

if(variable == 0 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_LowDef.jpg",0,0,1600,900);
if(variable == 1 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Easy_LowDef.jpg",0,0,1600,900);
if(variable == 2 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Medium_LowDef.jpg",0,0,1600,900);
if(variable == 3 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_Hard_LowDef.jpg",0,0,1600,900);
if(variable == 4 && graphics == 1)readimagefile("PIX\\TRON_Main_Menu_ChooseDifficulty.jpg",0,0,1600,900);


//choosing which image to read for the high  graphics option

if(variable == 0 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_HighDef.jpg",0,0,1600,900);
if(variable == 1 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Easy_HighDef.jpg",0,0,1600,900);
if(variable == 2 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Medium_HighDef.jpg",0,0,1600,900);
if(variable == 3 && graphics == 2)readimagefile("PIX\\TRON_Main_Menu_Hard_HighDef.jpg",0,0,1600,900);



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