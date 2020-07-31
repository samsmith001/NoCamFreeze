// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

void PatchGame()
{
    // Don't do anything until the game reports it has loaded to a certain stage //
    while(*(int*)0xC8D4C0 < 9)
        Sleep(10);

     // On foot mouse camera //
    memset((void*)0x523F4F, 0x0A, 1); // Vertical
    memset((void*)0x524036, 0x0A, 1); // Horizontal

    // In vehicle mouse camera //
    memset((void*)0x525629, 0x0A, 1); 

    // CPad::GetLookLeft //
    memset((void*)0x53FDD3, 0x0A, 1);
    // CPad::GetLookRight //
    memset((void*)0x53FE13, 0x0A, 1);
    // CPad::GetLookBehindForCar //
    memset((void*)0x53FE73, 0x0A, 1);
    // CPad::GetLookBehindForPed //
    memset((void*)0x5EFEC3, 0x0A, 1);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PatchGame, NULL, 0, 0);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

