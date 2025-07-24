//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdlib.h>
#include <stdio.h>

// Process data structure
typedef struct {
    int pid;
    int arrival_time;
    int cpu_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to sort an array of processes by arrival time
void sortProcesses(Process *processes, int num_processes) {
    int i, j;
    Process temp;
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// First Come First Serve (FCFS) scheduling algorithm
void fcfs(Process *processes, int num_processes) {
    int i;
    float total_wait = 0, total_turnaround = 0;
    printf("FCFS Scheduling:\n");
    printf("-----------------\n");
    printf("Process\tCPU Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        if (i == 0) {
            processes[i].waiting_time = 0;
        } else {
            processes[i].waiting_time = processes[i - 1].cpu_time + processes[i - 1].waiting_time - processes[i].arrival_time;
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].cpu_time;
        total_wait += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].cpu_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    float avg_wait = total_wait / num_processes;
    float avg_turnaround = total_turnaround / num_processes;
    printf("Average Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

// Shortest Job First (SJF) scheduling algorithm
void sjf(Process *processes, int num_processes) {
    int i, j, time = 0, next_process = 0;
    float total_wait = 0, total_turnaround = 0;
    printf("SJF Scheduling:\n");
    printf("-----------------\n");
    printf("Process\tCPU Time\tWaiting Time\tTurnaround Time\n");
    while (next_process < num_processes) {
        int shortest_time = processes[next_process].cpu_time;
        int shortest_index = next_process;
        for (j = next_process + 1; j < num_processes; j++) {
            if (processes[j].arrival_time <= time && processes[j].cpu_time < shortest_time) {
                shortest_time = processes[j].cpu_time;
                shortest_index = j;
            }
        }
        time += processes[shortest_index].cpu_time;
        processes[shortest_index].waiting_time = time - processes[shortest_index].arrival_time - processes[shortest_index].cpu_time;
        if (processes[shortest_index].waiting_time < 0) {
            processes[shortest_index].waiting_time = 0;
        }
        processes[shortest_index].turnaround_time = processes[shortest_index].cpu_time + processes[shortest_index].waiting_time;
        total_wait += processes[shortest_index].waiting_time;
        total_turnaround += processes[shortest_index].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[shortest_index].pid, processes[shortest_index].cpu_time, processes[shortest_index].waiting_time, processes[shortest_index].turnaround_time);
        next_process++;
    }
    float avg_wait = total_wait / num_processes;
    float avg_turnaround = total_turnaround / num_processes;
    printf("Average Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

// Round Robin (RR) scheduling algorithm
void rr(Process *processes, int num_processes, int time_slice) {
    int i, j, time = 0;
    float total_wait = 0, total_turnaround = 0;
    printf("RR Scheduling:\n");
    printf("-----------------\n");
    printf("Process\tCPU Time\tWaiting Time\tTurnaround Time\n");
    while (1) {
        int all_finished = 1;
        for (i = 0; i < num_processes; i++) {
            if (processes[i].cpu_time > 0) {
                all_finished = 0;
                if (processes[i].cpu_time <= time_slice) {
                    time += processes[i].cpu_time;
                    processes[i].cpu_time = 0;
                    processes[i].waiting_time = time - processes[i].arrival_time - processes[i].turnaround_time;
                    if (processes[i].waiting_time < 0) {
                        processes[i].waiting_time = 0;
                    }
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    total_wait += processes[i].waiting_time;
                    total_turnaround += processes[i].turnaround_time;
                    printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, time - processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
                } else {
                    time += time_slice;
                    processes[i].cpu_time -= time_slice;
                }
            }
        }
        if (all_finished) {
            break;
        }
    }
    float avg_wait = total_wait / num_processes;
    float avg_turnaround = total_turnaround / num_processes;
    printf("Average Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

int main() {
    Process processes[] = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5},
        {5, 4, 7},
    };
    int num_processes = sizeof(processes) / sizeof(Process);
    sortProcesses(processes, num_processes);
    fcfs(processes, num_processes);
    sjf(processes, num_processes);
    rr(processes, num_processes, 2);
    return 0;
}