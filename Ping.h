#pragma once

#include <SFML/Graphics.hpp>


static bool ar = false;

static int ky = 4;
static int kx = 1;

static int r = 20;
//static int fps = 1;

extern int fps;
static int rebound = 60 / ky;

static float xmap = 500;
static float ymap = 900;

static int xm = xmap - 2 * r;
static int ym = ymap - 2 * r;


static int random1;
static int random2;

static float size = 50;
static float size2 = 30;

static int radius = size2 / 2;

static int c1size = 100;
static int c2size = 60;
static int c3size = 125;
static int c4size = 125;
static float outline = 5;

static int xc1 = (xmap - 2 * c1size) / 2;
static int xc2 = (xmap - 2 * c2size) / 2;
static int xc3 = (xmap - 2 * c3size) / 2;
static int xc4 = (xmap - 2 * c4size) / 2;

static int yc1 = (ymap - 2 * c1size) / 2;
static int yc2 = (ymap - 2 * c2size) / 2;
static int yc3 = 0 - c3size;
static int yc4 = ymap - c4size;

static int yl1 = 175;
static int yl2 = ymap - 175;

static sf::Font font;

static sf::RectangleShape background{ {float(xmap), float(ymap)} };


// extern данные меняются из любого модуля и общие для всех
extern int x;
extern int y;

extern int x1plat1;
extern int x1plat2;

extern int y1plat1;
extern int y1plat2;

extern bool who;
extern bool game;
extern bool win;

extern int ourpoints;
extern int anotherpoints;

//ball
extern sf::CircleShape ball;

//platforms and their circles 
extern sf::RectangleShape platform;
extern sf::CircleShape platformcircle1;
extern sf::CircleShape platformcircle2;

extern sf::RectangleShape plat;
extern sf::CircleShape platcircle1;
extern sf::CircleShape platcircle2;

extern sf::RectangleShape line1;
extern sf::RectangleShape line2;

//decorate for base
static sf::CircleShape circle1(c1size);
static sf::CircleShape circle2(c2size);
static sf::CircleShape circle3(c3size);
static sf::CircleShape circle4(c4size);
