//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define process structure
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

// Method to generate random processes
Process generate_process(int pid) {
    Process p;
    p.pid = pid;
    p.arrival_time = rand() % 10;
    p.burst_time = (rand() % 10) + 1;
    p.priority = rand() % 10;
    p.waiting_time = 0;
    p.turnaround_time = 0;
    return p;
}

// Method to print process information
void print_process(Process p) {
    printf("Process PID: %d\n", p.pid);
    printf("Arrival Time: %d\n", p.arrival_time);
    printf("Burst Time: %d\n", p.burst_time);
    printf("Priority: %d\n", p.priority);
    printf("Waiting Time: %d\n", p.waiting_time);
    printf("Turnaround Time: %d\n", p.turnaround_time);
    printf("\n");
}

// First-Come-First-Serve Scheduling Algorithm
void fcfs(Process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        current_time += processes[i].burst_time;
    }
    
    float average_waiting_time = (float) total_waiting_time / num_processes;
    float average_turnaround_time = (float) total_turnaround_time / num_processes;
    
    printf("First-Come-First-Serve Scheduling Algorithm\n");
    printf("Average Waiting Time: %f\n", average_waiting_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
}

// Shortest-Job-First Scheduling Algorithm
void sjf(Process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    // Sort processes by burst time
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].burst_time > processes[j+1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        current_time += processes[i].burst_time;
    }
    
    float average_waiting_time = (float) total_waiting_time / num_processes;
    float average_turnaround_time = (float) total_turnaround_time / num_processes;
    
    printf("\nShortest-Job-First Scheduling Algorithm\n");
    printf("Average Waiting Time: %f\n", average_waiting_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
}

// Priority-Based Scheduling Algorithm
void priority(Process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    // Sort processes by priority
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        current_time += processes[i].burst_time;
    }
    
    float average_waiting_time = (float) total_waiting_time / num_processes;
    float average_turnaround_time = (float) total_turnaround_time / num_processes;
    
    printf("\nPriority-Based Scheduling Algorithm\n");
    printf("Average Waiting Time: %f\n", average_waiting_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
}

int main() {
    srand(time(0));     // Initialize random number generator
    int num_processes = 5;      // Number of processes
    Process processes[num_processes];
    
    // Generate random processes
    for (int i = 0; i < num_processes; i++) {
        processes[i] = generate_process(i+1);
    }
    
    // Print process information
    for (int i = 0; i < num_processes; i++) {
        print_process(processes[i]);
    }
    
    // Schedule processes
    fcfs(processes, num_processes);
    sjf(processes, num_processes);
    priority(processes, num_processes);
    
    return 0;
}