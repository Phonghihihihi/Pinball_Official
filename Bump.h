#ifndef BUMP_H_INCLUDED
#define BUMP_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"

class Bump: public BaseObject
{
public:
    Bump();
    ~Bump();
    void setPos(int x, int y);
    void Show(SDL_Renderer* des);

private:
    float x_pos_;
    float y_pos_;
};


#endif // BUMP_H_INCLUDED
