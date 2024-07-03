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
    int WindowHalfWidth = window->Width() / 2, WindowHalfHeight = window->Height() / 2;
    window->render(sky);

    for (int tiley = (y - WindowHalfHeight) / tileSize; tiley < 1 + (y + WindowHalfHeight) / tileSize; tiley += 1)
    {
        for (int tilex = (x - WindowHalfWidth) / tileSize; tilex < 1 + (x + WindowHalfWidth) / tileSize; tilex += 1)
        {
            if (0 < tiley && tiley < mapHeight && 0 < tilex && tilex < mapWidth)
            {
                currentTile = arr[tiley][tilex];
                if (currentTile != 0)
                {
                    window->render(textures[currentTile], SDL_Rect{tilex * tileSize + WindowHalfWidth - x, tiley * tileSize + WindowHalfHeight - y, tileSize, tileSize});
                }
            }
        }
    }
}

bool Map::isCollidingWall(SDL_Rect collider)
{
    int currentTile = 0;
    for (int tiley = (collider.y) / tileSize - 1; tiley < 2 + (collider.y + collider.h) / tileSize; tiley += 1)
    {
        for (int tilex = (collider.x) / tileSize - 1; tilex < 2 + (collider.x + collider.w) / tileSize; tilex += 1)
        {
            if (0 < tiley && tiley < mapHeight && 0 < tilex && tilex < mapWidth)
            {
                currentTile = arr[tiley][tilex];
                if (currentTile != 0 && currentTile != 1)
                {
                    if (((collider.w + collider.x) >= (tilex * tileSize) && (collider.x) <= ((tilex + 1) * tileSize)) && ((collider.h + collider.y) >= (tiley * tileSize) && (collider.y) <= ((tiley + 1) * tileSize)))
                    {
                        return true;
                    }
                    // window->render(textures[currentTile], SDL_Rect{tilex * tileSize + WindowHalfWidth - x, tiley * tileSize + WindowHalfHeight - y, tileSize, tileSize});
                }
            }
        }
    }
    return false;
}