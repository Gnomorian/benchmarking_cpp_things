#pragma once
#include "BenchmarkTest.h"

namespace wiwyum::benchmark
{
	/// <summary>
	/// run a variable amount of <see cref="wiwyum::benchmark::BenchmarkTests">BenchmarkTests</see> for a set amount of <see cref="BenchmarkRunner::NumRuns">iterations</see>.
	/// </summary>
	class BenchmarkRunner
	{
		const std::uintmax_t NumRuns;
	public:
		BenchmarkRunner(decltype(NumRuns) runs);
		BenchmarkRunner& addTest(BenchmarkTest& newTest);
	};
}