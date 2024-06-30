#pragma once
#include "Entity.hpp"
#include "Window.hpp"

class Player : public Entity
{
private:
    int velX = 0;
    int velY = 0;
    
public:
    Player(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window);
    void Events(SDL_Event event);
    SDL_Texture *getPTexture();
};