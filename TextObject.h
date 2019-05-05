#ifndef TEXTOBJECT_H_INCLUDED
#define TEXTOBJECT_H_INCLUDED
#include"BaseObject.h"
#include"CommonFunction.h"

class TextObject : public BaseObject
{
public:
    TextObject();
    enum TextColor
    {
        RED_TEXT=0,
        WHITE_TEXT=1,
        BLACK_TEXT=2,
    };
    bool LoadFromRenderText(TTF_Font* font,SDL_Renderer* screen);
    void Free();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);
    void RenderText(SDL_Renderer* screen, int xp,int yp);
    int GetWidth() const{ return width_;};
    int GetHeight() const{ return height_;}
    void SetText(const std::string &text) {str_val_=text;}
    std::string GetText()const {return str_val_; }
    void CreateGameText(TTF_Font* font , SDL_Texture* des, SDL_Renderer* screen);
    void SetRect(const int&x, const int&y);
    SDL_Rect GetRect() const;
private:
    SDL_Rect rect_;
    std::string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};


#endif // TEXTOBJECT_H_INCLUDED
