#include "BaseObject.h"

BaseObject::BaseObject()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.h = 0;
    rect_.w = 0;
}

BaseObject::~BaseObject()
{

}

bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_DestroyTexture(p_object_);
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface= IMG_Load(path.c_str());
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

    p_object_= new_texture;


    return p_object_!= NULL;
}

void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip /* = NULL */)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void BaseObject::Free()
{
    if (p_object_!= NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_= NULL;
        rect_.w= 0;
        rect_.h= 0;
    }
}

void BaseObject::SetRect(const int&x, const int&y)
{
    rect_.x = x, rect_.y = y;
}
SDL_Rect BaseObject::GetRect() const
{
    return rect_;
}
SDL_Texture* BaseObject::GetObject() const
{
    return p_object_;
}

void BaseObject::Destroy(SDL_Texture* texture ,SDL_Window* window,SDL_Renderer* ren)
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}

void BaseObject::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void BaseObject::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;

	SDL_RenderCopy(ren, tex, NULL, &dst);
}

SDL_Texture* BaseObject::LoadPNG(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface= IMG_Load(path.c_str());
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

    p_object_= new_texture;
    return p_object_;
}

void BaseObject::waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
