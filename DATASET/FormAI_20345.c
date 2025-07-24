//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// struct to represent each process
typedef struct {
    int burst_time;
    int time_left;
    int arrival_time;
    int priority;
} process;

// function to sort the processes by arrival time
void sort_processes_by_arrival_time(process *processes, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function to sort the processes by priority (if applicable)
void sort_processes_by_priority(process *processes, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(processes[i].priority > processes[j].priority) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function to execute a process for one time unit
void execute_process(process *p) {
    p->time_left -= 1;
}

// function to check if all processes have completed execution
int all_processes_completed(process *processes, int n) {
    for(int i=0; i<n; i++) {
        if(processes[i].time_left > 0) {
            return 0;
        }
    }
    return 1;
}

// function to implement the FCFS scheduling algorithm
void fcfs(process *processes, int n) {
    int current_time = 0;
    for(int i=0; i<n; i++) {
        while(current_time < processes[i].arrival_time) {
            current_time++;
        }
        while(processes[i].time_left > 0) {
            execute_process(&processes[i]);
            current_time++;
        }
    }
}

// function to implement the SJF scheduling algorithm
void sjf(process *processes, int n) {
    int current_time = 0;
    int process_index = -1;
    while(!all_processes_completed(processes, n)) {
        process_index = -1;
        for(int i=0; i<n; i++) {
            if(processes[i].time_left > 0 && processes[i].arrival_time <= current_time) {
                if(process_index == -1 || processes[i].burst_time < processes[process_index].burst_time) {
                    process_index = i;
                }
            }
        }
        if(process_index == -1) {
            current_time++;
        } else {
            execute_process(&processes[process_index]);
            current_time++;
        }
    }
}

// function to implement the Priority scheduling algorithm
void priority(process *processes, int n) {
    int current_time = 0;
    int process_index = -1;
    while(!all_processes_completed(processes, n)) {
        process_index = -1;
        for(int i=0; i<n; i++) {
            if(processes[i].time_left > 0 && processes[i].arrival_time <= current_time) {
                if(process_index == -1 || processes[i].priority < processes[process_index].priority) {
                    process_index = i;
                }
            }
        }
        if(process_index == -1) {
            current_time++;
        } else {
            execute_process(&processes[process_index]);
            current_time++;
        }
    }
}

// function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // generate some random processes
    process processes[MAX_PROCESSES];
    for(int i=0; i<MAX_PROCESSES; i++) {
        processes[i].burst_time = random_int(1, 10);
        processes[i].time_left = processes[i].burst_time;
        processes[i].arrival_time = random_int(0, 20);
        processes[i].priority = random_int(1, 5);
    }
    
    // print the generated processes
    printf("Generated Processes:\n");
    for(int i=0; i<MAX_PROCESSES; i++) {
        printf("Process %d -> Burst Time: %d, Arrival Time: %d, Priority: %d\n", i+1, processes[i].burst_time, processes[i].arrival_time, processes[i].priority);
    }
    printf("\n");
    
    // sort the processes by arrival time
    sort_processes_by_arrival_time(processes, MAX_PROCESSES);
    
    // execute the FCFS scheduling algorithm
    printf("FCFS Scheduling Algorithm:\n");
    fcfs(processes, MAX_PROCESSES);
    printf("\n");
    
    // reset time left values
    for(int i=0; i<MAX_PROCESSES; i++) {
        processes[i].time_left = processes[i].burst_time;
    }
    
    // sort the processes by arrival time
    sort_processes_by_arrival_time(processes, MAX_PROCESSES);
    
    // execute the SJF scheduling algorithm
    printf("SJF Scheduling Algorithm:\n");
    sjf(processes, MAX_PROCESSES);
    printf("\n");
    
    // reset time left values
    for(int i=0; i<MAX_PROCESSES; i++) {
        processes[i].time_left = processes[i].burst_time;
    }
    
    // sort the processes by priority
    sort_processes_by_priority(processes, MAX_PROCESSES);
    
    // execute the Priority scheduling algorithm
    printf("Priority Scheduling Algorithm:\n");
    priority(processes, MAX_PROCESSES);
    printf("\n");
    
    return 0;
}