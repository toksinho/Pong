#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle();
    virtual void    draw(sf::RenderWindow& window);
    void    movePaddle(float& moveX,sf::Time& elapsedTime);
    float   getX();
    float   getY();
protected :
    sf::RectangleShape myPaddle;
};

#endif // PADDLE_H
