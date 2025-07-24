//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PREEMPTIVE 1
#define NON_PREEMPTIVE 0

#define MAX_PROCESSES 10
#define MIN_ARRIVAL_TIME 0
#define MAX_ARRIVAL_TIME 10
#define MIN_BURST_TIME 1
#define MAX_BURST_TIME 20

typedef struct process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} process;

typedef struct queue {
    process* arr[MAX_PROCESSES];
    int front;
    int rear;
    int size;
} queue;

void init_queue(queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(queue* q, process* p) {
    q->arr[++q->rear] = p;
    ++q->size;
}

process* dequeue(queue* q) {
    if (q->size == 0) return NULL;
    process* p = q->arr[q->front++];
    --q->size;
    return p;
}

int is_queue_empty(queue* q) {
    return (q->size == 0);
}

void display_queue(queue* q) {
    printf("Queue-> front: %d rear: %d\n", q->front, q->rear);
    for (int i = q->front; i <= q->rear; i++) {
        printf("id: %d arrival_time: %d burst_time: %d remaining_time: %d\n", q->arr[i]->id, q->arr[i]->arrival_time, q->arr[i]->burst_time, q->arr[i]->remaining_time);
    }
}

void display_processes(process* processes, int n) {
    printf("id\tarrival_time\tburst_time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    }
}

void fcfs_scheduling (process* processes, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    for (int i = 0; i < n; i++) {
        current_time += processes[i].arrival_time - current_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

void sjf_scheduling (process* processes, int n) {
    int current_time = 0;
    int completed = 0;
    process* min_burst_time_process = NULL;
    while (completed < n) {
        min_burst_time_process = NULL;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (min_burst_time_process == NULL || processes[i].remaining_time < min_burst_time_process->remaining_time) {
                    min_burst_time_process = &processes[i];
                }
            }
        }
        if (min_burst_time_process == NULL) {
            current_time++;
            continue;
        }
        min_burst_time_process->remaining_time--;
        if (min_burst_time_process->remaining_time == 0) {
            min_burst_time_process->completion_time = current_time + 1;
            min_burst_time_process->turnaround_time = min_burst_time_process->completion_time - min_burst_time_process->arrival_time;
            min_burst_time_process->waiting_time = min_burst_time_process->turnaround_time - min_burst_time_process->burst_time;
            completed++;
        }
        current_time++;
    }
}

void rr_scheduling (process* processes, int n, int time_quantum) {
    int current_time = 0;
    int completed = 0;
    queue q;
    init_queue(&q);
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                enqueue(&q, &processes[i]);
            }
        }
        if (is_queue_empty(&q)) {
            current_time++;
            continue;
        }
        process* p = dequeue(&q);
        if (p->remaining_time <= time_quantum) {
            current_time += p->remaining_time;
            p->remaining_time = 0;
            p->completion_time = current_time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            completed++;
        } else {
            current_time += time_quantum;
            p->remaining_time -= time_quantum;
            enqueue(&q, p);
        }
    }
}

int main() {

    srand(time(NULL));

    int n = rand() % MAX_PROCESSES + 1;
    process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = rand() % (MAX_ARRIVAL_TIME - MIN_ARRIVAL_TIME + 1) + MIN_ARRIVAL_TIME;
        processes[i].burst_time = rand() % (MAX_BURST_TIME - MIN_BURST_TIME + 1) + MIN_BURST_TIME;
    }

    printf("Processes before scheduling:\n");
    display_processes(processes, n);

    int scheduling_algorithm = rand() % 3;
    printf("Selected scheduling algorithm: ");
    switch (scheduling_algorithm) {
        case 0:
            printf("FCFS (First-Come, First-Served)\n");
            fcfs_scheduling(processes, n);
            break;
        case 1:
            printf("SJF (Shortest Job First)\n");
            sjf_scheduling(processes, n);
            break;
        case 2:
            printf("RR (Round Robin)\n");
            int time_quantum = rand() % MAX_BURST_TIME + 1;
            printf("Time Quantum: %d\n", time_quantum);
            rr_scheduling(processes, n, time_quantum);
            break;
        default:
            printf("FCFS (First-Come, First-Served)\n");
            fcfs_scheduling(processes, n);
            break;
    }

    printf("Processes after scheduling:\n");
    display_processes(processes, n);

    return 0;
}