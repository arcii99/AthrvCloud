//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10 // maximum number of processes
#define MAX_BURST_TIME 10 // maximum burst time for a process
#define QUANTUM 2 // quantum time for round robin

struct process{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} processes[MAX_PROCESSES];

void initialize_processes(){
    srand(time(NULL)); // initialize random number generator
    for(int i=0; i<MAX_PROCESSES; i++){
        processes[i].id = i+1;
        processes[i].burst_time = rand()%(MAX_BURST_TIME+1); // generate random burst time between 0 and MAX_BURST_TIME
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void print_processes(){
    printf("ID\tBurst Time\n");
    for(int i=0; i<MAX_PROCESSES; i++){
        printf("%d\t%d\n", processes[i].id, processes[i].burst_time);
    }
}

void fcfs(){
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    printf("\nFirst Come First Serve (FCFS)\n");
    printf("ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<MAX_PROCESSES; i++){
        processes[i].waiting_time = total_waiting_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time/MAX_PROCESSES);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/MAX_PROCESSES);
}

void sjf(){
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int remaining_time[MAX_PROCESSES];
    for(int i=0; i<MAX_PROCESSES; i++){
        remaining_time[i] = processes[i].burst_time;
    }
    int completed_processes = 0;
    printf("\nShortest Job First (SJF)\n");
    printf("ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while(completed_processes < MAX_PROCESSES){
        int shortest_time = MAX_BURST_TIME+1;
        int shortest_index = 0;
        for(int i=0; i<MAX_PROCESSES; i++){
            if(remaining_time[i] < shortest_time && remaining_time[i] > 0){
                shortest_time = remaining_time[i];
                shortest_index = i;
            }
        }
        remaining_time[shortest_index] = 0;
        processes[shortest_index].waiting_time = total_waiting_time;
        processes[shortest_index].turnaround_time = processes[shortest_index].waiting_time + processes[shortest_index].burst_time;
        total_waiting_time += processes[shortest_index].burst_time;
        total_turnaround_time += processes[shortest_index].turnaround_time;
        completed_processes++;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[shortest_index].id, processes[shortest_index].burst_time, processes[shortest_index].waiting_time, processes[shortest_index].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time/MAX_PROCESSES);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/MAX_PROCESSES);
}

void round_robin(){
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int remaining_time[MAX_PROCESSES];
    for(int i=0; i<MAX_PROCESSES; i++){
        remaining_time[i] = processes[i].burst_time;
    }
    int completed_processes = 0;
    printf("\nRound Robin (RR)\n");
    printf("ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int time = 0;
    while(completed_processes < MAX_PROCESSES){
        for(int i=0; i<MAX_PROCESSES; i++){
            if(remaining_time[i] > 0){
                if(remaining_time[i] > QUANTUM){
                    time += QUANTUM;
                    remaining_time[i] -= QUANTUM;
                }
                else{
                    time += remaining_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_time[i] = 0;
                    completed_processes++;
                    printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
                }
            }
        }
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time/MAX_PROCESSES);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/MAX_PROCESSES);
}

int main(){
    initialize_processes();
    printf("Initial processes:\n");
    print_processes();
    fcfs();
    sjf();
    round_robin();
    return 0;
}