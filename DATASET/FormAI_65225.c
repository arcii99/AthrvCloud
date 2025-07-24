//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUANTA 100
#define MAX_ARRIVAL 20

// Structure to store the data of a process
struct Process {
    int pid;             // Process identifier
    int arrival_time;    // The time at which the process arrives in the ready queue
    int burst_time;      // The amount of CPU time the process requires
    int remaining_time;  // The amount of CPU time needed to complete the process
};

// Function to generate a random integer between min and max
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the First-Come, First-Serve (FCFS) scheduling algorithm
void fcfs(struct Process processes[], int num_processes) {
    int time = 0;      // The current time
    int total_time = 0; // The total processing time for all processes
    int i;
    
    // Sort the processes based on arrival time
    for (i = 0; i < num_processes - 1; i++) {
        int j;
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    // Process the jobs in the order they arrive
    for (i = 0; i < num_processes; i++) {
        // Update the time
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        // Process the job
        total_time += processes[i].burst_time;
        time += processes[i].burst_time;
    }
    
    printf("FCFS: Average waiting time = %f\n", (time - total_time) / (float) num_processes);
}

// Function to simulate the Shortest-Job-First (SJF) scheduling algorithm
void sjf(struct Process processes[], int num_processes) {
    int time = 0;      // The current time
    int total_time = 0; // The total processing time for all processes
    int i, j;
    
    // Sort the processes based on burst time
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    // Process the jobs in order of increasing length
    for (i = 0; i < num_processes; i++) {
        // Update the time
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        // Process the job
        total_time += processes[i].burst_time;
        time += processes[i].burst_time;
    }
    
    printf("SJF: Average waiting time = %f\n", (time - total_time) / (float) num_processes);
}

// Function to simulate the Round-Robin (RR) scheduling algorithm
void rr(struct Process processes[], int num_processes) {
    int time = 0;      // The current time
    int total_time = 0; // The total processing time for all processes
    int total_wait_time = 0; // The total wait time for all processes
    int i;
    
    // Set the quantum size
    int quantum = 5;
    
    // Simulate the execution of the processes using a loop
    int done = 0;
    while (!done) {
        done = 1;
        for (i = 0; i < num_processes; i++) {
            // Check if the process is ready to be executed
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                done = 0;
                // Execute the process for the quantum time
                if (processes[i].remaining_time < quantum) {
                    total_time += processes[i].remaining_time;
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                } else {
                    total_time += quantum;
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                }
                // Check if the process is finished
                if (processes[i].remaining_time == 0) {
                    total_wait_time += (time - processes[i].burst_time - processes[i].arrival_time);
                }
            }
        }
    }
    
    // Print the results
    printf("RR: Average waiting time = %f\n", total_wait_time / (float) num_processes);
}

int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Generate the processes
    struct Process processes[MAX_PROCESSES];
    int num_processes = random_int(5, 10);
    int i;
    for (i = 0; i < num_processes; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = random_int(0, MAX_ARRIVAL);
        processes[i].burst_time = random_int(1, MAX_QUANTA);
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    // Simulate the scheduling algorithms
    fcfs(processes, num_processes);
    sjf(processes, num_processes);
    rr(processes, num_processes);
    
    return 0;
}