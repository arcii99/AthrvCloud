//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
    int completed;
} Process;

void round_robin_scheduling(Process* processes, int n) {
    int time_elapsed = 0;
    int completed_processes = 0;
    int front = 0;
    int rear = -1;
    int queue[MAX_PROCESSES];

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time == time_elapsed) {
                processes[i].remaining_time = processes[i].burst_time;
                enqueue(queue, &rear, i);
            }
        }

        if (front <= rear) {
            Process* current_process = &processes[queue[front]];
            if (current_process->remaining_time <= TIME_QUANTUM) {
                time_elapsed += current_process->remaining_time;
                current_process->turnaround_time = time_elapsed - current_process->arrival_time;
                current_process->waiting_time = current_process->turnaround_time - current_process->burst_time;
                current_process->completed = 1;
                front++;
                completed_processes++;
            } else {
                time_elapsed += TIME_QUANTUM;
                current_process->remaining_time -= TIME_QUANTUM;
                enqueue(queue, &rear, dequeue(queue, &front));
            }
        } else {
            time_elapsed++;
        }
    }
}

void display_results(Process* processes, int n) {
    printf("Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {0, 0, 5, 0, 0, 0, 0},
        {1, 1, 3, 0, 0, 0, 0},
        {2, 2, 8, 0, 0, 0, 0},
        {3, 3, 6, 0, 0, 0, 0},
        {4, 4, 9, 0, 0, 0, 0}
    };

    round_robin_scheduling(processes, 5);
    display_results(processes, 5);

    return 0;
}

int dequeue(int queue[], int *front) {
    int data = queue[*front];
    (*front)++;
    return data;
}

void enqueue(int queue[], int *rear, int element) {
    (*rear)++;
    queue[*rear] = element;
}