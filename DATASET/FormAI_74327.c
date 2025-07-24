//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
// The Knight's Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_BURST_TIME 10
#define MAX_PRIORITY 10

struct Process {
    int id;
    int burst_time;
    int priority;
    int arrival_time;
    int remaining_time;
};

void initialize_processes(struct Process* processes) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        processes[i].id = i + 1;
        processes[i].burst_time = (rand() % MAX_BURST_TIME) + 1;
        processes[i].priority = (rand() % MAX_PRIORITY) + 1;
        processes[i].arrival_time = rand() % 5;
        processes[i].remaining_time = processes[i].burst_time;
    }
}

void print_processes(struct Process* processes) {
    printf("Process\tBurst Time\tPriority\tArrival Time\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].priority, processes[i].arrival_time);
    }
}

void knight_scheduling(struct Process* processes) {
    int time = 0;
    int completed = 0;
    int current_process = -1;

    while (completed < N) {
        int highest_priority = -1;
        for (int i = 0; i < N; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (processes[i].priority > highest_priority) {
                    highest_priority = processes[i].priority;
                    current_process = i;
                }
            }
        }

        if (current_process == -1) {
            printf("Idle for 1 second\n");
            time++;
            continue;
        }

        printf("Knight is executing process %d for 1 second\n", processes[current_process].id);
        processes[current_process].remaining_time--;
        time++;

        if (processes[current_process].remaining_time == 0) {
            printf("Process %d has completed at time %d\n", processes[current_process].id, time);
            completed++;
            current_process = -1;
        }
    }
}

int main() {
    struct Process processes[N];
    initialize_processes(processes);
    print_processes(processes);
    knight_scheduling(processes);
    return 0;
}