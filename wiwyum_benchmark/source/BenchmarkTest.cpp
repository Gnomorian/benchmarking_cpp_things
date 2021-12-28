#include "BenchmarkTest.h"
#include "RaiiTimer.h"
#include "BenchmarkTestId.h"

namespace wiwyum::benchmark
{
	class NullLogger : public Logger
	{
	public:
		virtual void info(const std::wstring& message) override {}
		virtual void debug(const std::wstring& message) override {}
		virtual void critical(const std::wstring& message) override {}
	}nullLogger;

	BenchmarkTest::BenchmarkTest()
		: myId{generateBenchmarkTestId() }
		, logger{nullLogger}
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
				: BenchmarkTestDescriptor{L"Default Test", L"Default benchmark test description", L"William Cameron"}
			{}
		};
		return DefaultDescription{};
	}
	bool BenchmarkTest::operator<(BenchmarkTest& right) const
	{
		return myId < right.myId;
	}
	void BenchmarkTest::setLogger(Logger& newLogger)
	{
		logger = newLogger;
	}
}