#ifndef FLAPPERCOLLISION_H_INCLUDED
#define FLAPPERCOLLISION_H_INCLUDED

#include "CommonFunction.h"
#include "Ball.h"

class FlapperCollision
{
public:
    FlapperCollision();
    ~FlapperCollision();
    void DrawFlapper_l(SDL_Renderer* des);
    void DrawFlapper_r(SDL_Renderer* des);
    void SetPos(int x, int y);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    bool isDistanceFromBallLessThanOrEqualFlapperLength(Ball* ball);
    bool isBallCollideWithFlapper(Ball* ball);
    void CheckFlapperCollision(Ball* ball);


private:
    double angle_l, angle_r;
    double flapper_length_;
    float flapper_x_pos_;
    float flapper_y_pos_;
    input input_type_;
};

#endif // FLAPPERCOLLISION_H_INCLUDED
