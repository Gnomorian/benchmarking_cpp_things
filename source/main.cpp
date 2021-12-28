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
	DummySleepTest(std::chrono::milliseconds sleepFor, wiwyum::Logger& logger)
		: SleepFor{sleepFor}
	{
		setLogger(logger);
	}
	// Inherited via BenchmarkTest
	virtual void execute() override
	{
		logger.get().debugArgs(L"sleeping for ", SleepFor);
		std::this_thread::sleep_for(SleepFor);
	}
};

void printResults(const auto& map)
{
	for (const auto& pair : map)
	{
		std::wcout << "TestId: " << pair.first << std::endl;
		std::wcout << L"\tMin: " << pair.second->min() << std::endl
			<< L"\tMax: " << pair.second->max() << std::endl
			<< L"\tAverage: " << pair.second->average() << std::endl;
	}
}

int wmain(int argc, wchar_t* args[])
{
	auto logger{ wiwyum::makeLogger() };
	auto testRunner{ wiwyum::benchmark::makeBenchmarkRunner(10, *logger) };
	DummySleepTest test1{std::chrono::milliseconds{5}, *logger.get()};
	DummySleepTest test2{ std::chrono::milliseconds{10}, *logger.get()};
	const auto results{ testRunner->addTest(test1).addTest(test2).run() };
	printResults(results);
}