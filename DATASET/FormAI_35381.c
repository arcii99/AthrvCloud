//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 50

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int compare_arrival_time(const void *a, const void *b) {
    return ((struct Process*)a)->arrival_time - ((struct Process*)b)->arrival_time;
}

int compare_burst_time(const void *a, const void *b) {
    return ((struct Process*)a)->burst_time - ((struct Process*)b)->burst_time;
}

void print_table(struct Process processes[], int n) {
    printf("+-----+------------+--------------+----------------+---------------+-----------------+\n");
    printf("| PID | Arrival    | Burst        | Completion     | Waiting       | Turnaround      |\n");
    printf("|     | Time       | Time         | Time           | Time          | Time            |\n");
    printf("+-----+------------+--------------+----------------+---------------+-----------------+\n");
    for(int i = 0; i < n; i++) {
        printf("| %3d | %10d | %12d | %14d | %13d | %15d |\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("+-----+------------+--------------+----------------+---------------+-----------------+\n");
}

void fcfs(struct Process processes[], int n) {
    int time = 0;
    for(int i = 0; i < n; i++) {
        processes[i].completion_time = time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        time = processes[i].completion_time;
    }
    print_table(processes, n);
}

void sjf(struct Process processes[], int n) {
    int time = 0;
    qsort(processes, n, sizeof(struct Process), compare_burst_time);
    for(int i = 0; i < n; i++) {
        processes[i].completion_time = time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        time = processes[i].completion_time;
    }
    print_table(processes, n);
}

void init_processes(struct Process processes[], int n) {
    srand(42);
    for(int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 100;
        processes[i].burst_time = rand() % 50;
    }
}

void print_menu() {
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Exit\n");
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n = 10;
    init_processes(processes, n);

    while(1) {
        print_menu();
        int option;
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                fcfs(processes, n);
                break;
            case 2:
                sjf(processes, n);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}