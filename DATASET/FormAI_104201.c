//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// process structure
typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

// function prototypes
void fcfs(Process *p, int n);
void sjf(Process *p, int n);
void priority(Process *p, int n);

int main(void) {
    // sample data
    Process processes[] = {
        {1, 6, 0, 0, 0, 6},
        {2, 8, 1, 0, 0, 8},
        {3, 7, 2, 0, 0, 7},
        {4, 3, 3, 0, 0, 3},
        {5, 2, 4, 0, 0, 2}
    };
    int n = sizeof(processes) / sizeof(Process);

    // run FCFS
    printf("First Come First Serve (FCFS):\n");
    fcfs(processes, n);

    // run SJF
    printf("\nShortest Job First (SJF):\n");
    sjf(processes, n);

    // run Priority
    printf("\nPriority:\n");
    priority(processes, n);

    return 0;
}

// First Come First Serve (FCFS) algorithm
void fcfs(Process *p, int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // sort by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate waiting and turnaround time
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p[i].waiting_time = 0;
        } else {
            p[i].waiting_time = p[i - 1].burst_time + p[i - 1].waiting_time;
        }
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    // print results
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    printf("Average Waiting Time: %.2lf\nAverage Turnaround Time: %.2lf\n", avg_waiting_time, avg_turnaround_time);
}

// Shortest Job First (SJF) algorithm
void sjf(Process *p, int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // sort by burst time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate waiting and turnaround time
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = current_time - p[i].arrival_time;
        if (i == 0) {
            p[i].waiting_time = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (p[j].remaining_time > 0 && p[j].remaining_time < p[i].burst_time) {
                    p[i].waiting_time += p[j].remaining_time;
                }
            }
        }
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        current_time += p[i].burst_time;
        p[i].remaining_time = 0;
    }

    // print results
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    printf("Average Waiting Time: %.2lf\nAverage Turnaround Time: %.2lf\n", avg_waiting_time, avg_turnaround_time);
}

// Priority algorithm
void priority(Process *p, int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // sort by priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate waiting and turnaround time
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        int highest_priority = -1;
        int highest_priority_index;
        for (int j = 0; j < n; j++) {
            if (p[j].arrival_time <= current_time && p[j].remaining_time > 0 && p[j].burst_time >= highest_priority) {
                highest_priority = p[j].burst_time;
                highest_priority_index = j;
            }
        }
        p[highest_priority_index].waiting_time = current_time - p[highest_priority_index].arrival_time;
        if (i == 0) {
            p[highest_priority_index].waiting_time = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (p[j].remaining_time > 0 && p[j].burst_time >= highest_priority) {
                    p[highest_priority_index].waiting_time += p[j].remaining_time;
                }
            }
        }
        p[highest_priority_index].turnaround_time = p[highest_priority_index].burst_time + p[highest_priority_index].waiting_time;
        total_waiting_time += p[highest_priority_index].waiting_time;
        total_turnaround_time += p[highest_priority_index].turnaround_time;
        current_time += p[highest_priority_index].burst_time;
        p[highest_priority_index].remaining_time = 0;
    }

    // print results
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    printf("Average Waiting Time: %.2lf\nAverage Turnaround Time: %.2lf\n", avg_waiting_time, avg_turnaround_time);
}