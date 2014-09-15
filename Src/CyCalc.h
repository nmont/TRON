/* graphics.h has 16 available colors:
BLACK (1), BLUE (2), GREEN (3), CYAN (4), RED (5), MAGENTA (6), 
BROWN (7), LIGHTGRAY (8), DARKGRAY (9), LIGHTBLUE (10), 
LIGHTGREEN (11), LIGHTCYAN (12), LIGHTRED (13), LIGHTMAGENTA (14), 
YELLOW (15), WHITE (16)
*/

//we want to include math library in this header file because functions in this file cannot look up libraries in main file
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "wii_main.c"
#include "wiiuse.h"

//same concept applies for defines
#define pi 3.14159265359

//wii vars
wiimote** wiimotes;
int found = 0, connected = 0;

//sorting algorithm test array
int list[240];

//initial ball position
int x = 100, y = 100;

//Like in CyCalc V2, DECLARE FUNCTIONS FIRST
double sum(float a, float b);//summing function
double sub(float a, float b);
double mul(float a, float b);
double Div(float a, float b);
double Sine(float degree);//sine function that accepte degrees
double Deg2Rad(float degree); //degree rad conversion
double Rad2Deg(float degree); //rad degree conversion
void welcome(); //prints welcome graphic
void error(); //prints error graphic
void help();
void draw(int Color);
int plotter (int mode);
double sampleNormal();
int pong(int direction);
int runpong();
void fullcolor();
int F14();
int init_wii();
void bubble_sort(int list[], int n);
void insertion_sort(int list[], int n);
void bubble_test();
void insertion_test();


float foo1(float a, float b, float c){
if(a/b == c) return a/b;
if(a/b != c) return (a/b) + (a/b);
}

float foo2(float a, float b, float c){
float result = a/b;
if(result == c) return result;
else return result * 2;}

///////////////////////////////
void generate();
int findMax();
void plot ( int max );
void clear();
void run();

////////////////////////////////////////////////
const int barWidth = 50; //bar width
const int limit = 500 ; //generation limit
const int maxPlus = 20 ; //histo limit
int histo[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//THEN, WRITE FUNCTION BODIES BELOW TO HOST THEM

double sum(float a, float b){

return a + b;

}//sum function ends

double sub(float a, float b){

return a - b;

}//sub function ends

double mul(float a, float b){

return a * b;

}//mul function ends

double Div(float a, float b){

//check for div/0 condition

	while((int)b==0){
		error();
	printf("CANNOT DIVIDE BY ZERO, enter second number again! >");
		scanf("%f", &b); 
		//printf("%f", b);
		
	}//while ends
	
return a / b;

}//div function ends

double Sine(float degree){

	return sin(Deg2Rad(degree));

	}//sine ends

double Deg2Rad(float degree){

double radians = 0;//store output

radians = degree * (pi / 180);

return radians;

}//deg2rad ends

double Rad2Deg(float radians){

double degrees = 0;//store output

degrees = radians * (180/pi);

return degrees;

}//deg2rad ends

void welcome(){

printf(" __________________________________________________________________________\n");
printf("|  _________________                   !#########       #                  |\n");
printf("| | Dobra utra y/   |                !########!          ##!               |\n");
printf("| |       /|   /    |             !########!               ###             |\n");
printf("| |  /|  / |  /     |          !##########                  ####           |\n");
printf("| | / |_/  |_/      |        ######### #####                ######         |\n");
printf("| |/    CyCalc Cemy |         !###!      !####!              ######        |\n");
printf("| |_________________|           !           #####            ######!       |\n");
printf("|  __ __ __ __ __ __                          !####!         #######       |\n");
printf("| |__|__|__|__|__|__|                            #####       #######       |\n");
printf("| |__|__|__|__|__|__|                              !####!   #######!       |\n");
printf("| |__|__|__|__|__|__|                                 ####!########        |\n");
printf("| |__|__|__|__|__|__|              ##                   ##########         |\n");
printf("|  ___ ___ ___   ___             ,######!          !#############          |\n");
printf("| | 7 | 8 | 9 | | + |          ,#### ########################!####!        |\n");
printf("| |___|___|___| |___|        ,####'     ##################!'    #####      |\n");
printf("| | 4 | 5 | 6 | | - |      ,####'            #######              !####!   |\n");
printf("| |___|___|___| |___|     ####'                                      ##### |\n");
printf("| | 1 | 2 | 3 | | x |     ~##                                          ##~ |\n");
printf("| |___|___|___| |___|                                                      |\n");
printf("| | . | 0 | = | | / | | Calculator Reactor Temperature: Nominal  |         |\n");
printf("| |___|___|___| |___| | RGDERNY PEAKTOP TEMREPATYPA NOMINALINE   |         |\n");
printf("|__________________________________________________________________________|\n");

}





void error(){

	PlaySound("SOUNDS\\div0_.wav", NULL, SND_ASYNC);
readimagefile("PIX\\EARTH\\earth0000.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0001.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0002.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0003.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0004.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0005.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0006.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0007.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0008.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0009.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0010.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0011.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0012.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0013.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0014.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0015.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0016.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0017.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0018.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0019.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0020.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0021.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0022.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0023.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0024.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0025.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0026.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0027.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0028.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0029.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0030.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0031.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0032.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0033.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0034.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0035.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0036.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0037.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0038.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0039.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0040.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0041.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0042.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0043.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0044.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0045.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0046.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0047.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0048.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0049.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0050.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0051.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0052.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0053.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0054.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0055.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0056.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0057.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0058.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0059.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0060.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0061.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0062.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0063.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0064.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0065.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0066.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0067.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0068.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0069.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0070.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0071.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0072.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0073.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0074.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0075.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0076.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0077.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0078.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0079.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0080.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0081.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0082.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0083.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0084.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0085.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0086.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0087.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0088.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0089.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0090.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0091.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0092.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0093.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0094.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0095.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0096.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0097.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0098.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0099.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0100.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0101.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0102.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0103.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0104.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0105.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0106.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0107.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0108.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0109.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0110.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0111.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0112.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0113.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0114.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0115.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0116.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0117.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0118.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0119.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0120.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0121.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0122.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0123.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0124.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0125.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0126.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0127.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0128.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0129.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0130.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0131.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0132.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0133.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0134.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0135.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0136.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0137.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0138.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0139.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0140.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0141.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0142.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0143.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0144.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0145.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0146.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0147.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0148.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0149.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0150.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0151.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0152.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0153.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0154.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0155.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0156.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0157.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0158.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0159.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0160.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0161.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0162.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0163.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0164.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0165.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0166.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0167.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0168.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0169.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0170.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0171.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0172.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0173.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0174.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0175.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0176.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0177.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0178.jpg", 0,0,640,480);Sleep(20);
readimagefile("PIX\\EARTH\\earth0179.jpg", 0,0,640,480);Sleep(2000);
readimagefile("PIX\\EARTH\\earth0180.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0181.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0182.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0183.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0184.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0185.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0186.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0187.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0188.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0189.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0190.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0191.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0192.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0193.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0194.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0195.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0196.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0197.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0198.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0199.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0200.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0201.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0202.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0203.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0204.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0205.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0206.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0207.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0208.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0209.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0210.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0211.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0212.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0213.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0214.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0215.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0216.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0217.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0218.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0219.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0220.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0221.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0222.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0223.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0224.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0225.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0226.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0227.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0228.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0229.jpg", 0,0,640,480);Sleep(40);
readimagefile("PIX\\EARTH\\earth0230.jpg", 0,0,640,480);Sleep(40);

}


///////////////////////////////////////

/* Generate the random numbers and histogram them. */
void generate()
{
  int j, r ;
  for ( j=0; j<limit; j++ )
  {
    r = rand()%maxPlus;
    histo[r]++;
  }
}



/* Find the maximum of all the histogram bins */
int findMax()
{
  int j;
  int max = histo[0];

  for ( j=1; j < maxPlus; j++ )
  {
    if ( histo[j] > max )
      max = histo[j];
  }
  
  return max;
}

/* Plot the histogram */
void plot ( int max )
{
  
  int j, s;

  for ( j=0; j<maxPlus; j++ )
  {
    printf("%3d (%5d) > ", j, histo[j] );
    for ( s=0; s<histo[j]*barWidth/max; s++ ) printf("|");
     
    printf("\n");
  }
}


void clear(){
int i = 0;    
     
for(i = 0; i<maxPlus; i++) histo[i] = 0;     
     
     }


void run(){
     
  int max;

  while(1){
  srand( time(NULL) );
  generate();
  max = findMax();
  plot( max );
  getchar();
    
}}


void bubble_test(){
for( int i = 0; i < 240; i++) list[i] = 1 + rand() % 50;
bubble_sort(list, 240);
}

void insertion_test(){
for( int i = 0; i < 240; i++) list[i] = 1 + rand() % 50;
insertion_sort(list, 240);
}


void help(){

printf("\n");
printf("--------------CyCalc V5 HELP MENU--------------\n");
printf("Type +, -, *, or / for arithmetic ops.\n");
printf("Type s to compute SINE(first)\n");
printf("Type S for function plotter\n");
printf("Type h for HISTOGRAM app.\n");
printf("Type d to access DRAW app.\n");
printf("Type p to run simple pong.\n");
printf("Type q to quit CyCalc.\n");
printf("Type c to CLEAR the graphing screen.\n");
printf("Type f to start the F14 flight simulator.\n");
printf("Type b to bubble-sort 240 random numbers.\n");
printf("Type i to insertion-sort 240 random numbers.\n");
printf("-----------------------------------------------\n");
printf("\n");
//printf("Type p to plot y = sin(x)\n");
//printf("Type P to plot y = t^2(cos(x)sin(x))\n");



}


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




int plotter(int mode){


readimagefile("PIX\\oscilloscope.jpg",0,0,640,480);
setbkcolor(WHITE);

//Other Misc. Variables
int midx,midy,mx,my,i,j,k,x,y,x1,y1;
double tpi,a;
int t = 0;
 midx = getmaxx()/2; midy = getmaxy()/2;
 tpi = pi * 2.0;
 t=100;


 for (t = 0; t < 360; t++)
{

	if(mode == 1){
	//printf("SINE of %d, is %.2f\n",t, sin(t*pi/180));
	putpixel(t+100, sin(t*pi/180)*100 + 200, 1); setcolor(COLOR(255,255,255)); circle(t+100, sin(t*pi/180)*100 + 200, 3);
	putpixel(t+100, cos(t*pi/180)*100 + 200, 2); setcolor(COLOR(255,0,0)); circle(t+100, cos(t*pi/180)*100 + 200, 3);
	putpixel(t+100, 2*sin(t*pi/180)*100 + 200, 3); setcolor(COLOR(0,255,0)); circle(t+100, 2*sin(t*pi/180)*100 + 200, 3);
	putpixel(t+100, 2*cos(t*pi/180)*100 + 200, 4); setcolor(COLOR(0,0,255)); circle(t+100, 2*cos(t*pi/180)*100 + 200, 3);
	putpixel(t+100, sin(2*t*pi/180)*100 + 200, 5); setcolor(COLOR(255,255,0)); circle(t+100, sin(2*t*pi/180)*100 + 200, 3);
	putpixel(t+100, cos(2*t*pi/180)*100 + 200, 6); setcolor(COLOR(0,0,0)); circle(t+100, cos(2*t*pi/180)*100 + 200, 3);

	}

	else if(mode == 2){

x = midx+ (t * cos((float) t) * sin((float) t));
y = midy+ (t * sin((float) t));


putpixel(x,y,getmaxcolor());
circle(x,y,4);
setcolor(getmaxcolor());

	}

}



 return 0;

}//plot ends


double sampleNormal() {
    double u = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double v = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double r = u * u + v * v;
    if (r == 0 || r > 1) return sampleNormal();
    double c = sqrt(-2 * log(r) / r);
    return u * c;
}


int pong(int direction){
//readimagefile("PIX\\shuttle.jpg",0,0,640,480);
setcolor(YELLOW);

switch (direction){

case 0:
	y = y+1; 
//readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);

	break;

case 1:
	y = y+1; 
	x = x+1;
//	readimagefile("PIX\\3dball.bmp",x,y,x+40,y+40);
circle(x,y,5);
	break;

case 2:
	x = x+1; 
//readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
	break;

case 3:
	x = x+1;
	y = y-1; 
//	readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
	break;

case 4:
	y = y-1; 
//	readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
	break;

case 5:
	y = y-1;
	x = x-1;
//	readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
	break;

case 6:
	x = x-1; 
//	readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
break;

case 7:
	x = x-1; 
	y = y+1;
//	readimagefile("PIX\\3dball.bmp",x,y,x+20,y+20);
circle(x,y,5);
break;

}//switch ends


//collision detected
if (x > 620 || y > 460 || x < 20 || y < 20) return 1;

else return 0;
}


int runpong(){

readimagefile("PIX\\racetrack.jpg",0,0,640,480);

int directions = 1;
int collisions = 0;

setbkcolor(RED);

//initialize the wii
if(!init_wii()){printf("There was a wii error.\n"); return 0;}

while(1){

outtextxy(200, 400, "Hit spacebar to stop.");

collisions = pong(directions);

wiiuse_poll(wiimotes, MAX_WIIMOTES);

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
printf("-------------------------------------\n");

if(collisions){ directions++;
if(directions > 7) directions = 0;
PlaySound("SOUNDS\\bam.wav", NULL, SND_ASYNC);

	if(connected){
		/*wiiuse_toggle_rumble(wiimotes[0]);
		Sleep(50);
		wiiuse_toggle_rumble(wiimotes[0]);*/

		if(directions == 0) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_1);
		if(directions == 1) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_2);
		if(directions == 2) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_3);
		if(directions == 3) wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_4);

	}

}
//for(int i =0; i<1999; i++){}//slow down animation speed
//cleardevice();
if (kbhit()) {
	getch(); 
	if(connected) {
		wiiuse_cleanup(wiimotes, MAX_WIIMOTES);
	}

	break;
}
}//while

return 0;}



int F14(){

char arrm[10];
char arrg[1000];
char arrf[1000];

int missles = 10;
int ammo = 1000;
int fuel = 1000;
int fuelCount = 0;

int flight = 185;
setbkcolor(RED);

//initialize the wii
if(!init_wii()){printf("There was a wii error.\n"); return 0;}

//PlaySound("SOUNDS\\top_gun.wav", NULL, SND_ASYNC);

while(1){

sprintf(arrm, "Misles: %d", missles);
sprintf(arrg, "Gun Ammo: %d", ammo);
sprintf(arrf, "Fuel: %d", fuel);

wiiuse_poll(wiimotes, MAX_WIIMOTES);

if (wiimotes[0]->orient.a_roll > 10){ flight++; }
if (wiimotes[0]->orient.a_roll < -10){ flight--; }

if (wiimotes[0]->orient.a_roll > 20){ flight++;flight++; }
if (wiimotes[0]->orient.a_roll < -20){ flight--;flight--; }

if (wiimotes[0]->orient.a_roll > 40){ flight+=4;}
if (wiimotes[0]->orient.a_roll < -40){ flight-=4;}

if (flight > 369){ flight = 369; }
if (flight < 0){ flight = 0; }


switch(flight){
case 0:readimagefile("PIX\\F14\\F_0000.jpg",0,0,640,480);break;
case 1:readimagefile("PIX\\F14\\F_0001.jpg",0,0,640,480);break;
case 2:readimagefile("PIX\\F14\\F_0002.jpg",0,0,640,480);break;
case 3:readimagefile("PIX\\F14\\F_0003.jpg",0,0,640,480);break;
case 4:readimagefile("PIX\\F14\\F_0004.jpg",0,0,640,480);break;
case 5:readimagefile("PIX\\F14\\F_0005.jpg",0,0,640,480);break;
case 6:readimagefile("PIX\\F14\\F_0006.jpg",0,0,640,480);break;
case 7:readimagefile("PIX\\F14\\F_0007.jpg",0,0,640,480);break;
case 8:readimagefile("PIX\\F14\\F_0008.jpg",0,0,640,480);break;
case 9:readimagefile("PIX\\F14\\F_0009.jpg",0,0,640,480);break;
case 10:readimagefile("PIX\\F14\\F_0010.jpg",0,0,640,480);break;
case 11:readimagefile("PIX\\F14\\F_0011.jpg",0,0,640,480);break;
case 12:readimagefile("PIX\\F14\\F_0012.jpg",0,0,640,480);break;
case 13:readimagefile("PIX\\F14\\F_0013.jpg",0,0,640,480);break;
case 14:readimagefile("PIX\\F14\\F_0014.jpg",0,0,640,480);break;
case 15:readimagefile("PIX\\F14\\F_0015.jpg",0,0,640,480);break;
case 16:readimagefile("PIX\\F14\\F_0016.jpg",0,0,640,480);break;
case 17:readimagefile("PIX\\F14\\F_0017.jpg",0,0,640,480);break;
case 18:readimagefile("PIX\\F14\\F_0018.jpg",0,0,640,480);break;
case 19:readimagefile("PIX\\F14\\F_0019.jpg",0,0,640,480);break;
case 20:readimagefile("PIX\\F14\\F_0020.jpg",0,0,640,480);break;
case 21:readimagefile("PIX\\F14\\F_0021.jpg",0,0,640,480);break;
case 22:readimagefile("PIX\\F14\\F_0022.jpg",0,0,640,480);break;
case 23:readimagefile("PIX\\F14\\F_0023.jpg",0,0,640,480);break;
case 24:readimagefile("PIX\\F14\\F_0024.jpg",0,0,640,480);break;
case 25:readimagefile("PIX\\F14\\F_0025.jpg",0,0,640,480);break;
case 26:readimagefile("PIX\\F14\\F_0026.jpg",0,0,640,480);break;
case 27:readimagefile("PIX\\F14\\F_0027.jpg",0,0,640,480);break;
case 28:readimagefile("PIX\\F14\\F_0028.jpg",0,0,640,480);break;
case 29:readimagefile("PIX\\F14\\F_0029.jpg",0,0,640,480);break;
case 30:readimagefile("PIX\\F14\\F_0030.jpg",0,0,640,480);break;
case 31:readimagefile("PIX\\F14\\F_0031.jpg",0,0,640,480);break;
case 32:readimagefile("PIX\\F14\\F_0032.jpg",0,0,640,480);break;
case 33:readimagefile("PIX\\F14\\F_0033.jpg",0,0,640,480);break;
case 34:readimagefile("PIX\\F14\\F_0034.jpg",0,0,640,480);break;
case 35:readimagefile("PIX\\F14\\F_0035.jpg",0,0,640,480);break;
case 36:readimagefile("PIX\\F14\\F_0036.jpg",0,0,640,480);break;
case 37:readimagefile("PIX\\F14\\F_0037.jpg",0,0,640,480);break;
case 38:readimagefile("PIX\\F14\\F_0038.jpg",0,0,640,480);break;
case 39:readimagefile("PIX\\F14\\F_0039.jpg",0,0,640,480);break;
case 40:readimagefile("PIX\\F14\\F_0040.jpg",0,0,640,480);break;
case 41:readimagefile("PIX\\F14\\F_0041.jpg",0,0,640,480);break;
case 42:readimagefile("PIX\\F14\\F_0042.jpg",0,0,640,480);break;
case 43:readimagefile("PIX\\F14\\F_0043.jpg",0,0,640,480);break;
case 44:readimagefile("PIX\\F14\\F_0044.jpg",0,0,640,480);break;
case 45:readimagefile("PIX\\F14\\F_0045.jpg",0,0,640,480);break;
case 46:readimagefile("PIX\\F14\\F_0046.jpg",0,0,640,480);break;
case 47:readimagefile("PIX\\F14\\F_0047.jpg",0,0,640,480);break;
case 48:readimagefile("PIX\\F14\\F_0048.jpg",0,0,640,480);break;
case 49:readimagefile("PIX\\F14\\F_0049.jpg",0,0,640,480);break;
case 50:readimagefile("PIX\\F14\\F_0050.jpg",0,0,640,480);break;
case 51:readimagefile("PIX\\F14\\F_0051.jpg",0,0,640,480);break;
case 52:readimagefile("PIX\\F14\\F_0052.jpg",0,0,640,480);break;
case 53:readimagefile("PIX\\F14\\F_0053.jpg",0,0,640,480);break;
case 54:readimagefile("PIX\\F14\\F_0054.jpg",0,0,640,480);break;
case 55:readimagefile("PIX\\F14\\F_0055.jpg",0,0,640,480);break;
case 56:readimagefile("PIX\\F14\\F_0056.jpg",0,0,640,480);break;
case 57:readimagefile("PIX\\F14\\F_0057.jpg",0,0,640,480);break;
case 58:readimagefile("PIX\\F14\\F_0058.jpg",0,0,640,480);break;
case 59:readimagefile("PIX\\F14\\F_0059.jpg",0,0,640,480);break;
case 60:readimagefile("PIX\\F14\\F_0060.jpg",0,0,640,480);break;
case 61:readimagefile("PIX\\F14\\F_0061.jpg",0,0,640,480);break;
case 62:readimagefile("PIX\\F14\\F_0062.jpg",0,0,640,480);break;
case 63:readimagefile("PIX\\F14\\F_0063.jpg",0,0,640,480);break;
case 64:readimagefile("PIX\\F14\\F_0064.jpg",0,0,640,480);break;
case 65:readimagefile("PIX\\F14\\F_0065.jpg",0,0,640,480);break;
case 66:readimagefile("PIX\\F14\\F_0066.jpg",0,0,640,480);break;
case 67:readimagefile("PIX\\F14\\F_0067.jpg",0,0,640,480);break;
case 68:readimagefile("PIX\\F14\\F_0068.jpg",0,0,640,480);break;
case 69:readimagefile("PIX\\F14\\F_0069.jpg",0,0,640,480);break;
case 70:readimagefile("PIX\\F14\\F_0070.jpg",0,0,640,480);break;
case 71:readimagefile("PIX\\F14\\F_0071.jpg",0,0,640,480);break;
case 72:readimagefile("PIX\\F14\\F_0072.jpg",0,0,640,480);break;
case 73:readimagefile("PIX\\F14\\F_0073.jpg",0,0,640,480);break;
case 74:readimagefile("PIX\\F14\\F_0074.jpg",0,0,640,480);break;
case 75:readimagefile("PIX\\F14\\F_0075.jpg",0,0,640,480);break;
case 76:readimagefile("PIX\\F14\\F_0076.jpg",0,0,640,480);break;
case 77:readimagefile("PIX\\F14\\F_0077.jpg",0,0,640,480);break;
case 78:readimagefile("PIX\\F14\\F_0078.jpg",0,0,640,480);break;
case 79:readimagefile("PIX\\F14\\F_0079.jpg",0,0,640,480);break;
case 80:readimagefile("PIX\\F14\\F_0080.jpg",0,0,640,480);break;
case 81:readimagefile("PIX\\F14\\F_0081.jpg",0,0,640,480);break;
case 82:readimagefile("PIX\\F14\\F_0082.jpg",0,0,640,480);break;
case 83:readimagefile("PIX\\F14\\F_0083.jpg",0,0,640,480);break;
case 84:readimagefile("PIX\\F14\\F_0084.jpg",0,0,640,480);break;
case 85:readimagefile("PIX\\F14\\F_0085.jpg",0,0,640,480);break;
case 86:readimagefile("PIX\\F14\\F_0086.jpg",0,0,640,480);break;
case 87:readimagefile("PIX\\F14\\F_0087.jpg",0,0,640,480);break;
case 88:readimagefile("PIX\\F14\\F_0088.jpg",0,0,640,480);break;
case 89:readimagefile("PIX\\F14\\F_0089.jpg",0,0,640,480);break;
case 90:readimagefile("PIX\\F14\\F_0090.jpg",0,0,640,480);break;
case 91:readimagefile("PIX\\F14\\F_0091.jpg",0,0,640,480);break;
case 92:readimagefile("PIX\\F14\\F_0092.jpg",0,0,640,480);break;
case 93:readimagefile("PIX\\F14\\F_0093.jpg",0,0,640,480);break;
case 94:readimagefile("PIX\\F14\\F_0094.jpg",0,0,640,480);break;
case 95:readimagefile("PIX\\F14\\F_0095.jpg",0,0,640,480);break;
case 96:readimagefile("PIX\\F14\\F_0096.jpg",0,0,640,480);break;
case 97:readimagefile("PIX\\F14\\F_0097.jpg",0,0,640,480);break;
case 98:readimagefile("PIX\\F14\\F_0098.jpg",0,0,640,480);break;
case 99:readimagefile("PIX\\F14\\F_0099.jpg",0,0,640,480);break;
case 100:readimagefile("PIX\\F14\\F_0100.jpg",0,0,640,480);break;
case 101:readimagefile("PIX\\F14\\F_0101.jpg",0,0,640,480);break;
case 102:readimagefile("PIX\\F14\\F_0102.jpg",0,0,640,480);break;
case 103:readimagefile("PIX\\F14\\F_0103.jpg",0,0,640,480);break;
case 104:readimagefile("PIX\\F14\\F_0104.jpg",0,0,640,480);break;
case 105:readimagefile("PIX\\F14\\F_0105.jpg",0,0,640,480);break;
case 106:readimagefile("PIX\\F14\\F_0106.jpg",0,0,640,480);break;
case 107:readimagefile("PIX\\F14\\F_0107.jpg",0,0,640,480);break;
case 108:readimagefile("PIX\\F14\\F_0108.jpg",0,0,640,480);break;
case 109:readimagefile("PIX\\F14\\F_0109.jpg",0,0,640,480);break;
case 110:readimagefile("PIX\\F14\\F_0110.jpg",0,0,640,480);break;
case 111:readimagefile("PIX\\F14\\F_0111.jpg",0,0,640,480);break;
case 112:readimagefile("PIX\\F14\\F_0112.jpg",0,0,640,480);break;
case 113:readimagefile("PIX\\F14\\F_0113.jpg",0,0,640,480);break;
case 114:readimagefile("PIX\\F14\\F_0114.jpg",0,0,640,480);break;
case 115:readimagefile("PIX\\F14\\F_0115.jpg",0,0,640,480);break;
case 116:readimagefile("PIX\\F14\\F_0116.jpg",0,0,640,480);break;
case 117:readimagefile("PIX\\F14\\F_0117.jpg",0,0,640,480);break;
case 118:readimagefile("PIX\\F14\\F_0118.jpg",0,0,640,480);break;
case 119:readimagefile("PIX\\F14\\F_0119.jpg",0,0,640,480);break;
case 120:readimagefile("PIX\\F14\\F_0120.jpg",0,0,640,480);break;
case 121:readimagefile("PIX\\F14\\F_0121.jpg",0,0,640,480);break;
case 122:readimagefile("PIX\\F14\\F_0122.jpg",0,0,640,480);break;
case 123:readimagefile("PIX\\F14\\F_0123.jpg",0,0,640,480);break;
case 124:readimagefile("PIX\\F14\\F_0124.jpg",0,0,640,480);break;
case 125:readimagefile("PIX\\F14\\F_0125.jpg",0,0,640,480);break;
case 126:readimagefile("PIX\\F14\\F_0126.jpg",0,0,640,480);break;
case 127:readimagefile("PIX\\F14\\F_0127.jpg",0,0,640,480);break;
case 128:readimagefile("PIX\\F14\\F_0128.jpg",0,0,640,480);break;
case 129:readimagefile("PIX\\F14\\F_0129.jpg",0,0,640,480);break;
case 130:readimagefile("PIX\\F14\\F_0130.jpg",0,0,640,480);break;
case 131:readimagefile("PIX\\F14\\F_0131.jpg",0,0,640,480);break;
case 132:readimagefile("PIX\\F14\\F_0132.jpg",0,0,640,480);break;
case 133:readimagefile("PIX\\F14\\F_0133.jpg",0,0,640,480);break;
case 134:readimagefile("PIX\\F14\\F_0134.jpg",0,0,640,480);break;
case 135:readimagefile("PIX\\F14\\F_0135.jpg",0,0,640,480);break;
case 136:readimagefile("PIX\\F14\\F_0136.jpg",0,0,640,480);break;
case 137:readimagefile("PIX\\F14\\F_0137.jpg",0,0,640,480);break;
case 138:readimagefile("PIX\\F14\\F_0138.jpg",0,0,640,480);break;
case 139:readimagefile("PIX\\F14\\F_0139.jpg",0,0,640,480);break;
case 140:readimagefile("PIX\\F14\\F_0140.jpg",0,0,640,480);break;
case 141:readimagefile("PIX\\F14\\F_0141.jpg",0,0,640,480);break;
case 142:readimagefile("PIX\\F14\\F_0142.jpg",0,0,640,480);break;
case 143:readimagefile("PIX\\F14\\F_0143.jpg",0,0,640,480);break;
case 144:readimagefile("PIX\\F14\\F_0144.jpg",0,0,640,480);break;
case 145:readimagefile("PIX\\F14\\F_0145.jpg",0,0,640,480);break;
case 146:readimagefile("PIX\\F14\\F_0146.jpg",0,0,640,480);break;
case 147:readimagefile("PIX\\F14\\F_0147.jpg",0,0,640,480);break;
case 148:readimagefile("PIX\\F14\\F_0148.jpg",0,0,640,480);break;
case 149:readimagefile("PIX\\F14\\F_0149.jpg",0,0,640,480);break;
case 150:readimagefile("PIX\\F14\\F_0150.jpg",0,0,640,480);break;
case 151:readimagefile("PIX\\F14\\F_0151.jpg",0,0,640,480);break;
case 152:readimagefile("PIX\\F14\\F_0152.jpg",0,0,640,480);break;
case 153:readimagefile("PIX\\F14\\F_0153.jpg",0,0,640,480);break;
case 154:readimagefile("PIX\\F14\\F_0154.jpg",0,0,640,480);break;
case 155:readimagefile("PIX\\F14\\F_0155.jpg",0,0,640,480);break;
case 156:readimagefile("PIX\\F14\\F_0156.jpg",0,0,640,480);break;
case 157:readimagefile("PIX\\F14\\F_0157.jpg",0,0,640,480);break;
case 158:readimagefile("PIX\\F14\\F_0158.jpg",0,0,640,480);break;
case 159:readimagefile("PIX\\F14\\F_0159.jpg",0,0,640,480);break;
case 160:readimagefile("PIX\\F14\\F_0160.jpg",0,0,640,480);break;
case 161:readimagefile("PIX\\F14\\F_0161.jpg",0,0,640,480);break;
case 162:readimagefile("PIX\\F14\\F_0162.jpg",0,0,640,480);break;
case 163:readimagefile("PIX\\F14\\F_0163.jpg",0,0,640,480);break;
case 164:readimagefile("PIX\\F14\\F_0164.jpg",0,0,640,480);break;
case 165:readimagefile("PIX\\F14\\F_0165.jpg",0,0,640,480);break;
case 166:readimagefile("PIX\\F14\\F_0166.jpg",0,0,640,480);break;
case 167:readimagefile("PIX\\F14\\F_0167.jpg",0,0,640,480);break;
case 168:readimagefile("PIX\\F14\\F_0168.jpg",0,0,640,480);break;
case 169:readimagefile("PIX\\F14\\F_0169.jpg",0,0,640,480);break;
case 170:readimagefile("PIX\\F14\\F_0170.jpg",0,0,640,480);break;
case 171:readimagefile("PIX\\F14\\F_0171.jpg",0,0,640,480);break;
case 172:readimagefile("PIX\\F14\\F_0172.jpg",0,0,640,480);break;
case 173:readimagefile("PIX\\F14\\F_0173.jpg",0,0,640,480);break;
case 174:readimagefile("PIX\\F14\\F_0174.jpg",0,0,640,480);break;
case 175:readimagefile("PIX\\F14\\F_0175.jpg",0,0,640,480);break;
case 176:readimagefile("PIX\\F14\\F_0176.jpg",0,0,640,480);break;
case 177:readimagefile("PIX\\F14\\F_0177.jpg",0,0,640,480);break;
case 178:readimagefile("PIX\\F14\\F_0178.jpg",0,0,640,480);break;
case 179:readimagefile("PIX\\F14\\F_0179.jpg",0,0,640,480);break;
case 180:readimagefile("PIX\\F14\\F_0180.jpg",0,0,640,480);break;
case 181:readimagefile("PIX\\F14\\F_0181.jpg",0,0,640,480);break;
case 182:readimagefile("PIX\\F14\\F_0182.jpg",0,0,640,480);break;
case 183:readimagefile("PIX\\F14\\F_0183.jpg",0,0,640,480);break;
case 184:readimagefile("PIX\\F14\\F_0184.jpg",0,0,640,480);break;
case 185:readimagefile("PIX\\F14\\F_0185.jpg",0,0,640,480);break;
case 186:readimagefile("PIX\\F14\\F_0186.jpg",0,0,640,480);break;
case 187:readimagefile("PIX\\F14\\F_0187.jpg",0,0,640,480);break;
case 188:readimagefile("PIX\\F14\\F_0188.jpg",0,0,640,480);break;
case 189:readimagefile("PIX\\F14\\F_0189.jpg",0,0,640,480);break;
case 190:readimagefile("PIX\\F14\\F_0190.jpg",0,0,640,480);break;
case 191:readimagefile("PIX\\F14\\F_0191.jpg",0,0,640,480);break;
case 192:readimagefile("PIX\\F14\\F_0192.jpg",0,0,640,480);break;
case 193:readimagefile("PIX\\F14\\F_0193.jpg",0,0,640,480);break;
case 194:readimagefile("PIX\\F14\\F_0194.jpg",0,0,640,480);break;
case 195:readimagefile("PIX\\F14\\F_0195.jpg",0,0,640,480);break;
case 196:readimagefile("PIX\\F14\\F_0196.jpg",0,0,640,480);break;
case 197:readimagefile("PIX\\F14\\F_0197.jpg",0,0,640,480);break;
case 198:readimagefile("PIX\\F14\\F_0198.jpg",0,0,640,480);break;
case 199:readimagefile("PIX\\F14\\F_0199.jpg",0,0,640,480);break;
case 200:readimagefile("PIX\\F14\\F_0200.jpg",0,0,640,480);break;
case 201:readimagefile("PIX\\F14\\F_0201.jpg",0,0,640,480);break;
case 202:readimagefile("PIX\\F14\\F_0202.jpg",0,0,640,480);break;
case 203:readimagefile("PIX\\F14\\F_0203.jpg",0,0,640,480);break;
case 204:readimagefile("PIX\\F14\\F_0204.jpg",0,0,640,480);break;
case 205:readimagefile("PIX\\F14\\F_0205.jpg",0,0,640,480);break;
case 206:readimagefile("PIX\\F14\\F_0206.jpg",0,0,640,480);break;
case 207:readimagefile("PIX\\F14\\F_0207.jpg",0,0,640,480);break;
case 208:readimagefile("PIX\\F14\\F_0208.jpg",0,0,640,480);break;
case 209:readimagefile("PIX\\F14\\F_0209.jpg",0,0,640,480);break;
case 210:readimagefile("PIX\\F14\\F_0210.jpg",0,0,640,480);break;
case 211:readimagefile("PIX\\F14\\F_0211.jpg",0,0,640,480);break;
case 212:readimagefile("PIX\\F14\\F_0212.jpg",0,0,640,480);break;
case 213:readimagefile("PIX\\F14\\F_0213.jpg",0,0,640,480);break;
case 214:readimagefile("PIX\\F14\\F_0214.jpg",0,0,640,480);break;
case 215:readimagefile("PIX\\F14\\F_0215.jpg",0,0,640,480);break;
case 216:readimagefile("PIX\\F14\\F_0216.jpg",0,0,640,480);break;
case 217:readimagefile("PIX\\F14\\F_0217.jpg",0,0,640,480);break;
case 218:readimagefile("PIX\\F14\\F_0218.jpg",0,0,640,480);break;
case 219:readimagefile("PIX\\F14\\F_0219.jpg",0,0,640,480);break;
case 220:readimagefile("PIX\\F14\\F_0220.jpg",0,0,640,480);break;
case 221:readimagefile("PIX\\F14\\F_0221.jpg",0,0,640,480);break;
case 222:readimagefile("PIX\\F14\\F_0222.jpg",0,0,640,480);break;
case 223:readimagefile("PIX\\F14\\F_0223.jpg",0,0,640,480);break;
case 224:readimagefile("PIX\\F14\\F_0224.jpg",0,0,640,480);break;
case 225:readimagefile("PIX\\F14\\F_0225.jpg",0,0,640,480);break;
case 226:readimagefile("PIX\\F14\\F_0226.jpg",0,0,640,480);break;
case 227:readimagefile("PIX\\F14\\F_0227.jpg",0,0,640,480);break;
case 228:readimagefile("PIX\\F14\\F_0228.jpg",0,0,640,480);break;
case 229:readimagefile("PIX\\F14\\F_0229.jpg",0,0,640,480);break;
case 230:readimagefile("PIX\\F14\\F_0230.jpg",0,0,640,480);break;
case 231:readimagefile("PIX\\F14\\F_0231.jpg",0,0,640,480);break;
case 232:readimagefile("PIX\\F14\\F_0232.jpg",0,0,640,480);break;
case 233:readimagefile("PIX\\F14\\F_0233.jpg",0,0,640,480);break;
case 234:readimagefile("PIX\\F14\\F_0234.jpg",0,0,640,480);break;
case 235:readimagefile("PIX\\F14\\F_0235.jpg",0,0,640,480);break;
case 236:readimagefile("PIX\\F14\\F_0236.jpg",0,0,640,480);break;
case 237:readimagefile("PIX\\F14\\F_0237.jpg",0,0,640,480);break;
case 238:readimagefile("PIX\\F14\\F_0238.jpg",0,0,640,480);break;
case 239:readimagefile("PIX\\F14\\F_0239.jpg",0,0,640,480);break;
case 240:readimagefile("PIX\\F14\\F_0240.jpg",0,0,640,480);break;
case 241:readimagefile("PIX\\F14\\F_0241.jpg",0,0,640,480);break;
case 242:readimagefile("PIX\\F14\\F_0242.jpg",0,0,640,480);break;
case 243:readimagefile("PIX\\F14\\F_0243.jpg",0,0,640,480);break;
case 244:readimagefile("PIX\\F14\\F_0244.jpg",0,0,640,480);break;
case 245:readimagefile("PIX\\F14\\F_0245.jpg",0,0,640,480);break;
case 246:readimagefile("PIX\\F14\\F_0246.jpg",0,0,640,480);break;
case 247:readimagefile("PIX\\F14\\F_0247.jpg",0,0,640,480);break;
case 248:readimagefile("PIX\\F14\\F_0248.jpg",0,0,640,480);break;
case 249:readimagefile("PIX\\F14\\F_0249.jpg",0,0,640,480);break;
case 250:readimagefile("PIX\\F14\\F_0250.jpg",0,0,640,480);break;
case 251:readimagefile("PIX\\F14\\F_0251.jpg",0,0,640,480);break;
case 252:readimagefile("PIX\\F14\\F_0252.jpg",0,0,640,480);break;
case 253:readimagefile("PIX\\F14\\F_0253.jpg",0,0,640,480);break;
case 254:readimagefile("PIX\\F14\\F_0254.jpg",0,0,640,480);break;
case 255:readimagefile("PIX\\F14\\F_0255.jpg",0,0,640,480);break;
case 256:readimagefile("PIX\\F14\\F_0256.jpg",0,0,640,480);break;
case 257:readimagefile("PIX\\F14\\F_0257.jpg",0,0,640,480);break;
case 258:readimagefile("PIX\\F14\\F_0258.jpg",0,0,640,480);break;
case 259:readimagefile("PIX\\F14\\F_0259.jpg",0,0,640,480);break;
case 260:readimagefile("PIX\\F14\\F_0260.jpg",0,0,640,480);break;
case 261:readimagefile("PIX\\F14\\F_0261.jpg",0,0,640,480);break;
case 262:readimagefile("PIX\\F14\\F_0262.jpg",0,0,640,480);break;
case 263:readimagefile("PIX\\F14\\F_0263.jpg",0,0,640,480);break;
case 264:readimagefile("PIX\\F14\\F_0264.jpg",0,0,640,480);break;
case 265:readimagefile("PIX\\F14\\F_0265.jpg",0,0,640,480);break;
case 266:readimagefile("PIX\\F14\\F_0266.jpg",0,0,640,480);break;
case 267:readimagefile("PIX\\F14\\F_0267.jpg",0,0,640,480);break;
case 268:readimagefile("PIX\\F14\\F_0268.jpg",0,0,640,480);break;
case 269:readimagefile("PIX\\F14\\F_0269.jpg",0,0,640,480);break;
case 270:readimagefile("PIX\\F14\\F_0270.jpg",0,0,640,480);break;
case 271:readimagefile("PIX\\F14\\F_0271.jpg",0,0,640,480);break;
case 272:readimagefile("PIX\\F14\\F_0272.jpg",0,0,640,480);break;
case 273:readimagefile("PIX\\F14\\F_0273.jpg",0,0,640,480);break;
case 274:readimagefile("PIX\\F14\\F_0274.jpg",0,0,640,480);break;
case 275:readimagefile("PIX\\F14\\F_0275.jpg",0,0,640,480);break;
case 276:readimagefile("PIX\\F14\\F_0276.jpg",0,0,640,480);break;
case 277:readimagefile("PIX\\F14\\F_0277.jpg",0,0,640,480);break;
case 278:readimagefile("PIX\\F14\\F_0278.jpg",0,0,640,480);break;
case 279:readimagefile("PIX\\F14\\F_0279.jpg",0,0,640,480);break;
case 280:readimagefile("PIX\\F14\\F_0280.jpg",0,0,640,480);break;
case 281:readimagefile("PIX\\F14\\F_0281.jpg",0,0,640,480);break;
case 282:readimagefile("PIX\\F14\\F_0282.jpg",0,0,640,480);break;
case 283:readimagefile("PIX\\F14\\F_0283.jpg",0,0,640,480);break;
case 284:readimagefile("PIX\\F14\\F_0284.jpg",0,0,640,480);break;
case 285:readimagefile("PIX\\F14\\F_0285.jpg",0,0,640,480);break;
case 286:readimagefile("PIX\\F14\\F_0286.jpg",0,0,640,480);break;
case 287:readimagefile("PIX\\F14\\F_0287.jpg",0,0,640,480);break;
case 288:readimagefile("PIX\\F14\\F_0288.jpg",0,0,640,480);break;
case 289:readimagefile("PIX\\F14\\F_0289.jpg",0,0,640,480);break;
case 290:readimagefile("PIX\\F14\\F_0290.jpg",0,0,640,480);break;
case 291:readimagefile("PIX\\F14\\F_0291.jpg",0,0,640,480);break;
case 292:readimagefile("PIX\\F14\\F_0292.jpg",0,0,640,480);break;
case 293:readimagefile("PIX\\F14\\F_0293.jpg",0,0,640,480);break;
case 294:readimagefile("PIX\\F14\\F_0294.jpg",0,0,640,480);break;
case 295:readimagefile("PIX\\F14\\F_0295.jpg",0,0,640,480);break;
case 296:readimagefile("PIX\\F14\\F_0296.jpg",0,0,640,480);break;
case 297:readimagefile("PIX\\F14\\F_0297.jpg",0,0,640,480);break;
case 298:readimagefile("PIX\\F14\\F_0298.jpg",0,0,640,480);break;
case 299:readimagefile("PIX\\F14\\F_0299.jpg",0,0,640,480);break;
case 300:readimagefile("PIX\\F14\\F_0300.jpg",0,0,640,480);break;
case 301:readimagefile("PIX\\F14\\F_0301.jpg",0,0,640,480);break;
case 302:readimagefile("PIX\\F14\\F_0302.jpg",0,0,640,480);break;
case 303:readimagefile("PIX\\F14\\F_0303.jpg",0,0,640,480);break;
case 304:readimagefile("PIX\\F14\\F_0304.jpg",0,0,640,480);break;
case 305:readimagefile("PIX\\F14\\F_0305.jpg",0,0,640,480);break;
case 306:readimagefile("PIX\\F14\\F_0306.jpg",0,0,640,480);break;
case 307:readimagefile("PIX\\F14\\F_0307.jpg",0,0,640,480);break;
case 308:readimagefile("PIX\\F14\\F_0308.jpg",0,0,640,480);break;
case 309:readimagefile("PIX\\F14\\F_0309.jpg",0,0,640,480);break;
case 310:readimagefile("PIX\\F14\\F_0310.jpg",0,0,640,480);break;
case 311:readimagefile("PIX\\F14\\F_0311.jpg",0,0,640,480);break;
case 312:readimagefile("PIX\\F14\\F_0312.jpg",0,0,640,480);break;
case 313:readimagefile("PIX\\F14\\F_0313.jpg",0,0,640,480);break;
case 314:readimagefile("PIX\\F14\\F_0314.jpg",0,0,640,480);break;
case 315:readimagefile("PIX\\F14\\F_0315.jpg",0,0,640,480);break;
case 316:readimagefile("PIX\\F14\\F_0316.jpg",0,0,640,480);break;
case 317:readimagefile("PIX\\F14\\F_0317.jpg",0,0,640,480);break;
case 318:readimagefile("PIX\\F14\\F_0318.jpg",0,0,640,480);break;
case 319:readimagefile("PIX\\F14\\F_0319.jpg",0,0,640,480);break;
case 320:readimagefile("PIX\\F14\\F_0320.jpg",0,0,640,480);break;
case 321:readimagefile("PIX\\F14\\F_0321.jpg",0,0,640,480);break;
case 322:readimagefile("PIX\\F14\\F_0322.jpg",0,0,640,480);break;
case 323:readimagefile("PIX\\F14\\F_0323.jpg",0,0,640,480);break;
case 324:readimagefile("PIX\\F14\\F_0324.jpg",0,0,640,480);break;
case 325:readimagefile("PIX\\F14\\F_0325.jpg",0,0,640,480);break;
case 326:readimagefile("PIX\\F14\\F_0326.jpg",0,0,640,480);break;
case 327:readimagefile("PIX\\F14\\F_0327.jpg",0,0,640,480);break;
case 328:readimagefile("PIX\\F14\\F_0328.jpg",0,0,640,480);break;
case 329:readimagefile("PIX\\F14\\F_0329.jpg",0,0,640,480);break;
case 330:readimagefile("PIX\\F14\\F_0330.jpg",0,0,640,480);break;
case 331:readimagefile("PIX\\F14\\F_0331.jpg",0,0,640,480);break;
case 332:readimagefile("PIX\\F14\\F_0332.jpg",0,0,640,480);break;
case 333:readimagefile("PIX\\F14\\F_0333.jpg",0,0,640,480);break;
case 334:readimagefile("PIX\\F14\\F_0334.jpg",0,0,640,480);break;
case 335:readimagefile("PIX\\F14\\F_0335.jpg",0,0,640,480);break;
case 336:readimagefile("PIX\\F14\\F_0336.jpg",0,0,640,480);break;
case 337:readimagefile("PIX\\F14\\F_0337.jpg",0,0,640,480);break;
case 338:readimagefile("PIX\\F14\\F_0338.jpg",0,0,640,480);break;
case 339:readimagefile("PIX\\F14\\F_0339.jpg",0,0,640,480);break;
case 340:readimagefile("PIX\\F14\\F_0340.jpg",0,0,640,480);break;
case 341:readimagefile("PIX\\F14\\F_0341.jpg",0,0,640,480);break;
case 342:readimagefile("PIX\\F14\\F_0342.jpg",0,0,640,480);break;
case 343:readimagefile("PIX\\F14\\F_0343.jpg",0,0,640,480);break;
case 344:readimagefile("PIX\\F14\\F_0344.jpg",0,0,640,480);break;
case 345:readimagefile("PIX\\F14\\F_0345.jpg",0,0,640,480);break;
case 346:readimagefile("PIX\\F14\\F_0346.jpg",0,0,640,480);break;
case 347:readimagefile("PIX\\F14\\F_0347.jpg",0,0,640,480);break;
case 348:readimagefile("PIX\\F14\\F_0348.jpg",0,0,640,480);break;
case 349:readimagefile("PIX\\F14\\F_0349.jpg",0,0,640,480);break;
case 350:readimagefile("PIX\\F14\\F_0350.jpg",0,0,640,480);break;
case 351:readimagefile("PIX\\F14\\F_0351.jpg",0,0,640,480);break;
case 352:readimagefile("PIX\\F14\\F_0352.jpg",0,0,640,480);break;
case 353:readimagefile("PIX\\F14\\F_0353.jpg",0,0,640,480);break;
case 354:readimagefile("PIX\\F14\\F_0354.jpg",0,0,640,480);break;
case 355:readimagefile("PIX\\F14\\F_0355.jpg",0,0,640,480);break;
case 356:readimagefile("PIX\\F14\\F_0356.jpg",0,0,640,480);break;
case 357:readimagefile("PIX\\F14\\F_0357.jpg",0,0,640,480);break;
case 358:readimagefile("PIX\\F14\\F_0358.jpg",0,0,640,480);break;
case 359:readimagefile("PIX\\F14\\F_0359.jpg",0,0,640,480);break;
case 360:readimagefile("PIX\\F14\\F_0360.jpg",0,0,640,480);break;
case 361:readimagefile("PIX\\F14\\F_0361.jpg",0,0,640,480);break;
case 362:readimagefile("PIX\\F14\\F_0362.jpg",0,0,640,480);break;
case 363:readimagefile("PIX\\F14\\F_0363.jpg",0,0,640,480);break;
case 364:readimagefile("PIX\\F14\\F_0364.jpg",0,0,640,480);break;
case 365:readimagefile("PIX\\F14\\F_0365.jpg",0,0,640,480);break;
case 366:readimagefile("PIX\\F14\\F_0366.jpg",0,0,640,480);break;
case 367:readimagefile("PIX\\F14\\F_0367.jpg",0,0,640,480);break;
case 368:readimagefile("PIX\\F14\\F_0368.jpg",0,0,640,480);break;

}



outtextxy(100, 80, arrm);
outtextxy(100, 100, arrg);
outtextxy(100, 120, arrf);

if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_A)) missles = missles - 1;
if (IS_JUST_PRESSED(wiimotes[0], WIIMOTE_BUTTON_B)) ammo = ammo - 1;

fuelCount++;
if(fuelCount%10 == 0)
{
	fuel = fuel - 1;}	

if (kbhit()) {
	getch(); 
	if(connected) {
		wiiuse_cleanup(wiimotes, MAX_WIIMOTES); //clean memory of wii libraries
	}

	break;
}
}//while

PlaySound("SOUNDS\\bam.wav", NULL, SND_ASYNC);

return 0;}





int init_wii(){


wiimotes =  wiiuse_init(MAX_WIIMOTES);
	//Get wiimotes
	found = wiiuse_find(wiimotes, MAX_WIIMOTES, 5);
	printf("WII Remote Detection Status (0/1): %d\n", found);

	if (!found) {
		printf("Wiimote was not found!\n");
		return 0;
	}

	/*
	 *	Connect to the wiimotes
	 *	This will return the number of established connections to the found wiimotes.
	 */
	connected = wiiuse_connect(wiimotes, MAX_WIIMOTES);
	printf("WII Remote Connection Status (0/1): %d\n", connected);

	//enable accelerometer for wii number 0
	if (connected){
		wiiuse_motion_sensing(wiimotes[0],1);
	}

return 1; //wii is working successfully
}






void bubble_sort(int list[], int n)
{

	cleardevice();
	setcolor(COLOR(0,0,200));
	setbkcolor(COLOR(200,200,200));
	//readimagefile("PIX\\shuttle.jpg",0,0,640,480);

  int c, d, t; //two counters and a temporary variable
  int i = 0; // plotting counter


  for (c = 0 ; c < ( n - 1 ); c++) // select a number from the array
  {
  for (d = 0 ; d < n - c - 1; d++) // compare it to all other numbers in the array
    {
      if (list[d] < list[d+1]) // at each comparison check who is larger
      {
        /* Swapping */
        t         = list[d]; //save current item in temporary variable
        list[d]   = list[d+1]; //swap next item with current
        list[d+1] = t; //restore temp to next item
      }

    }//inner for (nested loop)

  cleardevice(); //clear screen
  //readimagefile("PIX\\shuttle.jpg",0,0,640,480);

  for (i=0; i<n; i++){ rectangle(0,i*2,list[i]*5,(i*2)+2);} //draw sorted rectangles at each master iteration
    Sleep(30); //slow it down so we can see it happen
	
  }//main for

outtextxy(300, 400, "Bubble-Sort Complete.");

}




void insertion_sort(int list[], int n)
{

	cleardevice();
	setcolor(COLOR(0,0,255));
	setbkcolor(COLOR(255,255,255));


   int i, z;
   for (i=0; i < n; i++)
   {
       /* Insert a[i] into the sorted sublist */
       int j, v = list[i];
 
       for (j = i - 1; j >= 0; j--)
       {
           if (list[j] >= v) break;
           list[j + 1] = list[j];
       }
       list[j+1] = v;

cleardevice(); //clear screen
for (z=0; z<n; z++){ rectangle(0,z*2,list[z]*5,(z*2)+2);} //draw sorted rectangles at each master iteration
Sleep(30); //slow it down so we can see it happen
}

outtextxy(300, 400, "Insertion-Sort Complete.");

}




