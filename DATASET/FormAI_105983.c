//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

#define N 10  // Number of processes

// Structure of each process
struct Process {
    int pid; // Process ID
    int burstTime; // Burst Time
    int arrivalTime; // Arrival Time
    int waitingTime; // Waiting Time
    int turnaroundTime; // Turnaround Time 
};

int main() {
    int timeQuantum = 2; // Time quantum
    int currentTime = 0; // Current Time
    float avgWaitingTime = 0; // Average Waiting Time
    float avgTurnaroundTime = 0; // Average Turnaround Time
    
    // Process List
    struct Process processList[N] = {
        {1, 6, 0},
        {2, 8, 1},
        {3, 7, 2},
        {4, 3, 3},
        {5, 4, 4},
        {6, 5, 5},
        {7, 2, 6},
        {8, 1, 7},
        {9, 9, 8},
        {10, 10, 9}
    };
    
    // Print process list
    printf("Process List:\n");
    printf("---------------\n");
    printf("PID\tBurst Time\tArrival Time\n");
    for(int i=0; i<N; i++) {
        printf("%d\t%d\t\t%d\n", processList[i].pid, processList[i].burstTime, processList[i].arrivalTime);
    }
    printf("---------------\n");
    
    // Sort the processes by their Arrival Time
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-i-1; j++) {
            if(processList[j].arrivalTime > processList[j+1].arrivalTime) {
                struct Process temp = processList[j];
                processList[j] = processList[j+1];
                processList[j+1] = temp;
            }
        }
    }
    
    // Round Robin CPU Scheduling Algorithm
    int timeRemaining[N];  // Time remaining for each process
    for(int i=0; i<N; i++) {
        timeRemaining[i] = processList[i].burstTime;
        processList[i].waitingTime = 0;
    }
    int completedProcesses = 0;
    while(completedProcesses < N) {
        int flag = 0;
        for(int i=0; i<N; i++) {
            if(timeRemaining[i] > 0) {
                flag = 1;
                if(timeRemaining[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    timeRemaining[i] -= timeQuantum;
                }
                else {
                    currentTime += timeRemaining[i];
                    processList[i].turnaroundTime = currentTime - processList[i].arrivalTime;
                    processList[i].waitingTime = processList[i].turnaroundTime - processList[i].burstTime;
                    timeRemaining[i] = 0;
                    completedProcesses++;
                }
            }
        }
        if(flag == 0) {
            currentTime++;
        }
    }
    
    // Calculate average Waiting Time and Turnaround Time
    for(int i=0; i<N; i++) {
        avgWaitingTime += processList[i].waitingTime;
        avgTurnaroundTime += processList[i].turnaroundTime;
    }
    avgWaitingTime /= N;
    avgTurnaroundTime /= N;
    
    // Print Process Schedule
    printf("\nProcess Schedule:\n");
    printf("---------------\n");
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<N; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processList[i].pid, processList[i].burstTime, processList[i].arrivalTime, processList[i].waitingTime, processList[i].turnaroundTime);
    }
    printf("---------------\n");
    
    // Print Performance Metrics
    printf("\nPerformance Metrics:\n");
    printf("---------------\n");
    printf("Average Waiting Time: %0.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %0.2f\n", avgTurnaroundTime);
    printf("---------------\n");

    return 0;
}