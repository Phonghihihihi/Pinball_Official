#include "FlapperCollision.h"

FlapperCollision::FlapperCollision()
{
    flapper_x_pos_=0;
    flapper_y_pos_=0;
    flapper_length_=60;
    angle_l=20;
    angle_r=160;
}

FlapperCollision::~FlapperCollision()
{
    ;
}

void FlapperCollision::DrawFlapper_l(SDL_Renderer* des)
{
    if (input_type_.left_flapper_==1)
    {
        angle_l-=1.99;
    }
    angle_l++;
    if (angle_l<=-40) angle_l = -40;
    else if (angle_l>=20) angle_l =20;

    double x1 = flapper_x_pos_ + flapper_length_*cos(angle_l*RADIAN);
    double y1 = flapper_y_pos_ + flapper_length_*sin(angle_l*RADIAN);

    SDL_RenderDrawLine(des, flapper_x_pos_, flapper_y_pos_, x1, y1);
}

void FlapperCollision::DrawFlapper_r(SDL_Renderer* des)
{
    if (input_type_.right_flapper_==1)
    {
        angle_r+=1.99;
    }
    angle_r--;
    if (angle_r>=220) angle_r = 220;
    else if (angle_r<=160) angle_r =160;

    double x1 = flapper_x_pos_ + flapper_length_*cos(angle_r*RADIAN);
    double y1 = flapper_y_pos_ + flapper_length_*sin(angle_r*RADIAN);

    SDL_RenderDrawLine(des, flapper_x_pos_, flapper_y_pos_, x1, y1);

}

void FlapperCollision::SetPos(int x, int y)
{
    flapper_x_pos_= x, flapper_y_pos_= y;
}

void FlapperCollision::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_z:
            {
                input_type_.left_flapper_ = 1;
            }
            break;
        case SDLK_m:
            {
                input_type_.right_flapper_ = 1;
            }
            break;
        default:
            break;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_z:
            {
                input_type_.left_flapper_ = 0;
            }
            break;
        case SDLK_m:
            {
                input_type_.right_flapper_ = 0;
            }
            break;
        default:
            break;
        }
    }
}

WhichFlapper FlapperCollision::isDistanceFromBallLessThanOrEqualFlapperLength(Ball* ball)
{
    double distance_from_ball_to_point_l = sqrt(pow(*ball->x-FLAPPER_LEFT_X_POS,2) + pow(*ball->y-FLAPPER_LEFT_Y_POS,2));
    double distance_from_ball_to_point_r = sqrt(pow(*ball->x-FLAPPER_RIGHT_X_POS,2) + pow(*ball->y-FLAPPER_RIGHT_Y_POS,2));
    if (distance_from_ball_to_point_l <= flapper_length_)
        return LEFT;
    else if (distance_from_ball_to_point_r <= flapper_length_)
        return RIGHT;
}

WhichFlapper FlapperCollision::isBallCollideWithFlapper(Ball* ball)
{
    double distance_from_ball_to_flapper_l = fabs(tan(angle_l*RADIAN)*(*ball->x)-(*ball->y)+FLAPPER_LEFT_Y_POS-FLAPPER_LEFT_X_POS*tan(angle_l*RADIAN))
                                                /(sqrt(pow(tan(angle_l*RADIAN),2))+1);
    double distance_from_ball_to_flapper_r = fabs(tan(angle_r*RADIAN)*(*ball->x)-(*ball->y)+FLAPPER_RIGHT_Y_POS-FLAPPER_RIGHT_X_POS*tan(angle_r*RADIAN))
                                                /(sqrt(pow(tan(angle_r*RADIAN),2))+1);
    std::cout<<distance_from_ball_to_flapper_l<<"-"<<distance_from_ball_to_flapper_r<<"/";
    if (distance_from_ball_to_flapper_l<= ball->R)
        return LEFT;
    if (distance_from_ball_to_flapper_r<= ball->R)
        return RIGHT;
}

void FlapperCollision::CheckAndHandleFlapperCollision(Ball* ball, Flapper* flapper_l, Flapper* flapper_r)
{
//    double distance_from_ball_to_point = sqrt(pow(*x-FLAPPER_LEFT_X_POS,2) + pow(*y-FLAPPER_LEFT_Y_POS,2));
//    std::cout<<*x<<"-"<<*y<<"/";
    double distance_from_ball_to_point_l = sqrt(pow(*ball->x-FLAPPER_LEFT_X_POS,2) + pow(*ball->y-FLAPPER_LEFT_Y_POS,2));
    double distance_from_ball_to_point_r = sqrt(pow(*ball->x-FLAPPER_RIGHT_X_POS,2) + pow(*ball->y-FLAPPER_RIGHT_Y_POS,2));

    if (isDistanceFromBallLessThanOrEqualFlapperLength(ball)== LEFT)
    {
        if (isBallCollideWithFlapper(ball)== LEFT)
        {
//            ball->dy = -fabs(ball->dy) -50 ;
//            ball->dx = ball->dx + 50;
//            ball->dx = ball->dx + distance_from_ball_to_point_l + cos(flapper_l->angle_l)*30;
            ball->dy = -fabs(ball->dy) - distance_from_ball_to_point_l - cos(flapper_l->angle_l)*30;

        }
    }
    else if (isDistanceFromBallLessThanOrEqualFlapperLength(ball)== RIGHT)
    {
        if (isBallCollideWithFlapper(ball)== RIGHT)
        {
//            ball->dx = ball->dx + distance_from_ball_to_point_r + cos(flapper_r->angle_r)*30;
            ball->dy = -fabs(ball->dy) - distance_from_ball_to_point_r - cos(flapper_r->angle_r)*30;
        }
    }
}
//
//void FlapperCollision::FlapperAndBallCollisionHandling(Ball* ball, Flapper* flapper_l, Flapper* flapper_r)
//{
//
//
//    ball->dx = ball->dx + distance_from_ball_to_point_l/3 + cos(flapper_l->angle_l)*30;
//    ball->dy = -fabs(ball->dy) + distance_from_ball_to_point_l/3 + cos(flapper_l->angle_l)*30;
//
//}




