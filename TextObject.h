#ifndef TEXTOBJECT_H_INCLUDED
#define TEXTOBJECT_H_INCLUDED

#include"BaseObject.h"
#include<string>
#include<SDL_ttf.h>
#include"CommonFunction.h"
#include<fstream>
class TextObject: public BaseObject
{
public:
    TextObject(const std::string str);
    ~TextObject();
    SDL_Texture* GetText(int c_size, SDL_Renderer *ren);
     std::string str_;
private:

    SDL_Color color_text={255,0,0};
};

#endif // TEXTOBJECT_H_INCLUDED
