#pragma once
#include "Entity.hpp"
#include "Window.hpp"
#include "Map.hpp"


class Player : public Entity
{
private:
    int mouseX;
    int mouseY;
    int centerX, centerY;
    double FPSTime = 1;
    bool moving = false;

public:
    Player(int width, int height, float speed, int maxHealth, int attackDamage, Window *window,Map *map);
    void Events(SDL_Event event);
    SDL_Texture *getPTexture();
    SDL_Rect getDrawRect();
    void setFPSTime(double time);
};