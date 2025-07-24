//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>

int main(){

    int n, burst_time[20], waiting_time[20], turn_around_time[20], average_waiting_time = 0, average_turn_around_time = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("\nEnter the burst time for each process:\n");
    for(int i = 0; i < n; i++){
        printf("Process[%d]:", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // FCFS scheduling
    waiting_time[0] = 0;
    for(int i = 1; i < n; i++){
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
    for(int i = 0; i < n; i++){
        turn_around_time[i] = burst_time[i] + waiting_time[i];
        average_waiting_time += waiting_time[i];
        average_turn_around_time += turn_around_time[i];
    }
    average_waiting_time /= n;
    average_turn_around_time /= n;
    printf("\nAverage Waiting Time: %d", average_waiting_time);
    printf("\nAverage Turnaround Time: %d", average_turn_around_time);

    return 0;
}