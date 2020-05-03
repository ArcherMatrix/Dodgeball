#include "Graphics.h"
#include "Colors.h"
#include "Player.h"
#include <random>

class Dodgeball
{
public:
	Dodgeball();
	Dodgeball(float x,float y, float w, float h, std::random_device& rd);
	Dodgeball(float x, float y, float w, float h, float veloX,float VeloY);
	~Dodgeball();
	void Movement(Graphics& gfx);
	void Draw(Graphics& gfx, Surface& s);
	bool CollisionCheck(Player a);
	float posX;
	float posY;
	float width;
	float height;
	float veloX;
	float veloY;
	bool Collided = false;

private:
	std::mt19937 rng;				
	std::uniform_real_distribution<float> xDist;	
	std::uniform_real_distribution<float> yDist;	
	std::uniform_real_distribution<float> yVel;	
	std::uniform_real_distribution<float> xVel;	
};
