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
    bool isGameOver();
    bool isBallOutOfLauncher();


    const double PI = M_PI;
    bool flag;
    double R;
    double m = 0.3;
    double *x = NULL;
    double *y = NULL;
    double dx, dy;
    double v_input_;
    input input_type_;
protected:
        const int V_MAX = 300;
        double ball_x_pos = 515;
        double ball_y_pos = 320;
        double f_x, f_y;
        double ddx, ddy;
        double dt = 0.009;
        double d1,d_ball1,d_ball2,d_ball3,d_thanh_ngang,d_thang_ngang_2,d7,d8,d9,d10,d11,d12,d13,d14;
        double diem;
        bool waifu;


};



#endif // BALL_H_INCLUDED
