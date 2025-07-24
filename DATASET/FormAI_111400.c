//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

// Structure to hold information about a process
typedef struct {
    int pid;        // Process ID
    int burst_time; // Burst time of process
    int priority;   // Priority of process
} Process;

// Function to print out the schedule
void print_schedule(char* algorithm, Process* processes, int num_processes);

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Create an array of processes
    Process processes[MAX_PROCESSES];

    // Initialize the processes with random values
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].priority = rand() % 10 + 1;
    }

    // Print out the initial list of processes
    printf("Initial List of Processes:\n\n");
    printf("PID\tBurst Time\tPriority\n");
    printf("----------------------------------\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
    }
    printf("\n");

    // First Come First Serve Scheduling Algorithm
    printf("First Come First Serve Scheduling Algorithm:\n\n");
    print_schedule("First Come First Serve", processes, MAX_PROCESSES);

    // Shortest Job First Scheduling Algorithm
    printf("Shortest Job First Scheduling Algorithm:\n\n");
    print_schedule("Shortest Job First", processes, MAX_PROCESSES);

    // Round Robin Scheduling Algorithm
    printf("Round Robin Scheduling Algorithm:\n\n");
    print_schedule("Round Robin", processes, MAX_PROCESSES);

    return 0;
}

// Function to print out the schedule
void print_schedule(char* algorithm, Process* processes, int num_processes) {
    // Determine the total time required to complete all the processes
    int total_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_time += processes[i].burst_time;
    }

    // Create an array to hold the completion times for each process
    int completion_times[MAX_PROCESSES] = {0};

    // Create variables to hold the current time and the time remaining for the current process
    int current_time = 0;
    int remaining_time = 0;

    // Loop through each time slice
    for (int time_slice = 0; time_slice < total_time; time_slice++) {
        // Loop through each process to find the one with the highest priority
        int highest_priority = -1;
        int highest_priority_index = -1;
        for (int i = 0; i < num_processes; i++) {
            // Skip processes that have already completed
            if (completion_times[i] > 0) {
                continue;
            }

            // Determine the remaining time for the current process
            if (i == highest_priority_index && remaining_time > 0) {
                remaining_time--;
            } else {
                remaining_time = processes[i].burst_time - 1;
            }

            // Check if this process has the highest priority so far
            if (processes[i].priority > highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }

        // Record the completion time for the process with the highest priority
        completion_times[highest_priority_index] = current_time + remaining_time + 1;
        current_time += remaining_time + 1;
    }

    // Print out the final schedule
    printf("%s Schedule:\n\n", algorithm);
    printf("PID\tBurst Time\tPriority\tCompletion Time\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, completion_times[i]);
    }
    printf("\n");
}