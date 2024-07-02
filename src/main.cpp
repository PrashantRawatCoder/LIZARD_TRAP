#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

#include "Window.hpp"
#include "Map.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy_Bee.hpp"
#include "Enemy_Ant.hpp"
#include "parameters.hpp"

void init()
{
    std::srand(time(0));
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL Video Initilisation Failed !!\nERROR : " << SDL_GetError() << "\n";
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "SDL Image Initilisation Failed !!\nERROR : " << SDL_GetError() << "\n";
}

int main(int argc, char *argv[])
{
    bool running = true;
    Uint32 frameStart = 0;

    SDL_Event event;
    Window window((char *)title, windowWidth, windowHeight);
    Map myMap(&window, (char *)"res/map/", 120);
    Player player = Player(120, 60, 10, 2, &window);
    std::cout << "Game Started !!\n";
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            frameStart = SDL_GetTicks();
            if (event.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
            {

                SDL_Quit();
                exit(0);
            }
            player.Events(event);
        }
        window.clear();
        myMap.renderMap(player.x() - player.getWidth() / 2, player.y() - player.getHeight() / 2);
        window.render(player.getPTexture(), player.getRect(), player.angle());
        window.display();

        // Adjusting constant FPS
        frameStart = SDL_GetTicks() - frameStart;
        if (frameStart < (unsigned)frameDelay)
        {
            SDL_Delay(frameDelay - frameStart);
        }
    }
    return 0;
}
