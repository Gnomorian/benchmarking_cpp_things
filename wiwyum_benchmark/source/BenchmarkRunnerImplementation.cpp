#include "BenchmarkRunnerImplementation.h"

namespace wiwyum::benchmark
{
	BenchmarkRunnerImplementation::BenchmarkRunnerImplementation(decltype(NumRuns) runs, decltype(logger) logger)
		: NumRuns{ runs }
		, logger{ logger }
	{
		assertNumRunsNotZero();
	}
	std::map<BenchmarkTestId, std::unique_ptr<TestResults>> BenchmarkRunnerImplementation::run()
	{
		std::map<BenchmarkTestId, std::unique_ptr<TestResults>> testResults;
		auto doTestForCount = [&testResults](BenchmarkTest* test, const auto count)
		{
			auto result{ test->run() };
			const auto [iterator, emplaced] {testResults.emplace(std::make_pair(test->myId, makeTestResults()))};
			auto& resultsArray{ iterator->second };
			for (size_t i{ 1 }; i < count; i++)
			{
				auto result{ test->run() };
				resultsArray->addTimePoint(result);
			}
		};
		logRunStart();
		for (auto& test : tests)
		{
			logTestRunStart(*test);
			doTestForCount(test, NumRuns);
			logTestRunEnd(*test);
		}
		logRunEnd();
		return testResults;
	}
	void BenchmarkRunnerImplementation::assertNumRunsNotZero() const
	{
		if (NumRuns == 0)
		{
			logger.critical(L"BenchmarkRunner::NumRuns should not be 0.");
			throw std::invalid_argument{ "BenchmarkRunner::NumRuns should not be 0." };
		}
	}
	BenchmarkRunner& BenchmarkRunnerImplementation::addTest(BenchmarkTest& newTest)
	{
		tests.insert(&newTest);
		return *this;
	}
	BenchmarkTestDescriptor BenchmarkRunnerImplementation::getTestDescriptorById(BenchmarkTestId id) const
	{
		const auto foundTest {
			[&]() -> BenchmarkTest*
			{
				for (const auto& test : tests)
				{
					if (test->myId == id)
					{
						return test;
					}
				}
				return nullptr;
			}()
		};

		if (foundTest == nullptr)
			throw std::invalid_argument{ "BenchmarkRunner does not have that test id" };

		return foundTest->description();
	}
	void BenchmarkRunnerImplementation::logRunStart()
	{
		std::wstringstream stream;
		stream << L"Running " << tests.size() << " tests " << NumRuns << " times." << std::endl
			<< "Tests to run:" << std::endl;
		for (auto& test : tests)
		{
			stream << L"\t" << test->description().Name << std::endl;
		}
		logger.info(stream.str());
	}
	void BenchmarkRunnerImplementation::logRunEnd()
	{
		logger.info(L"Benchmark runs completed.");
	}
	void BenchmarkRunnerImplementation::logTestRunStart(BenchmarkTest& test)
	{
		auto[name, description, author] { test.description() };
		std::wstringstream stream;
		stream << L"Starting Test:" << std::endl
			<< L"\t" << L"Name: " << name << std::endl
			<< L"\t" << L"Description: " << description << std::endl
			<< L"\t" << L"Author: " << author << std::endl;
		logger.info(stream.str());
	}
	void BenchmarkRunnerImplementation::logTestRunEnd(BenchmarkTest& test)
	{
		logger.infoArgs(L"Finished running ", test.description().Name);
	}
}