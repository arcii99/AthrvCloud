//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the maximum possible value for the burst time of a process
#define MAX_BURST_TIME 20

// Defining the size of the ready queue
#define READY_QUEUE_SIZE 10

// Global variable to store the current time
int current_time = 0;

// Structure to represent a process
typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

// Function to generate a new process with random burst time
Process generate_process(int id) {
    Process p;
    p.id = id;
    p.burst_time = rand() % MAX_BURST_TIME + 1;
    p.remaining_time = p.burst_time;
    return p;
}

// Function to print the details of a process
void print_process(Process p) {
    printf("Process %d\tBurst Time: %d\tRemaining Time: %d\n", p.id, p.burst_time, p.remaining_time);
}

// Function to print the details of all processes in the ready queue
void print_ready_queue(Process *ready_queue, int queue_size) {
    printf("Ready Queue:\n");
    for (int i = 0; i < queue_size; i++) {
        print_process(ready_queue[i]);
    }
}

// Function to simulate the execution of a process for one time unit
void execute_process(Process *p) {
    printf("Executing Process %d for 1 unit of time...\n", p->id);
    p->remaining_time--;
    current_time++;
}

// Function to implement the First-Come-First-Serve scheduling algorithm
void FCFS(Process *processes, int num_processes) {

    printf("\n\nFirst-Come-First-Serve Scheduling Algorithm\n\n");

    // Initialize the ready queue with the first process
    Process ready_queue[READY_QUEUE_SIZE];
    ready_queue[0] = processes[0];
    int queue_size = 1;

    for (int i = 1; i < num_processes; i++) {
        // Add the process to the end of the ready queue
        ready_queue[queue_size] = processes[i];
        queue_size++;

        // Print the details of the ready queue
        print_ready_queue(ready_queue, queue_size);

        // Execute the first process in the ready queue until completion
        while (ready_queue[0].remaining_time > 0) {
            execute_process(&ready_queue[0]);
        }

        // Remove the completed process from the ready queue
        for (int j = 0; j < queue_size - 1; j++) {
            ready_queue[j] = ready_queue[j+1];
        }
        queue_size--;

        // Print the details of the ready queue
        print_ready_queue(ready_queue, queue_size);
    }
}

// Function to implement the Shortest-Job-First scheduling algorithm
void SJF(Process *processes, int num_processes) {

    printf("\n\nShortest-Job-First Scheduling Algorithm\n\n");

    // Initialize the ready queue with the first process
    Process ready_queue[READY_QUEUE_SIZE];
    ready_queue[0] = processes[0];
    int queue_size = 1;

    for (int i = 1; i < num_processes; i++) {
        // Find the process with the shortest remaining time
        int shortest_time_index = -1;
        for (int j = 0; j < i; j++) {
            if (processes[j].remaining_time > 0 && 
                (shortest_time_index == -1 || processes[j].remaining_time < processes[shortest_time_index].remaining_time)) {
                shortest_time_index = j;
            }
        }

        // Add the process to the ready queue
        ready_queue[queue_size] = processes[shortest_time_index];
        queue_size++;

        // Print the details of the ready queue
        print_ready_queue(ready_queue, queue_size);

        // Execute the process with the shortest remaining time until completion
        while (ready_queue[0].remaining_time > 0) {
            execute_process(&ready_queue[0]);
        }

        // Remove the completed process from the ready queue
        for (int j = 0; j < queue_size - 1; j++) {
            ready_queue[j] = ready_queue[j+1];
        }
        queue_size--;

        // Print the details of the ready queue
        print_ready_queue(ready_queue, queue_size);
    }
}

int main() {

    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate 5 random processes
    Process processes[5];
    for (int i = 0; i < 5; i++) {
        processes[i] = generate_process(i+1);
    }

    // Print the details of the processes
    printf("Initial Processes:\n");
    for (int i = 0; i < 5; i++) {
        print_process(processes[i]);
    }

    // Run the FCFS algorithm on the processes
    FCFS(processes, 5);

    // Reset the remaining time of the processes
    for (int i = 0; i < 5; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Run the SJF algorithm on the processes
    SJF(processes, 5);

    return 0;
}