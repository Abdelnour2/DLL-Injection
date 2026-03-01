#include <windows.h>
#include <stdio.h>

// This function will run in a separate thread inside the game
DWORD WINAPI CheatThread(LPVOID lpParam) {
    // HARDCODED ADDRESSES (Copy these from the victim's output for this test)
    // In a real hack, you'd find these using 'Pattern Scanning' or 'Offsets'
    int* hp_ptr = (int*)0x00007ff78a97a010; // Replace with Health address
    float* x_ptr = (float*)0x00007ff78a97a014; // Replace with X address
    float* y_ptr = (float*)0x00007ff78a97a018; // Replace with Y address

    // Give the user a moment to see the injection
    MessageBoxA(NULL, "Cheat Loaded! Press OK to God Mode.", "Cheat", MB_OK);

    // Write directly to memory!
    if (hp_ptr) *hp_ptr = 999999;
    if (x_ptr)  *x_ptr  = 1337.0f;
    if (y_ptr)  *y_ptr  = 1337.0f;

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        // Create a thread so we don't 'freeze' the game's main thread
        CreateThread(NULL, 0, CheatThread, NULL, 0, NULL);
    }
    return TRUE;
}