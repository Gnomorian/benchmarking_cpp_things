#include <iostream>
#include <string>
#include "common.h"
#include "BenchmarkTest.h"
#include "BenchmarkRunner.h"
#include <thread>
#include <valarray>
#include <Logger.h>

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

constexpr auto average = [](auto valarray)
{
	auto sumOfValues{valarray.sum()};
	return sumOfValues / valarray.size();
};

void printResults(auto map)
{
	for (auto [testId, results] : map)
	{
		std::wcout << "TestId: " << testId << std::endl;
		std::vector<wiwyum::timer::ClockDuration> totals;
		for (auto& result : results)
		{
			totals.push_back(result.duration());
		}
		std::valarray<wiwyum::timer::ClockDuration> valArray{ &totals[0], totals.size() };
		std::wcout << "\t" << "Max Time: " << valArray.max() << std::endl
			<< "\tMin Time : " << valArray.min() << std::endl
			<< "\tAverage: " << average(valArray) << std::endl;
	}
}

int wmain(int argc, wchar_t* args[])
{
	auto testRunner{ wiwyum::benchmark::makeBenchmarkRunner(10) };
	DummySleepTest test1{std::chrono::milliseconds{5}};
	DummySleepTest test2{ std::chrono::milliseconds{10} };
	const auto results{ testRunner->addTest(test1).addTest(test2).run() };
	printResults(results);

	wiwyum::makeLogger()->infoArgs(L"some message", "blah");
}