#pragma once

#include <SFML/Graphics.hpp>
#include "Ping.h"

class Base
{
private:
    sf::Font font;
public:
    sf::RenderWindow window;

    bool isOpen();
    void TakeColorBase();
    void TakePositionBase();
    void MainFunctionBase();

    Base()
    {
        font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
        window.create(sf::VideoMode(xmap, ymap), "Aero Hockey");
    }
};