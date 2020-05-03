#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
   
    for (int i = 0; i < numOfDodgeballs;i++)
    {
        dodgeballBallSpawner.push_back(Dodgeball(gfx.ScreenWidth,gfx.ScreenHeight,63,66,rd));
    }
}


void Game::MovePlayer()
{
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        dodger.posX = dodger.posX + 3;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        dodger.posX = dodger.posX - 3;
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        dodger.posY = dodger.posY + 3;
    }
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        dodger.posY = dodger.posY - 3;
    }
    
    if (dodger.posX < 0)
    {
        dodger.posX = 0;
    }
    if (dodger.posX + dodger.width >= gfx.ScreenWidth)
    {
        dodger.posX = gfx.ScreenWidth - 64;
    }
    if (dodger.posY < 0)
    {
        dodger.posY = 0;
    }
    if (dodger.posY + dodger.height >= gfx.ScreenHeight)
    {
        dodger.posY = gfx.ScreenHeight - dodger.height;
    }
}

void Game::WinCondition()
{
    if (game_counter==25)
    {
        gamewon = true;
    }
}

void Game::GameWon()
{
    gfx.DrawSprite(100, 100, winScreen,Colors::Magenta);
}

void Game::GameOver()
{
    gfx.DrawSprite(100, 100, endScreen);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    MovePlayer();
    WinCondition();
    
    
    for (Dodgeball d : dodgeballBallSpawner)
    {
        if (d.CollisionCheck(dodger))
        {
            d.Collided=true;
        }
    }
    for (Dodgeball d : dodgeballBallSpawner)
    {
        d.Movement(gfx);
    }
}

void Game::ComposeFrame()
{
    if (!gameStart)
    {
        gfx.DrawSprite(144, 350, startScreen,Colors::Magenta);
        if (wnd.kbd.KeyIsPressed(VK_RETURN))
        {
            gameStart = true;
        }
    }
    else
    {
        gfx.DrawSprite(dodger.posX, dodger.posY, player, Color(195, 195, 195));
        
        if (!gameover)
        {

            for (Dodgeball d : dodgeballBallSpawner)
            {
                if (!(d.Collided))
                {
                    d.Draw(gfx, ball);
                }
            }
        }
    }
}
