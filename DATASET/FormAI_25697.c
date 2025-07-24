//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define process struct
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
} Process;

// define function for sorting processes by arrival time
int compare_arrival_time(const void* a, const void* b) {
    const Process* process_a = (Process*) a;
    const Process* process_b = (Process*) b;
    return process_a->arrival_time - process_b->arrival_time;
}

// define function for sorting processes by burst time
int compare_burst_time(const void* a, const void* b) {
    const Process* process_a = (Process*) a;
    const Process* process_b = (Process*) b;
    return process_a->burst_time - process_b->burst_time;
}

// define function for running FCFS algorithm
void fcfs(Process* processes, int num_processes) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        current_time = current_time > processes[i].arrival_time ? current_time : processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time = processes[i].completion_time;
    }
}

// define function for running SJF algorithm
void sjf(Process* processes, int num_processes) {
    int current_time = 0;
    qsort(processes, num_processes, sizeof(Process), compare_burst_time);
    for (int i = 0; i < num_processes; i++) {
        current_time = current_time > processes[i].arrival_time ? current_time : processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time = processes[i].completion_time;
    }
}

int main() {
    // set random seed for reproducibility
    srand(time(NULL));
    
    // initialize processes
    Process processes[5];
    for (int i = 0; i < 5; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = (rand() % 10) + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    printf("Initial processes:\n");
    printf("PID  Arrival Time  Burst Time\n");
    for (int i = 0; i < 5; i++) {
        printf("%2d%14d%12d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }
    
    // run FCFS algorithm
    fcfs(processes, 5);
    printf("\nFCFS results:\n");
    printf("PID  Arrival Time  Burst Time  Completion Time  Waiting Time\n");
    for (int i = 0; i < 5; i++) {
        printf("%2d%14d%12d%17d%14d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time);
    }
    
    // run SJF algorithm
    sjf(processes, 5);
    printf("\nSJF results:\n");
    printf("PID  Arrival Time  Burst Time  Completion Time  Waiting Time\n");
    for (int i = 0; i < 5; i++) {
        printf("%2d%14d%12d%17d%14d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time);
    }
    
    return 0;
}