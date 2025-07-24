//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock(); // gets the current clock ticks
    while (clock() < start_time + seconds * CLOCKS_PER_SEC); // waits for specified number of ticks
}

int main() {
    printf("Welcome to the C System Boot Optimizer\n");
    printf("This program will randomly optimize your boot process\n");
    printf("Press any key to begin...\n");
    getchar(); // waits for user to press a key
    
    srand(time(NULL)); // initializes random seed based on current time
    int total_iterations = rand() % 10 + 10; // randomly chooses number of iterations
    
    printf("Optimizing...\n");
    for (int i = 0; i < total_iterations; i++) {
        int step = rand() % 3; // randomly chooses optimization step
        switch (step) {
            case 0:
                printf("Clearing cache...\n");
                delay(1);
                break;
            case 1:
                printf("Defragmenting hard drive...\n");
                delay(2);
                break;
            case 2:
                printf("Updating system drivers...\n");
                delay(3);
                break;
            default:
                printf("Error: invalid optimization step chosen\n");
        }
    }
    
    printf("Boot optimization complete!\n");
    printf("Press any key to exit...\n");
    getchar(); // waits for user to press a key
    return 0;
}