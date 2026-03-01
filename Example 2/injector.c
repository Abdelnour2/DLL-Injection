#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Run: injector.exe <PID>\n");
        return 1;
    }

    DWORD pid = atoi(argv[1]);
    const char* dllPath = "C:\\Users\\Abdel nour Ayoubi\\Documents\\VS Code Projects\\C\\DLL Injection Practice\\2\\dll\\cheat.dll";

    // Step 1: Open the target process
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        printf("Failed to open process!\n");
        return 1;
    }

    // Step 2: Allocate memory in the target for the DLL path string
    LPVOID pRemoteCode = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT, PAGE_READWRITE);

    // Step 3: Write the DLL path into that allocated space
    WriteProcessMemory(hProcess, pRemoteCode, dllPath, strlen(dllPath) + 1, NULL);

    // Step 4: Find LoadLibraryA address and start a remote thread
    PVOID pLoadLibrary = (PVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pLoadLibrary, pRemoteCode, 0, NULL);

    if (hThread) {
        printf("Injection completed! Check the victim process.\n");
        CloseHandle(hThread);
    }

    CloseHandle(hProcess);
    return 0;
}