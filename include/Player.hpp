#pragma once
#include "Entity.hpp"
#include "Window.hpp"

class Player : public Entity
{
private:
    int mouseX;
    int mouseY;
    int centerX, centerY;
    bool moving = false;

public:
    Player(int width, int height, int maxHealth, int attackDamage, Window *window);
    void Events(SDL_Event event);
    SDL_Texture *getPTexture();
    SDL_Rect getRect();
};