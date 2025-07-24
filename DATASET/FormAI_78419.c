//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
// Post-Apocalyptic CPU Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

// Structure representing a process
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    bool executed;
} process;

// Function to generate random processes
void generate_processes(process processes[MAX_PROCESSES], int max_time) {
    srand(time(NULL));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = rand() % (max_time + 1);
        processes[i].burst_time = rand() % (max_time + 1);
        processes[i].priority = rand() % (max_time + 1);
        processes[i].executed = false;
    }
}

// Function to print the details of a process
void print_process(process p) {
    printf("Process %d:\n", p.id);
    printf("Arrival time: %d\n", p.arrival_time);
    printf("Burst time: %d\n", p.burst_time);
    printf("Priority: %d\n", p.priority);
}

// Function to print the details of all processes
void print_processes(process processes[MAX_PROCESSES]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        print_process(processes[i]);
    }
}

// Function to execute a process
void execute_process(process *p, int *current_time) {
    printf("Executing process %d at time %d...\n", p->id, *current_time);
    *current_time += p->burst_time;
    p->executed = true;
}

// Function to find the process with the highest priority that hasn't been executed yet
process *find_highest_priority(process processes[MAX_PROCESSES], int current_time) {
    process *highest_priority = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!processes[i].executed && processes[i].arrival_time <= current_time) {
            if (highest_priority == NULL || processes[i].priority > highest_priority->priority) {
                highest_priority = &processes[i];
            }
        }
    }
    return highest_priority;
}

// Main function
int main() {
    // Generate random processes
    process processes[MAX_PROCESSES];
    generate_processes(processes, MAX_TIME);
    printf("Generated processes:\n");
    print_processes(processes);

    // Execute processes using priority-based scheduling algorithm
    int current_time = 0;
    process *p;
    while (true) {
        p = find_highest_priority(processes, current_time);
        if (p == NULL) break;
        execute_process(p, &current_time);
    }

    printf("All processes executed!\n");

    return 0;
}