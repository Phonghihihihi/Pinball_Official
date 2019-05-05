#include "Bump.h"

Bump::Bump()
{
    x_pos_=0;
    y_pos_=0;
}

Bump::~Bump()
{
    ;
}

void Bump::setPos(int x, int y)
{
    x_pos_ = x, y_pos_ = y;
}

void Bump::Show(SDL_Renderer* des)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* clip = NULL;

    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderQuad);

}
