#include "Paddle.h"

Paddle::Paddle()
:myPaddle()
{

    myPaddle.setSize(sf::Vector2f(100,25));
    myPaddle.setOutlineThickness(1);
    myPaddle.setOutlineColor(sf::Color(245,120,120));
    myPaddle.setFillColor(sf::Color::Red);
    myPaddle.setOrigin(50,12.5);
    myPaddle.setPosition(sf::Vector2f(540 / 2, 610));

}

void Paddle::draw(sf::RenderWindow& window)
{
   window.draw(myPaddle);
}
float Paddle::getX()
{
    return myPaddle.getPosition().x;
}

float Paddle::getY()
{
    return myPaddle.getPosition().y;
}

void Paddle::movePaddle(float& moveX,sf::Time& elapsedTime)
{
    if((moveX<0)&& (myPaddle.getPosition().x-50 > 5.f)) //check if left bound then stop paddle
        myPaddle.move(moveX*elapsedTime.asSeconds(),0.f);

    if((moveX>0)&& (myPaddle.getPosition().x+50 < 535.f))//check if right bound then stop paddle
        myPaddle.move(moveX*elapsedTime.asSeconds(),0.f);
}
