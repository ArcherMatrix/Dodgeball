#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Dodgeball.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
    /********************************/
	/*  User Functions              */
    void MovePlayer();
    void WinCondition();
    void GameWon();
    void GameOver();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
    std::mt19937 rng;
    std::uniform_real_distribution<float> xDist;
    std::uniform_real_distribution<float> yDist;
    std::uniform_real_distribution<float> yVel;
    std::uniform_real_distribution<float> xVel;
    std::random_device rd;
	/********************************/
	/*  User Variables              */
    Player dodger = Player(400,400,32,32);
    Surface player = Surface("player.bmp");
    Surface ball = Surface("Dodgeball.bmp");
    Surface startScreen = Surface("start.bmp");
    Surface winScreen = Surface("victory2.bmp");
    Surface endScreen = Surface("gameover.bmp");
    

    std::vector<Dodgeball> dodgeballBallSpawner;
    Dodgeball test = Dodgeball(600,600,63,67,1,1);
    int numOfDodgeballs = 0;
    bool gameStart = false;
    bool gameover = false;
    bool gamewon = false;
    int game_counter = 0;
	/********************************/
};