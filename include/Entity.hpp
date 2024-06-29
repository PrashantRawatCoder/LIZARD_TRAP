#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct entityTextures
{
    SDL_Texture *move[2];
    SDL_Texture *damage;
    SDL_Texture *attack;

} entityTextures;

class Entity
{
private:
    int posX,posY;
    int width, height;
    int maxHealth;
    int health;
    int attackDamage;
    entityTextures texture;

public:
    Entity(int posX, int posY, int width, int height, int maxHealth, int attackDamage, entityTextures Texture);
    int x();
    int y();
    int getWidth();
    int getHeight();
    int attack();
    SDL_Texture *getTexture();

    void move(int x, int y);
    int getDamage(int attack);
    void heal(int addHealth);
};