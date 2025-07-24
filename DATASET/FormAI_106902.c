//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define our processes
struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Compares arrival times of two processes
int compare_arrival_time(const void* a, const void* b) {
    struct process* process1 = (struct process*)a;
    struct process* process2 = (struct process*)b;
    return process1->arrival_time - process2->arrival_time;
}

// Runs the First-Come, First-Serve (FCFS) algorithm
void fcfs(struct process* processes, int num_processes) {
    // Sort processes by arrival time
    qsort(processes, num_processes, sizeof(struct process), compare_arrival_time);
    
    // Initialize variables for calculating waiting and turnaround times
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    
    // Run each process in order of arrival time
    for (int i = 0; i < num_processes; i++) {
        // Wait for process to arrive if necessary
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        // Update waiting and turnaround times
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        
        // Move to next process
        current_time += processes[i].burst_time;
    }
    
    // Print results
    printf("FCFS algorithm:\n");
    printf("Average waiting time: %f\n", (double)total_waiting_time / (double)num_processes);
    printf("Average turnaround time: %f\n", (double)total_turnaround_time / (double)num_processes);
}

// Compares remaining burst times of two processes
int compare_remaining_burst_time(const void* a, const void* b) {
    struct process* process1 = (struct process*)a;
    struct process* process2 = (struct process*)b;
    return process1->burst_time - process2->burst_time;
}

// Runs the Shortest Job First (SJF) algorithm
void sjf(struct process* processes, int num_processes) {
    // Sort processes by arrival time then by burst time
    qsort(processes, num_processes, sizeof(struct process), compare_arrival_time);
    qsort(&processes[1], num_processes-1, sizeof(struct process), compare_remaining_burst_time);
    
    // Initialize variables for calculating waiting and turnaround times
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = processes[0].arrival_time + processes[0].burst_time;
    
    // Run each process in order of shortest remaining burst time
    for (int i = 1; i < num_processes; i++) {
        // Wait for next process to arrive if necessary
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        // Update waiting and turnaround times
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        
        // Update current time and remaining burst times
        current_time += processes[i].burst_time;
    }
    
    // Print results
    printf("SJF algorithm:\n");
    printf("Average waiting time: %f\n", (double)total_waiting_time / (double)num_processes);
    printf("Average turnaround time: %f\n", (double)total_turnaround_time / (double)num_processes);
}

int main() {
    // Define our processes
    struct process processes[] = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 8},
        {4, 3, 6},
        {5, 4, 4},
        {6, 5, 2},
        {7, 6, 7},
        {8, 7, 5}
    };
    int num_processes = sizeof(processes) / sizeof(struct process);
    
    // Run each scheduling algorithm
    fcfs(processes, num_processes);
    sjf(processes, num_processes);
    
    return 0;
}