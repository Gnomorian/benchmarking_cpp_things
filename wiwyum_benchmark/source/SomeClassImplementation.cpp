#include "SomeClassImplementation.h"
#include <iostream>

void SomeClassImplementation::helloWorld() const
{
	std::wcout << __FUNCTIONW__": Hello, World! I'm a hidden virtual implementation of an exported class! ";
}

ExportCppFunction std::unique_ptr<SomeClass> CALL_CONVENTION makeSomeClass()
{
	return std::make_unique<SomeClassImplementation>();
}