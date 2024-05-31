#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Ping.h"
#include "OnlineChoiceMenu.h"
#include "ChoiceMenu.h"
#include "WaitMenu.h"
#include "Base.h"
#include "OurPlatform.h"
#include "AnotherPlatform.h"
#include "HockeyPuck.h"
#include "Online.h"

bool who = false;
bool game = false;

int fps = 20;
int y1plat1 = ymap - size2 - 50;
int x1plat1 = xmap / 2;

int x1plat2 = xmap / 2 ;
int y1plat2 = 50;

int x = (xmap - 2 * r) / 2;
int y = (ymap - 2 * r) / 2;

int ourpoints;
int anotherpoints;

sf::CircleShape ball = sf::CircleShape(r);

sf::RectangleShape platform = sf::RectangleShape({size, size2});
sf::CircleShape platformcircle1 = sf::CircleShape(radius);
sf::CircleShape platformcircle2 = sf::CircleShape(radius);

sf::RectangleShape plat = sf::RectangleShape(sf::Vector2f{size, size2});
sf::CircleShape platcircle1 = sf::CircleShape(radius);
sf::CircleShape platcircle2 = sf::CircleShape(radius);

sf::RectangleShape line1 = sf::RectangleShape(sf::Vector2f{ xmap, outline });
sf::RectangleShape line2 = sf::RectangleShape(sf::Vector2f{ xmap, outline });

int main()
{
    font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

    OnlineChoiceMenu onlinemenushka;
  
    while (onlinemenushka.isOpen())
    {
        sf::Event event;
        while (onlinemenushka.onlinemenu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                onlinemenushka.onlinemenu.close();
            }
            onlinemenushka.ArrowMovementOnline();
        }
        onlinemenushka.onlinemenu.clear();

        onlinemenushka.MainFunctionOnlineMenu();

        onlinemenushka.onlinemenu.display();
    }

    ar = true;

    //сервер 
    if (who == false)
    {
        ChoiceMenu menushka;

        while (menushka.isOpen())
        {
            sf::Event event;
            while (menushka.menu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    menushka.menu.close();
                }
                menushka.ArrowMovement();
            }
            menushka.menu.clear();
            menushka.MainFunctionMenu();
            menushka.menu.display();
        }

        WaitMenu waitm;
        Online on{waitm};

        while (waitm.isOpen())
        {
            sf::Event event;
            while (waitm.wait.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    waitm.wait.close();
                }
            }
            waitm.wait.clear();
            waitm.MainFunctionWaitMenu();
            on.FirstServer();
            waitm.wait.display();
        }
        Base baza;

        OurPlatform platform{ baza };
        AnotherPlatform plat{ baza };
        HockeyPuck ball{ baza };

        baza.window.setFramerateLimit(fps);
        ball.RandomDirection();

        while (baza.isOpen())
        {
            sf::Event event;
            while (baza.window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    baza.window.close();
            }
            baza.window.clear();
            baza.MainFunctionBase();
            platform.MainFunctionOurPlatform();
            plat.MainFunctionAnotherPlatform();
            ball.MainFunctionBall();
            on.Server();
            baza.window.display();
        }
    }
    //клиент
    if (who == true) 
    {
        WaitMenu waitm;
        Online on{waitm};

        while (waitm.isOpen())
        {
            sf::Event event;
            while (waitm.wait.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    waitm.wait.close();
                }
            }
            waitm.wait.clear();
            waitm.MainFunctionWaitMenu();
            waitm.wait.display();
            on.FirstClient();

        }

        game = true;

        if (game == true)
        {
            Base baza;

            OurPlatform platform{ baza };
            AnotherPlatform plat{ baza };
            HockeyPuck ball{ baza };

            baza.window.setFramerateLimit(fps);

            ball.RandomDirection();

            while (baza.isOpen())
            {
                sf::Event event;
                while (baza.window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        baza.window.close();
                }
                baza.window.clear();
                baza.MainFunctionBase();
                platform.MainFunctionOurPlatformClient();
                plat.MainFunctionAnotherPlatformClient();
                ball.MainFunctionBallClient();
                on.Client();
                baza.window.display();
            }
        }
    }


    return 0;
}