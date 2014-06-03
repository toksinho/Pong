#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Scene
{
public:
    Scene();
    void    draw(sf::RenderWindow&);
    void    drawBeginMessage(sf::RenderWindow&);
    void    firstScreenShow(sf::RenderWindow&);

private:
    sf::RectangleShape line1;
    sf::RectangleShape line2;
    sf::Font font;
    sf::Text beginMessage1;
    sf::Text beginMessage2;
    sf::Texture image;
    sf::Sprite sprite;



};
#endif // SCENE_H
