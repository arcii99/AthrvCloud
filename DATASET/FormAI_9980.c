//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct _process {
    char name[10];
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void sort(Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void sherlock_holmes(Process *processes, int n) {
    int current_time = processes[0].arrival_time;
    int remaining_time[MAX_PROCESSES];
    bool is_completed[MAX_PROCESSES];
    memset(is_completed, false, sizeof(is_completed));

    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    while (true) {
        bool all_completed = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_completed = false;
                if (remaining_time[i] > 2) {
                    current_time += 2;
                    remaining_time[i] -= 2;
                } else {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    is_completed[i] = true;
                }
            }
        }
        if (all_completed) {
            break;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    processes[0] = (Process) { "P1", 0, 6 };
    processes[1] = (Process) { "P2", 1, 8 };
    processes[2] = (Process) { "P3", 2, 7 };
    processes[3] = (Process) { "P4", 3, 3 };

    int n = sizeof(processes) / sizeof(processes[0]);

    sort(processes, n);

    sherlock_holmes(processes, n);

    printf("Name\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
            processes[i].name, processes[i].arrival_time, processes[i].burst_time,
            processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}