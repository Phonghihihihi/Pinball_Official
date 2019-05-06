#include "Game_Physics.h"

/**
void DRAW_BALL(SDL_Renderer * renderer, SDL_Color color, double x, double y, double R, double k)
{
    double a,b;
    double angle = 0;
    while( angle <= 2*PI )
    {
        double p_a = x + R * cos(angle);
        double p_b = y + R * sin(angle);

        angle += k;
        a = x + R * cos(angle);
        b = y + R * sin(angle);

        SDL_RenderDrawLine(g_screen, (int) p_a, (int) p_b, (int) a,(int)  b);
    }

}
*/
/**
void CHUONG_NGAI_VAT()
{

    DRAW_BALL(g_screen,BLUE_COLOR,275,60,20,TRON);
    DRAW_BALL(g_screen,BLUE_COLOR,350,120,20,TRON);
    DRAW_BALL(g_screen,BLUE_COLOR,200,120,20,TRON);

    SDL_RenderDrawLine(g_screen,500, 0, 550, 50);
    SDL_RenderDrawLine(g_screen,450,400,350,500);
    SDL_RenderDrawLine(g_screen,100,400,200,500);
    SDL_RenderDrawLine(g_screen,450,400,450,500);
    SDL_RenderDrawLine(g_screen,100,400,100,500);
    SDL_RenderDrawLine(g_screen,450,500,350,500);
    SDL_RenderDrawLine(g_screen,100,500,200,500);


}
*/
void VA_CHAM()
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

                    if( dx > 500 && dy > 500)
                    {
                        dx *= 0.99;
                        dy *= 0.99;
                    }
}
