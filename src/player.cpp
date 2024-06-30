#include "Player.hpp"
#include "Window.hpp"

Player::Player(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window) : Entity(posx, posy, width, height, maxHealth, attackDamage)
{
    entityTextures Texture;
    Texture.move[0] = (*window).loadTexture("res/entity/lizard/move1.png");
    Texture.move[1] = (*window).loadTexture("res/entity/lizard/move2.png");
    Texture.attack = (*window).loadTexture("res/entity/lizard/attack.png");
    Texture.damage = (*window).loadTexture("res/entity/lizard/move1.png");
    setTexture(Texture);
}

void Player::Events(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_d:
            setVel(10, velY());
            break;
        case SDLK_a:
            setVel(-10, velY());
            break;
        case SDLK_s:
            setVel(velX(), 10);
            break;
        case SDLK_w:
            setVel(velX(), -10);
            break;
        default:
            break;
        }
    }
    if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
            setVel(0, velY());
            break;
        case SDLK_d:
            setVel(0, velY());
            break;
        case SDLK_w:
            setVel(velX(), 0);
            break;
        case SDLK_s:
            setVel(velX(), 0);
            break;
        default:
            break;
        }
    }
}

SDL_Texture *Player::getPTexture()
{
    move();
    return getTexture();
}