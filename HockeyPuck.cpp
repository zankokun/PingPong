#include "HockeyPuck.h"
#include "Ping.h"
#include "Base.h"
#include "OurPlatform.h"
#include "AnotherPlatform.h"

void HockeyPuck::RandomDirection()
{
    srand(time(0));

    random1 = 1 + rand() % 2;

    if (random1 == 2)
    {
        ky *= -1;
    }

    random2 = 1 + rand() % 2;

    if (random2 == 2)
    {
        kx *= -1;
    }
}

void HockeyPuck::TakeColorBall()
{
    ball.setFillColor(sf::Color(190, 190, 190));
}

void HockeyPuck::JumpWall()
{
    if (x >= xm)
    {
        x = xm;
        kx *= -1;
    }
    else if (x <= 5)
    {
        x = 5;
        kx *= -1;
    }
    if (y >= ym)
    {
        y = ym;
        ky *= -1;
    }
    else if (y <= 5)
    {
        y = 5;
        ky *= -1;
    }
}

void HockeyPuck::JumpPlatforms()
{
    sf::FloatRect BallBounds = ball.getGlobalBounds();
    sf::FloatRect PlatBounds = plat.getGlobalBounds();
    sf::FloatRect PlatformBounds = platform.getGlobalBounds();

    sf::FloatRect Platformcircle1Bounds = platformcircle1.getGlobalBounds();
    sf::FloatRect Platformcircle2Bounds = platformcircle2.getGlobalBounds();
    sf::FloatRect Platcircle1Bounds = platcircle1.getGlobalBounds();
    sf::FloatRect Platcircle2Bounds = platcircle2.getGlobalBounds();

    if (BallBounds.intersects(PlatformBounds) || BallBounds.intersects(Platformcircle1Bounds) || BallBounds.intersects(Platformcircle2Bounds))
    {
        y1plat1 += ky;
        ky *= -1;
        x += kx * rebound;
        y += ky * rebound;
    }
    if (BallBounds.intersects(PlatBounds) || BallBounds.intersects(Platcircle1Bounds) || BallBounds.intersects(Platcircle2Bounds))
    {
        y1plat2 += ky;
        ky *= -1;
        x += kx * rebound;
        y += ky * rebound;
    }

}

void HockeyPuck::Points()
{
    if (x >= xc1 && x <= (xc1 + c4size * 2) && y == 0)
    {
        ourpoints += 1;
    }
    if (x >= xc1 && x <= (xc1 + c4size * 2) && y == (ymap - 2*r))
    {
        anotherpoints += 1;
    }
}

void HockeyPuck::MainFunctionBall()
{
    TakeColorBall();

    ball.setPosition(x, y);

    x = kx * 1 + x;
    y = ky * 1 + y;

    JumpWall();
    JumpPlatforms();

    baza.window.draw(ball);
}

void HockeyPuck::MainFunctionBallClient()
{
    TakeColorBall();
    ball.setPosition(x, y);
    JumpPlatforms();

    baza.window.draw(ball);
}