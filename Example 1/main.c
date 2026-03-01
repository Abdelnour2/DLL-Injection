#include <windows.h>
#include <stdio.h>

int main() {
    printf("--- Target Process Running (PID: %d) ---\n", GetCurrentProcessId());
    printf("Welcome to the Secure Program! Try Attacking Me\n\n");

    while(1) {
        printf("Waitng for something to happen...\n");
        Sleep(2000);
    }
    return 0;
}