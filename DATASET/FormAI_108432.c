//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of processes
#define MAX_PROCESS 5

// Define the maximum time slice for Round Robin
#define TIME_SLICE 2

// Define the process structure
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool completed;
} process;

// Define the globally declared variables
process processes[MAX_PROCESS];
int completed_processes = 0;

// Function to initialize the processes
void initialize_processes() {

    // Set the values for process 1
    processes[0].id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 4;
    processes[0].remaining_time = processes[0].burst_time;
    processes[0].completed = false;

    // Set the values for process 2
    processes[1].id = 2;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 1;
    processes[1].remaining_time = processes[1].burst_time;
    processes[1].completed = false;

    // Set the values for process 3
    processes[2].id = 3;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 3;
    processes[2].remaining_time = processes[2].burst_time;
    processes[2].completed = false;

    // Set the values for process 4
    processes[3].id = 4;
    processes[3].arrival_time = 3;
    processes[3].burst_time = 2;
    processes[3].remaining_time = processes[3].burst_time;
    processes[3].completed = false;

    // Set the values for process 5
    processes[4].id = 5;
    processes[4].arrival_time = 4;
    processes[4].burst_time = 5;
    processes[4].remaining_time = processes[4].burst_time;
    processes[4].completed = false;
}

// Function to print the details of the processes
void print_processes() {
    printf("Process ID\tArrival Time\tBurst Time\n");
    for(int i=0; i<MAX_PROCESS; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    }
}

// Function to execute the Round Robin algorithm
void execute_rr() {
    int current_time = 0;
    int waiting_time = 0;

    printf("\nRound Robin");
    printf("\nTime Slice: %d\n", TIME_SLICE);
    printf("\nExecution Sequence:\n");

    while (completed_processes < MAX_PROCESS) {

        for (int i = 0; i < MAX_PROCESS; i++) {

            if (processes[i].remaining_time <= 0) {
                continue;
            }

            // Execute the process for the specified time slice
            printf("P%d ", processes[i].id);
            current_time += TIME_SLICE;
            processes[i].remaining_time -= TIME_SLICE;

            // Check if the process has been completed
            if (processes[i].remaining_time <= 0) {
                completed_processes++;
                processes[i].completed = true;
                waiting_time += current_time - processes[i].arrival_time - processes[i].burst_time;
            }
        }
    }

    printf("\n\nAverage Waiting Time: %0.2f\n\n", (float) waiting_time / MAX_PROCESS);
}

// Main function
int main() {
    initialize_processes();
    print_processes();
    execute_rr();
    return 0;
}