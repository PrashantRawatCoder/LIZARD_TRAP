#include <cstdlib>
#include <time.h>
#include "Enemy_Bee.hpp"

Enemy_Bee::Enemy_Bee(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window, Map *map) : Entity(posx, posy, 1.5f, width, height, maxHealth, attackDamage, map)
{
    entityTextures Texture;
    Texture.move[0] = (*window).loadTexture((char *)"res/entity/bee/move1.png");
    Texture.move[1] = (*window).loadTexture((char *)"res/entity/bee/move1.png");
    Texture.attack = (*window).loadTexture((char *)"res/entity/bee/move1.png");
    Texture.damage = (*window).loadTexture((char *)"res/entity/bee/move1.png");
    setTexture(Texture);
}

SDL_Texture *Enemy_Bee::getPTexture()
{
    setAngle((angle() + rand() % 31) - 15);
    setVel();
    move();
    move();
    return getTexture();
}
