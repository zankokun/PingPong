#include "Ping.h"
#include "OurPlatform.h"
#include "Base.h"


void OurPlatform::TakeColorOurPlatform()
{
    platform.setFillColor(sf::Color(247, 85, 15));
    platformcircle1.setFillColor(sf::Color(247, 85, 15));
    platformcircle2.setFillColor(sf::Color(247, 85, 15));
}

void OurPlatform::TakePositionOurPlatform()
{
    platform.setPosition(x1plat1, y1plat1);
    platformcircle1.setPosition(x1plat1 - radius, y1plat1);
    platformcircle2.setPosition(x1plat1 + size - radius, y1plat1);
}

void OurPlatform::Movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x1plat1 -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x1plat1 += 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y1plat1 -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y1plat1 += 5;
    }
}

void OurPlatform::ReturnOurPlatform()
{
    if (x1plat1 == size * -1)
    {
        x1plat1 = xmap;
    }
    else if (x1plat1 == xmap)
    {
        x1plat1 = size * -1;
    }
    if (y1plat1 >= ymap - size2)
    {
        y1plat1 = ymap - size2;
    }
}

void OurPlatform::ReboundPlatform()
{
    sf::FloatRect PlatformBounds = platform.getGlobalBounds();
    sf::FloatRect Line2Bounds = line2.getGlobalBounds();

    if (PlatformBounds.intersects(Line2Bounds))
    {
        y1plat1 = yl2 + 5;
    }
}

void OurPlatform::MainFunctionOurPlatform()
{
    TakeColorOurPlatform();
    TakePositionOurPlatform();

    Movement();
    ReturnOurPlatform();
    ReboundPlatform();

    baza.window.draw(platform);
    baza.window.draw(platformcircle1);
    baza.window.draw(platformcircle2);
}

void OurPlatform::MainFunctionOurPlatformClient()
{
    TakeColorOurPlatform();
    TakePositionOurPlatform();

    baza.window.draw(platform);
    baza.window.draw(platformcircle1);
    baza.window.draw(platformcircle2);
}
