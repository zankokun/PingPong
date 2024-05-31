#include "WaitMenu.h"

bool WaitMenu::isOpen()
{
    return wait.isOpen();
}

void WaitMenu::TakeColorWaitMenu()
{
    background.setFillColor(sf::Color(80, 80, 80));
	WaitText.setFillColor(sf::Color(247, 85, 15));
}

void WaitMenu::TakePositionWaitMenu()
{
    background.setPosition(0, 0);
    WaitText.setPosition(50 ,300);
}

void WaitMenu::MainFunctionWaitMenu()
{
    TakeColorWaitMenu();
    TakePositionWaitMenu();

    wait.draw(background);
    wait.draw(WaitText);
}
