#ifndef UPPADLE_H
#define UPPADLE_H
#include <SFML/Graphics.hpp>

class   UpPaddle
{
public:
    UpPaddle();
    void    draw(sf::RenderWindow& window);
    float   getX();
    float   getY();
    void    movePaddle(float& speed,sf::Time& deltaTime);

private:
    sf::RectangleShape upPaddle;
};
#endif // UPPADLE_H
