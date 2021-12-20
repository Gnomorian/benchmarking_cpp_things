#include <iostream>
#include <string>
#include "common.h"
#include "BenchmarkTest.h"
#include "BenchmarkRunner.h"
#include <thread>

class DummySleepTest : public wiwyum::benchmark::BenchmarkTest
{
	std::chrono::milliseconds SleepFor;
public:
	DummySleepTest(std::chrono::milliseconds sleepFor)
		: SleepFor{sleepFor}
	{}
	// Inherited via BenchmarkTest
	virtual void execute() override
	{
		std::this_thread::sleep_for(SleepFor);
	}
};

int wmain(int argc, wchar_t* args[])
{
	wiwyum::benchmark::BenchmarkRunner testRunner{ 1000 };
	DummySleepTest test1{std::chrono::milliseconds{5}};
	DummySleepTest test2{ std::chrono::milliseconds{10} };
	const auto results{ testRunner.addTest(test1).addTest(test2).run() };
}