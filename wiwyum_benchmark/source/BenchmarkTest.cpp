#include "BenchmarkTest.h"
#include "RaiiTimer.h"
#include "BenchmarkTestId.h"

namespace wiwyum::benchmark
{
	BenchmarkTest::BenchmarkTest()
		: myId{generateBenchmarkTestId() }
	{}

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
	BenchmarkTestDescriptor BenchmarkTest::description() const
	{
		struct DefaultDescription : BenchmarkTestDescriptor
		{
			DefaultDescription()
				: BenchmarkTestDescriptor{L"Default benchmark test description", L"William Cameron"}
			{}
		};
		return DefaultDescription{};
	}
	bool BenchmarkTest::operator<(BenchmarkTest& right) const
	{
		return myId < right.myId;
	}
}