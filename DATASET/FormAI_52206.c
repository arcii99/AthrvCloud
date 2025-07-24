//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>

/* 
This is it! A program that simulates a CPU Scheduling Algorithm.

Are you ready to see the power of scheduling? Let's dive in!

*/

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
} Process;

void first_come_first_serve(Process processes[], int num_processes) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    printf("\n---------------FIRST COME FIRST SERVE SCHEDULING---------------\n");
    printf("ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (int i = 0; i < num_processes; i++) {
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }

    float avg_waiting_time = total_waiting_time / (float) num_processes;
    float avg_turnaround_time = total_turnaround_time / (float) num_processes;

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
}

void shortest_job_first(Process processes[], int num_processes) {
    int total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;
    int current_time = 0;

    printf("\n---------------SHORTEST JOB FIRST SCHEDULING---------------\n");
    printf("ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (int i = 0; i < num_processes; i++) {
        int shortest_job = -1;
        for (int j = i; j < num_processes; j++) {
            if (processes[j].arrival_time <= current_time && (shortest_job == -1 || processes[j].burst_time < processes[shortest_job].burst_time)) {
                shortest_job = j;
            }
        }

        if (shortest_job == -1) {
            current_time = processes[i].arrival_time + processes[i].burst_time;
        } else {
            current_time += processes[shortest_job].burst_time;

            int j = shortest_job;
            processes[j].turnaround_time = current_time - processes[j].arrival_time;
            processes[j].waiting_time = processes[j].turnaround_time - processes[j].burst_time;
            processes[j].response_time = processes[j].waiting_time;
            total_waiting_time += processes[j].waiting_time;
            total_turnaround_time += processes[j].turnaround_time;
            total_response_time += processes[j].response_time;

            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[j].id, processes[j].arrival_time, processes[j].burst_time, processes[j].waiting_time, processes[j].turnaround_time, processes[j].response_time);
            Process tmp = processes[i];
            processes[i] = processes[j];
            processes[j] = tmp;
        }
    }

    float avg_waiting_time = total_waiting_time / (float) num_processes;
    float avg_turnaround_time = total_turnaround_time / (float) num_processes;
    float avg_response_time = total_response_time / (float) num_processes;

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Response Time: %.2f", avg_response_time);
}

int main() {
    Process processes[] = {
        {1, 0, 6},
        {2, 1, 8},
        {3, 2, 7},
        {4, 3, 3},
        {5, 4, 4},
    };

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    first_come_first_serve(processes, num_processes);
    shortest_job_first(processes, num_processes);

    printf("\nThank you for witnessing the power of scheduling!\n");

    return 0;
}