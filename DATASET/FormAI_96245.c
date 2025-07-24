//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    bool executed;
};

struct GanttChart {
    int process_id;
    int start_time;
    int end_time;
};

void draw_gantt_chart(struct GanttChart *chart, int len) {
    printf("\n\nGantt Chart:\n\n");
    int total_time = chart[len - 1].end_time;
    for (int i = 0; i <= total_time; ++i) {
        printf("%d", i);
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
        for (int j = chart[i].start_time; j < chart[i].end_time; ++j) {
            printf(" ");
        }
        printf("P%d", chart[i].process_id);
    }
}

void print_process_details(struct Process *processes, int n) {
    printf("\nProcess\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    printf("-------\t----------\t------------\t---------------\t------------\t-------------\n");
    for (int i = 0; i < n; ++i) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, 
        processes[i].turnaround_time, processes[i].waiting_time, processes[i].response_time);
    }
}

float calculate_average_turnaround_time(struct Process *processes, int n) {
    float avg_turnaround_time = 0.0;
    for (int i = 0; i < n; ++i) {
        avg_turnaround_time += processes[i].turnaround_time;
    }
    return avg_turnaround_time / n;
}

float calculate_average_waiting_time(struct Process *processes, int n) {
    float avg_waiting_time = 0.0;
    for (int i = 0; i < n; ++i) {
        avg_waiting_time += processes[i].waiting_time;
    }
    return avg_waiting_time / n;
}

void sort_processes_by_arrival_time(struct Process *processes, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void execute_processes(struct Process *processes, int n, int quantum_time) {
    struct GanttChart chart[MAX_PROCESSES];
    int curr_time = 0;
    int chart_i = 0;
    int remaining = n;
    bool done = false;

    while (!done) {
        done = true;
        for (int i = 0; i < n; ++i) {
            if (processes[i].executed) {
                continue;
            }
            processes[i].response_time = curr_time - processes[i].arrival_time;
            if (processes[i].remaining_time > 0) {
                done = false;
                if (processes[i].remaining_time > quantum_time) {
                    curr_time += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                    chart[chart_i].process_id = processes[i].id;
                    chart[chart_i].start_time = curr_time - quantum_time;
                    chart[chart_i].end_time = curr_time;
                    chart_i++;
                } else {
                    curr_time += processes[i].remaining_time;
                    processes[i].turnaround_time = curr_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    processes[i].executed = true;
                    chart[chart_i].process_id = processes[i].id;
                    chart[chart_i].start_time = curr_time - processes[i].burst_time;
                    chart[chart_i].end_time = curr_time;
                    chart_i++;
                    remaining--;
                }
            }
        }
        if (done) {
            break;
        }
    }
    draw_gantt_chart(chart, chart_i);
    print_process_details(processes, n);
    printf("\nAverage Turnaround Time: %.2f", calculate_average_turnaround_time(processes, n));
    printf("\nAverage Waiting Time: %.2f", calculate_average_waiting_time(processes, n));
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[MAX_PROCESSES];

    for (int i = 0; i < num_processes; ++i) {
        printf("\nProcess %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].executed = false;
    }

    int quantum_time;
    printf("\nEnter Quantum Time: ");
    scanf("%d", &quantum_time);

    sort_processes_by_arrival_time(processes, num_processes);

    execute_processes(processes, num_processes, quantum_time);

    return 0;
}