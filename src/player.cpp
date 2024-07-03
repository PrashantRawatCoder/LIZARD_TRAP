#include "Player.hpp"
#include "Window.hpp"
#include <cmath>

Player::Player(int width, int height, float speed, int maxHealth, int attackDamage, Window *window) : Entity(window->Width() / 2 - width / 2, window->Height() / 2 - height / 2, speed, width, height, maxHealth, attackDamage), centerX(window->Width() / 2 - getWidth() / 2), centerY(window->Height() / 2 - getHeight() / 2)
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

void Player::setFPSTime(double time)
{
    FPSTime = time;
}

SDL_Texture *Player::getPTexture()
{
    {
        float angle_rad = std::atan2(mouseY - centerY, mouseX - centerX);
        double angle = angle_rad * 180.0f / M_PI;
        angle -= 5.0000001f;
        if (angle < 0)
        {
            angle += 360.0f;
        }
        setAngle(angle);
    }
    if (moving && (sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY)) > 1))
    {
        setVel(FPSTime);
    }
    else
    {
        setVel(0, 0);
        moving = false;
    }
    move();
    return getTexture();
}

SDL_Rect Player::getRect()
{

    SDL_Rect rect{centerX, centerY, getWidth(), getHeight()};
    return rect;
}