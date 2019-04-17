#ifndef LAUNCHER_H_INCLUDED
#define LAUNCHER_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"

struct Launcher: public BaseObject
{
public:
    Launcher();
    ~Launcher();
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void setPos(int x, int y);

private:
    float x_pos_;
    float y_pos_;

    input input_type_;
};


#endif // LAUNCHER_H_INCLUDED
