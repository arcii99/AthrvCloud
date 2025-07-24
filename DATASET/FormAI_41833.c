//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// define process structure
typedef struct process {
    int pid;        // process ID
    int burst_time; // process burst time
    int priority;   // process priority
    int waiting_time;   // process waiting time
    int turnaround_time;    // process turnaround time
} process;

// function to swap process values
void swap(process *xp, process *yp) {
    process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// function to perform bubble sort for priority scheduling
void bubbleSort(process* p, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].priority > p[j+1].priority) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

// function to perform FCFS scheduling
void fcfs(process* p, int n) {
    int i;
    p[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

int main() {
    // define number of processes
    int n = 5;
    process p[n];
    // assign process details
    p[0].pid = 1;
    p[0].burst_time = 6;
    p[0].priority = 3;
    p[1].pid = 2;
    p[1].burst_time = 2;
    p[1].priority = 1;
    p[2].pid = 3;
    p[2].burst_time = 8;
    p[2].priority = 2;
    p[3].pid = 4;
    p[3].burst_time = 3;
    p[3].priority = 4;
    p[4].pid = 5;
    p[4].burst_time = 4;
    p[4].priority = 5;
    // sort processes by priority
    bubbleSort(p, n);
    // perform FCFS scheduling
    fcfs(p, n);
    // display process details
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    return 0;
}