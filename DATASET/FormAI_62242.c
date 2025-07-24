//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Define boot optimization variables
    int boot_time = 60; // in seconds
    int num_startup_programs = 5;
    int *startup_time = malloc(num_startup_programs * sizeof(int));
    printf("Enter the time taken by each startup program in seconds:\n");
    for (int i = 0; i < num_startup_programs; i++) {
        scanf("%d", &startup_time[i]);
    }

    // Calculate total time taken by all startup programs
    int total_startup_time = 0;
    for (int i = 0; i < num_startup_programs; i++) {
        total_startup_time += startup_time[i];
    }

    // Calculate optimal boot time by subtracting startup program time from boot time
    int optimal_boot_time = boot_time - total_startup_time;
    printf("\nOptimal boot time: %d seconds\n", optimal_boot_time);

    // Free memory allocated to startup_time array
    free(startup_time);

    return 0;
}