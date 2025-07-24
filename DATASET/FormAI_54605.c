//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int wait_time; 
    int turnaround_time;
    int completion_time;  
} process;

int main() {
    int n, quantum_time, total_time = 0, total_wait_time = 0, total_turnaround_time = 0, i, j;
    float avg_wait_time, avg_turnaround_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &quantum_time);
    process arr[n];
    for(i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &arr[i].arrival_time);
        total_time += arr[i].arrival_time;
        printf("Enter burst time for process %d: ", i+1); 
        scanf("%d", &arr[i].burst_time);
        arr[i].remaining_time = arr[i].burst_time;
        arr[i].pid = i+1;
    }
    int current_time = 0;
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWait\n");
    int flag = 0;
    while(flag != 1) {
        flag = 1;
        for(i = 0; i < n; i++) {
            if(arr[i].remaining_time > 0) {
                flag = 0;
                if(arr[i].remaining_time > quantum_time) {
                    current_time += quantum_time;
                    arr[i].remaining_time -= quantum_time;
                }
                else {
                    current_time += arr[i].remaining_time;
                    arr[i].completion_time = current_time;
                    arr[i].turnaround_time = arr[i].completion_time - arr[i].arrival_time;
                    arr[i].wait_time = arr[i].turnaround_time - arr[i].burst_time;
                    arr[i].remaining_time = 0;
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        total_wait_time += arr[i].wait_time;
        total_turnaround_time += arr[i].turnaround_time;
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].arrival_time, arr[i].burst_time, arr[i].completion_time, arr[i].turnaround_time, arr[i].wait_time);
    }
    avg_wait_time = (float) total_wait_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;
    printf("\nAverage Wait Time: %f\n", avg_wait_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    return 0;
}