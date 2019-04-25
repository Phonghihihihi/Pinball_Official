#ifndef FLAPPER_H_INCLUDED
#define FLAPPER_H_INCLUDED
#include "CommonFunction.h"
#include "BaseObject.h"

struct Flapper: public BaseObject
{
public:
    Flapper();
    ~Flapper();
    void Show_l(SDL_Renderer* des);
    void Show_r(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void setPos(float x, float y);


private:
    float x_pos_;
    float y_pos_;
    SDL_Point point_;
    double angle_l;
    double angle_r;

    input input_type_;


};



#endif // FLAPPER_H_INCLUDED
