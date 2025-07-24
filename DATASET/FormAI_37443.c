//FormAI DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to System Boot Optimizer!\n\n");
    srand(time(NULL)); // Seed the random number generator with current time

    // Generate random boot optimizer values
    int numCores = rand() % 4 + 1; // Random number between 1-4 for number of CPU cores
    int bootTime = rand() % 20 + 10; // Random number between 10-29 for boot time in seconds
    float ramSpeed = ((float) rand() / RAND_MAX) * 2 + 1; // Random float between 1-3 for RAM speed multiplier

    // Display generated values
    printf("Number of CPU cores: %d\n", numCores);
    printf("Boot time: %d seconds\n", bootTime);
    printf("RAM speed multiplier: %.2f\n", ramSpeed);

    // Calculate overall system performance score
    float performanceScore = (numCores * 10) / (float) bootTime * ramSpeed;
    printf("\nOverall system performance score: %.2f\n", performanceScore);

    // Check if system needs optimization based on performance score
    if (performanceScore < 20) {
        printf("System performance is poor. Optimization strongly recommended.\n");
    } else if (performanceScore < 40) {
        printf("System performance is below average. Optimization recommended.\n");
    } else if (performanceScore < 60) {
        printf("System performance is average. Optimization may be needed.\n");
    } else {
        printf("System performance is good. Optimization may not be necessary.\n");
    }

    // End program
    printf("\nThank you for using System Boot Optimizer.\n");

    return 0;
}