#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include "Map.hpp"

typedef struct entityTextures
{
    SDL_Texture *move[2];
    SDL_Texture *damage;
    SDL_Texture *attack;

} entityTextures;

class Entity
{
private:
    int posX, posY;
    float speed;
    int width, height;
    int velocityX = 0, velocityY = 0;
    int MouseX = 0, MouseY = 0;
    double rotationAngle = 0;
    int maxHealth;
    int health;
    int attackDamage;
    entityTextures texture;

    bool damaging = false;
    bool attacking = false;
    int currentMoveTexture = 0;
    Map *map;

public:
    Entity(int posX, int posY, float speed, int width, int height, int maxHealth, int attackDamage,Map *map);
    Entity(int posX, int posY, float speed, int width, int height, int maxHealth, int attackDamage, entityTextures Texture,Map *map);
    int x();
    int y();
    int velX();
    int velY();
    double angle();
    int getWidth();
    int getHeight();
    float getSpeed();
    int attack();
    SDL_Texture *getTexture();

    void setVel(int velx, int vely);
    void setVel(double time = 1);
    void setAngle(double angle);
    void move();
    void setTexture(entityTextures Texture);
    int getDamage(int attack);
    void heal(int addHealth);
    SDL_Rect getDrawRect(int playerPOV_X=0, int playerPOV_Y=0);
    SDL_Rect getRect();
};