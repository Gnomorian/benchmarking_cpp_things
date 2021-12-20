#pragma once
#include "dllexports.h"
#include <memory>

class ExportClass SomeClass
{
public:
	virtual void helloWorld() const = 0;
};

ExportCppFunction std::unique_ptr<SomeClass> CALL_CONVENTION makeSomeClass();