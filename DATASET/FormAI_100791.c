//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid; // process ID
    int burst_time; // time for which process needs CPU
};

int time_quantum = 2; // default time quantum is 2

int min(int a, int b) {
    return (a < b) ? a : b;
}

void round_robin(struct Process processes[], int n, int remaining_time[]) {
    int done = 1;
    for (int i = 0; i < n; i++) {
        if (remaining_time[i] > 0) { // if there's a process with remaining time
            done = 0;
            if (remaining_time[i] > time_quantum) { // if process needs more CPU time
                remaining_time[i] -= time_quantum; // reduce remaining time
                printf("Process %d is executing for %d units\n", processes[i].pid, time_quantum);
            } else { // process can complete in this time quantum
                printf("Process %d is executing for %d units\n", processes[i].pid, remaining_time[i]);
                remaining_time[i] = 0; // set remaining time as 0, process is complete
            }
        }
    }
    if (done)
        return;
    round_robin(processes, n, remaining_time); // recursive call
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
        remaining_time[i] = processes[i].burst_time;
    }
    round_robin(processes, n, remaining_time);
    return 0;
}