#include"TextObject.h"

TextObject::TextObject(const std::string str)
{
    str_=str;
}

TextObject::~TextObject()
{
    ;
}

SDL_Texture* TextObject::GetText(int c_size,SDL_Renderer* ren)
{

            SDL_Texture *texture = nullptr;
            TTF_Font* font = TTF_OpenFont("arial.ttf", c_size);
            SDL_Surface *loadedText = TTF_RenderText_Solid(font, str_.c_str(), color_text);

            if (loadedText != nullptr)
                {
                texture = SDL_CreateTextureFromSurface(ren, loadedText);
                SDL_FreeSurface(loadedText);
                TTF_CloseFont(font);

                return texture;
                }
}