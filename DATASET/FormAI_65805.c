//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    printf("Welcome to the CPU Scheduling Algorithm simulator!\n");
    printf("Are you ready to see how a processor schedules tasks?\n");

    // Start by defining the array of processes to be scheduled
    int processes[5] = {1, 2, 3, 4, 5};

    // Now let's randomly generate burst times for each process
    int burst_times[5];
    srand(time(NULL)); // Seed the random number generator with system time
    for(int i = 0; i < 5; i++) {
        burst_times[i] = (rand() % 10) + 1; // Burst time between 1 and 10
    }

    printf("\nHere are the randomly generated burst times for each process:\n");
    for(int i = 0; i < 5; i++) {
        printf("Process %d: %d\n", processes[i], burst_times[i]);
    }

    // Let's simulate using the First-Come, First-Serve (FCFS) algorithm first
    printf("\nNow let's run the First-Come, First-Serve (FCFS) algorithm...\n");
    int fcfs_waiting_time = 0;
    int fcfs_turnaround_time = 0;
    for(int i = 0; i < 5; i++) {
        fcfs_turnaround_time += burst_times[i]; // Add the burst time of the current process to the turnaround time
        fcfs_waiting_time += fcfs_turnaround_time - burst_times[i]; // Add the waiting time of the current process
    }
    // Print out the average waiting and turnaround times for FCFS
    printf("Average Waiting Time for FCFS: %.2f\n", (float) fcfs_waiting_time / 5);
    printf("Average Turnaround Time for FCFS: %.2f\n", (float) fcfs_turnaround_time / 5);

    // Let's try using the Shortest Job First (SJF) algorithm
    printf("\nNow let's run the Shortest Job First (SJF) algorithm...\n");
    int sjf_waiting_time = 0;
    int sjf_turnaround_time = 0;
    int remaining_burst_times[5];
    for(int i = 0; i < 5; i++) {
        remaining_burst_times[i] = burst_times[i]; // Clone the burst times array to use in SJF
    }
    int clock_time = 0;
    int completed_processes = 0;
    while(completed_processes < 5) {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 100;
        for(int i = 0; i < 5; i++) {
            if(remaining_burst_times[i] <= 0) { // Process has completed
                continue;
            }
            if(remaining_burst_times[i] < shortest_job_burst_time) {
                shortest_job_index = i;
                shortest_job_burst_time = remaining_burst_times[i]; // Update shortest job burst time
            }
        }
        if(shortest_job_index == -1) { // All processes have completed
            break;
        }
        remaining_burst_times[shortest_job_index] = 0; // Mark the shortest job as completed
        completed_processes += 1;
        clock_time += shortest_job_burst_time;
        sjf_turnaround_time += clock_time; // Add the turnaround time of the current process
        sjf_waiting_time += sjf_turnaround_time - burst_times[shortest_job_index]; // Add the waiting time of the current process
    }
    // Print out the average waiting and turnaround times for SJF
    printf("Average Waiting Time for SJF: %.2f\n", (float) sjf_waiting_time / 5);
    printf("Average Turnaround Time for SJF: %.2f\n", (float) sjf_turnaround_time / 5);

    // Let's try using the Round Robin (RR) algorithm
    printf("\nNow let's run the Round Robin (RR) algorithm...\n");
    int rr_waiting_time = 0;
    int rr_turnaround_time = 0;
    int time_quantum = 2; // Time quantum of 2 units
    int remaining_burst_times_rr[5];
    for(int i = 0; i < 5; i++) {
        remaining_burst_times_rr[i] = burst_times[i]; // Clone the burst times array to use in RR
    }
    int rr_clock_time = 0;
    int rr_completed_processes = 0;
    while(rr_completed_processes < 5) {
        for(int i = 0; i < 5; i++) {
            if(remaining_burst_times_rr[i] <= 0) { // Process has completed
                continue;
            }
            if(remaining_burst_times_rr[i] > time_quantum) {
                rr_clock_time += time_quantum;
                remaining_burst_times_rr[i] -= time_quantum;
            } else {
                rr_clock_time += remaining_burst_times_rr[i];
                rr_turnaround_time += rr_clock_time; // Add the turnaround time of the current process
                rr_waiting_time += rr_turnaround_time - burst_times[i]; // Add the waiting time of the current process
                remaining_burst_times_rr[i] = 0; // Mark the process as completed
                rr_completed_processes += 1;
            }
        }
    }
    // Print out the average waiting and turnaround times for RR
    printf("Average Waiting Time for RR: %.2f\n", (float) rr_waiting_time / 5);
    printf("Average Turnaround Time for RR: %.2f\n", (float) rr_turnaround_time / 5);

    printf("\nThanks for running the CPU Scheduling Algorithm simulator!\n");

    return 0;
}