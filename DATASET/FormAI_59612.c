//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>

int main()
{
    int n, i, j, total_burst_time = 0, total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n); // Get number of processes

    int burst_time[n], waiting_time[n], turnaround_time[n];

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("P[%d]: ", i+1);
        scanf("%d", &burst_time[i]); // Get burst time for each process
        total_burst_time += burst_time[i]; // Find the total burst time
    }

    waiting_time[0] = 0; // The first process has to wait for no time
    printf("\nProcess\t         Burst Time        \tWaiting Time\tTurnaround Time");

    for(i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i]; // Calculate turnaround time for each process

        total_waiting_time += waiting_time[i]; // Find the total waiting time
        total_turnaround_time += turnaround_time[i]; // Find the total turnaround time

        printf("\nP[%d]\t\t\t  %d\t\t    %d\t\t\t%d", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);

        if(i != n-1) waiting_time[i+1] = turnaround_time[i]; // Calculate waiting time for the next process
    }

    // Output the results
    printf("\n\nAverage Waiting Time = %.2f", (float)total_waiting_time / (float)n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_turnaround_time / (float)n);

    return 0;
}