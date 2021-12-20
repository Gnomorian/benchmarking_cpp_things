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
		virtual BenchmarkRunner& addTest(BenchmarkTest& newTest);
		/// <summary>
		/// run all the <see cRef="BenchmarkRunner::tests">tests</see> for the given <see cRef="BenchmarkRunner::NumRuns">number of runs</see>
		/// </summary>
		/// <returns>a map containing the timer results for each testid
		/// //TODO: change TimerResultsArray to a map of string,time_point containing the custom defined benchmark keys for each test incase someone wants total time and sub transaction times for instance.
		/// </returns>
		virtual std::map<BenchmarkTest::TestId, TimerResultsArray> run();
	protected:
		virtual void assertNumRunsNotZero() const;

		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
	};
}