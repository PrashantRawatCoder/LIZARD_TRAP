#pragma once
#include "Entity.hpp"

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width, height;

public:
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