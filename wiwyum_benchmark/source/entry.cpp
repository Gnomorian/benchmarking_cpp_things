#include <Windows.h>
#include <iostream>

// the return code of DllMain is ignored for all calls except for Process Attach.
// application terminates or LoadLibrary() returns null on false.
using SuccessfullyAttached = bool;

SuccessfullyAttached onProcessAttach(HINSTANCE thisDllHandle)
{
    return true;
}

void onProcessDetach(HINSTANCE thisDllHandle)
{}

void onThreadAttach(HINSTANCE thisDllHandle)
{}

void onThreadDetach(HINSTANCE thisDllHandle)
{}

BOOL WINAPI DllMain(
    HINSTANCE   hinstDLL,       // handle to DLL module
    DWORD       callReason,     // reason for calling function
    LPVOID      lpReserved)     // reserved
{
    bool result{ true };
    switch (callReason)
    {
    case DLL_PROCESS_ATTACH:
        result = onProcessAttach(hinstDLL);
        break;
    case DLL_PROCESS_DETACH:
        onProcessDetach(hinstDLL);
        break;
    case DLL_THREAD_ATTACH:
        onThreadAttach(hinstDLL);
        break;
    case DLL_THREAD_DETACH:
        onThreadDetach(hinstDLL);
        break;
    }
    return result;
}