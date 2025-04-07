
#include <chrono>
#include <thread>
#include <iostream>
#include "raylib.h"
#include <vector>
#include "grid.hpp"
#include "button.hpp"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#define cellblue   CLITERAL(Color){  203, 67, 53,255 }   // My own White (raylib logo)
#define fondblack   CLITERAL(Color){   29, 29, 29 ,255 } 


int cellSize=25;

int FPS =100;
int windowwidth =1280;
int windowheight = 800;
bool play=false;
Grid grid(windowwidth,windowheight,cellSize);
Button pause(100,50,1100,700,BLACK,"PLAY",WHITE);

int speed = 20;
int counter=speed;
int main ()
{
	grid.setvalue(5,5,1);
	grid.setvalue(5,6,1);
	grid.setvalue(5,7,1);

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(windowwidth,windowheight,"Game Of Life");
	SetTargetFPS(FPS);


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(fondblack);
		grid.draw();
		pause.draw();
		grid.placecell();
		if (pause.clicked()){
			play=!play;
		}
		EndDrawing();
		if(play){
			if (counter == 0){
				grid.resetcount();
				grid.count();
				grid.DieOrLive();
				counter=speed;
			}
		counter--;
		}
		
}
	CloseWindow();
	return 0;

}