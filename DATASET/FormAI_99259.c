//FormAI DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

typedef struct {
    int pid;
    int priority;
} Process;

Process processes[MAX_PROCESSES];
int num_processes;

// Generate random processes with random priorities
void generate_processes() {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].priority = (rand() % (MAX_PRIORITY - MIN_PRIORITY + 1)) + MIN_PRIORITY;
    }
    num_processes = MAX_PROCESSES;
}

// Print the list of processes
void print_processes() {
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: Priority %d\n", processes[i].pid, processes[i].priority);
    }
}

// Sort the processes by priority (higher priority first)
void sort_processes() {
    int i, j;
    for (i = 0; i < num_processes; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].priority < processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    generate_processes();
    printf("Original list of processes:\n");
    print_processes();

    sort_processes();
    printf("\nOptimized list of processes:\n");
    print_processes();

    return 0;
}