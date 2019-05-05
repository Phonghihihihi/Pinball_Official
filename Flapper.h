#ifndef FLAPPER_H_INCLUDED
#define FLAPPER_H_INCLUDED
#include "CommonFunction.h"
#include "BaseObject.h"

class Flapper: public BaseObject
{
public:
    Flapper();
    ~Flapper();
    void Show_l(SDL_Renderer* des);
    void Show_r(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void setPos(float x, float y);

    double angle_l;
    double angle_r;

private:
    float x_pos_;
    float y_pos_;
    SDL_Point point_;

    input input_type_;


};



#endif // FLAPPER_H_INCLUDED
