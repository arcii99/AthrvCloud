//FormAI DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_BOOT_TIME 10000
#define MIN_BOOT_TIME 100

int main() {
    int i, j, k, temp;
    int boot_times[MAX_PROCESSES];
    int total_boot_time = 0;
    float avg_boot_time;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random boot times for system processes
    for (i = 0; i < MAX_PROCESSES; i++) {
        boot_times[i] = (rand() % (MAX_BOOT_TIME - MIN_BOOT_TIME + 1)) + MIN_BOOT_TIME;
    }

    // Sort the boot times in descending order
    for (i = 0; i < MAX_PROCESSES - 1; i++) {
        for (j = i + 1; j < MAX_PROCESSES; j++) {
            if (boot_times[i] < boot_times[j]) {
                temp = boot_times[i];
                boot_times[i] = boot_times[j];
                boot_times[j] = temp;
            }
        }
    }

    // Calculate the total boot time and average boot time
    for (k = 0; k < MAX_PROCESSES; k++) {
        total_boot_time += boot_times[k];
    }
    avg_boot_time = (float) total_boot_time / MAX_PROCESSES;

    // Print the boot times and average boot time
    printf("System Process Boot Times:\n");
    for (k = 0; k < MAX_PROCESSES; k++) {
        printf("%d\n", boot_times[k]);
    }
    printf("Average Boot Time: %.2f\n", avg_boot_time);

    return 0;
}