//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Definition of a process control block (PCB)
typedef struct
{
    int process_id;     // ID of the process
    int arrival_time;   // Time at which the process arrives in the ready queue
    int burst_time;     // Time required by the process to complete its execution
    int completion_time;// Time at which the process completes its execution
    int turnaround_time;// Time taken by the process from arrival to completion
    int waiting_time;   // Time spent by the process in the ready queue
    int priority;       // Priority of the process (used by priority scheduling algorithm)
} PCB;

// Definition of the ready queue containing processes
PCB ready_queue[MAX_PROCESSES];

// Definition of the arrival time, burst time and priority of the processes
int arrival_times[MAX_PROCESSES] = {0, 2, 4, 7, 10};  // Example arrival times of the processes
int burst_times[MAX_PROCESSES] = {6, 3, 1, 5, 2};     // Example burst times of the processes
int priorities[MAX_PROCESSES] = {1, 2, 3, 4, 5};      // Example priorities of the processes

// Number of processes in the ready queue
int num_processes_ready_queue = 0;

// Function to sort the processes in the ready queue based on their arrival times
void sort_processes_arrival_time()
{
    int i, j;
    PCB temp;
    for(i = 0; i < num_processes_ready_queue - 1; i++)
    {
        for(j = i + 1; j < num_processes_ready_queue; j++)
        {
            if(ready_queue[i].arrival_time > ready_queue[j].arrival_time)
            {
                temp = ready_queue[i];
                ready_queue[i] = ready_queue[j];
                ready_queue[j] = temp;
            }
        }
    }
}

// Function to schedule the processes using First Come First Serve (FCFS) algorithm
void fcfs()
{
    int i;
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;

    // Sort the processes in the ready queue based on their arrival times
    sort_processes_arrival_time();

    // Compute the completion time, turnaround time and waiting time of each process
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        if(i == 0)
        {
            ready_queue[i].completion_time = ready_queue[i].burst_time;
        }
        else
        {
            ready_queue[i].completion_time = ready_queue[i - 1].completion_time + ready_queue[i].burst_time;
        }
        ready_queue[i].turnaround_time = ready_queue[i].completion_time - ready_queue[i].arrival_time;
        ready_queue[i].waiting_time = ready_queue[i].turnaround_time - ready_queue[i].burst_time;

        // Compute the average turnaround time and average waiting time of the processes
        avg_turnaround_time += ready_queue[i].turnaround_time;
        avg_waiting_time += ready_queue[i].waiting_time;
    }

    avg_turnaround_time /= num_processes_ready_queue;
    avg_waiting_time /= num_processes_ready_queue;

    // Print the results
    printf("FIRST COME FIRST SERVE (FCFS):\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", ready_queue[i].process_id, ready_queue[i].arrival_time, ready_queue[i].burst_time, ready_queue[i].completion_time, ready_queue[i].turnaround_time, ready_queue[i].waiting_time);
    }
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
}

// Function to schedule the processes using Shortest Job First (SJF) algorithm
void sjf()
{
    int i, j;
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;

    // Sort the processes in the ready queue based on their burst times (shortest job first)
    for(i = 0; i < num_processes_ready_queue - 1; i++)
    {
        for(j = i + 1; j < num_processes_ready_queue; j++)
        {
            if(ready_queue[i].burst_time > ready_queue[j].burst_time)
            {
                PCB temp = ready_queue[i];
                ready_queue[i] = ready_queue[j];
                ready_queue[j] = temp;
            }
        }
    }

    // Compute the completion time, turnaround time and waiting time of each process
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        if(i == 0)
        {
            ready_queue[i].completion_time = ready_queue[i].burst_time;
        }
        else
        {
            ready_queue[i].completion_time = ready_queue[i - 1].completion_time + ready_queue[i].burst_time;
        }
        ready_queue[i].turnaround_time = ready_queue[i].completion_time - ready_queue[i].arrival_time;
        ready_queue[i].waiting_time = ready_queue[i].turnaround_time - ready_queue[i].burst_time;

        // Compute the average turnaround time and average waiting time of the processes
        avg_turnaround_time += ready_queue[i].turnaround_time;
        avg_waiting_time += ready_queue[i].waiting_time;
    }

    avg_turnaround_time /= num_processes_ready_queue;
    avg_waiting_time /= num_processes_ready_queue;

    // Print the results
    printf("SHORTEST JOB FIRST (SJF):\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", ready_queue[i].process_id, ready_queue[i].arrival_time, ready_queue[i].burst_time, ready_queue[i].completion_time, ready_queue[i].turnaround_time, ready_queue[i].waiting_time);
    }
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
}

// Function to schedule the processes using Priority Scheduling algorithm
void priority_scheduling()
{
    int i, j;
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;

    // Sort the processes in the ready queue based on their priorities (higher priority first)
    for(i = 0; i < num_processes_ready_queue - 1; i++)
    {
        for(j = i + 1; j < num_processes_ready_queue; j++)
        {
            if(ready_queue[i].priority < ready_queue[j].priority)
            {
                PCB temp = ready_queue[i];
                ready_queue[i] = ready_queue[j];
                ready_queue[j] = temp;
            }
        }
    }

    // Compute the completion time, turnaround time and waiting time of each process
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        if(i == 0)
        {
            ready_queue[i].completion_time = ready_queue[i].burst_time;
        }
        else
        {
            ready_queue[i].completion_time = ready_queue[i - 1].completion_time + ready_queue[i].burst_time;
        }
        ready_queue[i].turnaround_time = ready_queue[i].completion_time - ready_queue[i].arrival_time;
        ready_queue[i].waiting_time = ready_queue[i].turnaround_time - ready_queue[i].burst_time;

        // Compute the average turnaround time and average waiting time of the processes
        avg_turnaround_time += ready_queue[i].turnaround_time;
        avg_waiting_time += ready_queue[i].waiting_time;
    }

    avg_turnaround_time /= num_processes_ready_queue;
    avg_waiting_time /= num_processes_ready_queue;

    // Print the results
    printf("PRIORITY SCHEDULING:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; i < num_processes_ready_queue; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", ready_queue[i].process_id, ready_queue[i].arrival_time, ready_queue[i].burst_time, ready_queue[i].priority, ready_queue[i].completion_time, ready_queue[i].turnaround_time, ready_queue[i].waiting_time);
    }
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
}

int main()
{
    int i;

    // Initialize the processes in the ready queue
    for(i = 0; i < MAX_PROCESSES; i++)
    {
        if(arrival_times[i] != 0)
        {
            ready_queue[num_processes_ready_queue].process_id = i + 1;        // Process ID starts from 1
            ready_queue[num_processes_ready_queue].arrival_time = arrival_times[i];
            ready_queue[num_processes_ready_queue].burst_time = burst_times[i];
            ready_queue[num_processes_ready_queue].priority = priorities[i];
            num_processes_ready_queue++;
        }
    }

    // Schedule the processes using various scheduling algorithms
    fcfs();
    sjf();
    priority_scheduling();

    return 0;
}