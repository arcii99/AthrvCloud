//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the process structure */
struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
};

/* Function to generate random priority */
int random_priority(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

/* Function to execute a process */
void execute(struct Process p) {
    printf("Executing process with PID %d\n", p.pid);
}

/* Function to sort the processes based on arrival time */
void sort_arrival_time(struct Process p[], int n) {
    struct Process temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

/* Function to implement Priority Scheduling algorithm */
void priority_scheduling(struct Process p[], int n) {
    int time = 0;
    while(1) {
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(p[i].burst_time > 0 && p[i].arrival_time <= time) {
                flag = 1;
                int highest_priority = 100;
                int next_process = -1;
                for(int j = 0; j < n; j++) {
                    if(p[j].burst_time > 0 && p[j].arrival_time <= time && p[j].priority < highest_priority) {
                        next_process = j;
                        highest_priority = p[j].priority;
                    }
                }
                if(next_process != -1) {
                    execute(p[next_process]);
                    p[next_process].burst_time--;
                    if(p[next_process].burst_time == 0) {
                        printf("Process with PID %d completed at time %d.\n", p[next_process].pid, time+1);
                    }
                }
            }
        }
        if(flag == 0) {
            break;
        }
        time++;
    }
}

/* Main function */
int main() {
    srand(time(0));
    int num_processes = 5;
    struct Process processes[num_processes];
    for(int i = 0; i < num_processes; i++) {
        processes[i].pid = i+1;
        processes[i].burst_time = (rand() % 10) + 1;
        processes[i].arrival_time = (rand() % 5) + 1;
        processes[i].priority = random_priority(1, 10);
    }
    printf("Processes:\n\n");
    printf("PID\tBurst Time\tArrival Time\tPriority\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].priority);
    }
    sort_arrival_time(processes, num_processes);
    printf("\nExecuting Processes using Priority Scheduling Algorithm:\n\n");
    priority_scheduling(processes, num_processes);
    return 0;
}