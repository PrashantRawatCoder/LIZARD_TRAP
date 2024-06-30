#pragma once
#include "Entity.hpp"
#include "Window.hpp"

class Player : public Entity
{
public:
    Player(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window);
    void Events(SDL_Event event);
    SDL_Texture *getPTexture();
};