//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>

int main() {
    // Set up process array
    int process[10], arrival_time[10], burst_time[10], completion_time[10];
    float turnaround_time[10], waiting_time[10];
    int n, i, j, smallest, time = 0, remaining;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get process information
    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        process[i] = i+1;
    }

    // Sort by arrival time
    for(i = 0; i < n-1; i++) {
        smallest = i;
        for(j = i+1; j < n; j++) {
            if(arrival_time[j] < arrival_time[smallest])
                smallest = j;
        }
        swap(&process[i], &process[smallest]);
        swap(&arrival_time[i], &arrival_time[smallest]);
        swap(&burst_time[i], &burst_time[smallest]);
    }

    // Run the scheduler
    remaining = n;
    while(remaining != 0) {
        smallest = n;
        for(i = 0; i < n; i++) {
            if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                smallest = i;
        }
        time++;
        burst_time[smallest]--;
        if(burst_time[smallest] == 0) {
            completion_time[smallest] = time;
            turnaround_time[smallest] = completion_time[smallest] - arrival_time[smallest];
            waiting_time[smallest] = turnaround_time[smallest] - burst_time[smallest];
            avg_turnaround_time += turnaround_time[smallest];
            avg_waiting_time += waiting_time[smallest];
            remaining--;
        }
    }

    // Print results
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%f\t\t%f\n", process[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average Turnaround Time: %f\n", avg_turnaround_time/n);
    printf("Average Waiting Time: %f\n", avg_waiting_time/n);
    return 0;
}

// Swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}