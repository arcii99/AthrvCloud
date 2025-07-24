//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROCESS_NUM 5
#define SLEEP_TIME 5

// Process structure
typedef struct {
    int id;         // Process ID
    int priority;   // Process priority (higher value means higher priority)
    int burst_time; // Time required to complete the process
} Process;

// Function to generate random values for a process
Process generate_process(int id) {
    Process process;
    process.id = id;
    process.priority = rand() % 10 + 1;     // Random priority between 1 and 10
    process.burst_time = rand() % 10 + 1;   // Random burst time between 1 and 10
    return process;
}

// Function to simulate processing a process for a given amount of time
void process(Process process, int time) {
    printf("Processing process with ID %d and priority %d for %d seconds.\n", process.id, process.priority, time);
    sleep(time);
    printf("Process with ID %d and priority %d is done processing.\n", process.id, process.priority);
}

// First-Come, First-Served (FCFS) scheduling algorithm
void fcfs(Process processes[]) {
    printf("\nRunning First-Come, First-Served (FCFS) scheduling algorithm.\n");
    for (int i = 0; i < PROCESS_NUM; i++) {
        process(processes[i], processes[i].burst_time);
    }
}

// Shortest Job First (SJF) scheduling algorithm
void sjf(Process processes[]) {
    printf("\nRunning Shortest Job First (SJF) scheduling algorithm.\n");
    for (int i = 0; i < PROCESS_NUM; i++) {
        int shortest_job = i;
        for (int j = i + 1; j < PROCESS_NUM; j++) {
            if (processes[j].burst_time < processes[shortest_job].burst_time) {
                shortest_job = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[shortest_job];
        processes[shortest_job] = temp;
        process(processes[i], processes[i].burst_time);
    }
}

// Priority Scheduling scheduling algorithm
void priority(Process processes[]) {
    printf("\nRunning Priority Scheduling scheduling algorithm.\n");
    for (int i = 0; i < PROCESS_NUM; i++) {
        int highest_priority = i;
        for (int j = i + 1; j < PROCESS_NUM; j++) {
            if (processes[j].priority > processes[highest_priority].priority) {
                highest_priority = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[highest_priority];
        processes[highest_priority] = temp;
        process(processes[i], processes[i].burst_time);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    printf("Generating processes...\n");
    Process processes[PROCESS_NUM];
    for (int i = 0; i < PROCESS_NUM; i++) {
        processes[i] = generate_process(i+1);
    }

    fcfs(processes);
    sjf(processes);
    priority(processes);

    return 0;
}