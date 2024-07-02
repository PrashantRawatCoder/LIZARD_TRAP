#include "Map.hpp"

Map::Map(Window *window, char *filename, int tileSize) : window(window), tileSize(tileSize)
{
    int currentTile = 0;
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
    window->render(sky);
    // int currentTile=0;
    // for (int tileY = ((y - window->Height() / 2 - 119) / 120) * 120; tileY < (y + window->Height() / 2); tileY += tileSize)
    // {
    //     for (int tileX = ((x - window->Width() / 2 - 119) / 120) * 120; tileX < (x + window->Width() / 2); tileX += tileSize)
    //     {

    //     }
    // }

    do
    {
        switch (arr[currentTile])
        {
        case 9:
            tiley += 120;
            tilex = -120;
            break;
        case 0:
            break;
        default:
            if ((tilex > (x - window->Width() / 2 - 119)) && (tilex < (x + window->Width() / 2)) && (tiley > (y - window->Height() / 2 - 119)) && (tiley < (y + window->Height() / 2)))
            {
                window->render(textures[arr[currentTile]], SDL_Rect{tilex + window->Width() / 2 - x, tiley + window->Height() / 2 - y, 120, 120});
            }
            itr++;
            break;
        }
        currentTile++;
        tilex += 120;
    } while (arr[currentTile] != 100);
}
