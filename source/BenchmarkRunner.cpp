#include "BenchmarkRunner.h"

namespace wiwyum::benchmark
{
	BenchmarkRunner::BenchmarkRunner(decltype(NumRuns) runs)
		: NumRuns{runs}
	{
		assertNumRunsNotZero();
	}
	BenchmarkRunner& BenchmarkRunner::addTest(BenchmarkTest& newTest)
	{
		tests.insert(&newTest);
		return *this;
	}
	std::map<BenchmarkTest::TestId, BenchmarkRunner::TimerResultsArray> BenchmarkRunner::run()
	{
		std::map<BenchmarkTest::TestId, TimerResultsArray> testResults;
		auto doTestForCount = [&testResults](BenchmarkTest* test, const auto count)
		{
			auto result{ test->run() };
			const auto[iterator, emplaced] {testResults.emplace(std::make_pair(test->myId, TimerResultsArray{ {result} }))};
			auto& resultsArray {iterator->second};
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
	void BenchmarkRunner::assertNumRunsNotZero() const
	{
		if (NumRuns == 0)
		{
			throw std::invalid_argument{ "BenchmarkRunner::NumRuns should not be 0." };
		}
	}
}