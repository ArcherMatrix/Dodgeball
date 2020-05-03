#include "DodgeBall.h"
#include <cassert>

Dodgeball::Dodgeball()
{
}

Dodgeball::Dodgeball(float x, float y, float w, float h,std::random_device& rd)
    :
    xDist(0,x-80),
    yDist(0,y-80),
    yVel(-2.5f, 2.5f),						
    xVel(-2.5f, 2.5f),
    width(63),
    height(67),
    Collided (false),
    rng(rd())
{
    assert(posX = xDist(rng));
    assert(posY = yDist(rng));
    assert(veloX = xVel(rng));
    assert(veloY = yVel(rng));

    while (veloX == 0) {
       veloX = xVel(rng);
    }

    while (veloY == 0) {
        veloY = yVel(rng);
    }
}

Dodgeball::Dodgeball(float x, float y, float w, float h, float vX, float vY)
{
    posX = x;
    posY = y;
    width = w;
    height = h;
    veloX = vX;
    veloX = vY;
}

Dodgeball::~Dodgeball()
{
}

void Dodgeball::Movement(Graphics& gfx)
{
 
   
    posX =+ veloX;
    posY =+ veloY;

    if (posX < 0)
    {
        posX = 0;
        veloX = -veloX;

    }
    if (posX + width >= gfx.ScreenWidth)
    {
        posX = gfx.ScreenWidth-width;
        veloX = -veloX;
    }
    if (posY < 0)
    {
        posY = 0;
        veloY = -veloY;
    }
    if (posY + height >= gfx.ScreenHeight)
    {
        posY = gfx.ScreenWidth - height;
        veloY = -veloY;
    }
}

void Dodgeball::Draw(Graphics &gfx, Surface &s)
{
    gfx.DrawSprite(posX, posY, s, Colors::Magenta);   
}

bool Dodgeball::CollisionCheck(Player a)
{
    const float playerRight = a.posX + a.width;
    const float playerBottom = a.posY + a.height;
    const float ballRight = posX + width;
    const float ballBottom = posY + height;

    return
        playerRight >= posX &&
        a.posX <= ballRight &&
        playerBottom >= posY &&
        a.posY <= ballBottom;
}



