#include "OnlineChoiceMenu.h"

bool OnlineChoiceMenu::isOpen()
{
    return  onlinemenu.isOpen();
}

void OnlineChoiceMenu::TakeColorOnlineMenu()
{
    background.setFillColor(sf::Color(80, 80, 80));
    wel.setFillColor(sf::Color(247, 85, 15));
    sel.setFillColor(sf::Color(247, 85, 15));
    cre.setFillColor(sf::Color(247, 85, 15));
    arr.setFillColor(sf::Color(247, 85, 15));
}

void OnlineChoiceMenu::TakePositionOnlineMenu()
{
    background.setPosition(0, 0);
    wel.setPosition((xmap - 7 * 30) / 2, massy[0]);
    sel.setPosition((xmap - 7 * 30) / 2, massy[1] + 16);
    cre.setPosition((xmap - 7 * 30) / 2, massy[2] + 16);
    arr.setPosition(50, temp);
}

void OnlineChoiceMenu::ArrowMovementOnline()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        temp = massy[1];
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        temp = massy[2];
    }
}

void OnlineChoiceMenu::ChoiceOnline()
{
    if (temp == massy[1])
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            onlinemenu.close();

            who = true;
        }
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            onlinemenu.close();
        }
    }
}

void OnlineChoiceMenu::MainFunctionOnlineMenu()
{
    TakeColorOnlineMenu();
    TakePositionOnlineMenu();
    ChoiceOnline();

    onlinemenu.draw(background);
    onlinemenu.draw(wel);
    onlinemenu.draw(sel);
    onlinemenu.draw(cre);
    onlinemenu.draw(arr);
}
