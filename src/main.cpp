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

void renderGame(Window *window, Map *gameMap, Player *player, std::vector<Enemy_Bee *> *Bees, std::vector<Enemy_Ant *> *Ants)
{
    int playerX = player->x() - player->getWidth() / 2,
        playerY = player->y() - player->getHeight() / 2;
    int playerFOV_X = window->Width() / 2 - playerX,
        playerFOV_Y = window->Height() / 2 - playerY;
    gameMap->renderMap(playerX, playerY);

    window->render(player->getPTexture(), player->getRect(), player->angle());
    for (Enemy_Ant *ant : *Ants)
    {
        window->render(ant->getPTexture(), ant->getRect(playerFOV_X, playerFOV_Y), ant->angle());
    }
    for (Enemy_Bee *bee : *Bees)
    {
        window->render(bee->getPTexture(), bee->getRect(playerFOV_X, playerFOV_Y), bee->angle());
    }
}

int main(int argc, char *argv[])
{
    bool running = true;
    Uint32 frameStart = 0;

    SDL_Event event;
    Window window((char *)title, windowWidth, windowHeight);
    Map gameMap(&window, (char *)"res/map/", 120);
    Player player(120, 60, 300.0f, 10, 2, &window);
    std::vector<Enemy_Bee *> Bees;
    std::vector<Enemy_Ant *> Ants;
    {
        Bees.push_back(new Enemy_Bee(1000, 600, 64, 64, 10, 2, &window));
        Bees.push_back(new Enemy_Bee(1700, 900, 64, 64, 10, 2, &window));
        Bees.push_back(new Enemy_Bee(700, 900, 64, 64, 10, 2, &window));
        Ants.push_back(new Enemy_Ant(1000, 600, 64, 64, 10, 2, &window));
        Ants.push_back(new Enemy_Ant(1700, 900, 64, 64, 10, 2, &window));
        Ants.push_back(new Enemy_Ant(700, 900, 64, 64, 10, 2, &window));
    }
    std::cout << "Game Started !!\n";
    while (running)
    {
        frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if ((event.type == SDL_KEYDOWN))
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    SDL_Quit();
                    exit(0);
                    break;
                default:
                    break;
                }
            }
            player.Events(event);
        }
        window.clear();
        renderGame(&window, &gameMap, &player, &Bees, &Ants);
        window.display();

        frameStart = SDL_GetTicks() - frameStart;
        std::cout << "FPS : " << 1000.0 / frameStart << "\n";
        player.setFPSTime(frameStart / 1000.0);
        // Adjusting constant FPS if over 60 FPS
        if (frameStart < (unsigned)frameDelay)
        {
            SDL_Delay(frameDelay - frameStart - 0.01);
        }
    }
    return 0;
}
