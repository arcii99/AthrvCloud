//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // Maximum number of processes
#define MAX_TIME_QUANTUM 5 // Maximum time quantum for Round Robin scheduling
#define MAX_ARRIVAL_TIME 10 // Maximum arrival time for generating random processes

/* Struct to hold information about a process */
typedef struct {
    int pid; // Process ID
    int arrivalTime; // Arrival time of process
    int cpuBurstTime; // CPU burst time required by process
    int remainingTime; // Remaining time needed to complete the CPU burst
    int waitingTime; // Waiting time of process
} Process;

/* Function to generate a random process */
void generateRandomProcess(Process* process) {
    process->pid = rand() % MAX_PROCESSES;
    process->arrivalTime = rand() % MAX_ARRIVAL_TIME;
    process->cpuBurstTime = (rand() % 10) + 1; // CPU burst time can range from 1 to 10
    process->remainingTime = process->cpuBurstTime;
    process->waitingTime = 0;
}

/* Function to sort processes in ascending order of arrival time */
void sortProcessesByArrivalTime(Process processes[], int n) {
    for(int i=0; i<n; i++) {
        int minIndex = i;
        for(int j=i; j<n; j++) {
            if(processes[j].arrivalTime < processes[minIndex].arrivalTime) {
                minIndex = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[minIndex];
        processes[minIndex] = temp;
    }
}

/* Function to implement First-Come, First-Serve (FCFS) scheduling */
void runFCFS(Process processes[], int n) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    for(int i=0; i<n; i++) {
        Process process = processes[i];
        int waitingTime = currentTime - process.arrivalTime;
        process.waitingTime = waitingTime > 0 ? waitingTime : 0;
        totalWaitingTime += process.waitingTime;
        currentTime += process.cpuBurstTime;
    }
    printf("FCFS Scheduling:\n");
    printf("Total waiting time: %d\n", totalWaitingTime);
    printf("Average waiting time: %.2f\n", (float) totalWaitingTime / n);
}

/* Function to implement Shortest-Job-First (SJF) scheduling */
void runSJF(Process processes[], int n) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    int processesRemaining = n;
    while(processesRemaining > 0) {
        int minRemainingTime = MAX_ARRIVAL_TIME + 1;
        int minIndex = -1;
        for(int i=0; i<n; i++) {
            if(processes[i].arrivalTime <= currentTime && processes[i].remainingTime < minRemainingTime && processes[i].remainingTime > 0) {
                minRemainingTime = processes[i].remainingTime;
                minIndex = i;
            }
        }
        if(minIndex != -1) {
            Process* process = &processes[minIndex];
            process->remainingTime--;
            if(process->remainingTime == 0) {
                int waitingTime = currentTime + 1 - process->arrivalTime - process->cpuBurstTime;
                process->waitingTime = waitingTime > 0 ? waitingTime : 0;
                totalWaitingTime += process->waitingTime;
                processesRemaining--;
            }
            currentTime++;
        }
        else {
            currentTime++;
        }
    }
    printf("SJF Scheduling:\n");
    printf("Total waiting time: %d\n", totalWaitingTime);
    printf("Average waiting time: %.2f\n", (float) totalWaitingTime / n);
}

/* Function to implement Round Robin (RR) scheduling */
void runRR(Process processes[], int n, int timeQuantum) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    int processesRemaining = n;
    int currentIndex = 0;
    while(processesRemaining > 0) {
        Process* process = &processes[currentIndex];
        if(process->remainingTime > 0) {
            process->remainingTime -= timeQuantum;
            if(process->remainingTime <= 0) {
                int waitingTime = currentTime + timeQuantum - process->arrivalTime - process->cpuBurstTime;
                process->waitingTime = waitingTime > 0 ? waitingTime : 0;
                totalWaitingTime += process->waitingTime;
                processesRemaining--;
            }
        }
        currentIndex = (currentIndex + 1) % n;
        currentTime += timeQuantum;
    }
    printf("Round Robin Scheduling:\n");
    printf("Total waiting time: %d\n", totalWaitingTime);
    printf("Average waiting time: %.2f\n", (float) totalWaitingTime / n);
}

int main() {
    srand(1);
    Process processes[MAX_PROCESSES];
    for(int i=0; i<MAX_PROCESSES; i++) {
        generateRandomProcess(&processes[i]);
    }
    sortProcessesByArrivalTime(processes, MAX_PROCESSES);
    runFCFS(processes, MAX_PROCESSES);
    runSJF(processes, MAX_PROCESSES);
    runRR(processes, MAX_PROCESSES, MAX_TIME_QUANTUM);
    return 0;
}