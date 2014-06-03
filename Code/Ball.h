#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    void    draw(sf::RenderWindow& window);
    void    moveBall(float& x,float& y);
    float   getX();
    float   getY();
    void    setCenter();
    void    setPos(float,float);
private:
    sf::CircleShape ball;
};
#endif // BALL_H
