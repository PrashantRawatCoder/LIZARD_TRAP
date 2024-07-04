#pragma once
#include "Window.hpp"
#include "Map.hpp"
#include "Entity.hpp"

class Enemy_Ant : public Entity
{
private:
    int velX = 0;
    int velY = 0;

public:
    Enemy_Ant(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window, Map *map);
    SDL_Texture *getPTexture();
};