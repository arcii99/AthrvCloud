//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include<stdio.h>

int main()
{
    // random seed
    srand(time(NULL));

    // initializing variables
    int i, j, k, n, bt[20], wt[20], tat[20], at[20], p[20], temp;
    float avgwt = 0, avgtat = 0;

    // choosing random number of processes (between 5-20)
    n = rand() % 16 + 5;

    // random arrival time (between 0-10) of processes
    for(i = 0; i < n; i++)
    {
        at[i] = rand() % 11;
        p[i] = i+1;
    }

    // random burst time (between 1-10) of processes
    for(i = 0; i < n; i++)
    {
        bt[i] = rand() % 10 + 1;
    }

    // sorting processes by arrival time
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(at[j]>at[j+1])
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // FCFS scheduling algorithm
    for(i = 0; i < n; i++)
    {
        // waiting time of process i is sum of burst time of all previous processes
        wt[i] = 0;
        for(j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }

        // turnaround time of process i is sum of waiting time and burst time
        tat[i] = wt[i] + bt[i];

        // calculating average waiting time and average turnaround time
        avgwt += wt[i];
        avgtat += tat[i];
    }

    // printing gantt chart
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("|P%d", p[i]);
        for(j = 0; j < bt[i]-1; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");

    // printing process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    // printing average waiting time and average turnaround time
    avgwt /= n;
    avgtat /= n;
    printf("\nAverage Waiting Time: %f\n",avgwt);
    printf("Average Turnaround Time: %f\n",avgtat);

    return 0;
}