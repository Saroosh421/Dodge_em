//============================================================================
// Name        : game.cpp
// Author      : Saroosh Hammad
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
	int s=0,h=0,xaxis=0,yaxis=0,i=0,q=0,w=0;
	float c = 360, d = 610; 	
	float a = 50, b = 300;
	float e = 350, f = 25;
	float o,p;

	int speed=5;
	int opspeed=5;
	int points=0;
	int dead=3;
	int levelOf=1;

	float width = 10; 	
	float height = 8;	
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3.0;	

	int gap_turn = 60;
	int sx = 20;
	int sy = -90;
	int swidth = 800/2 - gap_turn/2; 
	int sheight = 10;
	
	bool food[64];
	bool gameStart=false;
	bool reDraw=false;
	bool detect=false;
	bool help=false;
	bool pauseMenu=false;
	bool highScore=false;

	float *scolor = colors[BROWN];
	

//================================================================================================================================================================//
						// Functions are used to implement menu 
						// Functions are also used for levels

	//Pause function is used to pause game during its play

void Pause(){
	if (pauseMenu==true){
		DrawSquare( 220 , 140 ,400,colors[DARK_SALMON]);
		DrawString( 350, 450, "Start a new game", colors[BLACK]);
		DrawString( 370, 400, "Highscore", colors[BLACK]);
		DrawString( 400, 350, "Help", colors[BLACK]);
		DrawString( 400, 300, "Exit", colors[BLACK]);
		DrawString( 370, 250, "Continue", colors[BLACK]);
		speed=0;opspeed=0;
			}
	if (pauseMenu==false){
		if (reDraw=false){
			if (detect=true){
				points=0;
			}
		}	
	}
}

	//help function is used to display some suggestions

void Help(){
	if (help==true){
	DrawSquare( 130 , 130 ,600,colors[DARK_SALMON]);
	DrawString( 150, 700, "We can help you by controls:", colors[BLACK]);
	DrawString( 250, 660, "Use arrow keys to move the car.", colors[BLACK]);
	DrawString( 150, 620, "What to do?", colors[BLACK]);
	DrawString( 250, 580, "Your ultimate goal is to pick up all the gifts", colors[BLACK]);
	DrawString( 250, 550, "without colliding with the opponent car.", colors[BLACK]);
	DrawString( 150, 450, "Once you have picked", colors[BLACK]);
	DrawString( 150, 420, "all the gifts you will", colors[BLACK]);
	DrawString( 150, 390, "be promoted to next level.", colors[BLACK]);
	DrawSquare( 470 ,320  ,200,colors[BLACK]);
	DrawRectangle(sx + swidth + gap_turn+20, sy+550, swidth-170, sheight, scolor);
	DrawRectangle(sx + swidth + gap_turn+20, sy+470, swidth-170, sheight, scolor);
	DrawCircle(570,425,10,colors[PURPLE]);
	 o=500;p=405;	
	 width = 10; 	
	 height = 8;	
	 color = colors[BLUE_VIOLET]; 
	 radius = 3.0;
	DrawRoundRect(o+xaxis,p+yaxis,width,height,color,radius); // bottom left tyre
	DrawRoundRect(o+xaxis+width*3,p+yaxis,width,height,color,radius); // bottom right tyre
	DrawRoundRect(o+xaxis+width*3,p+yaxis+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(o+xaxis,p+yaxis+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(o+xaxis, p+yaxis+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(o+xaxis+width, p+yaxis+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(o+xaxis+width*3, p+yaxis+height*2, width, height, color, radius/2); // body right rect
	DrawString( 400, 200, "Back", colors[BLACK]);}		
}

	// car detection function is used to detect collision of cars
	
void crash(){
	if (detect==true){
		if(c+xaxis+width+10>=a+s+width && c+xaxis+width-10<=a+s+width && d+yaxis+height+10>=b+h+height*2 && d+yaxis+height-10<=b+h+height*2 ){
		speed=0;
		opspeed=0;
		dead--;
		reDraw=true;
		points=0;
		c=360;d=610;a=50;b=300;
			if (levelOf==3){
				c=360;d=610;a=350;b=25;}
		}
		if(c+xaxis+width+10>=e+q+width && c+xaxis+width-10<=e+q+width && d+yaxis+height+10>=f+w+height*2 && d+yaxis+height-10<=f+w+height*2){
			speed=0;
			opspeed=0;
			dead--;
			reDraw=true;
			points=0;
			c=320;d=25;a=520;b=25;}
		}
}
	// This function is implemented to read file 

string readFile(){
	ifstream DIS("Highscores.txt");
		if(DIS){
			char buffer[100];
			string READ="   = ";
			DIS.getline(buffer,99);
			do{
				READ+=(string) buffer;
				READ+="   = ";
				DIS.getline(buffer,99);
				
			}while (DIS);
		return READ;
		}
	return "";			
}					
	// This function is used to carry out level 2

void level2(){
	if (points==64){		//When user has collected all the gifts than level 2 will be implemented
		levelOf++;
		points+=100;
		c = 360; d = 610; 	
		a = 50; b = 300;
		gameStart=true;
		reDraw=true;
		detect=true;
		help=false;
		pauseMenu=false;
		}
}
	// This function is used to carry out level 3
void level3(){
	if (points==228){		//When user has collected all the gifts than level 3 will be implemented
		levelOf++;
		points+=100;		
		c = 350; d = 610; 	
		a = 350; b = 25;
		gameStart=true;
		reDraw=true;
		detect=true;
		help=false;
		pauseMenu=false;
		}
}	
	// This function is used to carry out level 4
void level4(){
	if (points==392){		//When user has collected all the gifts than level 4 will be implemented
		levelOf++;
		points+=100;
		c = 360; d = 610; 	
		a = 50; b = 300;
		e = 350, f = 25;
		gameStart=true;
		reDraw=true;
		detect=true;
		help=false;
		pauseMenu=false;
		}
}			
	
	// This fuction is specifically used to draw and disappear gifts/food	

void foodssss(){
	if (reDraw==true){
		for (int k=0; k<=63; k++){
			food[k]=true;
		}
		reDraw=false;
	}
	else
	{
		for (int j=0, p=0;j<4;j++){					// Food/gift implification
			if (food[j]==true){
				DrawCircle(60 + p*90 , 45 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=4, p=0;j<8;j++){
			if (food[j]==true){
			DrawCircle(510 + p*90 , 45 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=8, p=0;j<12;j++){	
			if (food[j]==true){
				DrawCircle(60 + p*90 , 110 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=12, p=0;j<16;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 110 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=16, p=0;j<20;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 175 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=20, p=0;j<24;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 175 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=24, p=0;j<28;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 240 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=28, p=0;j<32;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 240 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=32, p=0;j<36;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 435 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=36, p=0;j<40;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 435 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=40, p=0;j<44;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 500 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=44, p=0;j<48;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 500 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=48, p=0;j<52;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 565 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=52, p=0;j<56;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 565 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=56, p=0;j<60;j++){
			if (food[j]==true){
				DrawCircle(60 + p*90 , 630 , 10,colors[PURPLE]);
					}p++;
				}
		for (int j=60, p=0;j<64;j++){
			if (food[j]==true){
				DrawCircle(510 + p*90 , 630 , 10,colors[PURPLE]);
					}p++;
				}


		//Collecting food
		for (int j=0, p=0; j<4; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=45 && d-20<=45) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=4, p=0; j<8; j++){
			if ((c+10>=510+(p*90) && c-10<=510+(p*90)) && (d+20>=45 && d-20<=45) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=8, p=0; j<12; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=110 && d-20<=110) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=12, p=0; j<16; j++){
			if ((c+20>=510+(p*90) && c-20<=510+(p*90)) && (d+20>=110 && d-20<=110) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=16, p=0; j<20; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=175 && d-20<=175) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=20, p=0; j<24; j++){
			if ((c+10>=510+(p*90)-20 && c-10<=510+(p*90)) && (d+20>=175 && d-20<=175) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=24, p=0; j<28; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=240 && d-20<=240) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=28, p=0; j<32; j++){
			if ((c+10>=510+(p*90)-20 && c-10<=510+(p*90)) && (d+20>=240 && d-20<=240) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=32, p=0; j<36; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=435 && d-20<=435) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=36, p=0; j<40; j++){
			if ((c+10>=510+(p*90)-20 && c-10<=510+(p*90)) && (d+20>=435 && d-20<=435) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=40, p=0; j<44; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=500 && d-20<=500) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=44, p=0; j<48; j++){
			if ((c+10>=510+(p*90)-25 && c-10<=510+(p*90)) && (d+20>=500 && d-20<=500) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=48, p=0; j<52; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=565 && d-20<=565) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=52, p=0; j<56; j++){
			if ((c+10>=510+(p*90)-20 && c-10<=510+(p*90)) && (d+20>=565 && d-20<=565) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=56, p=0; j<60; j++){
			if ((c+10>=60+(p*90) && c-10<=60+(p*90)) && (d+20>=630 && d-20<=630) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}
		for (int j=60, p=0; j<64; j++){
			if ((c+10>=510+(p*90)-20 && c-10<=510+(p*90)) && (d+20>=630 && d-20<=630) && food[j]==true){
				food[j]=false;
				points++;
					}p++;
				}	
	}
}

//================================================================================================================================================================//

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
//===========================================================================================================================================================//	

								//Drawing cars

	// Drawing player's car
	
	 width = 10; 	//20
	 height = 8;	//15
	 color = colors[BLUE_VIOLET]; 
	 radius = 3.0;	//5.0
	DrawRoundRect(c+xaxis,d+yaxis,width,height,color,radius); // bottom left tyre
	DrawRoundRect(c+xaxis+width*3,d+yaxis,width,height,color,radius); // bottom right tyre
	DrawRoundRect(c+xaxis+width*3,d+yaxis+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(c+xaxis,d+yaxis+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(c+xaxis, d+yaxis+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(c+xaxis+width, d+yaxis+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(c+xaxis+width*3, d+yaxis+height*2, width, height, color, radius/2); // body right rect

	 //Drawing opponent's car
	
	 width = 10; 
	 height = 8;
	 color = colors[BLUE]; 
	 radius = 3.0;
	DrawRoundRect(a+s,b+h,width,height,color,radius); // bottom left tyre
	DrawRoundRect(a+s+width*3,b+h,width,height,color,radius); // bottom right tyre
	DrawRoundRect(a+s+width*3,b+h+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(a+s,b+h+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(a+s, b+h+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(a+s+width, b+h+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(a+s+width*3, b+h+height*2, width, height, color, radius/2); // body right rect	
	
	//When user completes 3 levels than in level 4 another opponenet car is allowed to draw
	
	if (levelOf==4){
	 width = 10; 
	 height = 8;
	 color = colors[BLUE]; 
	 radius = 3.0;
	DrawRoundRect(e+q,f+w,width,height,color,radius); // bottom left tyre
	DrawRoundRect(e+q+width*3,f+w,width,height,color,radius); // bottom right tyre
	DrawRoundRect(e+q+width*3,f+w+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(e+q,f+w+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(e+q, f+w+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(e+q+width, f+w+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(e+q+width*3, f+w+height*2, width, height, color, radius/2); // body right rect	
	}

//===============================================================================================================================================================//

									// Drawing Arena
	
	// Outer boundary	
	DrawRectangle(sx, sy+100, swidth-20, sheight, scolor); // bottom left	
	DrawRectangle(sx + swidth + gap_turn+20, sy+100, swidth-20, sheight, scolor); // bottom right	
	DrawRectangle(sx-2+swidth*2+gap_turn, sy+90+sheight, sheight*2, swidth-100, scolor); // right down	
	DrawRectangle(sx+swidth*2+gap_turn, sy+40+sheight+swidth+gap_turn, sheight*2, swidth-90, scolor); // right up 
	DrawRectangle(sx + swidth + gap_turn+20, sy+750, swidth, sheight, scolor); // top right	
	DrawRectangle(sx, sy+750, swidth-20, sheight, scolor); // top left	
	DrawRectangle(sx+2-sheight*2, sy+40+sheight+swidth+gap_turn, sheight*2, swidth-90, scolor); // left up	
	DrawRectangle(sx+2-sheight*2, sy+90+sheight, sheight*2, swidth-100, scolor); // left down	
	
	// next Inner boundary
	DrawRectangle(sx+100, sy+160, swidth-120, sheight, scolor); // bottom left
	DrawRectangle(sx+102-sheight*2, sy+150+sheight, sheight*2, swidth-160, scolor); // left down
	DrawRectangle(sx + swidth + gap_turn+20, sy+680, swidth-100, sheight, scolor); // top right
	DrawRectangle(sx-95+swidth*2+gap_turn, sy+100+sheight+swidth-60+gap_turn, sheight*2, swidth-160, scolor); // right up
	DrawRectangle(sx+102-sheight*2, sy+40+sheight+swidth-60+gap_turn+60, sheight*2, swidth-160, scolor); // left up
	DrawRectangle(sx+10 +swidth-90 + gap_turn+100, sy+160, swidth-110, sheight, scolor); // bottom right
	DrawRectangle(sx-95+swidth*2+gap_turn, sy+150+sheight, sheight*2, swidth-160, scolor); // right down
	DrawRectangle(sx+100, sy+680, swidth-120, sheight, scolor); // top left
	
	// next Inner boundary
	DrawRectangle(sx+190, sy+220, swidth-210, sheight, scolor); // bottom left
	DrawRectangle(sx+195-sheight*2, sy+210+sheight, sheight*2, swidth-220, scolor); // left down
	DrawRectangle(sx + swidth + gap_turn+20, sy+620, swidth-200, sheight, scolor); // top right
	DrawRectangle(sx-185+swidth*2+gap_turn, sy+130+sheight+swidth-90+gap_turn, sheight*2, swidth-220, scolor); // right up
	DrawRectangle(sx+195-sheight*2, sy+120+sheight+swidth-140+gap_turn+60, sheight*2, swidth-220, scolor); // left up
	DrawRectangle(sx+ swidth-150 + gap_turn+170, sy+220, swidth-200, sheight, scolor); // bottom right
	DrawRectangle(sx-185+swidth*2+gap_turn, sy+210+sheight, sheight*2, swidth-220, scolor); // right down
	DrawRectangle(sx+190, sy+620, swidth-210, sheight, scolor); // top left

	// next Inner boundary
	DrawRectangle(sx+275, sy+290, swidth-295, sheight, scolor); // bottom left
	DrawRectangle(sx+280-sheight*2, sy+280+sheight, sheight*2, swidth-290, scolor); // left down
	DrawRectangle(sx+2+ swidth-180 + gap_turn+200, sy+290, swidth-290, sheight, scolor); // bottom right
	DrawRectangle(sx-275+swidth*2+gap_turn, sy+280+sheight, sheight*2, swidth-290, scolor); // right down
	DrawRectangle(sx+275, sy+560, swidth-295, sheight, scolor); // top left	
	DrawRectangle(sx+280-sheight*2, sy+160+sheight+swidth-180+gap_turn+60, sheight*2, swidth-280, scolor); // left up
	DrawRectangle(sx + swidth + gap_turn+20, sy+560, swidth-290, sheight, scolor); // top right
	DrawRectangle(sx-275+swidth*2+gap_turn, sy+180+sheight+swidth-140+gap_turn, sheight*2, swidth-280, scolor); // right up

	// Inner boundary
	DrawRectangle(sx+355, sy+370, swidth-325, sheight, scolor); // bottom left	
	DrawRectangle(sx-50 + swidth + gap_turn+15, sy+370, swidth-320, sheight, scolor); // bottom right	
	DrawRectangle(sx-360+swidth*2+gap_turn, sy+360+sheight, sheight*2, swidth-320, scolor); // right down	
	DrawRectangle(sx-360+swidth*2+gap_turn, sy+200+sheight+swidth-200+gap_turn, sheight*2, swidth-320, scolor); // right up 
	DrawRectangle(sx-50 + swidth + gap_turn+15, sy+480, swidth-320, sheight, scolor); // top right	
	DrawRectangle(sx+355, sy+480, swidth-325, sheight, scolor); // top left	
	DrawRectangle(sx+370-sheight*2, sy+250+sheight+swidth-250+gap_turn, sheight*2, swidth-320, scolor); // left up	
	DrawRectangle(sx+370-sheight*2, sy+360+sheight, sheight*2, swidth-320, scolor); // left down	

//===============================================================================================================================================================//


	// Lives and score representation on the top of screen
	
	DrawString( 700, 700, "Score="+to_string(points), colors[MISTY_ROSE]);
	DrawString( 50, 700, "Lives="+to_string(dead), colors[MISTY_ROSE]);
	DrawString( 380, 700, "Level="+to_string(levelOf), colors[MISTY_ROSE]);

	//Menu created in the start of game
	//car moves when mouse is clicked

	//Menu that comes when game is compiled

	if (gameStart==false){
		speed=0;	
		opspeed=0;
		DrawSquare( 220 , 140 ,400,colors[DARK_SALMON]);
		DrawString( 350, 450, "Start a new game", colors[BLACK]);
		DrawString( 370, 400, "Highscore", colors[BLACK]);
		DrawString( 400, 350, "Help", colors[BLACK]);
		DrawString( 400, 300, "Exit", colors[BLACK]);
		DrawString( 700, 700, "Score=0", colors[MISTY_ROSE]);
		DrawString( 50, 700, "Lives=3", colors[MISTY_ROSE]);
		DrawString( 380, 700, "Level=1", colors[MISTY_ROSE]);
		}
	else{
		
		speed=5;
		opspeed=5;
		}

	// Functions that were made on the top are called here

	foodssss();
	Pause();
	//crash();
	Help();

	//When user runs out of lives than game is started again (Menu appear again) 

	if (dead==0){
	gameStart=false;
	dead=3;}
	
	if (points==556){
		DrawSquare( 220 , 140 ,400,colors[PURPLE]);
		DrawString( 350, 400, "You have won!!!", colors[BLACK]);
		DrawString( 400, 300, "Exit", colors[BLACK]);
		speed=0;
		opspeed=0;
	}
	
	if (highScore==true){
		DrawSquare( 130 , 130 ,600,colors[DARK_SALMON]);
		DrawString( 150, 400, readFile() , colors[MISTY_ROSE]);
		DrawString( 400, 200, "Back", colors[BLACK]);
	}

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is p;.ressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	//When up,down,left and right key is pressed with-in the domain of height than car shifts its position


	if (key == GLUT_KEY_LEFT){
		if ((d>=250 && d<=350) && (c>=130 && c<=410))
			c-=90;
		else if ((d>=250 && d<=350) && (c>=510 && c<=790))		
			c-=90;
							
	
	}/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/ 
		// what to do when left key is pressed...
	
	else if (key == GLUT_KEY_RIGHT){
		if ((d>=250 && d<=350) && (c>=40 && c<=310))
			c+=90;
		else if ((d>=250 && d<=350) && (c>=490 && c<=700 ))			
			c+=90;
			
			
	}/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/ 


	else if (key == GLUT_KEY_UP) {
		if ((c>=360 && c<=480) && (d>=20 && d<=210))			
			d+=65;
		else if ((c>=360 && c<=480) && (d>=410 && d<=550))			
			d+=65;
			

	//	up=true;
	}/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/

	else if (key == GLUT_KEY_DOWN) {
		if ((c>=360 && c<=480) && (d>=420 && d<=620))			
			d-=65;
		if ((c>=360 && c<=480) && (d>=30 && d<=230))			
			d-=65;
		

	//	down=true;
	}/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/

	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if (key == 80 || key == 112)			// If p or P is pressed than pause menu appears
			{
		pauseMenu=true;

	}
	//if (key==32)
	//speed+=10;
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	
	if (levelOf==3)
		opspeed=10;
	else{
		if (levelOf==2 || levelOf==4)
		opspeed=5;
	}

//================================================================================================================================================================//

	//Movement of opponent in level 3 (It is different because speed is twice)

	if (levelOf==3){
		if ((a>=50 && a<=770 && b==30) || (a>=140 && a<=665 && b==95) || (a>=230 && a<=590 && b==160) || (a>=320 && a<=500 && b==220))
		a+=opspeed;
		if ((b>=30 && b<=605 && a==770) || (b>=90 && b<=535 && a==675) || (b>=160 && b<=480 && a==590) || (b>=220 && b<=410 && a==500))
		b+=opspeed;
		if ((a<=770 && a>=60 && b==605) || (a<=675 && a>=150 && b==540) || (a<=590 && a>=240 && b==480) || (a<=500 && a>=330 && b==420))
		a-=opspeed;
		if ((b<=605 && b>=30 && a==50) || (b<=540 && b>=95 && a==145) || (b<=480 && b>=160 && a==230) || (b<=420 && b>=230 && a==320))
		b-=opspeed;	
	}	


	//Logic to move opponent car in the shells
	
	if ((a>=50 && a<=765 && b==25) || (a>=140 && a<=675 && b==90) || (a>=230 && a<=585 && b==155) || (a>=320 && a<=495 && b==220)){
	a+=opspeed;
	}
	if ((b>=25 && b<=605 && a==770) || (b>=90 && b<=540 && a==680) || (b>=155 && b<=475 && a==590) || (b>=220 && b<=410 && a==500)){
	b+=opspeed;
	}
	if ((a<=770 && a>=55 && b==610) || (a<=680 && a>=145 && b==545) || (a<=590 && a>=235 && b==480) || (a<=500 && a>=325 && b==415)){
	a-=opspeed;
	}
	if ((b<=610 && b>=30 && a==50) || (b<=545 && b>=95 && a==140) || (b<=480 && b>=160 && a==230) || (b<=415 && b>=225 && a==320)){
	b-=opspeed;
	}		
		
	
	//Movement of second opponent when user reaches level 4
	if (levelOf==4){
		if ((e>=50 && e<=765 && f==25) || (e>=140 && e<=675 && f==90) || (e>=230 && e<=585 && f==155) || (e>=320 && e<=495 && f==220))
		e+=opspeed;	
		if ((f>=25 && f<=605 && e==770) || (f>=90 && f<=540 && e==680) || (f>=155 && f<=475 && e==590) || (f>=220 && f<=410 && e==500))		
		f+=opspeed;
		if ((e<=770 && e>=55 && f==610) || (e<=680 && e>=145 && f==545) || (e<=590 && e>=235 && f==480) || (e<=500 && e>=325 && f==415))
		e-=opspeed;
		if ((f<=610 && f>=30 && e==50) || (f<=545 && f>=95 && e==140) || (f<=480 && f>=160 && e==230) || (f<=415 && f>=225 && e==320))
		f-=opspeed;
	}

	//player's car movement in all levels

	if (levelOf==1 || levelOf==2 || levelOf==3 || levelOf==4){
		if ((c>=50 && c<=770 && d==25) || (c>=145 && c<=680 && d==90) || (c>=235 && c<=590 && d==155) || (c>=325 && c<=500 && d==220))
		c-=speed;
		if ((d>=25 && d<=605 && c==50) || (d>=90 && d<=540 && c==140) || (d>=155 && d<=495 && c==230) || (d>=220 && d<=430 && c==320))
		d+=speed;
		if ((c>=50 && c<=765 && d==610) || (c>=140 && c<=675 && d==545) || (c>=230 && c<=585 && d==480) || (c>=320 && c<=495 && d==415))
		c+=speed;
		if ((d<=610 && d>=30 && c==770) || (d<=545 && d>=95 && c==680) || (d<=480 && d>=160 && c==590) || (d<=415 && d>=225 && c==500))
		d-=speed;
	}	

//==============================================================================================================================================================//

								//AI logic employed
				//when player's car move in and out of the shell than opponent car performs certain actions

	//opponenet movement inward in case of level 1

	//As in level 1, only opponent can come from top or bottom space of the shell

	if(levelOf==1){
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=675 && d==545) || (d<=545 && d>=95 && c==680)){
			if (a>=130 && a<=780 ){
				if(a==350 && b==25){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}	
			}
		}
		if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
			if (a>=130 && a<=780 ){
				if(a==350 && b==25){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}		
				if(a==350 && b==90){
				b+=65;
				a+=5;}
				if(a==350 && b==545){
				b-=65;
				a-=5;}	
			}
		}
		if((c>=325 && c<=500 && d==220) || (d>=220 && d<=430 && c==320) || (c>=320 && c<=495 && d==415) || (d<=415 && d>=225 && c==500)){
			if (a>=130 && a<=780 ){
				if(a==350 && b==25){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}		
				if(a==350 && b==90){
				b+=65;
				a+=5;}
				if(a==350 && b==545){
				b-=65;
				a-=5;}			
				if(a==350 && b==155){
				b+=65;
				a+=5;}
				if(a==350 && b==480){
				b-=65;
				a-=5;}	
			}
		}
	}
	
	//opponent movement outward in case of level 1

	if (levelOf==1){
		if ((c>=50 && c<=770 && d==25) || (d>=25 && d<=605 && c==50) || (c>=50 && c<=765 && d==610) || (d<=610 && d>=30 && c==770)){
			if (c>=50 && c<=770 && d==25){
				if(a==350 && b==545){
				b+=65;
				a-=5;}
				if(a==350 && b==90){
				b-=65;
				a+=5;}
				if(a==350 && b==480){
				b+=65;
				a-=5;}		
				if(a==350 && b==155){
				b-=65;
				a+=5;}
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}			
			}
		}
	
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=665 && d==545) || (d<=545 && d>=95 && c==680)){
			if (a>=130 && a<=780 ){	
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==480){
				b+=65;
				a-=5;}		
				if(a==350 && b==155){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}			
			}
		}
		if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
			if (a>=130 && a<=780 ){	
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}	
			}
		}
	}	

//...............................................................................................................................................................//

	//opponenet movement inward in case of other levels

	//above logic of AI is enhansed as now opponent can alos come through side ways

	if(levelOf==2 || levelOf==3 || levelOf==4){
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=675 && d==545) || (d<=545 && d>=95 && c==680)){
			if (a>=130 && a<=780 ){
				if(a==350 && (b>=25 && b<=30)){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}
			}
			if (b>=20 && b<=700){
				if(b==300 && a==50){
				a+=90;
				b-=5;}
				if(b==300 && a==770){
				a-=90;
				b+=5;}		
			}
		}
		if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
			if (a>=130 && a<=780 ){
				if(a==350 && (b>=20 && b<=40)){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}		
				if(a==350 && (b>=85 && b<=120)){
				b+=65;
				a+=5;}
				if(a==350 && b==545){
				b-=65;
				a-=5;}
			}
			if (b>=20 && b<=700){
				if(b==300 && a==50){
				a+=90;
				b-=5;}
				if(b==300 && a==770){
				a-=90;
				b+=5;}
				if(b==300 && a==140){
				a+=90;
				b-=5;}
				if(b==300 && a==680){
				a-=90;
				b+=5;}		
			}	
		}
		if((c>=325 && c<=500 && d==220) || (d>=220 && d<=430 && c==320) || (c>=320 && c<=495 && d==415) || (d<=415 && d>=225 && c==500)){
			if (a>=130 && a<=780 ){
				if(a==350 && (b>=25 && b<=30)){
				b+=65;
				a+=5;}
				if(a==350 && b==610){
				b-=65;
				a-=5;}		
				if(a==350 && (b>=90 && b<=95)){
				b+=65;
				a+=5;}
				if(a==350 && b==545){
				b-=65;
				a-=5;}			
				if(a==350 && b==155){
				b+=65;
				a+=5;}
				if(a==350 && b==480){
				b-=65;
				a-=5;}
			}
			if (b>=20 && b<=700){
				if(b==300 && a==50){
				a+=90;
				b-=5;}
				if(b==300 && a==770){
				a-=90;
				b+=5;}
				if(b==300 && a==140){
				a+=90;
				b-=5;}
				if(b==300 && a==680){
				a-=90;
				b+=5;}
				if(b==300 && a==230){
				a+=90;
				b-=5;}
				if(b==300 && a==590){
				a-=90;
				b+=5;}		
			}		
		}
	}

	//opponent movement outward in case of other levels

	if (levelOf==2 || levelOf==3 ||levelOf==4){
		if ((c>=50 && c<=770 && d==25) || (d>=25 && d<=605 && c==50) || (c>=50 && c<=765 && d==610) || (d<=610 && d>=30 && c==770)){
			if (c>=50 && c<=770 && d==25){
				if(a==350 && b==545){
				b-=65;
				a+=5;}
				if(a==350 && b==90){
				b-=65;
				a+=5;}
				if(a==350 && b==480){
				b+=65;
				a-=5;}		
				if(a==350 && b==155){
				b-=65;
				a+=5;}
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}			
			}
			if (b>=20 && b<=700){
				if(b==300 && a==320){
				a-=90;
				b-=5;}
				if(b==300 && a==500){
				a+=90;
				b+=5;}
				if(b==300 && a==230){
				a-=90;
				b-=5;}
				if(b==300 && a==590){
				a+=90;
				b+=5;}
				if(b==300 && a==140){
				a-=90;
				b-=5;}
				if(b==300 && a==680){
				a+=90;
				b+=5;}
			}
		}
	
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=665 && d==545) || (d<=545 && d>=95 && c==680)){
			if (a>=130 && a<=780 ){	
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==480){
				b+=65;
				a-=5;}		
				if(a==350 && b==155){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}			
			}
		
			if (b>=20 && b<=700){
				if(b==300 && a==320){
				a-=90;
				b-=5;}
				if(b==300 && a==500){
				a+=90;
				b+=5;}
				if(b==300 && a==230){
				a-=90;
				b-=5;}
				if(b==300 && a==590){
				a+=90;
				b+=5;}		
			}
		}
		if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
			if (a>=130 && a<=780 ){	
				if(a==350 && b==220){
				b-=65;
				a+=5;}
				if(a==350 && b==415){
				b+=65;
				a-=5;}	
			}
			if (b>=20 && b<=700){
				if(b==300 && a==320){
				a-=90;
				b-=5;}
				if(b==300 && a==500){
				a+=90;
				b+=5;}		
			}
		}

	}

//..............................................................................................................................................................//

	// for level 4 another opponent car is introduced, therefore logic of AI for both cars is employed bellow

	//opponenet movement inward incase of level 4

	if (levelOf==4){
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=675 && d==545) || (d<=545 && d>=95 && c==680)){
				if (e>=130 && e<=780 ){
					if(e==350 && f==25){
					f+=65;
					e+=5;}
					if(e==350 && f==610){
					f-=65;
					e-=5;}
				}
				if (f>=20 && f<=700){
					if(f==300 && e==50){
					e+=90;
					f-=5;}
					if(f==300 && e==770){
					e-=90;
					f+=5;}		
				}
			}
			if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
				if (e>=130 && e<=780 ){
					if(e==350 && f==25){
					f+=65;
					e+=5;}
					if(e==350 && f==610){
					f-=65;
					e-=5;}		
					if(e==350 && f==90){
					f+=65;
					e+=5;}
					if(e==350 && f==545){
					f-=65;
					e-=5;}
				}
				if (f>=20 && f<=700){
					if(f==300 && e==50){
					e+=90;
					f-=5;}
					if(f==300 && e==770){
					e-=90;
					f+=5;}
					if(f==300 && e==140){
					e+=90;
					f-=5;}
					if(f==300 && e==680){
					e-=90;
					f+=5;}		
				}	
			}
			if((c>=325 && c<=500 && d==220) || (d>=220 && d<=430 && c==320) || (c>=320 && c<=495 && d==415) || (d<=415 && d>=225 && c==500)){
				if (e>=130 && e<=780 ){
					if(e==350 && f==25){
					f+=65;
					e+=5;}
					if(e==350 && f==610){
					f-=65;
					e-=5;}		
					if(e==350 && f==90){
					f+=65;
					e+=5;}
					if(e==350 && f==545){
					f-=65;
					e-=5;}			
					if(e==350 && f==155){
					f+=65;
					e+=5;}
					if(e==350 && f==480){
					f-=65;
					e-=5;}
				}
				if (f>=20 && f<=700){
					if(f==300 && e==50){
					e+=90;
					f-=5;}
					if(f==300 && e==770){
					e-=90;
					f+=5;}
					if(f==300 && e==140){
					e+=90;
					f-=5;}
					if(f==300 && e==680){
					e-=90;
					f+=5;}
					if(f==300 && e==230){
					e+=90;
					f-=5;}
					if(f==300 && e==590){
					e-=90;
					f+=5;}		
				}		
			}
		}

	//opponent movement outward in case of level 4

	if (levelOf==4){
		if ((c>=50 && c<=770 && d==25) || (d>=25 && d<=605 && c==50) || (c>=50 && c<=765 && d==610) || (d<=610 && d>=30 && c==770)){
			if (c>=50 && c<=770 && d==25){
				if(e==350 && f==415){
				f+=65;
				e-=5;}
				if(e==350 && f==90){
				f-=65;
				e+=5;}
				if(e==350 && f==545){
				f+=65;
				e-=5;}		
				if(e==350 && f==155){
				f-=65;
				e+=5;}
				if(e==350 && f==220){
				f-=65;
				e+=5;}
				if(e==350 && f==480){
				f+=65;
				e-=5;}			
			}
			if (f>=20 && f<=700){
				if(f==300 && e==320){
				e-=90;
				f-=5;}
				if(f==300 && e==500){
				e+=90;
				f+=5;}
				if(f==300 && e==230){
				e-=90;
				f-=5;}
				if(f==300 && e==590){
				e+=90;
				f+=5;}
				if(f==300 && e==140){
				e-=90;
				f-=5;}
				if(f==300 && e==680){
				e+=90;
				f+=5;}
			}
		}
	
		if ((c>=145 && c<=680 && d==90) || (d>=90 && d<=540 && c==140) || (c>=140 && c<=665 && d==545) || (d<=545 && d>=95 && c==680)){
			if (e>=130 && e<=780 ){	
				if(e==350 && f==220){
				f-=65;
				e+=5;}
				if(e==350 && f==480){
				f+=65;
				e-=5;}		
				if(e==350 && f==155){
				f-=65;
				e+=5;}
				if(e==350 && f==415){
				f+=65;
				e-=5;}			
			}
		
			if (f>=20 && f<=700){
				if(f==300 && e==320){
				e-=90;
				f-=5;}
				if(f==300 && e==500){
				e+=90;
				f+=5;}
				if(f==300 && e==230){
				e-=90;
				f-=5;}
				if(f==300 && e==590){
				e+=90;
				f+=5;}		
			}
		}
		if ((c>=235 && c<=590 && d==155) || (d>=155 && d<=495 && c==230) || (c>=230 && c<=585 && d==480) || (d<=480 && d>=160 && c==590)){
			if (e>=130 && e<=780 ){	
				if(e==350 && f==220){
				f-=65;
				e+=5;}
				if(e==350 && f==415){
				f+=65;
				e-=5;}	
			}
			if (f>=20 && f<=700){
				if(f==300 && e==320){
				e-=90;
				f-=5;}
				if(f==300 && e==500){
				e+=90;
				f+=5;}		
			}
		}

	}

//================================================================================================================================================================//

	// Coming levels are called here at the end
	
	level2();
	level3();
	level4();	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		if ((x>=360 && x<=500 ) && (y>=560 && y<=590))		//When left mouse button is clicked in certain co-ordinates than bool's are turned on 
			pauseMenu=false;
		if ((x>=380 && x<=470 ) && (y>=515 && y<=545))
			exit(1);
		if ((x>=380 && x<=470 ) && (y>=470 && y<=490))
			help=true;
		if ((x>=380 && x<=470 ) && (y>=620 && y<=640))
			help=false;
		if ((x>=360 && x<=490 ) && (y>=420 && y<=440))
			highScore=true;
		if ((x>=380 && x<=470 ) && (y>=620 && y<=640))
			highScore=false;
		if ((x>=350 && x<=520) && (y>=370 && y<=390)){	
			gameStart=true; 
			reDraw=true;
			detect=true;
		}
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{	

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge 'em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
