#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Window.hpp"

Window::Window(char *title, int width, int height) : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (window == nullptr)
    {
        std::cout << "Can't Create SDL Window !\nERROR : " << SDL_GetError() << "\n";
    }
    if (renderer == nullptr)
    {
        std::cout << "Can't Create SDL Renderer !\nERROR : " << SDL_GetError() << "\n";
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

void Window::clear()
{
    SDL_SetRenderDrawColor(renderer, 25, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture *texture, SDL_Rect dstrect)
{
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

SDL_Texture *Window::loadTexture(char *filename)
{
    return IMG_LoadTexture(renderer, filename);
}