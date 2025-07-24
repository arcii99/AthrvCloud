//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

// Structure to store Process Details
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
};

// Function to Swap two Processes
void swapProcesses(struct Process* a, struct Process* b) {
    struct Process t = *a;
    *a = *b;
    *b = t;
}

// Function to Sort Processes based on Arrival Time
void sortProcesses(struct Process* processes, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                swapProcesses(&processes[j], &processes[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// Function to Simulate Execution of Processes using SJF Algorithm
void SJF(struct Process* processes, int n) {
    int time = 0;
    int completedProcesses = 0;
    while (completedProcesses < n) {
        int indexOfNextProcess = -1;
        int minimumBurstTime = 1000000;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime < minimumBurstTime && processes[i].remainingTime > 0) {
                minimumBurstTime = processes[i].remainingTime;
                indexOfNextProcess = i;
            }
        }
        if (indexOfNextProcess == -1) { 
            time++;
            continue;
        }
        // Execution of Process
        processes[indexOfNextProcess].remainingTime--;
        // Update Completion Time of Process
        if (processes[indexOfNextProcess].remainingTime == 0) {
            completedProcesses++;
            processes[indexOfNextProcess].completionTime = time + 1;
        }
        time++;
    }
    // Calculate Total Time Taken and Waiting Time for Each Process
    int totalTimeTaken = 0;
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        int timeTaken = processes[i].completionTime - processes[i].arrivalTime;
        int waitingTime = timeTaken - processes[i].burstTime;
        totalTimeTaken += timeTaken;
        totalWaitingTime += waitingTime;
    }
    // Display Results
    printf("Total Time Taken: %d\n", totalTimeTaken);
    printf("Average Waiting Time: %.2f\n", (double)totalWaitingTime / n);
}

int main() {
    // Initialize Random Seed
    srand(time(0));
    // Generate Random Processes
    int n = 10;
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].processID = i;
        processes[i].arrivalTime = rand() % 10;
        processes[i].burstTime = rand() % 10 + 1;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completionTime = -1;
    }
    // Sort Processes based on Arrival Time
    sortProcesses(processes, n);
    // Simulate Execution of Processes using SJF Algorithm
    SJF(processes, n);
    // Exit Program
    return 0;
}