#include "BenchmarkRunner.h"
#include "BenchmarkRunnerImplementation.h"

namespace wiwyum::benchmark
{
	std::unique_ptr<BenchmarkRunner> CALL_CONVENTION makeBenchmarkRunner(size_t numberOfRuns)
	{
		return std::make_unique<BenchmarkRunnerImplementation>(numberOfRuns);
	}
}