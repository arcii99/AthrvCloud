//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
// Welcome to the ultimate drone remote control program!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int altitude = 0; // Our drone starts at ground level
    int battery_life = 100; // Fully charged!
    srand(time(NULL)); // Seed random generator
    
    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Use the arrow keys to control the drone:\n");
    printf("Up arrow: increase altitude\n");
    printf("Down arrow: decrease altitude\n");
    printf("Right arrow: move right\n");
    printf("Left arrow: move left\n");
    printf("Press 'q' to quit.\n");
    
    // Main loop to read user input
    while (1) {
        char input = getchar(); // Read single character input
        fflush(stdin); // Clear input buffer
        switch (input) {
            case 'q':
            printf("Goodbye! Drone returning to base.\n");
            return 0;
            case 'U':
            case 'u':
            altitude += 10; // Increase altitude by 10
            printf("Altitude increased to %d feet.\n", altitude);
            break;
            case 'D':
            case 'd':
            altitude -= 10; // Decrease altitude by 10
            printf("Altitude decreased to %d feet.\n", altitude);
            break;
            case 'R':
            case 'r':
            printf("Drone moved right.\n");
            break;
            case 'L':
            case 'l':
            printf("Drone moved left.\n");
            break;
            default:
            printf("Invalid input. Please use arrow keys to control drone or 'q' to quit.\n");
        }
        // Randomly decrease battery life by 1-5%
        int battery_drop = rand() % 5 + 1; 
        battery_life -= battery_drop;
        if (battery_life <= 0) {
            printf("Battery exhausted! Drone returning to base.\n");
            return 0;
        }
        // Print current battery life
        printf("Battery life remaining: %d%%\n", battery_life);
    }
    return 0;
}