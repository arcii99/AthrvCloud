//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to hold information about a process
struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int wait_time;
    int turnaround_time;
};

// Function to implement First Come First Serve (FCFS) scheduling algorithm
void fcfs(struct Process processes[], int num_processes) {
    int current_time = 0; // Keep track of current time
    int total_wait_time = 0; // Total wait time of all processes
    int total_turnaround_time = 0; // Total turnaround time of all processes
    
    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n");

    for(int i = 0; i < num_processes; i++) {
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, processes[i].wait_time, processes[i].turnaround_time);
    }

    float average_wait_time = (float) total_wait_time / num_processes;
    float average_turnaround_time = (float) total_turnaround_time / num_processes;

    printf("\nAverage Wait Time: %f\n", average_wait_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
}

// Function to implement Shortest Job First (SJF) scheduling algorithm
void sjf(struct Process processes[], int num_processes) {
    int current_time = 0; // Keep track of current time
    int total_wait_time = 0; // Total wait time of all processes
    int total_turnaround_time = 0; // Total turnaround time of all processes
    bool done[num_processes]; // Array to keep track of which processes are done

    // Initialize all elements of done array to false
    for(int i = 0; i < num_processes; i++) {
        done[i] = false;
    }

    printf("\nSJF Scheduling:\n");
    printf("Process ID\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n");

    while(true) {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 99999;

        // Find next process with shortest burst time
        for(int i = 0; i < num_processes; i++) {
            if(processes[i].arrival_time <= current_time && !done[i]) {
                if(processes[i].burst_time < shortest_job_burst_time) {
                    shortest_job_index = i;
                    shortest_job_burst_time = processes[i].burst_time;
                }
            }
        }

        if(shortest_job_index == -1) {
            // If no process is available, exit loop
            break;
        }

        // Process next shortest job
        current_time += processes[shortest_job_index].burst_time;
        processes[shortest_job_index].turnaround_time = current_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].wait_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
        total_wait_time += processes[shortest_job_index].wait_time;
        total_turnaround_time += processes[shortest_job_index].turnaround_time;
        done[shortest_job_index] = true;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[shortest_job_index].id, processes[shortest_job_index].burst_time, processes[shortest_job_index].arrival_time, processes[shortest_job_index].wait_time, processes[shortest_job_index].turnaround_time);
    }

    float average_wait_time = (float) total_wait_time / num_processes;
    float average_turnaround_time = (float) total_turnaround_time / num_processes;

    printf("\nAverage Wait Time: %f\n", average_wait_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
}

int main() {
    // Example processes
    struct Process processes[] = {
        {1, 5, 0, 0, 0},
        {2, 3, 1, 0, 0},
        {3, 8, 2, 0, 0},
        {4, 6, 3, 0, 0},
        {5, 4, 4, 0, 0}
    };

    int num_processes = sizeof(processes) / sizeof(struct Process);

    fcfs(processes, num_processes);
    sjf(processes, num_processes);

    return 0;
}