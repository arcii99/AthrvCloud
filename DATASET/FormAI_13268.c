//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completed;
    int named;
};
int total_waiting_time = 0, total_turnaround_time = 0;
float average_waiting_time, average_turnaround_time;
void print_gantt_chart(struct process[], int);
void execute_round_robin(struct process[], int, int, int);
void execute_priority_preemptive(struct process[], int);
void main(){
    printf("Enter total number of processes: ");
    int n;
    scanf("%d", &n);
    struct process processes[n];
    for(int i = 0; i < n; i++){
        processes[i].named = 0;
        processes[i].pid = i+1;
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].completed = 0;
    }
    printf("\nSelect a CPU scheduling algorithm:\n");
    printf("1. Round Robin\n2. Priority Preemptive\n");
    int choice, time_quantum;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("\nEnter time quantum: ");
            scanf("%d", &time_quantum);
            execute_round_robin(processes, n, time_quantum, 1);
            break;
        case 2:
            execute_priority_preemptive(processes, n);
            break;
        default:
            printf("\nInvalid choice!\n");
            exit(1);
    }
}

void execute_round_robin(struct process processes[], int n, int time_quantum, int named){
    printf("\nSelected scheduling algorithm: Round Robin\n\n");
    int remaining_time[n], current_time = 0;
    for(int i = 0; i < n; i++){
        remaining_time[i] = processes[i].burst_time;
    }
    while(1){
        int all_completed = 1;
        for(int i = 0; i < n; i++){
            if(processes[i].completed == 0){
                all_completed = 0;
                break;
            }
        }
        if(all_completed){
            print_gantt_chart(processes, n);
            break;
        }
        for(int i = 0; i < n; i++){
            if(processes[i].completed == 0){
                if(remaining_time[i] <= time_quantum){
                    current_time += remaining_time[i];
                    processes[i].waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_time[i] = 0;
                    processes[i].completed = 1;
                }
                else{
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                if(named == 1 && processes[i].named == 0){
                    printf("\nP%d starts at time: %d\n", processes[i].pid, current_time - remaining_time[i]);
                    processes[i].named = 1;
                }
            }
        }
    }
    average_waiting_time = (float)total_waiting_time/n;
    average_turnaround_time = (float)total_turnaround_time/n;
    printf("\nAverage waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

void execute_priority_preemptive(struct process processes[], int n){
    printf("\nSelected scheduling algorithm: Priority Preemptive\n\n");
    int current_time = 0, completed = 0, min_arrival_time = 999999;
    while(1){
        int all_completed = 1;
        for(int i = 0; i < n; i++){
            if(processes[i].completed == 0){
                all_completed = 0;
                if(processes[i].arrival_time < min_arrival_time){
                    min_arrival_time = processes[i].arrival_time;
                }
                break;
            }
        }
        if(all_completed){
            print_gantt_chart(processes, n);
            break;
        }
        int min_priority = 999999, index = -1;
        for(int i = 0; i < n; i++){
            if(processes[i].completed == 0 && processes[i].arrival_time <= current_time){
                if(processes[i].burst_time < min_priority){
                    min_priority = processes[i].burst_time;
                    index = i;
                }
            }
        }
        if(index != -1){
            current_time += 1;
            processes[index].burst_time -= 1;
            if(processes[index].burst_time == 0){
                processes[index].completed = 1;
                completed++;
                processes[index].waiting_time = current_time - processes[index].arrival_time - processes[index].burst_time;
                total_waiting_time += processes[index].waiting_time;
                processes[index].turnaround_time = current_time - processes[index].arrival_time;
                total_turnaround_time += processes[index].turnaround_time;
            }
            else if(processes[index].burst_time < min_priority){
                print_gantt_chart(processes, n);
                printf("Priority changed at time %d to Process %d\n", current_time, processes[index].pid);
            }
        }
        else{
            current_time += 1;
        }
    }
    average_waiting_time = (float)total_waiting_time/n;
    average_turnaround_time = (float)total_turnaround_time/n;
    printf("\nAverage waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

void print_gantt_chart(struct process processes[], int n){
    printf("\n");
    for(int i = 0; i <= (n*4); i++){
        if(i == 0){
            printf("|");
        }
        else if(i == (n*4)){
            printf("|\n");
        }
        else if(i%4 == 0){
            printf("|");
        }
        else{
            printf("-");
        }
    }
    printf("|");
    for(int i = 0; i < n; i++){
        printf(" P%d ", processes[i].pid);
        if(processes[i].turnaround_time >= 10){
            printf(" ");
        }
        else{
            printf("  ");
        }
        printf("|");
    }
    printf("\n");
    for(int i = 0; i <= (n*4); i++){
        if(i == 0){
            printf("|");
        }
        else if(i == (n*4)){
            printf("|\n");
        }
        else if(i%4 == 0){
            printf("|");
        }
        else{
            printf("-");
        }
    }
    printf("0");
    for(int i = 0; i < n; i++){
        if(processes[i].turnaround_time >= 100){
            printf("   %d", processes[i].turnaround_time);
        }
        else if(processes[i].turnaround_time >= 10){
            printf("    %d", processes[i].turnaround_time);
        }
        else{
            printf("     %d", processes[i].turnaround_time);
        }
    }
    printf("\n");
}