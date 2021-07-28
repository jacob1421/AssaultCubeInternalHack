// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include "PlayerEntity.h"
#include "Offsets.h"
#include <stdio.h>

using namespace std;

//Globals variables
PlayerEntity* local_player_ptr;
PlayerEntity* players_ptr[MAX_LOBBY_SIZE];

FILE* fConsoleOut;

DWORD WINAPI read_player_data(__in LPVOID lpParam){
    //Cast the local player pointer to a PlayerEntity pointer and set the local_player pointer
    local_player_ptr = (PlayerEntity*)(*(DWORD*)(local_player_offset));
    //for (int i = 0; i < MAX_LOBBY_SIZE; i++) {
    //    players_ptr[i] = (PlayerEntity*)(*(DWORD*)(*(DWORD*)entity_list_offset) + (i * 4));
    //}

    Sleep(10);
    return 0;
}

DWORD WINAPI main_thread(HINSTANCE hModule) {
    while (true) {
        if (GetAsyncKeyState(VK_F7)) {
            printf("Injection Removed\n");
            break;
        }
        if (GetAsyncKeyState(VK_F6)) {
            local_player_ptr->toString();
            Sleep(100);
        }
    }
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call){
        case DLL_PROCESS_ATTACH:
            AllocConsole();
            freopen_s(&fConsoleOut, "CONOUT$", "w", stdout);
            printf("Injected!\n");
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main_thread, 0, 0, 0);
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)read_player_data, 0, 0, 0);
        break;
        case DLL_THREAD_ATTACH:

        break;
        case DLL_THREAD_DETACH:

        break;
        case DLL_PROCESS_DETACH:
           
        break;
    }
    return TRUE;
}

