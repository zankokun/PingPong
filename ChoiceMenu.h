#pragma once

#include <SFML/Graphics.hpp>
#include "Ping.h" 

class ChoiceMenu
{
private:
    int masy[6]{ 100, 340, 480, 620, 800, 999 };
    int a = 1;
    int yar = masy[a];

    sf::Font font;

    sf::Text arrow{">", font, 50};
    sf::Text eazy{"EASY", font, 50};
    sf::Text normal{"NORMAL", font, 50};
    sf::Text hard{"HARD", font, 50};
    sf::Text play{"PLAY", font, 50};

    sf::RectangleShape eazyrec{ {200.f, 100.f} };
    sf::RectangleShape normalrec{ {200.f, 100.f} };
    sf::RectangleShape hardrec{ {200.f, 100.f} };
    sf::RectangleShape playrec{ {190.f, 100.f} };
    sf::RectangleShape choicerec{ { 190.f, 100.f } };
public:
    sf::RenderWindow menu;

    ChoiceMenu()
    {
        choicerec.setPosition((xmap - 200) / 2, masy[1]);
        choicerec.setFillColor(sf::Color::Green);

        font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
        menu.create(sf::VideoMode(xmap, ymap), "Aero Hockey Menu");
    }

    bool isOpen();
    void TakeColorMenu();
    void TakePositionMenu();
    void ArrowMovement();
    void Choice();
    void MainFunctionMenu();
};