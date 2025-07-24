//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int burst_time;
    int priority;
} process;

void print_process(process p) {
    printf("PID: %d - Burst Time: %d - Priority: %d\n", p.pid, p.burst_time, p.priority);
}

int main() {
    srand(time(NULL));

    process queue[MAX_PROCESSES];
    int num_processes = rand() % MAX_PROCESSES + 1;

    printf("Welcome to the surrealist CPU scheduling algorithm!\n");
    printf("Generating %d processes...\n\n", num_processes);

    for (int i = 0; i < num_processes; i++) {
        queue[i].pid = i + 1;
        queue[i].burst_time = rand() % 10 + 1;
        queue[i].priority = rand() % 5 + 1;
        print_process(queue[i]);
    }

    printf("\nSorting processes by priority...\n\n");

    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (queue[i].priority > queue[j].priority) {
                process temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    printf("Processes sorted! Here's the new queue:\n\n");

    for (int i = 0; i < num_processes; i++) {
        print_process(queue[i]);
    }

    printf("\nSimulating CPU scheduling...\n\n");

    int total_time = 0;

    for (int i = 0; i < num_processes; i++) {
        total_time += queue[i].burst_time;
    }

    printf("Total CPU time required: %d\n\n", total_time);

    int current_time = 0;
    int current_process = 0;

    while (current_time < total_time) {
        if (queue[current_process].burst_time > 0) {
            printf("Running process %d...\n", queue[current_process].pid);
            queue[current_process].burst_time--;
            current_time++;
        }

        current_process = (current_process + 1) % num_processes;

        // introduce surrealism
        if (current_time % 4 == 0) {
            printf("The CPU is now drifting in a strange and compelling direction...\n");
            current_process = (current_process + 2) % num_processes;
        }

        // introduce more surrealism
        if (current_time % 7 == 0) {
            printf("The processes are now communicating in a language of their own devising...\n");
        }
    }

    printf("All processes completed! Exiting surrealist CPU scheduling algorithm...\n");

    return 0;
}