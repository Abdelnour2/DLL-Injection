#include <windows.h>
#include <stdio.h>

int player_health = 100;
float x_coord = 10.0f;
float y_coord = 20.0f;

int main() {
    printf("--- Simple Game Engine (PID: %d) ---\n", GetCurrentProcessId());
    
    // We print the addresses so you don't have to hunt for them yet!
    printf("Memory Locations:\n");
    printf("  Health: %p\n", (void*)&player_health);
    printf("  Coords: %p, %p\n", (void*)&x_coord, (void*)&y_coord);
    printf("------------------------------------\n");

    while(1) {
        printf("[GAME] HP: %d | Pos: (%.1f, %.1f)\n", player_health, x_coord, y_coord);
        Sleep(2000);
    }
    return 0;
}