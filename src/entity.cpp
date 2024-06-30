#include "Entity.hpp"

Entity::Entity(int posx, int posy, int width, int height, int maxHealth, int attackDamage) : posX(posx), posY(posy), width(width), height(height), maxHealth(maxHealth), health(maxHealth), attackDamage(attackDamage)
{
}

Entity::Entity(int posx, int posy, int width, int height, int maxHealth, int attackDamage, entityTextures Texture) : posX(posx), posY(posy), width(width), height(height), maxHealth(maxHealth), health(maxHealth), attackDamage(attackDamage), texture(Texture)
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

int Entity::velX()
{
    return velocityX;
}

int Entity::velY()
{
    return velocityY;
}

void Entity::setVel(int velx, int vely)
{
    velocityX = velx;
    velocityY = vely;
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
    attacking = true;
    currentMoveTexture = 0;
    return attackDamage;
}

SDL_Texture *Entity::getTexture()
{
    if (attacking)
    {
        currentMoveTexture++;
        if (currentMoveTexture > 4)
        {
            attacking = false;
            currentMoveTexture = 0;
        }
        return texture.attack;
    }
    else if (damaging)
    {
        currentMoveTexture++;
        if (currentMoveTexture > 4)
        {
            damaging = false;
            currentMoveTexture = 0;
        }
        return texture.damage;
    }
    if ((velocityX || velocityY))
        currentMoveTexture = (currentMoveTexture + 1) % 4;
    return texture.move[((currentMoveTexture < 2) ? 0 : 1)];
}

void Entity::setTexture(entityTextures Texture)
{
    texture = Texture;
}

void Entity::move()
{
    posX += velocityX;
    posY += velocityY;
}
int Entity::getDamage(int attack)
{
    health -= attack;
    damaging = true;
    currentMoveTexture = 0;
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

SDL_Rect Entity::getRect()
{
    SDL_Rect rect{x(), y(), getWidth(), getHeight()};
    return rect;
}