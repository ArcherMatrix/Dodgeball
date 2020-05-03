#pragma once
class Player
{
public:
	Player();
	Player(float x, float y,float w, float h);
	float posX;
	float posY;
	float width;
	float height;
	float vx;
	float vy;
	bool isHit = false;
private:
};