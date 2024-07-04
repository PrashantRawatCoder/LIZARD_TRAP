#include <cstdlib>
#include <time.h>
#include "Enemy_Ant.hpp"

Enemy_Ant::Enemy_Ant(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window, Map *map) : Entity(posx, posy, 3.0f, width, height, maxHealth, attackDamage, map)
{
    entityTextures Texture;
    Texture.move[0] = (*window).loadTexture((char *)"res/entity/ant/move1.png");
    Texture.move[1] = (*window).loadTexture((char *)"res/entity/ant/move2.png");
    Texture.attack = (*window).loadTexture((char *)"res/entity/ant/move1.png");
    Texture.damage = (*window).loadTexture((char *)"res/entity/ant/move1.png");
    setTexture(Texture);
}

SDL_Texture *Enemy_Ant::getPTexture()
{
    setAngle((angle() + rand() % 27) - 13);
    setVel();
    move();
    return getTexture();
}
