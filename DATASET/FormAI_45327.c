//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include<stdio.h>

// Function to sort processes by arrival time
void SortByArrivalTime(int processes[], int n, int arrival_time[]) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arrival_time[processes[j]] < arrival_time[processes[min_index]]) {
                min_index = j;
            }
        }
        int temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;
    }
}

// Function to perform Round Robin CPU Scheduling
void RoundRobin(int processes[], int n, int burst_time[], int arrival_time[], int time_quantum) {
    int remaining_time[n], wait_time[n], turnaround_time[n];

    // Initialize remaining_time[] array with burst_time[] array
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }
  
    int current_time = 0; // Keep track of current time
    int completed_processes = 0; // Keep track of number of completed processes
    while (completed_processes < n) {
        int is_completed = 1;
        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and that it still has remaining time
            if (arrival_time[processes[i]] <= current_time && remaining_time[processes[i]] > 0) {
                is_completed = 0;
                if (remaining_time[processes[i]] <= time_quantum) {
                    current_time += remaining_time[processes[i]];
                    turnaround_time[processes[i]] = current_time - arrival_time[processes[i]];
                    remaining_time[processes[i]] = 0;
                }
                else {
                    current_time += time_quantum;
                    remaining_time[processes[i]] -= time_quantum;
                }
            }
        }
        // If no process was executed, increment current time
        if (is_completed) {
            current_time++;
        }
        // If all the remaining time of a process is consumed, increment the completed processes counter
        if (remaining_time[processes[n-1]] == 0) {
            completed_processes++;
        }
    }

    // Calculate wait_time[] array and average wait time
    int total_wait_time = 0;
    for (int i = 0; i < n; i++) {
        wait_time[i] = turnaround_time[i] - burst_time[i];
        total_wait_time += wait_time[i];
    }
    float average_wait_time = (float) total_wait_time / n;

    // Calculate turnaround_time[] array and average turnaround time
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += turnaround_time[i];
    }
    float average_turnaround_time = (float) total_turnaround_time / n;
  
    // Print the output
    printf("Process\tBurst Time\tArrival Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i], burst_time[processes[i]], arrival_time[processes[i]], turnaround_time[processes[i]], wait_time[processes[i]]);
    }
    printf("Average Turnaround Time = %.2f\n", average_turnaround_time);
    printf("Average Wait Time = %.2f\n", average_wait_time);
}

int main() {
    int n = 5, time_quantum = 2;
    int processes[] = {0, 1, 2, 3, 4};
    int arrival_time[] = {0, 1, 2, 3, 4};
    int burst_time[] = {5, 4, 3, 2, 1};

    SortByArrivalTime(processes, n, arrival_time);
    RoundRobin(processes, n, burst_time, arrival_time, time_quantum);

    return 0;
}