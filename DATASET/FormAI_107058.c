//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSES 5
#define MAX_BOOT_TIME 60

int main() {
    srand(time(NULL)); // Seed the random number generator

    int boot_times[NUM_PROCESSES]; // Array to hold boot times
    int total_boot_time = 0; // Variable to hold total boot time
    int i; // Loop counter iteration variable

    // Generate random boot times for each process between 1 and MAX_BOOT_TIME seconds
    for (i = 0; i < NUM_PROCESSES; i++) {
        boot_times[i] = rand() % MAX_BOOT_TIME + 1;
        total_boot_time += boot_times[i];
    }

    // Display the boot times for each process
    printf("Initial boot times:\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d: %d seconds\n", i + 1, boot_times[i]);
    }

    printf("Total initial boot time: %d seconds\n", total_boot_time);

    // Sort the boot times in ascending order using bubble sort
    int j;
    for (i = 0; i < NUM_PROCESSES - 1; i++) {
        for (j = 0; j < NUM_PROCESSES - i - 1; j++) {
            if (boot_times[j] > boot_times[j + 1]) {
                int temp = boot_times[j];
                boot_times[j] = boot_times[j + 1];
                boot_times[j + 1] = temp;
            }
        }
    }

    // Display the sorted boot times for each process
    printf("Sorted boot times:\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d: %d seconds\n", i + 1, boot_times[i]);
    }

    // Calculate the optimized boot order
    int optimized_boot_order[NUM_PROCESSES];
    int cur_index = 0;
    int start_index = 0;
    int end_index = NUM_PROCESSES - 1;

    while (cur_index < NUM_PROCESSES) {
        // If there are an even number of processes remaining
        if ((end_index - start_index + 1) % 2 == 0) {
            // Add the process with the shortest boot time to the optimized boot order
            if (boot_times[start_index] <= boot_times[end_index]) {
                optimized_boot_order[cur_index++] = start_index++;
            }
            else {
                optimized_boot_order[cur_index++] = end_index--;
            }
        }
        // If there are an odd number of processes remaining
        else {
            // If this is the first process to be added to the optimized boot order
            if (cur_index == 0) {
                // Add the process with the longest boot time to the optimized boot order first
                if (boot_times[start_index] >= boot_times[end_index]) {
                    optimized_boot_order[cur_index++] = start_index++;
                }
                else {
                    optimized_boot_order[cur_index++] = end_index--;
                }
            }
            else {
                // Add the process with the shortest boot time to the optimized boot order
                if (boot_times[start_index] <= boot_times[end_index]) {
                    optimized_boot_order[cur_index++] = start_index++;
                }
                else {
                    optimized_boot_order[cur_index++] = end_index--;
                }
            }
        }
    }

    // Display the optimized boot order
    printf("Optimized boot order:\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d\n", optimized_boot_order[i] + 1);
    }

    // Calculate the optimized boot time
    int optimized_boot_time = 0;
    for (i = 0; i < NUM_PROCESSES; i++) {
        optimized_boot_time += boot_times[optimized_boot_order[i]];
    }

    // Display the optimized boot time
    printf("Optimized boot time: %d seconds\n", optimized_boot_time);

    return 0;
}