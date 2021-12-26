#include "BenchmarkRunnerImplementation.h"

namespace wiwyum::benchmark
{
	BenchmarkRunnerImplementation::BenchmarkRunnerImplementation(decltype(NumRuns) runs, decltype(logger) logger)
		: NumRuns{ runs }
		, logger{ logger }
	{
		assertNumRunsNotZero();
	}
	std::map<BenchmarkTestId, BenchmarkRunner::TimerResultsArray> BenchmarkRunnerImplementation::run()
	{
		std::map<BenchmarkTestId, TimerResultsArray> testResults;
		auto doTestForCount = [&testResults](BenchmarkTest* test, const auto count)
		{
			auto result{ test->run() };
			const auto [iterator, emplaced] {testResults.emplace(std::make_pair(test->myId, TimerResultsArray{ {result} }))};
			auto& resultsArray{ iterator->second };
			for (size_t i{ 1 }; i < count; i++)
			{
				auto result{ test->run() };
				resultsArray.push_back(result);
			}
		};
		for (auto& test : tests)
		{
			doTestForCount(test, NumRuns);
		}
		return testResults;
	}
	void BenchmarkRunnerImplementation::assertNumRunsNotZero() const
	{
		if (NumRuns == 0)
		{
			throw std::invalid_argument{ "BenchmarkRunner::NumRuns should not be 0." };
		}
	}
	BenchmarkRunner& BenchmarkRunnerImplementation::addTest(BenchmarkTest& newTest)
	{
		tests.insert(&newTest);
		return *this;
	}
}