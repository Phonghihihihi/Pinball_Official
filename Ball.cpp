#include "Ball.h"

Ball::Ball()
{
    flag = false;
    waifu = false;
    x= &ball_x_pos;
    y= &ball_y_pos;
    dx= 0, dy =0;
    f_x= 0.0, f_y = -40.0;
    ddx = f_x / m, ddy = f_y / m;
    R = 8;
    v_input_ = 0;
    input_type_.launcher_ = 0;
    diem=0;
}

Ball::~Ball()
{
    x= NULL;
    y= NULL;
}

void Ball::Show(SDL_Renderer* des)
{
    rect_.x = *x;
    rect_.y = *y;

    SDL_Rect* clip = NULL;

    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}
void Ball::CheckCollision()
{
                    d1 = abs( *x/3 - *y - 400 /3 ) / sqrt(pow( 1/3 ,2) + pow(1, 2));
                    d_ball1 = sqrt( pow(*x - 275,2) + pow(*y - 60, 2));
                    d_ball2 = sqrt( pow(*x - 350,2) + pow(*y - 120, 2));
                    d_ball3 = sqrt( pow(*x - 200,2) + pow(*y - 120, 2));
                    d_thanh_ngang = abs( - *x - *y + 850) / sqrt(2);
                    d_thang_ngang_2 = abs(*x - *y + 300) / sqrt(2);
                    d7 = abs(*x - 450);
                    d8 = abs(*x - 100);
                    d9 = abs(*y - 500);
                    d10= abs(*y - 500);
                    d11= abs(*x - 450);
                    d12= abs(*y - 200);
                    d13= abs(*x - 500);

                    if  (*y <= R )
                    {
                        dy = abs(dy) * 0.5 ;

                    }

                    if ( *y >= SCREEN_HEIGHT - R )
                    {
                        dy = -dy;
                        ddy = ddy - 10.0 * dt;

                    }

                    if (*x <= R )
                    {

                        dx = abs(dx) * 0.8 ;

                    }

                    if ( *x >= SCREEN_WIDTH - R)
                    {
                        dx = -abs(dx) * 0.8 ;
                    }

                    if ( d1 <= R )
                    {
                        dx = dx - 50.0;
                        dy = dy + 50.0 * 3;

                        dx = -abs(dx) ;
                        dy =  abs(dy) ;

                        waifu = true;

                    }

                    if ( d_ball1 <= R + 20 && *x >= 275 && *y >= 60 )
                    {
                        dx = abs(dx);
                        dy = abs(dy);


                    }

                    if ( d_ball1 <= R + 20 && *x <= 275 && *y >= 60 )
                    {
                        dx = -abs(dx) -1;
                        dy = abs(dy) + 1;
                    }

                    if ( d_ball1 <= R + 20 && *x >= 275 && *y <= 60 )
                    {
                        dx = abs(dx) + 1;
                        dy = -abs(dy) - 1;
                    }

                    if ( d_ball1 <= R + 20 && *x <= 275 && *y <= 60 )
                    {
                        dx = -abs(dx) - 1;
                        dy = -abs(dy) - 1;
                    }

                    if ( d_ball2 <= R + 20 && *x >= 350 && *y >= 120 )
                    {
                        dx = abs(dx) + 1;
                        dy = abs(dy) + 1 ;
                    }

                    if ( d_ball2 <= R + 20 && *x <= 350 && *y >= 120 )
                    {
                        dx = -abs(dx) - 1;
                        dy = abs(dy)  + 1;
                    }

                    if ( d_ball2 <= R + 20 && *x >= 350 && *y <= 120 )
                    {
                        dx = abs(dx) + 1;
                        dy = -abs(dy) - 1;
                    }

                    if ( d_ball2 <= R + 20 && *x <= 350 && *y <= 120 )
                    {
                        dx = -abs(dx) - 1;
                        dy = -abs(dy) - 1;
                    }

                    if ( d_ball3 <= R + 20 && *x >= 200 && *y >= 120 )
                    {
                        dx = abs(dx) + 1;
                        dy = abs(dy) + 1;
                    }

                    if ( d_ball3 <= R + 20 && *x <= 200 && *y >= 120 )
                    {
                        dx = -abs(dx) - 1;
                        dy = abs(dy) + 1 ;
                    }

                    if ( d_ball3 <= R + 20 && *x >= 200 && *y <= 120 )
                    {
                        dx = abs(dx) + 1 ;
                        dy = -abs(dy) -1;
                    }

                    if ( d_ball3 <= R + 20 && *x <= 200 && *y <= 120 )
                    {
                        dx = -abs(dx) -1;
                        dy = -abs(dy) -1;
                    }

                    if ( d_thanh_ngang <= R && *y > 400 && *y < 500 )
                    {


                        dy = -abs(dy) - 40.0;
                        dx = -abs(dx) - 40.0;

                    }
                    if ( d_thang_ngang_2 <= R && *y > 400 && *y < 500 )
                    {

                        dx = abs(dx) + 40.0;
                        dy =-abs(dy) - 40.0;
                    }

                    if ( d7 <= R && *y > 400 && *y < 500)
                    {
                        dx = abs(dx);
                    }

                    if(d8 <= R && *y > 400 && *y < 500)
                    {
                        dx =-abs(dx);
                    }

                    if( d9 <= R &&   *x >= 350 && *x <= 500 )
                    {
                        dy = -dy;
                    }

                    if ( sqrt( pow(*x - 450, 2)  + pow( *y - 400, 2) ) <= R )
                    {
                        dy = -abs(dy)  ;
                    }

                    if ( sqrt( pow(*x - 350, 2)  + pow( *y - 500, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }

                    if ( sqrt( pow(*x - 100, 2)  + pow( *y - 400, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }

                    if ( sqrt( pow(*x - 200, 2)  + pow( *y - 500, 2) ) <= R )
                    {
                        dy = -abs(dy) ;
                    }


                    if (  sqrt( pow(*x - 450, 2)  + pow( *y - 500, 2) ) <= R )
                    {
                        dx= -dx;
                    }

                    if ( d10 <= R && *x >= 0 && *x <= 200)
                    {
                        dy = -dy;
                    }
                    if(d11 <= R && *y >= 200 && *y <= 500)
                    {
                        dx = -dx;
                    }

                    if ( waifu == false )
                    {

                        if(d12 <= R && *x >= 450 && *x <= 500)
                        {
                          dy = -dy;
                        }

                    }

                    if(d13 <= R && *y >= 200 && *y <= 500)
                    {
                        dx = -dx;

                    }

                    if( waifu == true)
                    {
                        if ( d12 <= R && *x >= 450 && *x <= SCREEN_WIDTH)
                            dy = -dy;
                    }

                    if ( sqrt( pow(*x - 500, 2)  + pow( *y - 500, 2) ) <= R)
                    {
                        dy = abs(dy);
                        dx = abs(dx);
                    }

                    if(sqrt( pow(*x - 450, 2)  + pow( *y - 200, 2)) <= R )
                    {
                       dx = -abs(dx);
                       dy = -abs(dy);
                    }
}

void Ball::RunBall()
{
//     std::cout<<dx<<"**"<<dy<<"/ ";
//                    dx = dx + ddx * dt;
//                    dy = dy + ddy * dt;
//
//                    x = x + dx * dt + ddx * dt * dt / 2.0;
//                    y = y + dy * dt + ddy * dt * dt / 2.0;
//
//
//                    ddy = ddy + 10.0 * dt;

                    ddy = ddy + 11.0 * dt;

                    dx = dx + ddx * dt;
                    dy = dy + ddy * dt;

                    ddx = ddx + -ddx * 0.5 * dt;
                    ddy = ddy + -ddy * 0.5 * dt;

                    dx = dx + -dx * 0.015 * dt;
                    dy = dy + -dy * 0.015 * dt;

                    *x = *x + dx * dt + ddx * dt * dt / 2.0;
                    *y = *y + dy * dt + ddy * dt * dt / 2.0;



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
            v_input_ += 10;
            if (v_input_ >= V_MAX) v_input_= V_MAX;
            dy = -v_input_;
            std::cout<<dy;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        if (events.key.keysym.sym == SDLK_SPACE)
        {
            input_type_.launcher_ = 1;
        }
    }
}

bool Ball::isGameOver()
{
    if (*y >= 540)
    {
        return true;
    }
    return false;
}

