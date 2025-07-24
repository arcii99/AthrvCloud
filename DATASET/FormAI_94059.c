//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

/* Surrealist CPU Scheduling Algorithms */

int main(){
    int quantum_time = 3;
    int num_processes = 5;
    int priority[5] = {1, 3, 4, 2, 5};
    int burst_time[5] = {7, 4, 9, 2, 5};

    printf("Welcome to the Surrealist CPU Scheduling Algorithms.\n");
    printf("Let's see how the processes will be executed.\n\n");

    int time_elapsed = 0;
    int completed_processes = 0;
    while(completed_processes < num_processes){
        int current_process = -1;
        int current_priority = 0;
        int i;
        for(i=0; i<num_processes; i++){
            if(priority[i] > current_priority && burst_time[i] != 0){
                current_priority = priority[i];
                current_process = i;
            }
        }

        if(current_process == -1){
            time_elapsed++;
            continue;
        }

        int time_remaining = burst_time[current_process];
        printf("Process %d has started.\n", current_process);

        while(time_remaining > 0){
            time_remaining -= quantum_time;
            time_elapsed += quantum_time;
            printf("Time elapsed: %d\n", time_elapsed);
        }

        printf("Process %d has completed.\n", current_process);
        completed_processes++;
        burst_time[current_process] = 0;
    }

    printf("\nAll processes have been completed.\n");

    return 0;
}