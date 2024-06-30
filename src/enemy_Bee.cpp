#include <cstdlib>
#include <time.h>
#include "Enemy_Bee.hpp"
#include "Window.hpp"

Enemy_Bee::Enemy_Bee(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window) : Entity(posx, posy, width, height, maxHealth, attackDamage)
{
    entityTextures Texture;
    Texture.move[0] = (*window).loadTexture("res/entity/bee/move1.png");
    Texture.move[1] = (*window).loadTexture("res/entity/bee/move1.png");
    Texture.attack = (*window).loadTexture("res/entity/bee/move1.png");
    Texture.damage = (*window).loadTexture("res/entity/bee/move1.png");
    setTexture(Texture);
}

SDL_Texture *Enemy_Bee::getPTexture()
{
    setVel(rand() % 13 - 6, rand() % 13 - 6);
    move();
    return getTexture();
}