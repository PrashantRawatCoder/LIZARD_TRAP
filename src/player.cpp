#include "Player.hpp"
#include "Window.hpp"
#include <cmath>

Player::Player(int posx, int posy, int width, int height, int maxHealth, int attackDamage, Window *window) : Entity(posx, posy, width, height, maxHealth, attackDamage)
{
    entityTextures Texture;
    Texture.move[0] = (*window).loadTexture((char *)"res/entity/lizard/move1.png");
    Texture.move[1] = (*window).loadTexture((char *)"res/entity/lizard/move2.png");
    Texture.attack = (*window).loadTexture((char *)"res/entity/lizard/attack.png");
    Texture.damage = (*window).loadTexture((char *)"res/entity/lizard/move1.png");
    setTexture(Texture);
}

void Player::Events(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            moving = true;
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            setVel(0, 0);
            moving = false;
        }
    }
    // making player look at mouse
    if (event.type == SDL_MOUSEMOTION)
    {
        mouseX = event.motion.x;
        mouseY = event.motion.y;
    }
}

SDL_Texture *Player::getPTexture()
{
    {
        float dx = mouseX - x();
        float dy = mouseY - y();
        float angle_rad = std::atan2(dy, dx);
        double angle = angle_rad * 180.0f / M_PI;
        angle -= 5.0000001f;
        if (angle < 0)
        {
            angle += 360.0f;
        }
        setAngle(angle);
    }
    if (moving && (sqrt((mouseX - x()) * (mouseX - x()) + (mouseX - x()) * (mouseX - x())) > 5))
    {
        setVel(std::cos(angle() * M_PI / 180.0) * (7), std::sin(angle() * M_PI / 180.0) * (7));
    }
    else
    {
        setVel(0, 0);
        moving = false;
    }
    move();
    return getTexture();
}
