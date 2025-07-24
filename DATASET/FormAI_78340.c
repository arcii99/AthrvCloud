//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
    int wait_time;
    int turnaround_time;
};

int main(){

    int i, n, total_burst_time = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("\n           ***** Medieval CPU Scheduling Algorithm ****\n\n");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(i = 0; i < n; i++){

        printf("\nEnter the arrival time for process %d: ", i+1);
        scanf("%d", &p[i].arrival_time);

        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst_time);

        printf("Enter the priority for process %d: ", i+1);
        scanf("%d", &p[i].priority);

        p[i].pid = i+1;
        p[i].remaining_time = p[i].burst_time;

        total_burst_time += p[i].burst_time;
    }

    int current_time = 0;

    printf("\nMedieval CPU Scheduling Order: \n");

    while(total_burst_time > 0){

        int highest_priority_index = -1;
        int highest_priority = -1;

        for(i = 0; i < n; i++){
            if(p[i].arrival_time <= current_time && p[i].remaining_time > 0){
                if(p[i].priority > highest_priority){
                    highest_priority = p[i].priority;
                    highest_priority_index = i;
                }
            }
        }

        if(highest_priority_index == -1){
            current_time++;
        }
        else{

            p[highest_priority_index].remaining_time--;
            total_burst_time--;
            current_time++;

            if(p[highest_priority_index].remaining_time == 0){
                p[highest_priority_index].turnaround_time = current_time - p[highest_priority_index].arrival_time;
                p[highest_priority_index].wait_time = p[highest_priority_index].turnaround_time - p[highest_priority_index].burst_time;

                avg_wait_time += p[highest_priority_index].wait_time;
                avg_turnaround_time += p[highest_priority_index].turnaround_time;

                printf("%d  ", p[highest_priority_index].pid);
            }
        }
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;

    printf("\n\n          ***** Medieval CPU Scheduling Algorithm Results ****\n\n");

    printf("Average Waiting Time: %.2fms\n", avg_wait_time);
    printf("Average Turnaround Time: %.2fms\n\n", avg_turnaround_time);

    return 0;
}