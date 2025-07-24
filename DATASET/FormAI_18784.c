//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// define custom process structure
typedef struct {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

// function prototypes
void fcfs_scheduler(Process processes[], int num_processes);
void sjf_scheduler(Process processes[], int num_processes);
void priority_scheduler(Process processes[], int num_processes);

// main function
int main() {
    // initialize array of processes
    Process processes[] = {
        {1, 6, 3, 0, 0},
        {2, 8, 2, 0, 0},
        {3, 4, 1, 0, 0},
        {4, 3, 4, 0, 0},
        {5, 5, 3, 0, 0},
    };
    int num_processes = sizeof(processes) / sizeof(Process);

    // run first-come first-serve scheduler
    printf("=== FIRST-COME FIRST-SERVE SCHEDULER ===\n");
    fcfs_scheduler(processes, num_processes);

    // run shortest job first scheduler
    printf("\n=== SHORTEST JOB FIRST SCHEDULER ===\n");
    sjf_scheduler(processes, num_processes);

    // run priority scheduler
    printf("\n=== PRIORITY SCHEDULER ===\n");
    priority_scheduler(processes, num_processes);

    return 0;
}

// first-come first-serve scheduler implementation
void fcfs_scheduler(Process processes[], int num_processes) {
    // initialize wait and turnaround times for first process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // calculate wait and turnaround times for remaining processes
    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // print process details and average wait and turnaround times
    printf("PID  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    float total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        printf("%d    %d           %d         %d             %d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", total_wait_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / num_processes);
}

// shortest job first scheduler implementation
void sjf_scheduler(Process processes[], int num_processes) {
    // sort processes by burst time
    for (int i = 0; i < num_processes-1; i++) {
        for (int j = i+1; j < num_processes; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // initialize wait and turnaround times for first process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // calculate wait and turnaround times for remaining processes
    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // print process details and average wait and turnaround times
    printf("PID  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    float total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        printf("%d    %d           %d         %d             %d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", total_wait_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / num_processes);
}

// priority scheduler implementation
void priority_scheduler(Process processes[], int num_processes) {
    // sort processes by priority
    for (int i = 0; i < num_processes-1; i++) {
        for (int j = i+1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // initialize wait and turnaround times for first process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // calculate wait and turnaround times for remaining processes
    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // print process details and average wait and turnaround times
    printf("PID  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    float total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        printf("%d    %d           %d         %d             %d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", total_wait_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / num_processes);
}