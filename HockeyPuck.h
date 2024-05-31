#pragma once

#include <SFML/Graphics.hpp>
#include "Base.h"

class HockeyPuck
{
private:
public:
    Base& baza;
    HockeyPuck(Base& newbaza) :baza(newbaza) {}

    void RandomDirection();
    void TakeColorBall();
    void JumpWall();
    void JumpPlatforms();
    void Points();
    void MainFunctionBall();
    void MainFunctionBallClient();
};