#pragma once
#include "dllexports.h"
#include "BenchmarkTest.h"
#include "BenchmarkTestComparitor.h"
#include <map>
#include <set>
#include "Logger.h"

namespace wiwyum::benchmark
{
	/// <summary>
	/// run a variable amount of <see cref="wiwyum::benchmark::BenchmarkTest">BenchmarkTests</see> for a set amount of iterations.
	/// </summary>
	class ExportClass BenchmarkRunner
	{
	public:
		using RunCountType = size_t;
		using TimerResultsArray = std::vector<timer::TimerResults>;
		/// <summary>
		/// Adds a <see cref="wiwyum::benchmark::BenchmarkTest">BenchmarkTest</see> to be run when you call run().
		/// </summary>
		/// <param name="newTest">the non-owning unique <see cref="wiwyum::benchmark::BenchmarkTest">BenchmarkTest</see></param>
		/// <returns>a reference to self</returns>
		virtual BenchmarkRunner& addTest(BenchmarkTest& newTest) = 0;
		/// <summary>
		/// run all the <see cRef="BenchmarkRunner::tests">tests</see> for the given <see cRef="BenchmarkRunner::NumRuns">number of runs</see>
		/// </summary>
		/// <returns>a map containing the timer results for each testid
		/// //TODO: change TimerResultsArray to a map of string,time_point containing the custom defined benchmark keys for each test incase someone wants total time and sub transaction times for instance.
		/// </returns>
		virtual std::map<BenchmarkTestId, TimerResultsArray> run() = 0;
	};
	
	/// <summary>
	/// Factory method to get the BenchmarkRunner.
	/// You cant export a class with non-exported members such as std library members, hence this function.
	/// </summary>
	/// <param name="numberOfRuns"></param>
	/// <returns></returns>
	ExportCppFunction std::unique_ptr<BenchmarkRunner> CALL_CONVENTION makeBenchmarkRunner(size_t numberOfRuns, Logger& logger);
}