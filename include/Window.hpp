#pragma once
#include "Entity.hpp"

class Window
{
private:
    SDL_Window *window;
    int width, height;

public:
    SDL_Renderer *renderer;
    Window(char *title, int width, int height);
    ~Window();
    void clear();
    void display();
    void render(SDL_Texture *texture, SDL_Rect dstrect, double angle);
    void render(SDL_Texture *texture, SDL_Rect dstrect);
    void render(SDL_Texture *texture);
    int Width();
    int Height();
    SDL_Texture *loadTexture(char *filename);
};