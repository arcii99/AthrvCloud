//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TIME_QUANTUM 4
#define MAX_PROCESSES 5

struct processes{
    int pid;
    int burst_time;
    int remaining_time;
};

int main(){
    struct processes p[MAX_PROCESSES];
    int time_quantum = TIME_QUANTUM;
    int n = MAX_PROCESSES;
    int i, j, total_time = 0, total_burst = 0;
    srand(time(0)); //seed for random number generation
    for (i = 0; i < n; i++){
        p[i].pid = i+1;
        p[i].burst_time = rand()%20 + 1; //random burst time between 1 to 20
        p[i].remaining_time = p[i].burst_time;
        total_burst += p[i].burst_time;
    }
    printf("Round Robin CPU scheduling algorithm\n");
    printf("Total processes: %d\n", n);
    printf("Total burst time: %d\n\n", total_burst);
    printf("PID\tBurst Time\n");
    for (i = 0; i < n; i++){
        printf("%d\t%d\n", p[i].pid, p[i].burst_time);
    }
    printf("\n");
    printf("Gantt chart:\n\n");
    i = 0;
    while (total_time < total_burst){
        if (p[i].remaining_time > 0){
            printf("P%d\t", p[i].pid);
            if (p[i].remaining_time > time_quantum){
                total_time += time_quantum;
                p[i].remaining_time -= time_quantum;
            }
            else{
                total_time += p[i].remaining_time;
                p[i].remaining_time = 0;
                printf("%d\t", total_time);
            }
        }
        i++;
        if (i == n){
            i = 0;
        }
    }
    printf("\n\n");
    return 0;
}