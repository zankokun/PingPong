#pragma once

#include <SFML/Graphics.hpp>
#include "Ping.h"

class OnlineChoiceMenu
{
private:
    int massy[3] = { 100, 400, 600 };
    int temp = massy[1];

    sf::Font font;

    sf::RectangleShape background{{float(xmap), float(ymap)}};

    sf::Text wel{ "WELCOME", font, 50 };
    sf::Text sel{ "SELECT A NEW SERVER", font, 30 };
    sf::Text cre{ "CREATE A NEW SERVER", font, 30 };
    sf::Text arr{ ">", font, 50 };

public:
    sf::RenderWindow onlinemenu;

    bool isOpen();
    void TakeColorOnlineMenu();
    void TakePositionOnlineMenu();
    void ArrowMovementOnline();
    void ChoiceOnline();
    void MainFunctionOnlineMenu();

    OnlineChoiceMenu() 
    {
        font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
        onlinemenu.create(sf::VideoMode(xmap, ymap), "Aero Hockey Menu");
    }
};
