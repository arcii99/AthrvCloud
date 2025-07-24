//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include<stdio.h> 

int main() 
{ 
    int n, temp, quantum, waiting_t=0, turnaround_t=0, i, j; 
    int burst_time[50], proc[50], res_time[50]; 
    printf("Enter the total number of processes: "); 
    scanf("%d", &n); 
    printf("\nEnter the burst time and priority of the processes:\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("Burst time of process %d: ", i+1); 
        scanf("%d", &burst_time[i]); 
        proc[i] = i+1; 
    } 
    printf("\nEnter the time quantum: "); 
    scanf("%d", &quantum); 
    res_time[0]=0;    
    for(i=1;i<n;i++) 
    { 
        res_time[i]=0; 
        for(j=0;j<i;j++) 
            res_time[i] += burst_time[j]; 
    } 
    printf("\nProcess\t\tWaiting Time\t\tTurnaround Time\n"); 
    for(i=0;i<n;i++) 
    { 
        waiting_t = 0; 
        int j;
        for(j=res_time[i];j<res_time[i+1];j+=quantum) 
            waiting_t += quantum; 
        turnaround_t = waiting_t + burst_time[i]; 
        printf("Process %d\t\t%d\t\t\t%d\n", proc[i], waiting_t, turnaround_t); 
    } 
    return 0; 
}