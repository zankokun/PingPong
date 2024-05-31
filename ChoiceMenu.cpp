#include "ChoiceMenu.h"
#include "Ping.h"

bool ChoiceMenu::isOpen()
{
    return  menu.isOpen();
}

void ChoiceMenu::TakeColorMenu()
{
    background.setFillColor(sf::Color(80, 80, 80));
    arrow.setFillColor(sf::Color(125, 125, 125));
    eazy.setFillColor(sf::Color(0, 250, 154));
    normal.setFillColor(sf::Color(240, 200, 46));
    hard.setFillColor(sf::Color(247, 85, 15));
    play.setFillColor(sf::Color(125, 125, 125));
}

void ChoiceMenu::TakePositionMenu()
{
    background.setPosition(0.f, 0.f);

    eazy.setPosition((xmap - 4 * 30) / 2, masy[1]);
    normal.setPosition((xmap - 6 * 30) / 2, masy[2]);
    hard.setPosition((xmap - 4 * 30) / 2, masy[3]);
    play.setPosition((xmap - 4 * 30) / 2, masy[4]);
    eazyrec.setPosition((xmap - 200) / 2, 320);
    normalrec.setPosition((xmap - 200) / 2, 460);
    hardrec.setPosition((xmap - 200) / 2, 600);
    playrec.setPosition((xmap - 200) / 2, 780);

    arrow.setPosition(50, yar);
}

void ChoiceMenu::ArrowMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        yar = masy[a -= 1];
        if (yar == masy[0])
        {
            yar = masy[1];
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        yar = masy[a += 1];
        if (yar == masy[5])
        {
            yar = masy[4];
        }
    }
}

void ChoiceMenu::Choice()
{
    if (yar == masy[1])
    {
        eazyrec.setFillColor(sf::Color(80, 80, 80));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            fps = 60;
            choicerec.setPosition((xmap - 200) / 2, masy[1]);
            choicerec.setFillColor(sf::Color(0, 250, 154));
            ar = true;
        }
    }
    
    else
    {
        eazyrec.setFillColor(sf::Color(80, 80, 80));
    }

    if (yar == masy[2])
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
           fps = 120;
            choicerec.setPosition((xmap - 200) / 2, masy[2]);
            choicerec.setFillColor(sf::Color(240, 200, 46));
            ar = true;
        }
    }
    
    else
    {
        normalrec.setFillColor(sf::Color(80, 80, 80));
    }

    if (yar == masy[3])
    {        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            fps = 180;
            choicerec.setPosition((xmap - 200) / 2, masy[3]);
            choicerec.setFillColor(sf::Color(247, 85, 15));
            ar = true;
        }
    }
    
    else
    {
        hardrec.setFillColor(sf::Color(80, 80, 80));
    }
        
    if (yar == masy[4])
    {
        playrec.setFillColor(sf::Color(38, 38, 38));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            menu.close();
        }
    }
    
    else
    {
        playrec.setFillColor(sf::Color(80, 80, 80));
    }
    

}

void ChoiceMenu::MainFunctionMenu()
{
    TakeColorMenu();
    Choice();
    TakePositionMenu();

    menu.draw(background);

    if (ar == true)
    {
         menu.draw(choicerec);
    }

    menu.draw(eazyrec);
    menu.draw(normalrec);
    menu.draw(hardrec);
    menu.draw(playrec);

    menu.draw(eazy);
    menu.draw(normal);
    menu.draw(hard);
    menu.draw(play);

    menu.draw(arrow);
}
