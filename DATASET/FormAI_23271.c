//FormAI DATASET v1.0 Category: System boot optimizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int boot_time;
    int startup_prog_count;
    float avg_startup_time = 0;
    float total_startup_time = 0;

    // Welcome message
    printf("Welcome to the System Boot Optimizer!\n");

    // Get user input for boot time
    printf("Please enter the current boot time in seconds: ");
    scanf("%d", &boot_time);

    // Get user input for startup program count
    printf("How many startup programs do you have? ");
    scanf("%d", &startup_prog_count);

    // Calculate average startup time
    for (int i = 0; i < startup_prog_count; i++) {
        int startup_time = rand() % 10 + 1; // Random startup time between 1-10 seconds
        total_startup_time += startup_time;
        printf("Startup Program %d took %d seconds to load.\n", i+1, startup_time);
    }
    avg_startup_time = total_startup_time / startup_prog_count;

    // Calculate new boot time with optimized program startup
    float new_boot_time = boot_time - avg_startup_time;
    printf("\nWith our optimizer, your new boot time is %.2f seconds!\n", new_boot_time);

    return 0;
}