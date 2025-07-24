//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* The SRTF (shortest remaining time first) CPU scheduling algorithm */
int main() {
   
    printf("Welcome to the CPU scheduler!\n\n");
    
    // Generate random arrival times and CPU burst times for 5 processes
    srand(time(NULL));
    int arrival_times[5];
    int burst_times[5];
    
    for (int i = 0; i < 5; i++) {      
        arrival_times[i] = rand() % 20; // max arrival time is 19
        burst_times[i] = rand() % 10 + 1; // min burst time is 1, max burst time is 10
    }
    
    // Print arrival times and burst times for each process
    printf("Process\tArrival Time\tBurst Time\n");
    for (int i = 0; i < 5; i++) {
        printf("  P%d\t      %d\t\t   %d\n", i+1, arrival_times[i], burst_times[i]);
    }
    printf("\n");
    
    // Initialize process completion times and turnaround times
    int completion_times[5];
    int turnaround_times[5];
    memset(completion_times, -1, sizeof(completion_times));
    memset(turnaround_times, -1, sizeof(turnaround_times));
    
    // Calculate average waiting time using SRTF
    int time = 0;
    int waiting_time = 0;
    int processed = 0;
    int remaining_burst_times[5];
    memcpy(remaining_burst_times, burst_times, sizeof(burst_times));
    
    while (processed < 5) {
        int shortest_job = -1;
        int shortest_burst_time = 99;
        for (int i = 0; i < 5; i++) {
            if (arrival_times[i] <= time && remaining_burst_times[i] < shortest_burst_time && remaining_burst_times[i] > 0) {
                shortest_job = i;
                shortest_burst_time = remaining_burst_times[i];
            }
        }
        if (shortest_job == -1) {
            time++;
            continue;
        }
        remaining_burst_times[shortest_job]--;
        if (remaining_burst_times[shortest_job] == 0) {
            processed++;
            completion_times[shortest_job] = time + 1;
            turnaround_times[shortest_job] = completion_times[shortest_job] - arrival_times[shortest_job];
            waiting_time += turnaround_times[shortest_job] - burst_times[shortest_job];
        }
        time++;
    }
    
    float avg_waiting_time = (float) waiting_time / 5;
    printf("Average Waiting Time: %.2f\n\n", avg_waiting_time);
    
    // Print process completion times and turnaround times
    printf("Process\tCompletion Time\tTurnaround Time\n");
    for (int i = 0; i < 5; i++) {
        printf("  P%d\t      %d\t\t   %d\n", i+1, completion_times[i], turnaround_times[i]);
    }

    return 0;
}