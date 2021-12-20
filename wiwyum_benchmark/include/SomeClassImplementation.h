#pragma once
#include "SomeClass.h"
// this header is not visible to other projects, as intended.

class SomeClassImplementation : public SomeClass
{
public:
	// Inherited via SomeClass
	virtual void helloWorld() const override;

};