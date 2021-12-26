#include "BenchmarkRunner.h"
#include "BenchmarkRunnerImplementation.h"

namespace wiwyum::benchmark
{
	std::unique_ptr<BenchmarkRunner> CALL_CONVENTION makeBenchmarkRunner(size_t numberOfRuns, Logger& logger)
	{
		return std::make_unique<BenchmarkRunnerImplementation>(numberOfRuns, logger);
	}
}