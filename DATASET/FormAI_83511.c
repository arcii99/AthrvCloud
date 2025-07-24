//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define QUANTUM 4

typedef struct {
    int pid;
    int burst_time;
    int remaining_burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} process;

void round_robin(process *process_list, int n) {
    int time = 0;
    int remaining_processes = n;
    int current_process = 0;
    int time_quantum = QUANTUM;

    while(remaining_processes > 0) {
        if(process_list[current_process].remaining_burst_time <= time_quantum && process_list[current_process].remaining_burst_time > 0) {
            time += process_list[current_process].remaining_burst_time;
            process_list[current_process].remaining_burst_time = 0;
        } else if(process_list[current_process].remaining_burst_time > 0) {
            time += time_quantum;
            process_list[current_process].remaining_burst_time -= time_quantum;
        }

        if(process_list[current_process].remaining_burst_time == 0) {
            remaining_processes--;
            process_list[current_process].completion_time = time;
            process_list[current_process].turnaround_time = process_list[current_process].completion_time - process_list[current_process].arrival_time;
            process_list[current_process].waiting_time = process_list[current_process].turnaround_time - process_list[current_process].burst_time;
            process_list[current_process].response_time = process_list[current_process].completion_time - process_list[current_process].burst_time - process_list[current_process].arrival_time;
        }

        current_process = (current_process + 1) % n;

        if(current_process == 0) {
            time_quantum++;
        }
    }
}

void display_results(process *process_list, int n) {
    printf("PID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process_list[i].pid, process_list[i].burst_time,
                process_list[i].arrival_time, process_list[i].completion_time, process_list[i].turnaround_time,
                process_list[i].waiting_time, process_list[i].response_time);
    }
}

void sort_by_arrival_time(process *process_list, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(process_list[i].arrival_time > process_list[j].arrival_time) {
                process temp = process_list[i];
                process_list[i] = process_list[j];
                process_list[j] = temp;
            }
        }
    }
}

void simulate(process *process_list, int n) {
    sort_by_arrival_time(process_list, n);
    round_robin(process_list, n);
    display_results(process_list, n);
}

int main() {
    process process_list[MAX_PROCESSES] = {
                                            {1, 6, 6, 0}, 
                                            {2, 8, 8, 1}, 
                                            {3, 7, 7, 2}, 
                                            {4, 3, 3, 3}, 
                                            {5, 4, 4, 4}
                                        };
    simulate(process_list, 5);
    return 0;
}