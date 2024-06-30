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
    int posX, posY;
    int width, height;
    int velocityX = 0, velocityY = 0;
    double rotationAngle = 0;
    int maxHealth;
    int health;
    int attackDamage;
    entityTextures texture;

    bool damaging = false;
    bool attacking = false;
    int currentMoveTexture = 0;

public:
    Entity(int posX, int posY, int width, int height, int maxHealth, int attackDamage);
    Entity(int posX, int posY, int width, int height, int maxHealth, int attackDamage, entityTextures Texture);
    int x();
    int y();
    int velX();
    int velY();
    double angle();
    int getWidth();
    int getHeight();
    int attack();
    SDL_Texture *getTexture();

    void setVel(int velx, int vely);
    void setAngle(double angle);
    void move();
    void setTexture(entityTextures Texture);
    int getDamage(int attack);
    void heal(int addHealth);
    SDL_Rect getRect();
};