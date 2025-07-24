//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void round_robin(Process processes[], int n, int quantum_time);
void shortest_job_first(Process processes[], int n);
void show_table(Process processes[], int n);

int main(){
    // Create an array of processes
    Process processes[5] = {
        {1, 10, 0},
        {2, 5, 2},
        {3, 8, 3},
        {4, 4, 4},
        {5, 2, 5}
    };

    // Call round robin algorithm with time quantum of 3
    round_robin(processes, 5, 3);
    
    // Call shortest job first algorithm
    shortest_job_first(processes, 5);

    // Display final table of processes with waiting and turnaround times
    show_table(processes, 5);

    return 0;
}

void round_robin(Process processes[], int n, int quantum_time){
    int time = 0;
    int remaining_burst_time[n];
    int i;

    // Set remaining burst times for all processes
    for(i = 0; i < n; i++){
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // Run algorithm until all processes are completed
    while(1){
        int flag = 0;

        // Loop through all processes
        for(i = 0; i < n; i++){
            // If process still has some remaining burst time
            if(remaining_burst_time[i] > 0){
                flag = 1;
                
                // If remaining burst time is less than or equal to quantum time
                if(remaining_burst_time[i] <= quantum_time){
                    time += remaining_burst_time[i];
                    
                    // Calculate waiting and turnaround times
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = time - processes[i].arrival_time;

                    // Set remaining burst time to 0
                    remaining_burst_time[i] = 0;
                }
                // If remaining burst time is greater than quantum time
                else{
                    time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                }
            }
        }
        // If all processes have been completed
        if(flag == 0){
            break;
        }
    }
}

void shortest_job_first(Process processes[], int n){
    int i, j;
    Process temp;

    // Sort processes by ascending order of burst time
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(processes[j].burst_time > processes[j+1].burst_time){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Set waiting and turnaround times for all processes
    int time = processes[0].arrival_time + processes[0].burst_time;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    for(i = 1; i < n; i++){
        processes[i].waiting_time = time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        time += processes[i].burst_time;
    }

}

void show_table(Process processes[], int n){
    printf("\n-------------------");
    printf("\n| Process | AT | BT | WT | TAT |");
    printf("\n-------------------");
    int i;
    for(i = 0; i < n; i++){
        printf("\n|   P%d    | %d  | %d  | %d  | %d   |", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\n-------------------");
}