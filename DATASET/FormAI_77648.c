//FormAI DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C System boot optimizer!\n\n");
    printf("This program will help you optimize your system's boot time by randomly generating a boot process and then suggesting optimizations.\n\n");

    srand(time(NULL)); // Seed the random number generator with current time

    // Generate random boot process
    int num_processes = 10;
    printf("Generating random boot process...\n");
    printf("Number of processes: %d\n", num_processes);

    // Create an array to hold the processes
    int processes[num_processes];

    // Fill the array with random integers between 1 and 10
    for (int i = 0; i < num_processes; i++) {
        processes[i] = (rand() % 10) + 1;
    }

    // Display the boot process
    printf("Boot process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: %d seconds\n", i+1, processes[i]);
    }
    printf("\n");

    // Optimize the boot process
    int total_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_time += processes[i];
    }

    printf("Total boot time: %d seconds\n", total_time);

    printf("Optimizing boot process...\n");
    printf("Suggested optimizations:\n");

    // If the total boot time exceeds 30 seconds, suggest removing the longest process
    if (total_time > 30) {
        int max_index = 0;
        for (int i = 1; i < num_processes; i++) {
            if (processes[i] > processes[max_index]) {
                max_index = i;
            }
        }
        printf("- Remove Process %d (length %d seconds)\n", max_index+1, processes[max_index]);
    }

    // If the total boot time is less than 10 seconds, suggest adding a process
    if (total_time < 10) {
        int min_index = 0;
        for (int i = 1; i < num_processes; i++) {
            if (processes[i] < processes[min_index]) {
                min_index = i;
            }
        }
        printf("- Add a new process with length %d seconds\n", processes[min_index]);
    }

    // If no suggestions, congratulate user on already having a well-optimized boot process
    if (total_time >= 10 && total_time <= 30) {
        printf("Congratulations! Your boot process is already well-optimized.\n");
    }

    return 0;
}