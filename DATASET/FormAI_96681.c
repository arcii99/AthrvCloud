//FormAI DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BOOT_TIME 10
#define OPTIMIZATION_TIME 5

/* Function declarations */
void boot();
void optimize();
void cleanUp();

int main() {
    printf("\nC System Boot Optimizer!\n\n");
    printf("Starting boot process...\n\n");
    boot();
    printf("\nBoot complete. Starting optimization process...\n\n");
    optimize();
    printf("\nOptimization complete. Cleaning up...\n\n");
    cleanUp();
    printf("Program terminated. Have a good day!\n\n");
    return 0;
}

/**
 * Simulates the boot process of a system
 */
void boot() {
    srand(time(0)); // Setting random seed
    int i, p;
    for(i=1; i<=BOOT_TIME; i++) {
        // Randomly generated progress percentage
        p = (rand() % 30) + 70;
        printf("Boot in progress...%d%%\n", p);
        sleep(1);
    }
    printf("\nBoot successful.\n");
}

/**
 * Simulates the optimization process of a system
 */
void optimize() {
    srand(time(0)); // Setting random seed
    int i, p;
    for(i=1; i<=OPTIMIZATION_TIME; i++) {
        // Randomly generated progress percentage
        p = (rand() % 30) + 70;
        printf("Optimizing...%d%%\n", p);
        sleep(1);
    }
    printf("\nOptimization successful.\n");
}

/**
 * Cleans up any resources used during the program execution
 */
void cleanUp() {
    // Adding clean up code if necessary
    printf("Cleaning up resources...\n");
}