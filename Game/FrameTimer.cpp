#include "FrameTimer.h"
#include "include/Lib.h"

namespace gnGame {

	FrameTimer::FrameTimer()
		: frameTime(0.0f)
	{
	}

	void FrameTimer::update()
	{
		frameTime += Time::deltaTime();
	}

	void FrameTimer::reset()
	{
		frameTime = 0.0f;
	}

	const bool FrameTimer::isTimeUp(float _time)
	{
		return frameTime >= _time;
	}

	const float FrameTimer::getFrameTime()
	{
		return frameTime;
	}

}