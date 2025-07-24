//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>

/*
    In this program, we will implement a unique CPU scheduling algorithm
    called "Round Robin with Priority Boosting".
    This algorithm works by allotting a fixed time slice to each process.
    However, if a process doesn't use up its full allotted time, it is
    immediately preempted and the next process in the queue is run.
    In addition, every once in a while, we will boost the priority of
    all processes in the queue in order to prevent starvation.
*/

// Define the maximum number of processes we can handle
#define MAX_PROCESSES 10

// Define the length of time slice each process gets
#define TIME_SLICE 10

// Define the interval at which we will boost priorities
#define PRIORITY_BOOST_INTERVAL 60

// Define a struct to represent a process
typedef struct _Process {
    int pid;                // Process ID
    int priority;           // Priority (lower number means higher priority)
    int time_remaining;     // Time remaining in time slice
} Process;

// Define a struct to represent a queue of processes
typedef struct _ProcessQueue {
    int count;                      // Number of processes in the queue
    Process processes[MAX_PROCESSES];// Array of processes
} ProcessQueue;

// Helper function to initialize a process
void init_process(Process* p, int pid, int priority) {
    p->pid = pid;
    p->priority = priority;
    p->time_remaining = TIME_SLICE;
}

// Helper function to initialize a queue
void init_queue(ProcessQueue* q) {
    q->count = 0;
}

// Helper function to add a process to a queue
void enqueue(ProcessQueue* q, Process* p) {
    q->processes[q->count] = *p;
    q->count++;
}

// Helper function to remove a process from a queue
void dequeue(ProcessQueue* q, int index) {
    for (int i = index; i < (q->count - 1); i++) {
        q->processes[i] = q->processes[i+1];
    }
    q->count--;
}

// Helper function to find the highest-priority process in a queue
int find_highest_priority(ProcessQueue* q) {
    int highest_priority = 999;     // Start with a very high priority
    int highest_priority_index = -1;

    for (int i = 0; i < q->count; i++) {
        if (q->processes[i].priority < highest_priority) {
            highest_priority = q->processes[i].priority;
            highest_priority_index = i;
        }
    }

    return highest_priority_index;
}

int main() {
    // Initialize an array of processes
    Process processes[MAX_PROCESSES];
    init_process(&processes[0], 1, 1);
    init_process(&processes[1], 2, 2);
    init_process(&processes[2], 3, 3);
    init_process(&processes[3], 4, 4);

    // Initialize a queue and add all processes to it
    ProcessQueue queue;
    init_queue(&queue);
    for (int i = 0; i < 4; i++) {
        enqueue(&queue, &processes[i]);
    }

    // Keep track of how much time has passed
    int current_time = 0;

    // Loop until all processes have finished
    while (queue.count > 0) {
        // Get the index of the highest-priority process
        int highest_priority_index = find_highest_priority(&queue);

        // Run the process for the time slice
        Process* p = &queue.processes[highest_priority_index];
        printf("Running process %d for %d time units (priority %d)\n", p->pid, p->time_remaining, p->priority);
        current_time += p->time_remaining;
        p->time_remaining = 0;

        // Remove the process from the queue if it is finished
        if (p->time_remaining == 0) {
            printf("Process %d has finished.\n", p->pid);
            dequeue(&queue, highest_priority_index);
        }

        // Decrement the remaining time for all other processes in the queue
        for (int i = 0; i < queue.count; i++) {
            if (i == highest_priority_index) {
                continue;
            }
            queue.processes[i].time_remaining -= TIME_SLICE;
            if (queue.processes[i].time_remaining < 0) {
                queue.processes[i].time_remaining = 0;
            }
        }

        // If it's time to boost priorities, do so
        if (current_time % PRIORITY_BOOST_INTERVAL == 0) {
            printf("Boosting priorities!\n");
            for (int i = 0; i < queue.count; i++) {
                queue.processes[i].priority--;
                if (queue.processes[i].priority < 1) {
                    queue.processes[i].priority = 1;
                }
            }
        }
    }

    return 0;
}