//FormAI DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
    int boot_time = 30; // Set the default boot time to 30 seconds
    int opt_time = 0; // Initialize the optimized boot time to 0 seconds
    int num_processes = 10; // Set the default number of processes to 10
    int process_times[num_processes]; // Initialize an array to store the time taken by each process
    int i;

    // Get user input for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Get user input for each process time
    for(i=0; i<num_processes; i++) {
        printf("Enter the time taken by process %d: ", i+1);
        scanf("%d", &process_times[i]);
    }

    // Calculate the total boot time
    for(i=0; i<num_processes; i++) {
        boot_time += process_times[i];
    }

    // Calculate the optimized boot time (assuming one process can be run concurrently)
    for(i=0; i<num_processes; i++) {
        int temp_time = boot_time - process_times[i] + (process_times[i]/2);
        if(temp_time < opt_time || opt_time == 0) {
            opt_time = temp_time;
        }
    }

    // Print the optimized boot time
    printf("Optimized boot time: %d seconds", opt_time);

    return 0;
}