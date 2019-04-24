#include "Ball.h"

Ball::Ball()
{
    x= 530, y= 630;
    dx= 0, dy =0;
    f_x= 0.0, f_y = -20.0;
    ddx = f_x / m, ddy = f_y / m;
    R = 8;

}

Ball::~Ball()
{
    ;
}

void Ball::Show(SDL_Renderer* des)
{
    rect_.x = x;
    rect_.y = y;

    SDL_Rect* clip = NULL;

    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}
void Ball::CheckCollision()
{
                    d1 = abs( x - y - 500) / sqrt(2);
                    d2 = sqrt( pow(x - 275,2) + pow(y - 60, 2));
                    d3 = sqrt( pow(x - 350,2) + pow(y - 120, 2));
                    d4 = sqrt( pow(x - 200,2) + pow(y - 120, 2));
                    d5 = abs( - x - y + 850) / sqrt(2);
                    d6 = abs(x - y + 300) / sqrt(2);
                    d7 = abs(x - 450);
                    d8 = abs(x - 100);
                    d9 = abs(y - 500);


                    past_x = x;
                    past_y = y;

                    if  (y <= R )
                    {
                        dy = abs(dy) * 0.9 ;

                    }

                    if ( y >= 650 - R )
                    {
                        dy = -abs(dy) - 9.8 - ddy * dt - 0.05 ;
                    }

                    if (x <= R )
                    {

                        dx = abs(dx)* 0.9;

                    }

                    if ( x >= 550 - R)
                    {
                        dx = -abs(dx) * 0.9;
                    }



                    if ( d1 <= R )
                    {

                        dy = abs(dy) + 10.0;
                        ddy = abs(ddy);
                        dx = -abs(dx) - 200.0;


                    }

                    if ( d2 <= R + 20 && x >= 275 && y >= 60 )
                    {
                        dx = abs(dx) + 3;
                        dy = abs(dy) + 3;
                    }

                    if ( d2 <= R + 20 && x <= 275 && y >= 60 )
                    {
                        dx = -abs(dx) - 3;
                        dy = abs(dy) + 3;
                    }

                    if ( d2 <= R + 20 && x >= 275 && y <= 60 )
                    {
                        dx = abs(dx) + 3;
                        dy = -abs(dy) - 3;
                    }

                    if ( d2 <= R + 20 && x <= 275 && y <= 60 )
                    {
                        dx = -abs(dx) - 3;
                        dy = -abs(dy) - 3;
                    }


                    if ( d3 <= R + 20 && x >= 350 && y >= 120 )
                    {
                        dx = abs(dx) + 2;
                        dy = abs(dy) + 2 ;
                    }

                    if ( d3 <= R + 20 && x <= 350 && y >= 120 )
                    {
                        dx = -abs(dx) - 2;
                        dy = abs(dy)  + 2;
                    }

                    if ( d3 <= R + 20 && x >= 350 && y <= 120 )
                    {
                        dx = abs(dx) + 2;
                        dy = -abs(dy) - 2;
                    }

                    if ( d3 <= R + 20 && x <= 350 && y <= 120 )
                    {
                        dx = -abs(dx) - 2;
                        dy = -abs(dy) - 2;
                    }

                    if ( d4 <= R + 20 && x >= 200 && y >= 120 )
                    {
                        dx = abs(dx) + 1;
                        dy = abs(dy) + 1;
                    }

                    if ( d4 <= R + 20 && x <= 200 && y >= 120 )
                    {
                        dx = -abs(dx) - 1;
                        dy = abs(dy) + 1 ;
                    }

                    if ( d4 <= R + 20 && x >= 200 && y <= 120 )
                    {
                        dx = abs(dx) + 1 ;
                        dy = -abs(dy) -1;
                    }

                    if ( d4 <= R + 20 && x <= 200 && y <= 120 )
                    {
                        dx = -abs(dx) -1;
                        dy = -abs(dy) -1;
                    }

                    if ( d5 <= R && y > 400 && y < 500 && x > 350 && x < 450)
                    {

                        dy =    -abs(dy) - 50.0;
                        dx =    - abs(dx) - 50.0;






                    }
                    if ( d6 <= R && y > 400 && y < 500 && x > 100 && x < 200 )
                    {

                        dx =   abs(dx) + 50.0;
                        dy =   -abs(dy) - 50.0;





                    }

                    if ( d7 <= R && y > 400 && y < 500)
                    {
                        dx = abs(dx);
                    }

                    if(d8 <= R && y > 400 && y < 500)
                    {
                        dx =-abs(dx);
                    }

                    if( d9 <= R && ( ( x >= 350 && x <= 450) || ( x >= 100 && x <= 200)) )
                    {
                        dy =abs(dy);
                    }



                    if ( sqrt( pow(x - 450, 2)  + pow( y - 500, 2) ) <= R )
                    {
                        dy = abs(dy) ;
                    }


                    if ( sqrt( pow(x - 450, 2)  + pow( y - 400, 2) ) <= R )
                    {
                        dy = -abs(dy)  ;
                    }

                    if ( sqrt( pow(x - 350, 2)  + pow( y - 500, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }

                    if ( sqrt( pow(x - 100, 2)  + pow( y - 400, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }

                    if ( sqrt( pow(x - 200, 2)  + pow( y - 500, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }

                    if( dx > 300 && dy > 300)
                    {
                        dx *= 0.99;
                        dy *= 0.99;
                    }
}

void Ball::RunBall()
{
     std::cout<<dx<<" *** "<<dy<<"/";
                    dx = dx + ddx * dt;
                    dy = dy + ddy * dt;


                    x = x + dx * dt + ddx * dt * dt / 2.0;
                    y = y + dy * dt + ddy * dt * dt / 2.0;


                    ddy = ddy + 10.0 * dt;
//                    x =(int) abs(x)%SCREEN_WIDTH;
//                    y =(int) abs(y)%SCREEN_HEIGHT;
//                    std::cout<<x<<" "<<y;

}

void Ball::isRan()
{
    if (input_type_.launcher_ == 1) flag = true;
}

void Ball::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
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

