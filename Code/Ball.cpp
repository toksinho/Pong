#include "Ball.h"
#include <cmath>
#include <iostream>
Ball::Ball()
{
    ball.setRadius(10);
    ball.setFillColor(sf::Color::White);
    ball.setOutlineThickness(2);
    ball.setOutlineColor(sf::Color::Black);
    ball.setOrigin(10,10);
    ball.setPosition(270, 320);
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(ball);
}

void Ball::moveBall(float& ballAngle,float& factor)
{
       ball.move(std::sin(ballAngle) * factor,std::cos(ballAngle) * factor);
}

float Ball::getX()
{
    return ball.getPosition().x;
}
float Ball::getY()
{
    return ball.getPosition().y;
}
void Ball::setCenter()
{
    ball.setPosition(270,320);
}
void Ball::setPos(float x,float y)
{

    ball.setPosition(x,y);
}
