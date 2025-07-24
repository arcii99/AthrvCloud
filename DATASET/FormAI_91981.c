//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs(Process* processes, int num_processes) {
    int curr_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        if (curr_time < processes[i].arrival_time) {
            curr_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = curr_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].burst_time 
            + processes[i].waiting_time;
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
        curr_time += processes[i].burst_time;
    }

    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    printf("FCFS CPU Scheduling Algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

void sjf(Process* processes, int num_processes) {
    int curr_time = 0;
    bool done[num_processes];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        done[i] = false;
    }

    while (true) {
        int min_burst_time = 10000000;
        int next_process = -1;

        for (int i = 0; i < num_processes; i++) {
            if (!done[i] && processes[i].arrival_time <= curr_time 
                && processes[i].burst_time < min_burst_time) {
                min_burst_time = processes[i].burst_time;
                next_process = i;
            }
        }

        if (next_process == -1) {
            bool all_done = true;
            for (int i = 0; i < num_processes; i++) {
                if (!done[i]) {
                    all_done = false;
                    break;
                }
            }
            if (all_done) {
                break;
            } else {
                curr_time++;
                continue;
            }
        }

        processes[next_process].waiting_time = curr_time - processes[next_process].arrival_time;
        processes[next_process].turnaround_time = processes[next_process].burst_time 
            + processes[next_process].waiting_time;
        avg_waiting_time += processes[next_process].waiting_time;
        avg_turnaround_time += processes[next_process].turnaround_time;
        curr_time += processes[next_process].burst_time;
        done[next_process] = true;
    }

    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    printf("SJF CPU Scheduling Algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

void priority(Process* processes, int num_processes) {
    int curr_time = 0;
    bool done[num_processes];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        done[i] = false;
    }

    while (true) {
        int highest_priority = -1;
        int next_process = -1;

        for (int i = 0; i < num_processes; i++) {
            if (!done[i] && processes[i].arrival_time <= curr_time 
                && processes[i].priority > highest_priority) {
                highest_priority = processes[i].priority;
                next_process = i;
            }
        }

        if (next_process == -1) {
            bool all_done = true;
            for (int i = 0; i < num_processes; i++) {
                if (!done[i]) {
                    all_done = false;
                    break;
                }
            }
            if (all_done) {
                break;
            } else {
                curr_time++;
                continue;
            }
        }

        processes[next_process].waiting_time = curr_time - processes[next_process].arrival_time;
        processes[next_process].turnaround_time = processes[next_process].burst_time 
            + processes[next_process].waiting_time;
        avg_waiting_time += processes[next_process].waiting_time;
        avg_turnaround_time += processes[next_process].turnaround_time;
        curr_time += processes[next_process].burst_time;
        done[next_process] = true;
    }

    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    printf("Priority CPU Scheduling Algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
            processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main() {
    Process procs[5] = {{1, 5, 3, 0, 0, 0}, {2, 3, 1, 1, 0, 0}, {3, 8, 2, 2, 0, 0}, 
                        {4, 6, 3, 3, 0, 0}, {5, 2, 4, 4, 0, 0}};

    fcfs(procs, 5);
    sjf(procs, 5);
    priority(procs, 5);

    return 0;
}