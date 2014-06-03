#include "Game.h"
Game::Game()
: window(sf::VideoMode(540, 640), "Pong", sf::Style::Close)
,paddle()
,ball()
,compPaddle()
,speed(400.f)
,ballSpeed(450.f)
,compSpeed(0.f)
,ballAngle(6.7)
, Right(false)
, Left(false)
,firstScene(true)
,menuScene(false)
,isPlay(false)
{
window.setVerticalSyncEnabled(true);
srand (time(NULL));
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        processEvents();
        sf::Time deltaTime=clock.restart();

    if(firstScene)
            scene.firstScreenShow(window);
    else if(menuScene==true)
            scene.drawBeginMessage(window);
    else if(isPlay)
{
          window.clear(sf::Color(100,150,100));
          update(deltaTime);
          render();
}

        }
}



void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
    handlePlayerInput(event.key.code, true);
    break;

    case sf::Event::KeyReleased:
    handlePlayerInput(event.key.code, false);
    break;
    case sf::Event::Closed:
    window.close();
    break;
}
}
}

void Game::update(sf::Time elapsedTime)
{
    float movementX=0.f;
    if (Left)
        movementX -= speed;
    if (Right)
        movementX += speed;

    paddle.movePaddle(movementX,elapsedTime);
    collisions(elapsedTime);
}

void Game::collisions(sf::Time elapsedTime)
{
    float factor = ballSpeed*elapsedTime.asSeconds();
    ball.moveBall(ballAngle,factor);
    compPaddle.movePaddle(compSpeed,elapsedTime);
    sf::Time AITime = sf::seconds(0.1f);

    //collision between my paddle and ball, move ball back with some different angle

            if(ball.getY() + 10 > paddle.getY() - 12.5f &&  // 10 is radius, 12.5 and 50 are half of paddle
               ball.getY() + 10 < paddle.getY() &&
               ball.getX() + 10 >= paddle.getX() - 50 &&
               ball.getX() - 10 <= paddle.getX() + 50)
            {

                if ((ball.getX() > paddle.getX()) && (ball.getX() < paddle.getX() + 35.f))
                {

                    float arr[3]={2.70, 2.65,2.75};
                    ballAngle =pick(arr);



                }

                else if((ball.getX() > paddle.getX()) && (ball.getX() > paddle.getX() + 35.f))
                {
                    float arr[3]={2.20,2.30,2.35};
                    ballAngle =pick(arr);

                }

                else if((ball.getX() < paddle.getX()) && (ball.getX() > paddle.getX() - 35.f))
                {
                    float arr[]={3.55,3.60,3.65};
                    ballAngle = pick(arr);

                }
                else
                {
                   float arr[]={4.05,4.10,4.15};
                   ballAngle = pick(arr);
                }

            }

           // Check collisions between the ball and the screen

            if ((ball.getX() - 10) < 0.f)//left side of the screen
            {
                ballAngle=-ballAngle;
                ball.setPos(10.1f,ball.getY()); //radius + 0.1f=10.1

            }
            if ((ball.getX() + 10) > 540)//right side of the screen
            {
                ballAngle=-ballAngle;
                ball.setPos(529.9f,ball.getY());//x of the screen - radius -0.1f =589.9

            }


            if((ball.getY()+10)>630) //if ball goes off the screen put menu screen
            {
                isPlay=false;
                menuScene=true;
                ball.setCenter();

            }

            if((ball.getY()-10)<0) //if ball goes off the screen put  menu screen
            {
                isPlay=false;
                menuScene=true;
                ball.setCenter();
            }

            if (AITimer.getElapsedTime() > AITime)
            {
                AITimer.restart();
                if (ball.getX() + 10 > compPaddle.getX() + 50)
                    compSpeed = 350;
                else if (ball.getX() - 10 < compPaddle.getX() - 50)
                    compSpeed = -350;
                else
                    compSpeed = 0.f;
            }
            //collision of computer's paddle and ball

           if (ball.getY() - 10 < compPaddle.getY() + 12.5f &&
               ball.getY() - 10 > compPaddle.getY() &&
               ball.getX() + 10 >= compPaddle.getX() - 50 &&
               ball.getX() - 10 <= compPaddle.getX() + 50)
            {

                if ((ball.getX() > compPaddle.getX()) && (ball.getX() < compPaddle.getX() + 35))
                {

                    ballAngle = 6.72;

                }

                else if ((ball.getX() > compPaddle.getX()) && (ball.getX() > compPaddle.getX() + 35))
                {

                   ballAngle = 7.23;
                }

                else if ((ball.getX() < compPaddle.getX()) && (ball.getX() > compPaddle.getX() - 35))
                {

                   ballAngle = 5.83;
                }
                else
                {
                    ballAngle = 5.35;
                }

}

}
void Game::render()
{
scene.draw(window);
paddle.draw(window);
ball.draw(window);
compPaddle.draw(window);

window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
if (key == sf::Keyboard::Left)
    Left = isPressed;
else if (key == sf::Keyboard::Right)
    Right = isPressed;
else if(key==sf::Keyboard::Return)
{
    firstScene=false;
    menuScene=true;
}
else if(key==sf::Keyboard::Space)
{
menuScene=false;
isPlay=true;
}
else if(key==sf::Keyboard::Escape)
    window.close();
}

float Game:: pick(float* arr) //return random number from array of 3 float numbers
{
    return arr[rand()%3];
}
