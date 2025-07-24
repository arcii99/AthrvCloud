//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LEN 30

typedef struct Process {
    char name[MAX_NAME_LEN];
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_burst_time;
} Process;

void generate_processes(Process processes[MAX_PROCESSES], int max_processes, int max_burst_time) {
    char process_names[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int i;
    srand(time(NULL));
    for (i = 0; i < max_processes; i++) {
        strcpy(processes[i].name, &process_names[i]);
        processes[i].arrival_time = rand() % 11; // random arrival time from 0 to 10
        processes[i].burst_time = rand() % (max_burst_time + 1); // random burst time from 0 to max_burst_time
        processes[i].priority = rand() % 11; // random priority from 0 to 10
        processes[i].remaining_burst_time = processes[i].burst_time;
    }
}

void print_processes(Process processes[MAX_PROCESSES], int max_processes) {
    int i;
    printf("Name\tArrival Time\tBurst Time\tPriority\n");
    for (i = 0; i < max_processes; i++) {
        printf("%s\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
}

void run_FCFS(Process processes[MAX_PROCESSES], int max_processes) {
    int i, j;
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    printf("\nFCFS Schedule:\n\n");
    printf("Time\tName\n");
    for (i = 0; i < max_processes; i++) {
        printf("%d\t%s\n", current_time, processes[i].name);
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        avg_waiting_time += current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        avg_turnaround_time += current_time - processes[i].arrival_time;
    }
    printf("%d\tIdle\n", current_time);
    avg_waiting_time /= max_processes;
    avg_turnaround_time /= max_processes;
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

void run_SJF(Process processes[MAX_PROCESSES], int max_processes) {
    int i, j;
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    printf("\nSJF Schedule:\n\n");
    printf("Time\tName\n");
    for (i = 0; i < max_processes; i++) {
        int shortest_burst_time = -1;
        int shortest_burst_time_index = -1;
        for (j = 0; j < max_processes; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].remaining_burst_time > 0) {
                if (shortest_burst_time == -1 || processes[j].remaining_burst_time < shortest_burst_time) {
                    shortest_burst_time = processes[j].remaining_burst_time;
                    shortest_burst_time_index = j;
                }
            }
        }
        if (shortest_burst_time_index == -1) {
            printf("%d\tIdle\n", current_time);
            current_time++;
            i--;
            continue;
        }
        printf("%d\t%s\n", current_time, processes[shortest_burst_time_index].name);
        if (current_time < processes[shortest_burst_time_index].arrival_time) {
            current_time = processes[shortest_burst_time_index].arrival_time;
        }
        avg_waiting_time += current_time - processes[shortest_burst_time_index].arrival_time;
        current_time += processes[shortest_burst_time_index].remaining_burst_time;
        processes[shortest_burst_time_index].remaining_burst_time = 0;
        avg_turnaround_time += current_time - processes[shortest_burst_time_index].arrival_time;
    }
    printf("%d\tIdle\n", current_time);
    avg_waiting_time /= max_processes;
    avg_turnaround_time /= max_processes;
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

void run_priority(Process processes[MAX_PROCESSES], int max_processes) {
    int i, j;
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    printf("\nPriority Schedule:\n\n");
    printf("Time\tName\n");
    for (i = 0; i < max_processes; i++) {
        int highest_priority = -1;
        int highest_priority_index = -1;
        for (j = 0; j < max_processes; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].remaining_burst_time > 0) {
                if (highest_priority == -1 || processes[j].priority < highest_priority) {
                    highest_priority = processes[j].priority;
                    highest_priority_index = j;
                }
            }
        }
        if (highest_priority_index == -1) {
            printf("%d\tIdle\n", current_time);
            current_time++;
            i--;
            continue;
        }
        printf("%d\t%s\n", current_time, processes[highest_priority_index].name);
        if (current_time < processes[highest_priority_index].arrival_time) {
            current_time = processes[highest_priority_index].arrival_time;
        }
        avg_waiting_time += current_time - processes[highest_priority_index].arrival_time;
        current_time += processes[highest_priority_index].remaining_burst_time;
        processes[highest_priority_index].remaining_burst_time = 0;
        avg_turnaround_time += current_time - processes[highest_priority_index].arrival_time;
    }
    printf("%d\tIdle\n", current_time);
    avg_waiting_time /= max_processes;
    avg_turnaround_time /= max_processes;
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

int main() {
    Process processes[MAX_PROCESSES];
    int max_processes = 5;
    int max_burst_time = 10;
    srand(time(NULL));
    generate_processes(processes, max_processes, max_burst_time);
    print_processes(processes, max_processes);
    run_FCFS(processes, max_processes);
    run_SJF(processes, max_processes);
    run_priority(processes, max_processes);
    return 0;
}