#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Window.hpp"
#include "parameters.hpp"

void init()
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL Video Initilisation Failed !!\nERROR : " << SDL_GetError() << "\n";
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "SDL Image Initilisation Failed !!\nERROR : " << SDL_GetError() << "\n";
}

int main(int argc, char *argv[])
{
    SDL_Event event;
    bool running = true;
    Window window(title, windowWidth, windowHeight);
    SDL_Texture *lizard = nullptr;
    lizard = window.loadTexture("res/entity/lizard/move1.png");
    SDL_Texture *lizard2 = nullptr;
    lizard2 = window.loadTexture("res/entity/lizard/move2.png");
    if (lizard == nullptr)
    {
        std::cout << "Can't load texture \nERROR : " << SDL_GetError() << "\n";
    }
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    SDL_Quit();
                    exit(0);
                case SDLK_w:
                    std::cout << "W key pressed \n";
                    break;
                default:
                    break;
                }
            }
            window.clear();
            window.render(lizard);
            window.display();
            window.clear();
            window.render(lizard2);

            window.display();
        }
    }
    return 0;
}
