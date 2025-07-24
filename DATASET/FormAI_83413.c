//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_BURST_TIME 10
#define TIME_QUANTUM 2
#define MAX_PRIORITY 10

/* Struct for process */
typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int priority;
} Process;

/* Global variables */
Process processes[MAX_PROCESSES];
int num_processes;

/* Function to initialize a process with random values */
void init_process(Process *p, int pid) {
    p->pid = pid;
    p->burst_time = rand() % MAX_BURST_TIME + 1;
    p->arrival_time = rand() % MAX_BURST_TIME + 1;
    p->remaining_time = p->burst_time;
    p->priority = rand() % MAX_PRIORITY + 1;
}

/* Function to print the current state of all processes */
void print_processes() {
    printf("Current state of processes:\n");
    printf("PID\tBurst time\tArrival time\tRemaining time\tPriority\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid,
               processes[i].burst_time, processes[i].arrival_time,
               processes[i].remaining_time, processes[i].priority);
    }
    printf("\n");
}

/* Function to simulate the First Come First Serve scheduling algorithm */
void fcfs() {
    printf("Executing First Come First Serve algorithm...\n");
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        printf("Process %d started execution at time %d\n", processes[i].pid, current_time);
        current_time += processes[i].burst_time;
        int turnaround_time = current_time - processes[i].arrival_time;
        total_waiting_time += turnaround_time - processes[i].burst_time;
        total_turnaround_time += turnaround_time;
        printf("Process %d finished execution at time %d\n", processes[i].pid, current_time);
    }
    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turnaround time: %d\n", total_turnaround_time);
    printf("Average waiting time: %.2f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", (float) total_turnaround_time / num_processes);
}

/* Function to simulate the Non-preemptive Priority scheduling algorithm */
void np_priority() {
    printf("Executing Non-preemptive Priority algorithm...\n");
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    while (true) {
        int highest_priority = MAX_PRIORITY + 1;
        int highest_priority_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time &&
                processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }
        if (highest_priority_index == -1) {
            break;
        }
        printf("Process %d started execution at time %d\n", processes[highest_priority_index].pid, current_time);
        current_time += processes[highest_priority_index].remaining_time;
        processes[highest_priority_index].remaining_time = 0;
        int turnaround_time = current_time - processes[highest_priority_index].arrival_time;
        total_waiting_time += turnaround_time - processes[highest_priority_index].burst_time;
        total_turnaround_time += turnaround_time;
        printf("Process %d finished execution at time %d\n", processes[highest_priority_index].pid, current_time);
    }
    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turnaround time: %d\n", total_turnaround_time);
    printf("Average waiting time: %.2f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", (float) total_turnaround_time / num_processes);
}

/* Function to simulate the Round Robin scheduling algorithm */
void round_robin() {
    printf("Executing Round Robin algorithm...\n");
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    while (true) {
        bool all_processes_completed = true;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                all_processes_completed = false;
                if (processes[i].arrival_time <= current_time) {
                    printf("Process %d started execution at time %d\n", processes[i].pid, current_time);
                    if (processes[i].remaining_time <= TIME_QUANTUM) {
                        current_time += processes[i].remaining_time;
                        processes[i].remaining_time = 0;
                        int turnaround_time = current_time - processes[i].arrival_time;
                        total_waiting_time += turnaround_time - processes[i].burst_time;
                        total_turnaround_time += turnaround_time;
                        printf("Process %d finished execution at time %d\n", processes[i].pid, current_time);
                    } else {
                        current_time += TIME_QUANTUM;
                        processes[i].remaining_time -= TIME_QUANTUM;
                        printf("Process %d remaining time: %d\n", processes[i].pid, processes[i].remaining_time);
                    }
                }
            }
        }
        if (all_processes_completed) {
            break;
        }
    }
    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turnaround time: %d\n", total_turnaround_time);
    printf("Average waiting time: %.2f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", (float) total_turnaround_time / num_processes);
}

/* Main function */
int main() {
    srand(time(NULL));

    /* Generate random processes */
    num_processes = rand() % MAX_PROCESSES + 1;
    for (int i = 0; i < num_processes; i++) {
        init_process(&processes[i], i + 1);
    }

    /* Print initial state of processes */
    print_processes();

    /* Simulate FCFS algorithm */
    fcfs();

    /* Simulate Non-preemptive Priority algorithm */
    np_priority();

    /* Simulate Round Robin algorithm */
    round_robin();

    return 0;
}