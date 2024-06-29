#include "Entity.hpp"

Entity::Entity(int posx, int posy, int width, int height, int maxHealth, int attackDamage, entityTextures Texture) : posX(posx),posY(posy),width(width), height(height), maxHealth(maxHealth), health(maxHealth), attackDamage(attackDamage), texture(Texture)
{
}

int Entity::x()
{
    return posX;
}

int Entity::y()
{
    return posY;
}

int Entity::getWidth()
{
    return width;
}

int Entity::getHeight()
{
    return height;
}

int Entity::attack()
{
    return attackDamage;
}

SDL_Texture *Entity::getTexture()
{
    return texture.move[1];
}

void Entity::move(int x, int y)
{
    posX = x;
    posY = y;
}
int Entity::getDamage(int attack)
{
    health -= attack;
    if (health <= 0)
        return 1;
    return 0;
}
void Entity::heal(int addHealth)
{
    health += addHealth;
    if (health > maxHealth)
        health = maxHealth;
}