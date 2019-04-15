#include "Flapper.h"


Flapper::Flapper()
{
    x_pos_=0;
    y_pos_=0;
    angle_l=0;
    angle_r=0;
}

Flapper::~Flapper()
{
    ;
}

void Flapper::setPos(int x, int y)
{
    x_pos_ = x, y_pos_ = y;
}

void Flapper::Show_l(SDL_Renderer* des)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* clip = NULL;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    if (input_type_.left_flapper_==1)
    {
        angle_l=-60;
    }
    angle_l++;
    if (angle_l>=0) angle_l =0;
    SDL_RenderCopyEx(des, p_object_, clip, &renderQuad, angle_l, NULL, SDL_FLIP_NONE);

}

void Flapper::Show_r(SDL_Renderer* des)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* clip = NULL;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    if (input_type_.right_flapper_==1)
    {
        angle_r=60;
    }
    angle_r--;
    if (angle_r<=0) angle_r =0;
    SDL_RenderCopyEx(des, p_object_, clip, &renderQuad, angle_r, NULL, SDL_FLIP_NONE);

}

void Flapper::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
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
