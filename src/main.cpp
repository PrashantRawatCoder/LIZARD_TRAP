#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

#include "Window.hpp"
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
    SDL_Event event;
    bool running = true;
    double angle = NULL;

    Window window(title, windowWidth, windowHeight);

    Player player = Player(100, 100, 120, 96, 10, 2, &window);
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
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
            if (event.type == SDL_MOUSEMOTION)
            {
                angle = 180 * std::atan2((event.motion.y - player.y()) / sqrt(player.x() * player.x() + player.y() * player.y()), ((event.motion.x - player.x()) / sqrt(sqrt(player.x() * player.x() + player.y() * player.y())))) /
                        M_PI;
                std::cout << "Angle : " << angle << "\n";
            }
            player.Events(event);
        }
        window.clear();
        window.render(player.getPTexture(), player.getRect(), angle);
        window.display();
    }
    return 0;
}
