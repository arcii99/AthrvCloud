//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Structure to hold process information */
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
};

/* Function to sort the processes based on arrival time */
void sort_by_arrival_time(struct process processes[], int n) {
    int i, j;
    struct process temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

/* Function to implement the Round Robin scheduling */
void round_robin(struct process processes[], int n, int tq) {
    int remaining_burst_time[n];
    int t = 0; /* Current time */
    int i, j;
    int completed = 0; /* Number of completed processes */
    int cpu_idle = 0; /* Whether CPU is idle */

    /* Initialize remaining burst times */
    for(i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    /* Execute processes */
    while(completed < n) {
        cpu_idle = 1; /* Assume CPU is idle*/
        for(i = 0; i < n; i++) {
            if(processes[i].arrival_time <= t && remaining_burst_time[i] > 0) {
                /* CPU is not idle when a process is found */
                cpu_idle = 0; 

                /* Execute the process */
                if(remaining_burst_time[i] <= tq) {
                    t += remaining_burst_time[i];
                    processes[i].burst_time = 0;
                } 
                else {
                    t += tq;
                    remaining_burst_time[i] -= tq;
                }

                /* Check if process is completed */
                if(processes[i].burst_time == 0) {
                    completed++;
                    printf("\nProcess %d completed at time %d\n", processes[i].pid, t);
                }
            }
        }
        /* If CPU is idle, waste a unit of time */
        if(cpu_idle == 1) {
            t++;
        }
    }
}

/* Function to generate processes */
void generate_processes(struct process processes[], int n) {
    srand(time(0));
    int i;
    for(i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 50;
        processes[i].burst_time = rand() % 20 + 1;
        processes[i].priority = rand() % 5;
    }
}

int main() {
    int n = 5; /* Number of processes */
    int tq = 3; /* Time quantum */
    struct process processes[n];
    generate_processes(processes, n);

    printf("Processes generated:\n");
    printf("PID\tAT\tBT\tPriority\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }

    /* Sort the processes according to arrival time */
    sort_by_arrival_time(processes, n);

    /* Execute the round robin scheduling */
    printf("\nExecuting Round Robin scheduling...\n");
    round_robin(processes, n, tq);

    return 0;
}