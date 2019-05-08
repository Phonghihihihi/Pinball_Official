#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include <windows.h>
#include <string>
#include <math.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// Screen
const int SCREEN_WIDTH = 550;
const int SCREEN_HEIGHT = 650;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const SDL_Color BLUE_COLOR = { 0,255,255};

const int RENDER_DRAW_COLOR = 0xff;

// Components
const int FLAPPER_LEFT_X_POS =  200;
const int FLAPPER_RIGHT_X_POS = 350;
const int FLAPPER_LEFT_Y_POS =  500;
const int FLAPPER_RIGHT_Y_POS = 500;
const double RADIAN = M_PI/180;

//Bump
const int LEFT_TRIANGLE_X_POS = 99;
const int LEFT_TRIANGLE_Y_POS = 420;
const int RIGHT_TRIANGLE_X_POS = 355;
const int RIGHT_TRIANGLE_Y_POS = 420;
const int CIRCLE_100_X_POS = 275-14;
const int CIRCLE_100_Y_POS = 60-14;
const int CIRCLE_50_X_POS = 350-14;
const int CIRCLE_50_Y_POS = 120-14;
const int CIRCLE_25_X_POS = 200-14;
const int CIRCLE_25_Y_POS = 120-14;



// Input
typedef struct input
{
    int left_flapper_;
    int right_flapper_;
    int launcher_;
};

//
enum WhichFlapper
{
    LEFT,
    RIGHT
};





#endif // COMMONFUNCTION_H_INCLUDED
