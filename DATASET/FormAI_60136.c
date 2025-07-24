//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
};

int main()
{
    int n, total_time = 0, total_waiting_time = 0;
    float average_waiting_time;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    struct process p[n], temp;
    for(int i=0; i<n; i++) {
        printf("\nEnter the Burst Time, Arrival Time, and Priority of the Process %d:\n", i+1);
        p[i].pid = i+1;
        scanf("%d%d%d", &p[i].burst_time, &p[i].arrival_time, &p[i].priority);
        p[i].remaining_time = p[i].burst_time; // Setting remaining time to burst time initially
        total_time += p[i].burst_time; // Calculating total time required
    }
    // Applying Priority Scheduling Algorithm
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].priority < p[j+1].priority) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\nProcess Execution order: ");
    for(int i=0; i<n; i++) {
        printf("%d ", p[i].pid);
        sleep(p[i].burst_time); // Adding sleep to simulate execution time
        total_waiting_time += total_time - p[i].arrival_time - p[i].burst_time;
        total_time -= p[i].burst_time;
    }
    average_waiting_time = (float)total_waiting_time/n;
    printf("\n\nAverage Waiting Time: %.2f ms", average_waiting_time);
    return 0;
}