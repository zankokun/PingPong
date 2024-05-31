#include "Ping.h"
#include "Base.h"

bool Base::isOpen()
{
    return  window.isOpen();
}

void Base::TakeColorBase()
{
    background.setFillColor(sf::Color(80, 80, 80));

    circle1.setFillColor(sf::Color(80, 80, 80));
    circle2.setFillColor(sf::Color(80, 80, 80));
    circle3.setFillColor(sf::Color(80, 80, 80));
    circle4.setFillColor(sf::Color(80, 80, 80));
    line1.setFillColor(sf::Color(125, 125, 125));
    line2.setFillColor(sf::Color(125, 125, 125));

    circle1.setOutlineThickness(outline);
    circle2.setOutlineThickness(outline);
    circle3.setOutlineThickness(outline);
    circle4.setOutlineThickness(outline);

    circle1.setOutlineColor(sf::Color(125, 125, 125));
    circle2.setOutlineColor(sf::Color(125, 125, 125));
    circle3.setOutlineColor(sf::Color(125, 125, 125));
    circle4.setOutlineColor(sf::Color(125, 125, 125));
}

void Base::TakePositionBase()
{
    circle1.setPosition(xc1, yc1);
    circle2.setPosition(xc2, yc2);
    circle3.setPosition(xc3, yc3);
    circle4.setPosition(xc4, yc4);
    line1.setPosition(0, yl1);
    line2.setPosition(0, yl2);
}

void Base::MainFunctionBase()
{
    TakeColorBase();
    TakePositionBase();

    window.draw(background);
    window.draw(circle1);
    window.draw(circle2);
    window.draw(circle3);
    window.draw(circle4);
    window.draw(line1);
    window.draw(line2);
}