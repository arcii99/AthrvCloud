//FormAI DATASET v1.0 Category: System boot optimizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate boot process
void boot() {
    printf("Booting system...\n");
    srand(time(NULL));
    int r = rand() % 5 + 1; // Random number between 1 and 5
    // Simulate different stages of the boot process
    for (int i=1; i<=r; i++) {
        printf("Stage %d...\n", i);
        sleep(1); // Wait for 1 second
    }
    printf("System boot complete!\n");
}

// Function to optimize system
void optimize() {
    printf("Optimizing system performance...\n");
    sleep(2); // Wait for 2 seconds
    printf("System optimization complete!\n");
}

// Main function
int main() {
    char input;
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("Press any key to begin boot process...\n");
    // Waits for user input to begin boot process
    scanf("%c", &input);
    boot(); // Initiates boot process
    printf("Press any key to optimize system performance...\n");
    // Waits for user input to begin optimization process
    scanf(" %c", &input);
    optimize(); // Initiates optimization process
    printf("Thank you for using the C System Boot Optimizer!\n");
    return 0;
}