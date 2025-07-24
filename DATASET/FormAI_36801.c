//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>

int main() {
    int n, i, j, temp, total = 0;
    float avg_wait_time, avg_turnaround_time;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    int burst_time[n], priority[n], process_id[n], waiting_time[n], turnaround_time[n];
    for (i = 0; i < n; i++) {
        process_id[i] = i+1;
        printf("Enter burst time and priority for process %d: ", i+1);
        scanf("%d %d", &burst_time[i], &priority[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        total += waiting_time[i];
    }
    avg_wait_time = (float)total/n;
    total = 0;
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total += turnaround_time[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", process_id[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    avg_turnaround_time = (float)total/n;
    printf("\n\nAverage Waiting Time = %f", avg_wait_time);
    printf("\nAverage Turnaround Time = %f", avg_turnaround_time);
    return 0;
}