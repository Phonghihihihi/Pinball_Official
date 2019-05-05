#ifndef LAUNCHER_H_INCLUDED
#define LAUNCHER_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"
#include "Ball.h"

class Launcher: public BaseObject
{
public:
    Launcher();
    ~Launcher();
    void Show(SDL_Renderer* des, Ball* ball);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void setPos(int x, int y);

private:
    float x_pos_;
    float y_pos_;

    double v_input_;
    const int V_MAX = 200;

    input input_type_;
};


#endif // LAUNCHER_H_INCLUDED
