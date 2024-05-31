#pragma once

#include <SFML/Graphics.hpp>

class WaitMenu
{
private:
    int xmap = 500;
    int ymap = 900;

    sf::Font font;

    sf::RectangleShape background{ {float(xmap), float(ymap)} };

    sf::Text WaitText{ "Please. Wait for  your opponent...", font, 30 };

public:
	sf::RenderWindow wait;

    bool isOpen();
    void TakeColorWaitMenu();
    void TakePositionWaitMenu();
    void MainFunctionWaitMenu();
    
    WaitMenu()
    {
        font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
        wait.create(sf::VideoMode(xmap, ymap), "Waiting...");
    }
};