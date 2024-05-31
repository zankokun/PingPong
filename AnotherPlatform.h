#pragma once

#include <SFML/Graphics.hpp>
#include "Base.h"

class AnotherPlatform
{
private:
public:
    Base &baza;
    AnotherPlatform(Base &newbaza) :baza(newbaza){}
    void TakeColorAnotherPlatform();
    void TakePositionAnotherPlatform();
    void Movement2();
    void ReturnAnotherPlatform();
    void ReboundPlatform2();
    void MainFunctionAnotherPlatform();
    void MainFunctionAnotherPlatformClient();
};