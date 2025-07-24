//FormAI DATASET v1.0 Category: System boot optimizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int miliseconds = 1000 * seconds;
    clock_t start_time = clock();

    while (clock() < start_time + miliseconds) {

    }
}

int main() {
    printf("Welcome to the System Boot Optimizer!\n");
    printf("Initializing startup sequence...\n\n");

    delay(3);

    printf("Checking for system updates...\n");
    delay(2);

    printf("Optimizing system performance...\n");
    delay(2);

    printf("Clearing cache and memory...\n");
    delay(2);

    printf("Scanning disk for errors...\n");
    delay(3);

    printf("Defragmenting disk...\n");
    delay(3);

    printf("Checking for unwanted startup programs...\n");
    delay(2);

    printf("Cleaning registry...\n");
    delay(2);

    printf("Optimizing BIOS settings...\n");
    delay(2);

    printf("Finalizing optimization settings...\n\n");
    delay(3);

    printf("Complete! Your system is now optimized for performance!\n");
    return 0;
}