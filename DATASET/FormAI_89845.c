//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_PROCESS 10

// Struct to represent a process
struct process{
    int pid;     // Process ID
    int burst_time;  // Burst time
    int arrival_time;   // Arrival time
    int waiting_time;   // Waiting time
    int turnaround_time;    // Turn around time
};

// Function to find the waiting time for all processes
void findWaitingTime(struct process p[], int n, int wt[]){
    int burst[n];
    for(int i=0;i<n;i++){
        burst[i] = p[i].burst_time;
    }
    int complete=0, time=0, min_burst=INT_MAX, shortest=0, finish_time;
    int check = 0;
    while(complete!=n){
        for(int j=0;j<n;j++){
            if(p[j].arrival_time<=time && burst[j]<min_burst && burst[j]>0){
                min_burst = burst[j];
                shortest = j;
                check = 1;
            }
        }
        if(check==0){
            time++;
            continue;
        }
        burst[shortest]--;
        min_burst = burst[shortest];
        if(min_burst==0){
            min_burst = INT_MAX;
        }
        if(burst[shortest]==0){
            complete++;
            check = 0;
            finish_time = time+1;
            p[shortest].waiting_time = finish_time - p[shortest].burst_time - p[shortest].arrival_time;
            if(p[shortest].waiting_time < 0){
                p[shortest].waiting_time=0;
            }
        }
        time++;
    }
}

// Function to find the turn around time for all processes
void findTurnAroundTime(struct process p[], int n, int wt[], int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = p[i].burst_time + wt[i];
    }
}

// Function to calculate average waiting and turn around time
void findAvgTime(struct process p[], int n){
    int wt[n], tat[n], total_wt=0, total_tat=0;
    findWaitingTime(p, n, wt);
    findTurnAroundTime(p, n, wt, tat);
    // Display Processes along with all details
    printf("Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time \n");
    for(int i=0;i<n;i++){
        p[i].turnaround_time = tat[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t    %d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %.2f", (float)total_wt/n);
    printf("\nAverage turn around time = %.2f",(float)total_tat/n);
}

// Driver code
int main(){
    // Test case
    struct process p[MAX_PROCESS]={{1,6,1,0,0},{2,8,1,0,0},{3,7,2,0,0},{4,3,3,0,0}};
    int n=4;    // Number of processes
    findAvgTime(p, n);
    return 0;
}