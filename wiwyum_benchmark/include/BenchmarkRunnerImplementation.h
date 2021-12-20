#pragma once
#include "BenchmarkRunner.h"

namespace wiwyum::benchmark
{
	class BenchmarkRunnerImplementation : public BenchmarkRunner
	{
		const std::uintmax_t NumRuns;
	public:
		BenchmarkRunnerImplementation(decltype(NumRuns) runs);
		virtual std::map<BenchmarkTestId, BenchmarkRunner::TimerResultsArray> run() override;
		virtual BenchmarkRunner& addTest(BenchmarkTest& newTest) override;
	private:
		virtual void assertNumRunsNotZero() const;
		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
	};
}