#pragma once
#include "Entity.hpp"
#include "Window.hpp"

class Enemy_Bee : public Entity
{
private:
    int velX = 0;
    int velY = 0;

public:
    Enemy_Bee(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window);
    SDL_Texture *getPTexture();
};