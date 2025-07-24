//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Process struct to store information about each process
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

// Function to calculate the waiting and turnaround time of each process using Shortest Job First scheduling algorithm
void shortestJobFirst(struct Process processList[], int n) {
    // Sort the processes based on their burst time
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(processList[j].burstTime > processList[j+1].burstTime) {
                struct Process temp = processList[j];
                processList[j] = processList[j+1];
                processList[j+1] = temp;
            }
        }
    }
    
    // Calculate waiting and turnaround time for each process
    int currentTime = 0;
    for(int i=0; i<n; i++) {
        processList[i].waitingTime = currentTime - processList[i].arrivalTime;
        processList[i].turnaroundTime = currentTime + processList[i].burstTime - processList[i].arrivalTime;
        processList[i].completionTime = currentTime + processList[i].burstTime;
        currentTime += processList[i].burstTime;
    }
}

int main() {
    // Initialize data for 5 processes
    struct Process processes[5] = {
        {1, 0, 3, 0, 0, 0},
        {2, 1, 4, 0, 0, 0},
        {3, 2, 5, 0, 0, 0},
        {4, 3, 1, 0, 0, 0},
        {5, 4, 2, 0, 0, 0}
    };

    int numProcesses = 5;

    shortestJobFirst(processes, numProcesses);

    // Print out the results
    printf("Process | Arrival Time | Burst Time | Waiting Time | Completion Time | Turnaround Time\n");
    for(int i=0; i<numProcesses; i++) {
        printf("%7d | %12d | %10d | %12d | %15d | %16d\n",
            processes[i].id,
            processes[i].arrivalTime,
            processes[i].burstTime,
            processes[i].waitingTime,
            processes[i].completionTime,
            processes[i].turnaroundTime);
    }

    return 0;
}