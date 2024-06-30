#pragma once
#include "Entity.hpp"

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Window(char *title, int width, int height);
    ~Window();
    void clear();
    void display();
    void render(SDL_Texture *texture, SDL_Rect dstrect);
    //void renderEntity(Entity *theEntity);
    SDL_Texture *loadTexture(char *filename);
};