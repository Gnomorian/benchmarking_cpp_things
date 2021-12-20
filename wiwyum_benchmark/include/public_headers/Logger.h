#pragma once
#include "dllexports.h"
#include <memory>
#include <string>

namespace wiwyum
{
	class ExportClass Logger
	{
	public:
		virtual void info(const std::wstring& message) = 0;
		virtual void debug(const std::wstring& message) = 0;
		virtual void critical(const std::wstring& message) = 0;
	};

	ExportCppFunction std::unique_ptr<Logger> CALL_CONVENTION makeLogger();
}