#ifndef PROGRAM_H
#define PROGRAM_H
//#include "dynamic_libs/os_functions.h"
//#include "dynamic_libs/vpad_functions.h"
#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//Using modified version of draw to render at twice the scale to improve framerate

struct Bullet {
	int x;
	int y;
	float m_x;
	float m_y;
	int active;
};

struct Enemy {
	float angle;
	struct Bullet position;
	unsigned char rotated_sprite[23][23];
};

struct Pixel {
	int x;
	int y;
	int r;
	int g;
	int b;
};

//Struct for global variables for pong
struct SpaceGlobals{
	//Flag for restarting the entire game.
	int restart;
	
	//Gameplay boundry
	unsigned int frame;
	
	unsigned int seed;
	
	unsigned char rotated_ship[36][36];
	unsigned char orig_ship[36][36];
	const unsigned char (*curPalette)[3];
	unsigned char enemy[23][23];
	unsigned char title[100][200];
    int * test;
	
	int passwordList[100];
	int playerExplodeFrame;
    
    u8* screen;

	//Globals for player1 location and movement dx/dy
	float p1X;
	float p1Y;
	float angle;
	
	int touched;
	int touchX;
	int touchY;
	int titleScreenRefresh;

	//Game engine globals
	u32 button;
//	Vec2D lstick;
//	Vec2D rstick;
	
	// only 20 bullets can be onscreen at a time
	struct Bullet bullets[20];
	
	// the locations of the 200 random stars
	struct Pixel stars[200];
	
	// the location of enemies
	struct Enemy enemies[100];

	int renderResetFlag;
	int invalid;
	int transIndex;
		
	// bonuses
	int playerChoice;
	int dontKeepTrackOfScore;
	int noEnemies;
	int enemiesSeekPlayer;
	
	int state; // 1 is title screen, 2 is gameplay, 3 is password, 4 is about
	int lives;
	int score;
	int level;
	
	int menuChoice;
	int passwordEntered;
	int allowInput;
	
	int displayHowToPlay;
	int firstShotFired;

};

/* Main */
#ifdef __cplusplus
extern "C" {
#endif

//! C wrapper for our C++ functions
int _entryPoint();

#ifdef __cplusplus
}
#endif

#endif /* PROGRAM_H */
