#pragma once
#include "BenchmarkTest.h"
#include "BenchmarkTestComparitor.h"
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
		/// <summary>
		/// Adds a <see cref="wiwyum::benchmark::BenchmarkTest">BenchmarkTest</see> to be run when you call run().
		/// </summary>
		/// <param name="newTest">the non-owning unique <see cref="wiwyum::benchmark::BenchmarkTest">BenchmarkTest</see></param>
		/// <returns>a reference to self</returns>
		BenchmarkRunner& addTest(BenchmarkTest& newTest);
	protected:
		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
		std::map<BenchmarkTest::TestId, TimerResultsArray> results;
	};
}