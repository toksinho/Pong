#include "Scene.h"

Scene::Scene()
{
    if(image.loadFromFile("screen.jpg") != true)
	{

		std::cout<<"Nema slike!!!";
	}
	else
        sprite.setTexture(image);


    font.loadFromFile("arial.ttf");
    line1.setSize(sf::Vector2f(3,640));
    line1.setPosition(sf::Vector2f(270, 320));
    line1.setOrigin(1.5,320);
    line1.setFillColor(sf::Color::White);

    line2.setSize(sf::Vector2f(640,3));
    line2.setPosition(sf::Vector2f(270, 320));
    line2.setOrigin(320,1.5);
    line2.setFillColor(sf::Color::White);
}

void Scene::draw(sf::RenderWindow& window)
{
    window.draw(line1);
    window.draw(line2);
}

void Scene:: drawBeginMessage(sf::RenderWindow& window)
{
    window.clear();
    beginMessage1.setFont(font);
    beginMessage1.setCharacterSize(60);
    beginMessage1.setPosition(50.f, 240.f);
    beginMessage1.setColor(sf::Color::Blue);
    beginMessage1.setString("Pong Game");

    beginMessage2.setFont(font);
    beginMessage2.setCharacterSize(40);
    beginMessage2.setPosition(50.f, 280.f);
    beginMessage2.setColor(sf::Color::White);
    beginMessage2.setString("\nPress Space for new game\nEsc for exit");

    window.draw(beginMessage1);
    window.draw(beginMessage2);

    window.display();
}


void Scene::firstScreenShow(sf::RenderWindow& window)
{

    window.draw(sprite);
    window.display();
}
