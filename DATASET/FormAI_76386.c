//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing a process
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to compare processes based on arrival time
int compare_arrival_time(const void* a, const void* b) {
    const struct Process *p1 = (struct Process *) a;
    const struct Process *p2 = (struct Process *) b;
    return p1->arrival_time - p2->arrival_time;
}

/* Function to implement Shortest Job First scheduling algorithm */
void shortest_job_first(struct Process *processes, int n) {

    // Sort the processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compare_arrival_time);

    // Initialize the waiting time and turnaround time for the first process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // Initialize the remaining burst time for all processes
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // Initialize the current time and completed processes count
    int current_time = processes[0].arrival_time;
    int completed_processes = 1;

    // Loop until all processes are completed
    while (completed_processes < n) {
        int min_burst_time = -1, min_index = -1;

        // Find the process with minimum burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && remaining_burst_time[i] > 0) {
                if (min_burst_time == -1 || remaining_burst_time[i] < min_burst_time) {
                    min_burst_time = remaining_burst_time[i];
                    min_index = i;
                }
            }
        }

        // If no process has arrived yet, move current_time to the arrival time of the next process
        if (min_index == -1) {
            for (int i = 0; i < n; i++) {
                if (processes[i].arrival_time > current_time) {
                    current_time = processes[i].arrival_time;
                    break;
                }
            }
        }

        // Assign the CPU to the process with minimum burst time
        remaining_burst_time[min_index]--;
        current_time++;

        // Check if the current process has finished executing
        if (remaining_burst_time[min_index] == 0) {
            completed_processes++;

            // Calculate the waiting time and turnaround time for the completed process
            int completion_time = current_time;
            int waiting_time = completion_time - processes[min_index].arrival_time - processes[min_index].burst_time;
            int turnaround_time = completion_time - processes[min_index].arrival_time;
            processes[min_index].waiting_time = waiting_time;
            processes[min_index].turnaround_time = turnaround_time;
        }
    }
}

int main() {

    // Define the number of processes
    int n = 5;

    // Define the processes with their arrival time and burst time
    struct Process processes[n];
    processes[0] = (struct Process) {1, 0, 5, 0, 0};
    processes[1] = (struct Process) {2, 1, 3, 0, 0};
    processes[2] = (struct Process) {3, 2, 1, 0, 0};
    processes[3] = (struct Process) {4, 3, 7, 0, 0};
    processes[4] = (struct Process) {5, 4, 2, 0, 0};

    // Implement Shortest Job First scheduling algorithm
    shortest_job_first(processes, n);

    // Print the waiting time and turnaround time for each process
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}