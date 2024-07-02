#pragma once
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include "Window.hpp"

class Map
{
private:
    std::vector<int> tileMap;
    Window *window;
    SDL_Texture *sky;
    int tileSize;
    int mapWidth = 0;
    int mapHeight = 0;
    int arr[92] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
                   41, 71, 71, 71, 71, 71, 71, 42, 9,
                   74, 1, 1, 1, 1, 1, 1, 72, 9,
                   74, 1, 1, 1, 1, 1, 1, 72, 9,
                   74, 1, 1, 1, 1, 1, 1, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 42, 9,
                   74, 1, 1, 1, 1, 1, 1, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 43, 9,
                   44, 73, 73, 73, 73, 73, 73, 43, 9, 100};

    std::unordered_map<int, SDL_Texture *> textures;

public:
    Map(Window *window, char *filename, int tileSize = 120);
    void renderMap(int x, int y);
};
