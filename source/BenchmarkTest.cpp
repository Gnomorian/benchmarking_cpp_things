#include "BenchmarkTest.h"
#include "RaiiTimer.h"

namespace wiwyum::benchmark
{
	timer::TimerResults BenchmarkTest::run()
	{
		timer::TimerResults results;
		{
			timer::RaiiTimer timer{ results };
			execute();
		}
		return results;
	}
	void BenchmarkTest::setup()
	{}
	void BenchmarkTest::teardown()
	{}
}