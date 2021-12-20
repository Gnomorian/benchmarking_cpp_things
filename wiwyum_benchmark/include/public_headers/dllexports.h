#pragma once

#ifdef DLL_EXPORT_GNOMORIAN
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllimport)
#endif // DLL_EXPORT_GNOMORIAN


#define CALL_CONVENTION _stdcall

// define an exported c function like so:
// ExportCFunction void CALL_CONVENTION myFunction();
// these have the benefit of not being name mangles, so you can easily refer to them
// by name with LoadLibrary()
#define ExportCFunction extern "C" DllExport

// define an exported c++ function like so:
// ExportCppFunction void CALL_CONVENTION myFunction();
// These have the benefit of being able to use C++ datatypes in the parameters.
// best have these defined in your public headers.
#define ExportCppFunction extern "C++" DllExport

// an example of exporting a class is in SomeClass.(h|cpp). The useage of it is in the example_using_dll project.
// its an example of a public interface and a factory function getting the concrete class.
#define ExportClass DllExport