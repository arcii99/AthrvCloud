//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
// This program implements a CPU scheduling algorithm based on Ada Lovelace's mathematical work.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burstTime;
    int priority;
} Process;

void printProcess(Process p) {
    printf("Process %d: Burst Time = %d, Priority = %d\n", p.id, p.burstTime, p.priority);
}

void swap(Process* a, Process* b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Process* p, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].priority > p[j+1].priority) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void fcfs(Process* p, int n) {
    int waitingTime = 0;
    int totalWaitingTime = 0;
    float averageWaitingTime = 0.0;
    printf("First Come First Serve Algorithm:\n");
    for(int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime;
        printProcess(p[i]);
        waitingTime += p[i].burstTime;
    }
    averageWaitingTime = (float)totalWaitingTime/n;
    printf("Average Waiting Time = %f\n\n", averageWaitingTime);
}

void sjf(Process* p, int n) {
    int waitingTime = 0;
    int totalWaitingTime = 0;
    float averageWaitingTime = 0.0;
    int completionTime[n];
    printf("Shortest Job First Algorithm:\n");
    bubbleSort(p, n);
    for(int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime;
        printProcess(p[i]);
        waitingTime += p[i].burstTime;
        completionTime[p[i].id] = waitingTime;
    }
    averageWaitingTime = (float)totalWaitingTime/n;
    printf("Average Waiting Time = %f\n", averageWaitingTime);
    printf("Completion Time:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: %d\n", i, completionTime[i]);
    }
    printf("\n");
}

void pri(Process* p, int n) {
    int waitingTime = 0;
    int totalWaitingTime = 0;
    float averageWaitingTime = 0.0;
    int completionTime[n];
    printf("Priority Scheduling Algorithm:\n");
    bubbleSort(p, n);
    for(int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime;
        printProcess(p[i]);
        waitingTime += p[i].burstTime;
        completionTime[p[i].id] = waitingTime;
    }
    averageWaitingTime = (float)totalWaitingTime/n;
    printf("Average Waiting Time = %f\n", averageWaitingTime);
    printf("Completion Time:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: %d\n", i, completionTime[i]);
    }
    printf("\n");
}

int main() {
    Process p[] = {
        {0, 5, 2},
        {1, 3, 1},
        {2, 8, 0},
        {3, 6, 3},
        {4, 4, 2}
    };
    int n = sizeof(p)/sizeof(p[0]);
    fcfs(p, n);
    sjf(p, n);
    pri(p, n);
    return 0;
}