//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid;        // Process ID
    int burstTime;  // Burst time of process
    int arrivalTime;// Arrival time of process
    int priority;   // Priority of process (lower value indicates higher priority)
} process;

// Function to swap two processes
void swap(process* a, process* b)
{
    process t = *a;
    *a = *b;
    *b = t;
}

// Function to implement Selection Sort on processes based on arrival time
void sortByArrivalTime(process* proc, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (proc[j].arrivalTime < proc[min_idx].arrivalTime)
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&proc[min_idx], &proc[i]);
    }
}

// Function to implement Priority Scheduling Algorithm
void priorityScheduling(process* proc, int n)
{
    int i;
    int time = 0;               // Current time
    int total_time = 0;         // Total time taken by all processes
    int waiting_time = 0;       // Total waiting time
    int turnaround_time = 0;    // Total turnaround time

    // Sort processes by arrival time
    sortByArrivalTime(proc, n);

    // Calculate total time required for all processes
    for (i = 0; i < n; i++)
        total_time += proc[i].burstTime;

    // Priority Scheduling Algorithm
    printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (time = 0; time < total_time;)
    {
        int highest_priority = 9999;
        int index = -1;
        for (i = 0; i < n; i++)
        {
            if (proc[i].arrivalTime <= time && proc[i].priority < highest_priority && proc[i].burstTime > 0)
            {
                highest_priority = proc[i].priority;
                index = i;
            }
        }

        // If no process is found, increase current time
        if (index == -1)
        {
            time++;
            continue;
        }

        // Update waiting time and turnaround time for selected process
        waiting_time += time - proc[index].arrivalTime;
        turnaround_time += time - proc[index].arrivalTime + proc[index].burstTime;

        // Print selected process
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[index].pid, proc[index].arrivalTime, proc[index].burstTime, proc[index].priority, 
              time - proc[index].arrivalTime, time - proc[index].arrivalTime + proc[index].burstTime);

        // Reduce burst time of selected process
        proc[index].burstTime--;

        // If burst time is zero, it means process is completed
        if (proc[index].burstTime == 0)
            proc[index].priority = 9999;

        // Increase time
        time++;
    }

    // Print average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", (float)waiting_time / (float)n);
    printf("Average turnaround time: %.2f\n", (float)turnaround_time / (float)n);
}

int main()
{
    process proc[] = {{1, 8, 0, 3}, {2, 4, 1, 1}, {3, 9, 2, 2}, {4, 5, 3, 1}, {5, 6, 4, 4}};
    int n = sizeof(proc) / sizeof(proc[0]);

    priorityScheduling(proc, n);

    return 0;
}