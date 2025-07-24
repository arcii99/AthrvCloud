//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
} process;

void print_table(process p[], int n, int waiting_time[], int turnaround_time[]) {
    int total_wait_time = 0;
    int total_tat = 0;

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, waiting_time[i], turnaround_time[i]);
        total_wait_time += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage waiting time = %.2f\n", (float) total_wait_time / (float) n);
    printf("Average turnaround time = %.2f\n", (float) total_tat / (float) n);
}

void fcfs(process p[], int n) {
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time > current_time) {
            current_time = p[i].arrival_time;
        }

        waiting_time[i] = current_time - p[i].arrival_time;
        turnaround_time[i] = waiting_time[i] + p[i].burst_time;

        current_time += p[i].burst_time;
    }

    print_table(p, n, waiting_time, turnaround_time);
}

void sjf(process p[], int n) {
    int waiting_time[n], turnaround_time[n];
    bool finished[n];
    int total_waiting_time = 0, total_turnaround_time = 0, shortest;
    int current_time = 0;

    memset(finished, false, sizeof(finished));

    while (true) {
        shortest = -1;

        for (int i = 0; i < n; i++) {
            if (!finished[i] && p[i].arrival_time <= current_time) {
                if (shortest == -1 || p[i].burst_time < p[shortest].burst_time) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            break;
        }

        waiting_time[shortest] = current_time - p[shortest].arrival_time;
        turnaround_time[shortest] = waiting_time[shortest] + p[shortest].burst_time;

        current_time += p[shortest].burst_time;
        finished[shortest] = true;

        total_waiting_time += waiting_time[shortest];
        total_turnaround_time += turnaround_time[shortest];
    }

    print_table(p, n, waiting_time, turnaround_time);
}

void rr(process p[], int n, int quantum) {
    int waiting_time[n], turnaround_time[n];
    int remaining_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0, time = 0;

    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false;

                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - p[i].burst_time - p[i].arrival_time;
                    turnaround_time[i] = time - p[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (done) {
            break;
        }
    }

    print_table(p, n, waiting_time, turnaround_time);
}

int main() {
    int n, algorithm, quantum;
    process p[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time for process %d: ", i);

        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
        p[i].pid = i;
    }

    printf("\nSelect CPU scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");

    scanf("%d", &algorithm);

    switch (algorithm) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            printf("Enter the quantum: ");
            scanf("%d", &quantum);
            rr(p, n, quantum);
            break;
        default:
            printf("Invalid selection\n");
    }

    return 0;
}