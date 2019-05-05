#include "Launcher.h"

Launcher::Launcher()
{
    x_pos_=0;
    y_pos_=0;
}

Launcher::~Launcher()
{
    ;
}

void Launcher::Show(SDL_Renderer* des, Ball* ball)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;
    int power= rect_.h - ball->v_input_/5;

    SDL_Rect* clip = NULL;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};
    if (ball->input_type_.launcher_== 0)
    {
        renderQuad = {rect_.x, rect_.y + ball->v_input_/5 , rect_.w,  rect_.h - ball->v_input_/5};
    }

    SDL_RenderCopy(des, p_object_, clip, &renderQuad);


}

void Launcher::setPos(int x, int y)
{
    x_pos_ = x, y_pos_ = y;
}

//void Launcher::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
//{
//    if (events.type == SDL_KEYDOWN)
//    {
//        if (events.key.keysym.sym == SDLK_SPACE)
//        {
//            v_input_ += 3;
//            if (v_input_ >= V_MAX) v_input_= V_MAX;
//        }
//    }
//    else if (events.type == SDL_KEYUP)
//    {
//        if (events.key.keysym.sym == SDLK_SPACE)
//        {
//            input_type_.launcher_ = 0;
//        }
//    }
//}

