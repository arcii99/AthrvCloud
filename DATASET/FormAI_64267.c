//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>

// Struct for holding information about a process
typedef struct {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingBurstTime;
} Process;

// Function for sorting an array of processes by arrival time
void sortByArrivalTime(Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
                // Swap the positions of the two processes
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function for sorting an array of processes by priority
void sortByPriority(Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[i].priority < processes[j].priority) {
                // Swap the positions of the two processes
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to simulate Shortest Job First scheduling
void SJF(Process processes[], int numProcesses) {
    sortByArrivalTime(processes, numProcesses);
    int currentTime = processes[0].arrivalTime;
    int completedProcesses = 0;
    while (completedProcesses < numProcesses) {
        // Sort the remaining processes by burst time
        int remainingProcesses = numProcesses - completedProcesses;
        sortByArrivalTime(processes + completedProcesses, remainingProcesses);
        // Find the process with the shortest burst time
        int shortestJobIndex = completedProcesses;
        for (int i = completedProcesses + 1; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime) {
                if (processes[i].remainingBurstTime < processes[shortestJobIndex].remainingBurstTime) {
                    shortestJobIndex = i;
                }
            } else {
                break; // The remaining processes haven't arrived yet
            }
        }
        // Execute the shortest job
        Process *shortestJob = &processes[shortestJobIndex];
        shortestJob->remainingBurstTime--;
        currentTime++;
        if (shortestJob->remainingBurstTime == 0) {
            // The process has completed
            completedProcesses++;
        }
    }
}

// Function to simulate Priority scheduling
void priority(Process processes[], int numProcesses) {
    sortByArrivalTime(processes, numProcesses);
    int currentTime = processes[0].arrivalTime;
    int completedProcesses = 0;
    while (completedProcesses < numProcesses) {
        // Sort the remaining processes by priority
        int remainingProcesses = numProcesses - completedProcesses;
        sortByArrivalTime(processes + completedProcesses, remainingProcesses);
        sortByPriority(processes + completedProcesses, remainingProcesses);
        // Find the process with the highest priority
        int highestPriorityIndex = completedProcesses;
        for (int i = completedProcesses + 1; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime) {
                if (processes[i].priority > processes[highestPriorityIndex].priority) {
                    highestPriorityIndex = i;
                }
            } else {
                break; // The remaining processes haven't arrived yet
            }
        }
        // Execute the process with the highest priority
        Process *highestPriority = &processes[highestPriorityIndex];
        highestPriority->remainingBurstTime--;
        currentTime++;
        if (highestPriority->remainingBurstTime == 0) {
            // The process has completed
            completedProcesses++;
        }
    }
}

int main() {
    // Create an array of processes
    Process processes[] = {
        {1, 0, 8, 3, 8},
        {2, 1, 4, 1, 4},
        {3, 2, 9, 2, 9},
        {4, 3, 5, 3, 5},
        {5, 4, 2, 2, 2}
    };
    int numProcesses = sizeof(processes) / sizeof(Process);
    // Run the SJF algorithm on the processes
    printf("Shortest Job First:\n");
    SJF(processes, numProcesses);
    // Reset the remaining burst times
    for (int i = 0; i < numProcesses; i++) {
        processes[i].remainingBurstTime = processes[i].burstTime;
    }
    // Run the priority algorithm on the processes
    printf("\nPriority:\n");
    priority(processes, numProcesses);
    return 0;
}