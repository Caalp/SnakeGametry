#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::PerFrame()
{
	const auto oldTime = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> duration = last - oldTime;

	
	return duration.count();
}
