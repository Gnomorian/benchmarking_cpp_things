#include "BenchmarkRunner.h"

namespace wiwyum::benchmark
{
	BenchmarkRunner::BenchmarkRunner(decltype(NumRuns) runs)
		: NumRuns{runs}
	{}
	BenchmarkRunner& BenchmarkRunner::addTest(BenchmarkTest& newTest)
	{
		return *this;
	}
}