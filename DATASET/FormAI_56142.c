//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include<stdio.h>

int main(){

    int n, i, j, bt[20], wt[20], tat[20], total=0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("\nEnter the burst time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d",&bt[i]);
    }

    //Calculating Waiting Time
    wt[0]=0; //waiting time for the first process is 0
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }

    //Calculating Turnaround Time
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
    }

    //Calculating Average Waiting Time and Average Turnaround Time
    avg_wt=(float)total/n;
    avg_tat=(float)total/n;

    printf("\n\nCPU Scheduling Algorithm Used: First Come First Serve (FCFS)\n");
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++){
        printf("\nProcess %d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    printf("\n\nAverage Waiting Time: %0.2f ms",avg_wt);
    printf("\nAverage Turnaround Time: %0.2f ms",avg_tat);

    return 0;
}