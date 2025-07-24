//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int bt;
    int rt;
};

void roundRobinScheduling(struct Process processes[], int n) {
    int quantum = 2; // Time quantum of 2 units
    int currentTime = 0;
    int completed = 0;

    // Loop until all processes are completed
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            // Check if the process is not completed and has a remaining burst time
            if (processes[i].rt > 0) {
                // Execute the process for the time quantum or its remaining burst time
                if (processes[i].rt <= quantum) {
                    currentTime += processes[i].rt;
                    processes[i].rt = 0;
                } else {
                    currentTime += quantum;
                    processes[i].rt -= quantum;
                }

                // Print the progress of the process
                printf("Process %d is executing at %d seconds.\n", processes[i].id, currentTime);

                // Check if the process is completed
                if (processes[i].rt == 0) {
                    printf("Process %d is completed at %d seconds.\n", processes[i].id, currentTime);
                    completed++;
                }
            }
        }
    }
}

int main() {
    // Initialize the processes
    struct Process processes[] = {{1, 8, 8}, {2, 4, 4}, {3, 5, 5}, {4, 2, 2}};
    int n = sizeof(processes) / sizeof(processes[0]);

    // Schedule the processes using Round Robin algorithm
    roundRobinScheduling(processes, n);

    return 0;
}