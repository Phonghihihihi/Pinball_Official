#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED
#include"CommonFunction.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    void SetRect(const int&x, const int&y);
    SDL_Rect GetRect() const;
    SDL_Texture* GetObject() const;
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void waitUntilKeyPressed();
    virtual void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
    void Destroy(SDL_Texture* texture, SDL_Window* window,SDL_Renderer* ren);
    SDL_Texture* LoadPNG(std::string path, SDL_Renderer* screen);

protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;

};





#endif // BASEOBJECT_H_INCLUDED
