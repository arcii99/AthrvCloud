//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIO 10
#define QUANTUM 10

typedef struct _process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int wait_time;
    int turnaround_time;
} Process;

void fcfs_scheduling(Process *processes, int n); // First Come First Serve
void sjf_scheduling(Process *processes, int n); // Shortest Job First
void srtf_scheduling(Process *processes, int n); // Shortest Remaining Time First
void rr_scheduling(Process *processes, int n); // Round Robin
void p_scheduling(Process *processes, int n); // Priority

int main() {
    int i;
    Process processes[] = {
        {1, 1, 21, 5, 0, 0, 0},
        {2, 3, 3, 1, 0, 0, 0},
        {3, 4, 6, 3, 0, 0, 0},
        {4, 7, 2, 5, 0, 0, 0},
        {5, 9, 12, 2, 0, 0, 0}
    };
    int n = sizeof(processes) / sizeof(Process);

    fcfs_scheduling(processes, n);
    sjf_scheduling(processes, n);
    srtf_scheduling(processes, n);
    rr_scheduling(processes, n);
    p_scheduling(processes, n);

    return 0;
}

void fcfs_scheduling(Process *processes, int n) {
    int i, total_wait_time = 0, total_turnaround_time = 0;

    printf("First Come First Serve\n");
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].wait_time = 0;
        } else {
            processes[i].wait_time = processes[i - 1].burst_time + processes[i - 1].wait_time;
        }

        processes[i].turnaround_time = processes[i].burst_time + processes[i].wait_time;
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].wait_time, processes[i].turnaround_time);
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

void sjf_scheduling(Process *processes, int n) {
    int i, j, min_index, total_wait_time = 0, total_turnaround_time = 0;
    Process temp;

    printf("Shortest Job First\n");
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (processes[j].burst_time < processes[min_index].burst_time) {
                min_index = j;
            }
        }
        temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].wait_time = 0;
        } else {
            processes[i].wait_time = processes[i - 1].burst_time + processes[i - 1].wait_time;
        }

        processes[i].turnaround_time = processes[i].burst_time + processes[i].wait_time;
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].wait_time, processes[i].turnaround_time);
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

void srtf_scheduling(Process *processes, int n) {
    int i, j, min_index, smallest, remaining_jobs = n, clock = 0, total_wait_time = 0, total_turnaround_time = 0;
    Process *ready_queue[n];

    printf("Shortest Remaining Time First\n");
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    while (remaining_jobs > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= clock && processes[i].remaining_time > 0) {
                ready_queue[i] = &processes[i];
            } else {
                ready_queue[i] = NULL;
            }
        }

        smallest = MAX_PRIO;
        for (i = 0; i < n; i++) {
            if (ready_queue[i] != NULL && ready_queue[i]->remaining_time < smallest) {
                smallest = ready_queue[i]->remaining_time;
                min_index = i;
            }
        }

        clock += smallest;
        ready_queue[min_index]->remaining_time -= smallest;

        if (ready_queue[min_index]->remaining_time == 0) {
            remaining_jobs--;
            ready_queue[min_index]->turnaround_time = clock - ready_queue[min_index]->arrival_time;
            ready_queue[min_index]->wait_time = ready_queue[min_index]->turnaround_time - ready_queue[min_index]->burst_time;
            total_turnaround_time += ready_queue[min_index]->turnaround_time;
            total_wait_time += ready_queue[min_index]->wait_time;

            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", ready_queue[min_index]->pid, ready_queue[min_index]->arrival_time, ready_queue[min_index]->burst_time, ready_queue[min_index]->wait_time, ready_queue[min_index]->turnaround_time);
        }
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

void rr_scheduling(Process *processes, int n) {
    int i, remaining_jobs = n, clock = 0, total_wait_time = 0, total_turnaround_time = 0;
    Process *ready_queue[n];

    printf("Round Robin\n");
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    while (remaining_jobs > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= clock && processes[i].remaining_time > 0) {
                ready_queue[i] = &processes[i];
            } else {
                ready_queue[i] = NULL;
            }
        }

        for (i = 0; i < n; i++) {
            if (ready_queue[i] != NULL) {
                if (ready_queue[i]->remaining_time <= QUANTUM) {
                    clock += ready_queue[i]->remaining_time;
                    ready_queue[i]->turnaround_time = clock - ready_queue[i]->arrival_time;
                    ready_queue[i]->wait_time = ready_queue[i]->turnaround_time - ready_queue[i]->burst_time;
                    total_turnaround_time += ready_queue[i]->turnaround_time;
                    total_wait_time += ready_queue[i]->wait_time;

                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", ready_queue[i]->pid, ready_queue[i]->arrival_time, ready_queue[i]->burst_time, ready_queue[i]->wait_time, ready_queue[i]->turnaround_time);

                    remaining_jobs--;
                    ready_queue[i]->remaining_time = 0;
                } else {
                    clock += QUANTUM;
                    ready_queue[i]->remaining_time -= QUANTUM;
                }
            }
        }
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

void p_scheduling(Process *processes, int n) {
    int i, j, max_index, remaining_jobs = n, clock = 0, total_wait_time = 0, total_turnaround_time = 0;
    Process *ready_queue[n];

    printf("Priority\n");
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\tPriority\n");

    while (remaining_jobs > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= clock && processes[i].remaining_time > 0) {
                ready_queue[i] = &processes[i];
            } else {
                ready_queue[i] = NULL;
            }
        }

        max_index = -1;
        for (i = 0; i < n; i++) {
            if (ready_queue[i] != NULL && ready_queue[i]->priority > max_index) {
                max_index = ready_queue[i]->priority;
            }
        }

        for (i = 0; i < n; i++) {
            if (ready_queue[i] != NULL && ready_queue[i]->priority == max_index) {
                clock += ready_queue[i]->remaining_time;
                ready_queue[i]->remaining_time = 0;
                ready_queue[i]->turnaround_time = clock - ready_queue[i]->arrival_time;
                ready_queue[i]->wait_time = ready_queue[i]->turnaround_time - ready_queue[i]->burst_time;
                total_turnaround_time += ready_queue[i]->turnaround_time;
                total_wait_time += ready_queue[i]->wait_time;
                printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ready_queue[i]->pid, ready_queue[i]->arrival_time, ready_queue[i]->burst_time, ready_queue[i]->wait_time, ready_queue[i]->turnaround_time, ready_queue[i]->priority);
                remaining_jobs--;
            }
        }
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}