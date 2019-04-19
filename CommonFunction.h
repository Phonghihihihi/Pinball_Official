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
const SDL_Color BLUE_COLOR = { 0, 255,255};

const int RENDER_DRAW_COLOR = 0xff;

// Components
/**
    x = 530.0;
    y = 630.0;
    f_x = -0.0;
    f_y = -70.0;
    R = 8;

const double PI = M_PI;
double R = 0;
double m = 0.3;
    double x = 0, y = 0;
    double dx = 0, dy = 0;
    double f_x = 0, f_y = 0;
    double ddx = f_y/m, ddy = f_y/m;
    double dt = 0.009;
    double d1= 0,d2=0,d3=0,d4=0,d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
    double past_x = 0, past_y = 0;

*/
// Input
typedef struct input
{
    int left_flapper_;
    int right_flapper_;
    int launcher_;
};




#endif // COMMONFUNCTION_H_INCLUDED
