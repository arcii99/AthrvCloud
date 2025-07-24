//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }
        p[i].completion_time = time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        time = p[i].completion_time;
    }
}

void sjf(struct process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        int shortest = i;
        for (int j = i+1; j < n; j++) {
            if (p[j].arrival_time <= time && p[j].burst_time < p[shortest].burst_time) {
                shortest = j;
            }
        }
        if (shortest != i) {
            struct process temp = p[i];
            p[i] = p[shortest];
            p[shortest] = temp;
        }
        p[i].completion_time = time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        time = p[i].completion_time;
    }
}

int main() {
    struct process p[] = {{1, 0, 5}, {2, 2, 3}, {3, 4, 1}, {4, 5, 8}, {5, 6, 2}};
    int n = sizeof(p)/sizeof(p[0]);
    
    printf("FCFS\n");
    fcfs(p, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: completion time=%d, turnaround time=%d, waiting time=%d\n", p[i].pid, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    
    printf("\nSJF\n");
    sjf(p, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: completion time=%d, turnaround time=%d, waiting time=%d\n", p[i].pid, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    
    return 0;
}