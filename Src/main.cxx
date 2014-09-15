
#pragma comment( lib, "winmm" ) //request Windows multimedia API, this is a .DLL file you are linking into.


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h> //required for sound fucntionality
#include <time.h>
#include "graphics.h"
#include "TRON.h"


int main()
{


initwindow(1600,900);

registermousehandler(WM_LBUTTONDOWN, left_click);
registermousehandler(WM_RBUTTONDOWN, right_click);





/*outtextxy(600, 780, "Press any key to play");
outtextxy(textheight("500"), textwidth("500"), "Press any key to play");*/




//PlaySound("SOUNDS\\radiation_warning.wav", NULL, SND_ASYNC);

//draw(0);
//while(1){
//
// if (kbhit()) {
//  getch();
 MainMenu();
//  getch();
//
//}
//
//
//	
//}

 return 0;
}
