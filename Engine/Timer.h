#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	float Set();
private:
	std::chrono::steady_clock::time_point last;
};