//FormAI DATASET v1.0 Category: System boot optimizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program optimizes system boot time by randomly disabling startup programs

void disable_startup_programs() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num_programs = 10; // Choose how many startup programs there are
    int programs[num_programs]; // Create an array for each program's status
    int num_disabled = 0; // Initialize the number of disabled programs to 0

    // Loop through each program and randomly disable some of them
    for (int i = 0; i < num_programs; i++) {
        programs[i] = rand() % 2; // 0 is disabled, 1 is enabled
        if (programs[i] == 0) {
            num_disabled++;
        }
    }

    // Print out the results
    printf("*************** System Boot Optimizer ***************\n");
    printf("Number of startup programs: %d\n", num_programs);
    printf("Number of programs disabled: %d\n", num_disabled);
    printf("Disabled programs: ");
    for (int i = 0; i < num_programs; i++) {
        if (programs[i] == 0) {
            printf("%d ", i+1);
        }
    }
    printf("\n");

    // Exit the program
    exit(0);
}

int main() {
    disable_startup_programs();
    return 0;
}