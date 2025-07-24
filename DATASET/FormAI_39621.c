//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void FCFS(Process* processes, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Calculate completion time of process i
        processes[i].completion_time = current_time + processes[i].burst_time;

        // Update waiting time and turnaround time
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        // Update current time
        current_time = processes[i].completion_time;
    }
}

void SJF(Process* processes, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Find shortest job remaining
        int shortest_job_index = i;
        for (int j = i; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time < processes[shortest_job_index].burst_time) {
                shortest_job_index = j;
            }
        }

        // Calculate completion time of shortest job
        processes[shortest_job_index].completion_time = current_time + processes[shortest_job_index].burst_time;

        // Update waiting time and turnaround time
        processes[shortest_job_index].waiting_time = current_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;

        // Swap current process with shortest job
        Process temp = processes[i];
        processes[i] = processes[shortest_job_index];
        processes[shortest_job_index] = temp;

        // Update current time
        current_time = processes[i].completion_time;
    }
}

void priority(Process* processes, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Find highest priority process
        int highest_priority_index = i;
        for (int j = i; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].priority < processes[highest_priority_index].priority) {
                highest_priority_index = j;
            }
        }

        // Calculate completion time of highest priority process
        processes[highest_priority_index].completion_time = current_time + processes[highest_priority_index].burst_time;

        // Update waiting time and turnaround time
        processes[highest_priority_index].waiting_time = current_time - processes[highest_priority_index].arrival_time;
        processes[highest_priority_index].turnaround_time = processes[highest_priority_index].completion_time - processes[highest_priority_index].arrival_time;

        // Swap current process with highest priority process
        Process temp = processes[i];
        processes[i] = processes[highest_priority_index];
        processes[highest_priority_index] = temp;

        // Update current time
        current_time = processes[i].completion_time;
    }
}

void print_results(Process* processes, int n) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    // Sample processes
    Process processes[5];
    processes[0].process_id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;
    processes[0].priority = 3;
    processes[1].process_id = 2;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 3;
    processes[1].priority = 1;
    processes[2].process_id = 3;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 8;
    processes[2].priority = 2;
    processes[3].process_id = 4;
    processes[3].arrival_time = 3;
    processes[3].burst_time = 4;
    processes[3].priority = 4;
    processes[4].process_id = 5;
    processes[4].arrival_time = 4;
    processes[4].burst_time = 2;
    processes[4].priority = 5;

    // First come first serve algorithm
    printf("First come first serve algorithm:\n");
    FCFS(processes, 5);
    print_results(processes, 5);

    // Shortest job first algorithm
    printf("\nShortest job first algorithm:\n");
    SJF(processes, 5);
    print_results(processes, 5);

    // Priority algorithm
    printf("\nPriority algorithm:\n");
    priority(processes, 5);
    print_results(processes, 5);

    return 0;
}