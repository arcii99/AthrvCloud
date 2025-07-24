//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genious
#include <stdio.h>

//Function to find the waiting time for each process
void calculateWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int quantum)
{
    // Create a copy of remaining burst time for each process
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0; // Current time
    int flag = 0; // Flag to check if any process is remaining

    // Loop until all processes are completed
    while (1)
    {
        flag = 0;

        // Loop through every process
        for (int i = 0; i < n; i++)
        {
            if (remainingBurstTime[i] > 0)
            {
                flag = 1;

                if (remainingBurstTime[i] > quantum)
                {
                    currentTime += quantum;
                    remainingBurstTime[i] -= quantum;
                }
                else
                {
                    // Process will finish within this time frame
                    currentTime = currentTime + remainingBurstTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    remainingBurstTime[i] = 0;
                }
            }
        }

        if (flag == 0)
        {
            break;
        }
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

// Function to calculate average waiting and turnaround time
void calculateAverageTime(int processes[], int n, int burstTime[], int quantum)
{
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculate waiting time of each process
    calculateWaitingTime(processes, n, burstTime, waitingTime, quantum);

    // Calculate turnaround time of each process
    calculateTurnaroundTime(processes, n, burstTime, waitingTime, turnaroundTime);

    printf("Processes    Burst Time    Waiting Time    Turnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("   %d           %d                %d                  %d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    
    }

    printf("Average waiting time = %.2f\n", (float)totalWaitingTime / (float)n);
    printf("Average turnaround time = %.2f\n", (float)totalTurnaroundTime / (float)n);
}

// Main function
int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burstTime[] = {8, 10, 1, 3};
    int quantum = 2;

    calculateAverageTime(processes, n, burstTime, quantum);

    return 0;
}