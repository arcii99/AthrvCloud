//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surreal CPU Scheduling Algorithm
int main()
{
    int arrival_time[5] = {1, 5, 7, 10, 15}; // Arrival times of processes
    int burst_time[5] = {3, 8, 4, 11, 6}; // Burst times of processes

    printf("Welcome to the surreal CPU Scheduling Algorithm!\n");
    srand(time(NULL)); // Initialize random seed

    // Randomly shuffle the arrays
    for(int i=0; i<5; i++)
    {
        int j = rand() % 5;
        int temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
    }

    printf("Process\tArrival Time\tBurst Time\n");

    // Print the shuffled arrays
    for(int i=0; i<5; i++)
    {
        printf("P%d\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i]);
    }

    int quantum = 3; // Quantum time for Round Robin algorithm
    int time = 0; // Current time
    int completed[5] = {0, 0, 0, 0, 0}; // Array to keep track of completed processes
    int remaining_burst_time[5]; // Array to keep track of remaining burst time of each process

    for(int i=0; i<5; i++)
    {
        remaining_burst_time[i] = burst_time[i]; // Initialize remaining burst times
    }

    printf("\nStarting simulation...\n");

    // Perform Round Robin scheduling
    while(1)
    {
        int flag = 1; // Flag to check if all processes completed

        for(int i=0; i<5; i++)
        {
            if(remaining_burst_time[i] > 0 && arrival_time[i] <= time)
            {
                printf("Executing process P%d for %d seconds\n", i+1, quantum);

                if(remaining_burst_time[i] <= quantum)
                {
                    time += remaining_burst_time[i];
                    remaining_burst_time[i] = 0;
                    printf("Process P%d completed in %d seconds\n", i+1, remaining_burst_time[i]);
                    completed[i] = 1;
                }
                else
                {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                }

                flag = 0;
            }
        }

        if(flag == 1)
        {
            break; // All processes completed
        }
    }

    printf("\nSimulation completed!\n");
    printf("Process\tWaiting Time\tTurnaround Time\n");

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Calculate waiting time and turnaround time for each process
    for(int i=0; i<5; i++)
    {
        int waiting_time = time - arrival_time[i] - burst_time[i];
        int turnaround_time = time - arrival_time[i];
        printf("P%d\t%d\t\t%d\n", i+1, waiting_time, turnaround_time);
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
    }

    printf("Average waiting time: %.2f seconds\n", (float)total_waiting_time/5);
    printf("Average turnaround time: %.2f seconds\n", (float)total_turnaround_time/5);

    return 0;
}