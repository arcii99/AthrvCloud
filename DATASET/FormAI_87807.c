//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 5

// Represent a process
struct process {
    int id;
    int cpu_burst;
    int priority;
    int wait_time;
    int turnaround_time;
};

// Initialize a process
void init_process(struct process *p, int id) {
    p->id = id;
    p->cpu_burst = rand() % 10 + 1; // Generate random CPU burst time between 1-10
    p->priority = rand() % 5; // Generate random priority value between 0-4
    p->wait_time = 0;
    p->turnaround_time = 0;
}

// Print process information
void print_process(struct process *p) {
    printf("Process ID: %d, CPU Burst: %d, Priority: %d, Waiting Time: %d, Turnaround Time: %d\n", 
        p->id, p->cpu_burst, p->priority, p->wait_time, p->turnaround_time);
}

// Perform First-Come First-Serve (FCFS) scheduling
void fcfs(struct process *processes, int N) {
    int time = 0; // Current time
    int i;
    for (i = 0; i < N; i++) {
        struct process *p = &processes[i];
        // Wait for process to arrive
        while (time < p->id) {
            printf("Waiting for process %d to arrive\n", p->id);
            sleep(1); // Sleep for 1 second to simulate waiting
            time++;
        }
        // Process arrives, run CPU burst
        p->wait_time = time - p->id;
        printf("Running process %d for %d sec...\n", p->id, p->cpu_burst);
        sleep(p->cpu_burst); // Sleep for the CPU burst time to simulate running
        time += p->cpu_burst;
        p->turnaround_time = time - p->id;
        print_process(p);
    }
}

// Perform Round-Robin (RR) scheduling
void rr(struct process *processes, int N, int quantum) {
    int i, j, remaining_processes = N;
    int time = 0; // Current time
    while (remaining_processes > 0) {
        for (i = 0; i < N; i++) {
            struct process *p = &processes[i];
            if (p->cpu_burst > 0) { // Process has remaining CPU burst time
                // Wait for process to arrive
                while (time < p->id) {
                    printf("Waiting for process %d to arrive\n", p->id);
                    sleep(1); // Sleep for 1 second to simulate waiting
                    time++;
                }
                // Process arrives, run for quantum time
                printf("Running process %d for %d sec...\n", p->id, quantum);
                if (p->cpu_burst > quantum) {
                    p->cpu_burst -= quantum;
                    time += quantum;
                } else { // Process finishes before quantum is up
                    time += p->cpu_burst;
                    p->cpu_burst = 0;
                    p->turnaround_time = time - p->id;
                    p->wait_time = p->turnaround_time - (p->cpu_burst + (i * quantum)); // Calculate wait time
                    print_process(p);
                    remaining_processes--;
                }
            }
        }
    }
}

// Perform Priority scheduling
void priority(struct process *processes, int N) {
    int i, j;
    int time = 0; // Current time
    // Sort processes by priority
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (processes[j].priority > processes[i].priority) {
                // Swap processes
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    // Run processes based on priority
    for (i = 0; i < N; i++) {
        struct process *p = &processes[i];
        // Wait for process to arrive
        while (time < p->id) {
            printf("Waiting for process %d to arrive\n", p->id);
            sleep(1); // Sleep for 1 second to simulate waiting
            time++;
        }
        // Process arrives, run CPU burst
        p->wait_time = time - p->id;
        printf("Running process %d for %d sec...\n", p->id, p->cpu_burst);
        sleep(p->cpu_burst); // Sleep for the CPU burst time to simulate running
        time += p->cpu_burst;
        p->turnaround_time = time - p->id;
        print_process(p);
    }
}

int main() {
    struct process processes[MAX_PROCESS];
    int i, algorithm_choice, quantum;
    // Initialize processes
    for (i = 0; i < MAX_PROCESS; i++) {
        init_process(&processes[i], i+1);
        print_process(&processes[i]);
    }
    // Choose scheduling algorithm
    printf("Choose a scheduling algorithm:\n");
    printf("1. First-Come First-Serve (FCFS)\n");
    printf("2. Round-Robin (RR)\n");
    printf("3. Priority\n");
    scanf("%d", &algorithm_choice);
    switch (algorithm_choice) {
        case 1:
            fcfs(processes, MAX_PROCESS);
            break;
        case 2:
            printf("Enter quantum value: ");
            scanf("%d", &quantum);
            rr(processes, MAX_PROCESS, quantum);
            break;
        case 3:
            priority(processes, MAX_PROCESS);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}