//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to find the waiting time for each process
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
    int t = 0; // Current time
 
    // Keep traversing processes in round robin manner until all of them are not done.
    while (1)
    {
        int done = 1;
 
        // Traverse all processes one by one repeatedly, in a round robin fashion
        for (int i = 0 ; i < n; i++)
        {
            // If any process has remaining burst time
            if (rem_bt[i] > 0)
            {
                done = 0; // There is a pending process
 
                if (rem_bt[i] > quantum)
                {
                    t += quantum; // Increase the value of time die to quantum
                    rem_bt[i] -= quantum; // Decrease the burst time of current process by quantum
                }

                else
                {
                    t = t + rem_bt[i]; // Increase the value of time due to the current process
                    wt[i] = t - bt[i]; // Waiting time is current time minus time required to burst the process

                    rem_bt[i] = 0; // Process is over
                }
            }
        }

        // If all processes are done
        if (done == 1)
          break;
    }
}
 
// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i]; // Turn around time is burst time plus waiting time
}

// Function to calculate the average waiting time and turn around time
void findAvgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);
 
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // Display the output
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
 
    // Calculate total waiting time and total turn around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
 
    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turnaround time = %f\n", (float)total_tat / (float)n);
}

int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    int burst_time[] = {9, 7, 5};
 
    int quantum = 2;

    findAvgTime(processes, n, burst_time, quantum);

    return 0;
}