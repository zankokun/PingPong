#include "Ping.h"
#include "Base.h"
#include "AnotherPlatform.h"

void AnotherPlatform::TakeColorAnotherPlatform()
{
    plat.setFillColor(sf::Color(247, 85, 15));
    platcircle1.setFillColor(sf::Color(247, 85, 15));
    platcircle2.setFillColor(sf::Color(247, 85, 15));
}

void AnotherPlatform::TakePositionAnotherPlatform()
{
    plat.setPosition(x1plat2, y1plat2);
    platcircle1.setPosition(x1plat2 - radius, y1plat2);
    platcircle2.setPosition(x1plat2 + size - radius, y1plat2);
}

void AnotherPlatform::MainFunctionAnotherPlatform()
{
    TakeColorAnotherPlatform();
    TakePositionAnotherPlatform();

    baza.window.draw(plat);
    baza.window.draw(platcircle1);
    baza.window.draw(platcircle2);
}

void AnotherPlatform::Movement2()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        x1plat2 -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        x1plat2 += 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        y1plat2 -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        y1plat2 += 5;
    }
}

void AnotherPlatform::ReturnAnotherPlatform()
{
    if (x1plat2 == size * -1)
    {
        x1plat2 = xmap;
    }
    else if (x1plat2 == xmap)
    {
        x1plat2 = size * -1;
    }
    if (y1plat2 >= ymap - size2)
    {
        y1plat2 = ymap - size2;
    }
}

void AnotherPlatform::ReboundPlatform2()
{
    sf::FloatRect PlatformBounds = platform.getGlobalBounds();
    sf::FloatRect Line1Bounds = line1.getGlobalBounds();

    if (PlatformBounds.intersects(Line1Bounds))
    {
        y1plat2 = yl1 - 5 - size2;
    }
}

void AnotherPlatform::MainFunctionAnotherPlatformClient()
{
    TakeColorAnotherPlatform();
    TakePositionAnotherPlatform();
    Movement2();
    ReturnAnotherPlatform();
    ReboundPlatform2();

    baza.window.draw(plat);
    baza.window.draw(platcircle1);
    baza.window.draw(platcircle2);
}