//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

typedef enum {
    FCFS,
    SJF,
    ROUND_ROBIN,
    RANDOM
} SchedulingAlgorithm;

void print_process(Process p) {
    printf("Process %d:\n", p.id);
    printf("Arrival time: %d\n", p.arrival_time);
    printf("Burst time: %d\n", p.burst_time);
    printf("Completion time: %d\n", p.completion_time);
    printf("Waiting time: %d\n", p.waiting_time);
    printf("Turnaround time: %d\n", p.turnaround_time);
}

void print_processes(Process processes[NUM_PROCESSES]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        Process p = processes[i];
        print_process(p);
        printf("\n");
    }
}

void swap_processes(Process* p1, Process* p2) {
    Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_processes_by_arrival_time(Process processes[NUM_PROCESSES]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = i+1; j < NUM_PROCESSES; j++) {
            if (processes[j].arrival_time < processes[i].arrival_time) {
                swap_processes(&processes[i], &processes[j]);
            }
        }
    }
}

void sort_processes_by_burst_time(Process processes[NUM_PROCESSES]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = i+1; j < NUM_PROCESSES; j++) {
            if (processes[j].burst_time < processes[i].burst_time) {
                swap_processes(&processes[i], &processes[j]);
            }
        }
    }
}

void simulate_fcfs(Process processes[NUM_PROCESSES]) {
    printf("Running FCFS scheduling algorithm...\n\n");
    sort_processes_by_arrival_time(processes);
    int time = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        Process p = processes[i];
        p.remaining_time = p.burst_time;
        if (time < p.arrival_time) {
            time = p.arrival_time;
        }
        p.completion_time = time + p.remaining_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
        time = p.completion_time;
        processes[i] = p;
    }
    print_processes(processes);
}

void simulate_sjf(Process processes[NUM_PROCESSES]) {
    printf("Running SJF scheduling algorithm...\n\n");
    sort_processes_by_arrival_time(processes);
    int time = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        Process* shortest = NULL;
        for (int j = i; j < NUM_PROCESSES; j++) {
            Process* p = &processes[j];
            if (p->arrival_time <= time && p->remaining_time > 0) {
                if (shortest == NULL || p->burst_time < shortest->burst_time) {
                    shortest = p;
                }
            }
        }
        if (shortest == NULL) {
            time++;
            i--;
            continue;
        }
        shortest->remaining_time--;
        if (shortest->remaining_time == 0) {
            shortest->completion_time = time+1;
            shortest->turnaround_time = shortest->completion_time - shortest->arrival_time;
            shortest->waiting_time = shortest->turnaround_time - shortest->burst_time;
        }
        time++;
    }
    print_processes(processes);
}

void simulate_round_robin(Process processes[NUM_PROCESSES], int quantum) {
    printf("Running Round Robin scheduling algorithm with quantum=%d...\n\n", quantum);
    sort_processes_by_arrival_time(processes);
    int time = 0;
    int num_completed = 0;
    while (num_completed < NUM_PROCESSES) {
        for (int i = 0; i < NUM_PROCESSES; i++) {
            Process* p = &processes[i];
            if (p->arrival_time <= time && p->remaining_time > 0) {
                p->remaining_time -= quantum;
                if (p->remaining_time < 0) {
                    time += quantum + p->remaining_time;
                    p->remaining_time = 0;
                } else {
                    time += quantum;
                }
                if (p->remaining_time == 0) {
                    num_completed++;
                    p->completion_time = time;
                    p->turnaround_time = p->completion_time - p->arrival_time;
                    p->waiting_time = p->turnaround_time - p->burst_time;
                }
            }
        }
    }
    print_processes(processes);
}

void simulate_random(Process processes[NUM_PROCESSES], SchedulingAlgorithm algorithm) {
    printf("Running %s scheduling algorithm...\n\n", algorithm == RANDOM ? "random" : "unknown");
    sort_processes_by_arrival_time(processes);
    int time = 0;
    int num_completed = 0;
    while (num_completed < NUM_PROCESSES) {
        int i = rand() % NUM_PROCESSES;
        Process* p = &processes[i];
        if (p->arrival_time <= time && p->remaining_time > 0) {
            if (algorithm == RANDOM) {
                int r = rand() % 2;
                if (r == 0) {
                    p->remaining_time--;
                }
            } else {
                printf("Unknown scheduling algorithm %d\n", algorithm);
                return;
            }
            if (p->remaining_time == 0) {
                num_completed++;
                p->completion_time = time+1;
                p->turnaround_time = p->completion_time - p->arrival_time;
                p->waiting_time = p->turnaround_time - p->burst_time;
            }
        }
        time++;
    }
    print_processes(processes);
}

int main() {
    Process processes[NUM_PROCESSES] = {
        { 0, 0, 10 },
        { 1, 0, 1 },
        { 2, 0, 2 },
        { 3, 1, 1 },
        { 4, 1, 5 },
        { 5, 2, 3 },
        { 6, 2, 4 },
        { 7, 3, 2 },
        { 8, 3, 1 },
        { 9, 4, 2 },
    };
    srand(time(0));
    printf("Initial processes:\n\n");
    print_processes(processes);
    printf("\n");
    simulate_fcfs(processes);
    printf("\n");
    simulate_sjf(processes);
    printf("\n");
    simulate_round_robin(processes, 2);
    printf("\n");
    simulate_random(processes, RANDOM);
    printf("\n");
    return 0;
}