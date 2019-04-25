#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "CommonFunction.h"
#include "BaseObject.h"

class Ball: public BaseObject
{
public:
    Ball();
    ~Ball();
    void Show(SDL_Renderer* des);
    void CheckCollision ();
    void RunBall();
    void isRan();
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);


    const double PI = M_PI;
    bool flag = false;
    double R;
    double m = 0.3;
        double *x = NULL;
        double *y = NULL;
        double dx, dy;
protected:
        double ball_x_pos = 530;
        double ball_y_pos = 630;
        double f_x, f_y;
        double ddx, ddy;
        double dt = 0.009;
        double d1,d2,d3,d4,d5,d6,d7,d8,d9,d10;

    input input_type_;

};



#endif // BALL_H_INCLUDED
