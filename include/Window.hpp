#pragma once
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
};