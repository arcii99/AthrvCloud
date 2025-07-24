//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
/**
 * A Simple CPU Scheduling Algorithm Simulation
 * Round Robin Algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process Struct
typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int completion_time;
} Process;

// Queue Struct
typedef struct Node {
    Process data;
    struct Node* next;
} Node;

// Circular Queue Struct
typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

void enqueue(Queue* queue, Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = process;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
}

Process dequeue(Queue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty!\n");
        exit(1);
    }
    Process result = queue->front->data;
    Node* oldFront = queue->front;
    queue->front = queue->front->next;
    free(oldFront);
    queue->count--;
    return result;
}

bool is_empty(Queue* queue) {
    return (queue->front == NULL);
}

void print_processes(Process* processes, int size) {
    printf("=====================================\n");
    printf("Processes:\n");
    printf("=====================================\n");
    printf("PID\tBT\tAT\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time);
    }
    printf("=====================================\n");
}

int main() {

    // Initialize Processes
    int n = 5;
    Process processes[n];
    processes[0] = (Process){1, 5, 5, 0};
    processes[1] = (Process){2, 3, 3, 0};
    processes[2] = (Process){3, 8, 8, 0};
    processes[3] = (Process){4, 6, 6, 0};
    processes[4] = (Process){5, 4, 4, 0};

    print_processes(processes, n);

    // Initialize Queue
    Queue readyQueue = {NULL, NULL, 0};

    // Execute Simulation
    int currentTime = 0;
    int quantum = 5;
    int completed = 0;

    while (completed < n) {
        // Insert New Processes into Queue
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time == currentTime && processes[i].remaining_time == processes[i].burst_time) {
                enqueue(&readyQueue, processes[i]);
            }
        }

        // Check if Queue is Empty
        if (is_empty(&readyQueue)) {
            currentTime++;
            continue;
        }

        // Execute Process in Queue
        Process currentProcess = dequeue(&readyQueue);
        if (currentProcess.remaining_time <= quantum) {
            currentTime += currentProcess.remaining_time;
            currentProcess.remaining_time = 0;
            currentProcess.completion_time = currentTime;
            completed++;
            printf("Process %d: %d\n", currentProcess.pid, currentProcess.completion_time);
        } else {
            currentTime += quantum;
            currentProcess.remaining_time -= quantum;
            enqueue(&readyQueue, currentProcess);
        }
    }
    return 0;
}