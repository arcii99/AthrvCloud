//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include<stdio.h>

// Function to find the waiting time for each process
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int i, rem_bt[n];
    for (i = 0; i < n; i++)
        rem_bt[i] =  bt[i];
  
    int t = 0; // Current time
  
    // Keep traversing processes in round robin manner
    while (1)
    {
        int done = 1;
  
        // Traverse all processes one by one repeatedly
        for (i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0
            if (rem_bt[i] > 0)
            {
                done = 0; // There is a pending process
  
                if (rem_bt[i] > quantum)
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t += quantum;
  
                    // Decrease the burst_time of current process by quantum
                    rem_bt[i] -= quantum;
                }
  
                // If burst time of a process is smaller than or equal to quantum
                else
                {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t = t + rem_bt[i];
  
                    // Waiting time is current time minus time used by the process
                    wt[i] = t - bt[i];
  
                    // Decrease the burst_time of current process to 0
                    rem_bt[i] = 0;
                }
            }
        }
  
        // If all processes are done
        if (done == 1)
          break;
    }
}
  
// Function to calculate the turnaround time for each process
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    int i;
    for (i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around time
void findAvgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
  
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);
  
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
  
    // Calculate total waiting and turnaround time
    int i;
    for (i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
  
    // Calculate and print average waiting and turnaround time
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);
}

// Main function
int main()
{
    // Initialize the process, burst time and quantum arrays
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 5, 8};
    int quantum = 2;
    // Call the function to find average waiting and turn-around time
    findAvgTime(processes, n, burst_time, quantum);
    return 0;
}