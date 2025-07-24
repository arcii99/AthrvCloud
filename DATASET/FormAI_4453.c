//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int n=5;

    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int total_waiting_time=0;
    int total_turnaround_time=0;

    printf("\n\t\tMEDIEVAL CPU SCHEDULING\n\n");
    printf("\n===============================================\n");
    printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\n");
    printf("\n===============================================\n");

    for(int i=0; i<n; i++)
    {
        processes[i]=i+1;
        arrival_time[i]=rand()%10;
        burst_time[i]=rand()%20+1;
        printf("\n%d\t\t%d\t\t%d\n", processes[i], arrival_time[i], burst_time[i]);
    }

    int temp_burst_time[n];
    for(int i=0; i<n; i++)
        temp_burst_time[i]=burst_time[i];

    int time=0;
    int min_burst_time=101;
    int min_burst_time_index=0;
    int flag=0;

    printf("\n===============================================\n");
    printf("\nPROCESS ID\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    printf("\n===============================================\n");

    while(flag!=n)
    {
        for(int i=0; i<n; i++)
        {
            if(arrival_time[i]<=time && burst_time[i]<min_burst_time && burst_time[i]>0)
            {
                min_burst_time=burst_time[i];
                min_burst_time_index=i;
            }
        }

        if(min_burst_time==101)
        {
            time++;
            continue;
        }

        burst_time[min_burst_time_index]--;
        min_burst_time=burst_time[min_burst_time_index];

        if(min_burst_time==0)
        {
            min_burst_time=101;
            flag++;
            completion_time[min_burst_time_index]=time+1;
            waiting_time[min_burst_time_index]=completion_time[min_burst_time_index]-arrival_time[min_burst_time_index]-temp_burst_time[min_burst_time_index];
            if(waiting_time[min_burst_time_index]<0)
                waiting_time[min_burst_time_index]=0;
        }

        time++;
    }

    for(int i=0; i<n; i++)
    {
        turnaround_time[i]=temp_burst_time[i]+waiting_time[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\n", processes[i], completion_time[i], waiting_time[i], turnaround_time[i]);

        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }

    printf("\nAverage Waiting Time= %f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time= %f", (float)total_turnaround_time/n);

    return 0;
}