#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Window.hpp"
#include "Entity.hpp"
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

    std::vector<Entity> entities;
    {
        entityTextures Texture;
        Texture.move[0] = window.loadTexture("res/entity/lizard/move1.png");
        Texture.move[1] = window.loadTexture("res/entity/lizard/move2.png");
        Texture.attack = window.loadTexture("res/entity/lizard/attack.png");
        Texture.damage = window.loadTexture("res/entity/lizard/move1.png");
        entities.push_back(Entity(100, 100, 120, 96, 10, 2, Texture));
    }
    int i = 1;
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
                    i += 38;
                    break;
                default:
                    break;
                }
            }
            window.clear();
            window.renderEntity(&entities[0]);
            entities[0].move(i, 379);
            window.display();
        }
    }
    return 0;
}
