#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <cmath> //for sin and cos
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Paddle.h"
#include "Ball.h"
#include "UpPaddle.h"
#include "Scene.h"

class Game
{
public:
    Game();
    void    run();
private:
    void	processEvents();
    void	update(sf::Time elapsedTime);
    void	render();
    void	handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void    collisions(sf::Time elapsedTime);
    float   pick(float*);

    sf::RenderWindow window;
    sf::RectangleShape shape;
    sf::Clock AITimer;
    Paddle paddle;
    Ball ball;
    UpPaddle compPaddle;
    Scene scene;
    float speed;
    float ballSpeed;
    float compSpeed;
    float ballAngle;
    bool isPlay;
    bool firstScene;
    bool menuScene;
    bool	Right;
    bool	Left;

};
#endif // GAME_H
