#pragma once
#include "BenchmarkTest.h"
#include <map>
#include <set>

namespace wiwyum::benchmark
{
	/// <summary>
	/// run a variable amount of <see cref="wiwyum::benchmark::BenchmarkTests">BenchmarkTests</see> for a set amount of <see cref="BenchmarkRunner::NumRuns">iterations</see>.
	/// </summary>
	class BenchmarkRunner
	{
		const std::uintmax_t NumRuns;
	public:
		using TimerResultsArray = std::vector<timer::TimerResults>;
		BenchmarkRunner(decltype(NumRuns) runs);
		BenchmarkRunner& addTest(BenchmarkTest& newTest);
	protected:
		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
		std::map<BenchmarkTest::TestId, TimerResultsArray> results;
	};
}