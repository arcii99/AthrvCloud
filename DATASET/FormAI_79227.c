//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5 // Number of Processes
#define MAX 10 // Maximum random burst time of a process

typedef struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void initialize(Process processes[]) {
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < N; i++) {
        processes[i].pid = i+1;
        processes[i].burst_time = rand() % MAX + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void display(Process processes[]) {
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < N; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %f\n", (float)total_waiting_time / N);
    printf("Average Turnaround Time: %f\n", (float)total_turnaround_time / N);
}

void FCFS(Process processes[]) {
    int time = 0;
    for (int i = 0; i < N; i++) {
        processes[i].waiting_time = time;
        time += processes[i].burst_time;
        processes[i].turnaround_time = time;
    }
}

void SJF(Process processes[]) {
    int time = 0;
    int i = 0;
    while (i < N) {
        int shortest = i;
        for (int j = i+1; j < N; j++) {
            if (processes[shortest].burst_time > processes[j].burst_time) {
                shortest = j;
            }
        }
        processes[shortest].waiting_time = time;
        time += processes[shortest].burst_time;
        processes[shortest].turnaround_time = time;
        i++;
    }
}

void roundRobin(Process processes[]) {
    int time = 0;
    int quantum = 2;
    int remaining[N];
    for (int i = 0; i < N; i++) {
        remaining[i] = processes[i].burst_time;
    }
    while (1) {
        int done = 1;
        for (int i = 0; i < N; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                }
                else {
                    time += remaining[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

int main() {
    Process processes[N];
    printf("Initial Process List:\n");
    initialize(processes);
    display(processes);

    printf("\nFCFS Algorithm:\n");
    FCFS(processes);
    display(processes);

    printf("\nSJF Algorithm:\n");
    SJF(processes);
    display(processes);

    printf("\nRound Robin Algorithm:\n");
    roundRobin(processes);
    display(processes);

    return 0;
}