#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "amemory.h"

void start_console() {
    SetConsoleTitleA("No Death Effect by Doki");
    AllocConsole();
    FILE* f_dummy;
    freopen_s(&f_dummy, "CONIN$", "r", stdin);
    freopen_s(&f_dummy, "CONOUT$", "w", stderr);
    freopen_s(&f_dummy, "CONOUT$", "w", stdout);
    //this is so the progran can compile
    //with g++ ignore it

    //freopen("CONIN$", "r",  f_dummy);
    //freopen("CONOUT$", "w", f_dummy);
}

DWORD WINAPI thread(void* arg) {
    start_console();
    char nKey;
    std::cout << "Welcome to No Death Effect by Doki! This is my first GD Mod :)\nType N and then press Enter to enable No Death Effect\n";
    std::cin >> nKey;
    if (nKey == 'n') {
        std::cout << "No Death Effect Enabled!\n";
        amemory::write_bytes_protect((int)GetModuleHandleA(nullptr) + 0x1EFAA0, { 0xC3 });
    }
    else {
        std::cout << "Wrong key. Try again!\n";
    }
    system("pause>nul");
    return 0;
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)  // reserved
{
    if (fdwReason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, thread, nullptr, 0, 0);
    }
    return TRUE;
}
