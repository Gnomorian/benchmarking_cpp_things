#pragma once
#include "BenchmarkRunner.h"
#include "Logger.h"

namespace wiwyum::benchmark
{
	class BenchmarkRunnerImplementation : public BenchmarkRunner
	{
		const std::uintmax_t NumRuns;
		Logger& logger;
	public:
		BenchmarkRunnerImplementation(decltype(NumRuns) runs, decltype(logger) logger);
		virtual std::map<BenchmarkTestId, BenchmarkRunner::TimerResultsArray> run() override;
		virtual BenchmarkRunner& addTest(BenchmarkTest& newTest) override;
	private:
		virtual void assertNumRunsNotZero() const;
		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
	};
}