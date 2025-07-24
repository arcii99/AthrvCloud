//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Struct to keep track of the process info
typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int wait_time;
    int turnaround_time;
} Process;

// Struct to keep track of the queue and its info
typedef struct Queue {
    Process* processes;
    int size;
    int front;
    int rear;
} Queue;

// Function to create a new queue with a given size
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    queue->processes = (Process*)malloc(size * sizeof(Process));
    return queue;
}

// Function to add a process to the back of the queue
void enqueue(Queue* queue, Process process) {
    queue->rear++;
    queue->processes[queue->rear] = process;
}

// Function to remove a process from the front of the queue
Process dequeue(Queue* queue) {
    Process process = queue->processes[queue->front];
    queue->front++;
    return process;
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

// Function to get the process with the highest priority in the queue
Process getHighestPriorityProcess(Queue* queue) {
    int highest_priority = queue->processes[queue->front].priority;
    int process_index = queue->front;
    for (int i = queue->front+1; i <= queue->rear; i++) {
        if (queue->processes[i].priority > highest_priority) {
            highest_priority = queue->processes[i].priority;
            process_index = i;
        }
    }
    Process process = queue->processes[process_index];
    for (int i = process_index; i > queue->front; i--)
        queue->processes[i] = queue->processes[i-1];
    queue->front++;
    return process;
}

// Function to print the timeline and each process's info
void printTimeline(Process* processes, int num_processes) {
    printf("Timeline: ");
    int total_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_time += processes[i].burst_time;
        printf("%d->P%d->", total_time, processes[i].pid);
    }
    printf("END\n\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", processes[i].pid);
        printf("\tArrival Time: %d\n", processes[i].arrival_time);
        printf("\tBurst Time: %d\n", processes[i].burst_time);
        printf("\tPriority: %d\n", processes[i].priority);
        printf("\tWait Time: %d\n", processes[i].wait_time);
        printf("\tTurnaround Time: %d\n\n", processes[i].turnaround_time);
    }
}

// Function to perform the priority scheduling algorithm
void priorityScheduling(Process* processes, int num_processes) {
    int current_time = 0;
    int completed_processes = 0;
    Queue* ready_queue = createQueue(num_processes);

    // Add all processes to the ready queue
    for (int i = 0; i < num_processes; i++)
        enqueue(ready_queue, processes[i]);

    printf("\nPriority Scheduling:\n\n");

    while (completed_processes < num_processes) {
        if (isQueueEmpty(ready_queue)) {
            printf("CPU Idle -> %d\n", current_time+1);
            current_time++;
            continue;
        }

        // Get the process with the highest priority from the ready queue
        Process current_process = getHighestPriorityProcess(ready_queue);

        // Wait for the process to arrive if necessary
        while (current_time < current_process.arrival_time) {
            printf("CPU Idle -> %d\n", current_time+1);
            current_time++;
        }

        // Run the current process and update its wait and turnaround time
        printf("P%d -> %d\n", current_process.pid, current_time+1);
        current_process.wait_time += current_time - current_process.arrival_time;
        current_time += current_process.burst_time;
        current_process.turnaround_time = current_time - current_process.arrival_time;
        completed_processes++;

        // Add any processes that have arrived while the current process was running to the ready queue
        for (int i = completed_processes; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time)
                enqueue(ready_queue, processes[i]);
        }
    }

    printTimeline(processes, num_processes);
}

int main() {
    // Set random seed
    srand(time(0));

    // Generate random values for each process's arrival time, burst time, and priority
    int num_processes = 5;
    Process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i+1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].priority = rand() % 5 + 1;
        processes[i].wait_time = 0;
        processes[i].turnaround_time = 0;
    }

    priorityScheduling(processes, num_processes);

    return 0;
}