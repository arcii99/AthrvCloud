//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    bool completed;
} Process;

int main() {

    // Initialize an array of processes
    Process processes[MAX_PROCESSES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].priority = rand() % 5;
        processes[i].completed = false;
    }

    // Implement an FCFS algorithm
    int current_time = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        printf("Executing process with PID %d at time %d\n", processes[i].pid, current_time);
        current_time += processes[i].burst_time;
    }

    return 0;
}