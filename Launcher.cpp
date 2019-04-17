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

void Launcher::Show(SDL_Renderer* des)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* clip = NULL;

    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}

void Launcher::setPos(int x, int y)
{
    x_pos_ = x, y_pos_ = y;
}

void Launcher::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        if (events.key.keysym.sym == SDLK_SPACE)
        {
            input_type_.launcher_ = 1;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        if (events.key.keysym.sym == SDLK_SPACE)
        {
            input_type_.launcher_ = 0;
        }
    }
}
