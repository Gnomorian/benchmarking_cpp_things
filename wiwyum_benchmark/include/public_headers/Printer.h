#pragma once
#include "dllexports.h"
#include <memory>

class ExportClass Printer
{
public:

};

ExportCppFunction std::unique_ptr<Printer> makeTestRunnerConsolePrinter();
ExportCppFunction std::unique_ptr<Printer> makeTestRunnerFilePrinter();