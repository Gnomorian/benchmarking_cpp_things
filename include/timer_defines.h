#pragma once
#include <chrono>

namespace wiwyum::timer
{
	using Clock = std::chrono::steady_clock;
	using ClockDuration = Clock::duration;
	using ClockTimePoint = Clock::time_point;
}