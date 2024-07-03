#include "Map.hpp"

Map::Map(Window *window, char *filename, int tileSize) : window(window), tileSize(tileSize)
{
    sky = window->loadTexture((char *)"res/map/sky.png");
    textures = {
        {1, window->loadTexture((char *)"res/map/floor.png")},
        {41, window->loadTexture((char *)"res/map/floor_wall_U_L.png")},
        {42, window->loadTexture((char *)"res/map/floor_wall_U_R.png")},
        {43, window->loadTexture((char *)"res/map/floor_wall_D_L.png")},
        {44, window->loadTexture((char *)"res/map/floor_wall_D_R.png")},
        {71, window->loadTexture((char *)"res/map/floor_wall_U.png")},
        {72, window->loadTexture((char *)"res/map/floor_wall_R.png")},
        {73, window->loadTexture((char *)"res/map/floor_wall_D.png")},
        {74, window->loadTexture((char *)"res/map/floor_wall_L.png")}};
}

void Map::renderMap(int x, int y)
{
    int currentTile = 0;
    int itr = 0;
    int tilex = 0, tiley = 0;
    int WindowHalfWidth = window->Width() / 2, WindowHalfHeight = window->Height() / 2;
    window->render(sky);
    do
    {
        switch (arr[currentTile])
        {
        case 9:
            tiley += tileSize;
            tilex = -tileSize;
            break;
        case 0:
            break;
        default:
            if ((tilex > (x + 1 - WindowHalfWidth - tileSize)) && (tilex < (x + WindowHalfWidth)) && (tiley > (y + 1 - WindowHalfHeight - tileSize)) && (tiley < (y + WindowHalfHeight)))
            {
                window->render(textures[arr[currentTile]], SDL_Rect{tilex + WindowHalfWidth - x, tiley + WindowHalfHeight - y, tileSize, tileSize});
            }
            itr++;
            break;
        }
        currentTile++;
        tilex += tileSize;
    } while (arr[currentTile] != 100);
}
