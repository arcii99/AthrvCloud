//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESS 10
#define TIME_QUANTUM 2
#define MAX_PRIORITY 10

//Node structure to store process info
typedef struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

//Function to generate random process arrival and burst times
void generateProcesses(Process processes[], int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        processes[i].process_id = i+1;
        processes[i].arrival_time = rand()%10;
        processes[i].burst_time = rand()%20 + 1;
        processes[i].priority = rand()%MAX_PRIORITY + 1;
    }
}

//Function to print process info
void printProcesses(Process processes[], int n) {
    printf("Process\t Arrival Time\t Burst Time\t Priority\n");
    for(int i=0; i<n; i++) {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
}

//Round Robin Scheduling Algorithm with Time Quantum = 2
void roundRobin(Process processes[], int n) {
    int arrival_time_copy[MAX_PROCESS], remaining_time[MAX_PROCESS];
    int total_waiting_time = 0, total_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        arrival_time_copy[i] = processes[i].arrival_time;
        remaining_time[i] = processes[i].burst_time;
    }
    int t = 0;
    while(1) {
        int flag = 1;
        for(int i=0; i<n; i++) {
            if(remaining_time[i] > 0) {
                flag = 0;
                if(remaining_time[i] > TIME_QUANTUM) {
                    t += TIME_QUANTUM;
                    remaining_time[i] -= TIME_QUANTUM;
                } else {
                    t += remaining_time[i];
                    processes[i].burst_time = remaining_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if(flag) {
            break;
        }
    }
    for(int i=0; i<n; i++) {
        int turnaround_time = t - arrival_time_copy[i];
        int waiting_time = turnaround_time - processes[i].burst_time;
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time/n);
}

int main() {
    int n = MAX_PROCESS;
    Process processes[MAX_PROCESS];
    generateProcesses(processes, n);
    printf("Initially Generated Processes:\n");
    printProcesses(processes, n);
    printf("\nRound Robin Scheduling Result:\n");
    roundRobin(processes, n);
    return 0;
}