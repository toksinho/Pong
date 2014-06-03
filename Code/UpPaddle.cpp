#include "UpPaddle.h"

UpPaddle::UpPaddle()
{
    upPaddle.setSize(sf::Vector2f(100,25));
    upPaddle.setOutlineThickness(1);
    upPaddle.setOutlineColor(sf::Color(120,120,240));
    upPaddle.setFillColor(sf::Color::Blue);
    upPaddle.setOrigin(50,12.5);
    upPaddle.setPosition(sf::Vector2f(540 / 2, 30));
}

void UpPaddle::draw(sf::RenderWindow& window)
{
    window.draw(upPaddle);
}
float UpPaddle::getX()
{
    return upPaddle.getPosition().x;
}

float UpPaddle::getY()
{
    return upPaddle.getPosition().y;
}
void UpPaddle::movePaddle(float& speed,sf::Time& deltaTime)
{
    upPaddle.move(speed * deltaTime.asSeconds(),0);
}
