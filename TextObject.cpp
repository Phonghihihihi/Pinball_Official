#include "TextObject.h"
#include "CommonFunction.h"
#include "BaseObject.h"


TextObject::TextObject()
{
    text_color_.r=255;
    text_color_.g=255;
    text_color_.b=255;
    texture_=NULL;
}

void TextObject::SetRect(const int&x, const int&y)
{
    rect_.x = x, rect_.y = y;
}

SDL_Rect TextObject::GetRect() const
{
    return rect_;
}

bool TextObject::LoadFromRenderText(TTF_Font *font, SDL_Renderer *screen)
{
    SDL_Surface* text_surface=TTF_RenderText_Solid(font,str_val_.c_str(),text_color_);
    if(text_surface)
    {
        texture_=SDL_CreateTextureFromSurface(screen, text_surface);
        width_= text_surface-> w;
        height_=text_surface->h;
        SDL_FreeSurface(text_surface);
    }

     return texture_!=NULL;
}

void TextObject::Free()
{
    if(texture_!=NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_=NULL;
    }

}

void TextObject::SetColor(Uint8 red, Uint8 green, Uint8 blue )
{
    text_color_.r=red;
    text_color_.g=green;
    text_color_.b=blue;
}

void TextObject::SetColor(int type)
{
    if(type==RED_TEXT )
    {
        SDL_Color color ={255,0,0};
        text_color_=color;
    }
    else if( type==BLACK_TEXT)
    {
        SDL_Color color ={0,0,0};
        text_color_=color;
    }
    else if (type==WHITE_TEXT)
    {
        SDL_Color color={255,255,255};
        text_color_=color;
    }
}

void TextObject::RenderText(SDL_Renderer* screen, int xp,int yp)
{   SDL_Rect* clip=NULL;
    SDL_Rect renderQuad={xp,yp,width_,height_};
    if(clip!=NULL)
    {
        renderQuad.w=clip->w;
        renderQuad.h=clip->h;
    }
    SDL_RenderCopy(screen,texture_,clip,&renderQuad);
}

void TextObject::CreateGameText(TTF_Font* font , SDL_Texture* des, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface = TTF_RenderText_Solid(font, str_val_.c_str() ,text_color_);
    if (load_surface!= NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if (new_texture!= NULL)
        {
            rect_.w= load_surface->w;
            rect_.h= load_surface->h;
        }
        SDL_FreeSurface(load_surface);

    }
    texture_= new_texture;

}
