//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROCESSES 5

typedef struct {
    int process_id;
    int burst_time;
} process_t;

void execute_process(process_t process) {
    printf("Executing Process %d for %d seconds...\n\n", process.process_id, process.burst_time);
    sleep(process.burst_time);
}

int main() {
    int i, j;
    process_t processes[NUM_PROCESSES] = {
        {1, 10},
        {2, 3},
        {3, 7},
        {4, 4},
        {5, 5}
    };

    printf("Starting Task Scheduler...\n\n");

    printf("Process Schedule\n");
    printf("---------------------------\n");
    for(i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d | Burst Time: %d sec\n", processes[i].process_id, processes[i].burst_time);
    }
    printf("---------------------------\n\n");

    printf("Executing Processes...\n\n");

    for(i = 0; i < NUM_PROCESSES; i++) {
        execute_process(processes[i]);
    }

    printf("Task Scheduler Complete!\n");

    return 0;
}