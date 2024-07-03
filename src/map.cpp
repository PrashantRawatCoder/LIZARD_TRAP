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

bool Map::isCollidingWall(SDL_Rect collider, SDL_Rect *result)
{
    SDL_Rect wall, walldraw, PlayerRect{window->Width() / 2, window->Height() / 2, collider.w, collider.h};

    for (int tiley = (collider.y) / tileSize - 2; tiley < 2 + (collider.y + collider.h) / tileSize; tiley += 1)
    {
        for (int tilex = (collider.x) / tileSize - 4; tilex < 4 + (collider.x + collider.w) / tileSize; tilex += 1)
        {
            if (0 < tiley && tiley < mapHeight && 0 < tilex && tilex < mapWidth)
            {
                SDL_RenderDrawRect(window->renderer, &PlayerRect);
                switch (arr[tiley][tilex])
                {
                case 0:
                    break;
                case 1:
                    break;
                case 71:
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, tileSize, (int)(tileSize * 0.25f)};

                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);

                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 72:
                    wall = SDL_Rect{(int)(tilex * tileSize + tileSize * 0.75f), tiley * tileSize, (int)(tileSize * 0.25f), tileSize};

                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);

                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 73:
                    wall = SDL_Rect{tilex * tileSize, (int)(tiley * tileSize + tileSize * 0.75f), tileSize, (int)(tileSize * 0.25f)};

                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);

                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 74:
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, (int)(tileSize * 0.25f), tileSize};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 41:
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, (int)(tileSize * 0.25f), tileSize};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, tileSize, (int)(tileSize * 0.25f)};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;

                case 42:
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, tileSize, (int)(tileSize * 0.25f)};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    wall = SDL_Rect{(int)(tilex * tileSize + tileSize * 0.75f), tiley * tileSize, (int)(tileSize * 0.25f), tileSize};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 43:
                    wall = SDL_Rect{(int)(tilex * tileSize + tileSize * 0.75f), tiley * tileSize, (int)(tileSize * 0.25f), tileSize};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }

                    wall = SDL_Rect{tilex * tileSize, (int)(tiley * tileSize + tileSize * 0.75f), tileSize, (int)(tileSize * 0.25f)};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;
                case 44:
                    wall = SDL_Rect{tilex * tileSize, tiley * tileSize, (int)(tileSize * 0.25f), tileSize};
                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);
                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    wall = SDL_Rect{tilex * tileSize, (int)(tiley * tileSize + tileSize * 0.75f), tileSize, (int)(tileSize * 0.25f)};

                    walldraw = wall;
                    walldraw.x = walldraw.x - collider.x + 300;
                    walldraw.y = walldraw.y - collider.y + 300;
                    SDL_RenderDrawRect(window->renderer, &walldraw);

                    if (SDL_IntersectRect(&collider, &wall, result) == SDL_TRUE)
                    {
                        return true;
                    }
                    break;

                default:
                    break;
                }
            }
        }
    }
    return false;
}