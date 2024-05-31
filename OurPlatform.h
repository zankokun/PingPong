#pragma once

#include <SFML/Graphics.hpp>
#include "Base.h"

class OurPlatform
{
private:
public:
    Base& baza;
    OurPlatform(Base& newbaza) :baza(newbaza) {}

    void TakeColorOurPlatform();
    void TakePositionOurPlatform();
    void Movement();
    void ReturnOurPlatform();
    void ReboundPlatform();
    void MainFunctionOurPlatform();
    void MainFunctionOurPlatformClient();
};