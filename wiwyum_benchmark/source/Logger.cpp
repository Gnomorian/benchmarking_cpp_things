#include "Logger.h"
#include "BasicLogger.h"
#include <Windows.h>
#include <array>

namespace wiwyum
{
	std::filesystem::path getLogPath()
	{
		constexpr auto getExeFileName = [](wchar_t* pStr, const size_t strLen, size_t& actualSize) -> bool
		{
			constexpr HMODULE ExeModule{ nullptr };
			const auto result{ GetModuleFileNameW(ExeModule, pStr, static_cast<DWORD>(strLen)) };
			actualSize = static_cast<size_t>(result);
			return result != strLen;
		};
		constexpr auto makeLogPath = [](auto stringView)
		{
			return std::filesystem::path{ stringView }.replace_extension(L".log");
		};

		std::array<wchar_t, MAX_PATH> moduleNameDefaultBuffer{};
		size_t actualSize{ 0 };
		if (getExeFileName(moduleNameDefaultBuffer.data(), moduleNameDefaultBuffer.size(), actualSize))
		{
			return makeLogPath(std::wstring_view{ moduleNameDefaultBuffer.data(), actualSize });
		}
		constexpr auto growthInterval{ 1.5 };
		std::vector<wchar_t> growablePathBuffer( static_cast<size_t>(moduleNameDefaultBuffer.size() * growthInterval), L'\0');
		while (!getExeFileName(growablePathBuffer.data(), growablePathBuffer.size(), actualSize))
		{
			growablePathBuffer.resize(static_cast<size_t>(growablePathBuffer.size() * growthInterval));
		}

		return makeLogPath(std::wstring_view{growablePathBuffer.data(), actualSize});
	}
	ExportCppFunction std::unique_ptr<Logger>CALL_CONVENTION wiwyum::makeLogger()
	{
		const auto UseConsole{ true };
		return std::make_unique<BasicLogger>(getLogPath(), UseConsole);
	}
}