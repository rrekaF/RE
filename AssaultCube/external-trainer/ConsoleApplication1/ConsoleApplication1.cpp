// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "proc.h"
#include <cstring> // For strlen
#include <cwchar> // For mbstowcs

// Function to convert char* to wchar_t*
static const wchar_t* ConvertCharToWChar(const char* c) {
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    size_t convertedChars = 0;
    mbstowcs_s(&convertedChars, wc, cSize, c, _TRUNCATE);
    return wc;
}
int main()
{
    const wchar_t* name = ConvertCharToWChar("ac_client.exe");
    DWORD procId = GetProcId(name);

    uintptr_t modAddr = GetModuleBaseAddress(procId, name);

    HANDLE hProcess = 0;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);


    delete[] name;

    return 0;
}

