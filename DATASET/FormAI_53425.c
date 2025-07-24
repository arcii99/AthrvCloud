//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define QUANTUM_TIME 4

// define process struct
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

// function to calculate waiting and turnaround time for each process
void calculate_times(Process *processes, int n) {
    int total_time = 0;
    int time = 0;
    int completed_processes = 0;
    bool all_processes_completed = false;

    // initialize remaining time for each process
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    // run round robin scheduling algorithm
    while (!all_processes_completed) {
        all_processes_completed = true;
        for (int i = 0; i < n; i++) {
            Process *p = &processes[i];
            if (p->remaining_time > 0) {
                all_processes_completed = false;
                if (p->remaining_time > QUANTUM_TIME) {
                    // run process for quantum time
                    time += QUANTUM_TIME;
                    p->remaining_time -= QUANTUM_TIME;
                } else {
                    // run process until completion
                    time += p->remaining_time;
                    p->waiting_time = time - p->arrival_time - p->burst_time;
                    p->remaining_time = 0;
                    p->turnaround_time = time - p->arrival_time;
                    completed_processes++;
                }
            }
        }
    }

    // print results
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        Process p = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p.pid, p.arrival_time, p.burst_time, p.waiting_time, p.turnaround_time);
        total_time += p.turnaround_time;
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_time / n);
}

int main() {
    // initialize processes
    Process processes[MAX_PROCESSES] = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 4},
        {4, 3, 2},
        {5, 4, 1}
    };

    calculate_times(processes, 5);

    return 0;
}