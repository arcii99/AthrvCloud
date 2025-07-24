//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define QUANTUM 5

// Struct to represent a process
typedef struct {
    int arrival_time;   // Arrival time of process
    int burst_time;     // Burst time of process
    int remaining_time; // Remaining time of process
    int turnaround_time;// Turnaround time of process
    int waiting_time;   // Waiting time of process
    int completion_time;// Completion time of process
} Process;

// Function to initialize an array of processes
void generate_processes(Process processes[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        processes[i].arrival_time = rand() % 50;
        processes[i].burst_time = 1 + rand() % 10;
        processes[i].remaining_time = processes[i].burst_time;
    }
}

// Function to print the details of a process
void print_process(Process p) {
    printf("Arrival Time: %d, Burst Time: %d, Turnaround Time: %d, Waiting Time: %d, Completion Time: %d\n", 
            p.arrival_time, p.burst_time, p.turnaround_time, p.waiting_time, p.completion_time);
}

// Function to calculate the waiting and turnaround times for all processes
void calculate_times(Process processes[], int n) {
    int total_time = processes[0].arrival_time;
    for(int i = 0; i < n; i++) {
        if(processes[i].remaining_time <= QUANTUM) {
            total_time += processes[i].remaining_time;
            processes[i].remaining_time = 0;
            processes[i].completion_time = total_time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        }
        else {
            processes[i].remaining_time -= QUANTUM;
            total_time += QUANTUM;
        }
        i = (i == n-1) ? -1 : i;
    }
}

// Function to implement Round Robin scheduling algorithm
void round_robin(Process processes[], int n) {
    int current_time = processes[0].arrival_time;
    int completed_processes = 0;
    while(completed_processes < n) {
        for(int i = 0; i < n; i++) {
            if(processes[i].remaining_time == 0) {
                continue;
            }
            else if(processes[i].arrival_time <= current_time) {
                printf("Executing Process %d at %d\n", i+1, current_time);
                if(processes[i].remaining_time <= QUANTUM) {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed_processes++;
                }
                else {
                    processes[i].remaining_time -= QUANTUM;
                    current_time += QUANTUM;
                }
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    generate_processes(processes, MAX_PROCESSES);
    printf("Initial Process Details:\n");
    for(int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: ", i+1);
        print_process(processes[i]);
    }
    round_robin(processes, MAX_PROCESSES);
    printf("Final Process Details:\n");
    for(int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: ", i+1);
        print_process(processes[i]);
    }
    return 0;
}