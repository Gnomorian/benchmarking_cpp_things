#include "Logger.h"
#include "BasicLogger.h"

namespace wiwyum
{
	std::filesystem::path getLogPath()
	{
		//TODO: create a real file.log path.
		return {};
	}
	ExportCppFunction std::unique_ptr<Logger>CALL_CONVENTION wiwyum::makeLogger()
	{
		const auto UseConsole{ true };
		return std::make_unique<BasicLogger>(getLogPath(), UseConsole);
	}
}