#ifndef FLAPPERCOLLISION_H_INCLUDED
#define FLAPPERCOLLISION_H_INCLUDED

#include "CommonFunction.h"
#include "Ball.h"
#include "Flapper.h"

class FlapperCollision
{
public:
    FlapperCollision();
    ~FlapperCollision();
    void DrawFlapper_l(SDL_Renderer* des);
    void DrawFlapper_r(SDL_Renderer* des);
    void SetPos(int x, int y);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    WhichFlapper isDistanceFromBallLessThanOrEqualFlapperLength(Ball* ball);
    WhichFlapper isBallCollideWithFlapper(Ball* ball);
    void CheckAndHandleFlapperCollision(Ball* ball, Flapper* flapper_l, Flapper* flapper_r);

private:
    double angle_l, angle_r;
    double flapper_length_;
    float flapper_x_pos_;
    float flapper_y_pos_;
    input input_type_;
};

#endif // FLAPPERCOLLISION_H_INCLUDED
