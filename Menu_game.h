#ifndef MENU_GAME_H_INCLUDED
#define MENU_GAME_H_INCLUDED

#include "BaseObject.h"
#include <fstream>
#include <vector>
#include"TextObject.h"
#include <string>
#include<algorithm>
class MenuGame : public BaseObject
{
public:
   MenuGame();
    ~MenuGame();
    void SaveHighScore(long score);
    void open_high_score(SDL_Renderer* ren);
    void Menu_game(SDL_Renderer* ren, SDL_Window* window);
    bool Play_again(SDL_Renderer* ren, SDL_Window* window, long score);

private:
    const int y_play        = 207;
    const int y_hs          = 342;
    const int y_quit        = 477;
    const int high          = 90;
    const int left          = 135;
    const int right         = 405;

    SDL_Event m_event;
    bool playing = false;
    int x=left;
    int y=0;
};
#endif // MENU_GAME_H_INCLUDED
