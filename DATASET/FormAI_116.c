//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 20

// Define the process struct
typedef struct {
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
} process_t;

// Define the scheduler struct
typedef struct {
    char name[20];
    void (*schedule)(process_t processes[], int num_processes);
} scheduler_t;

// Function to implement the First Come, First Serve scheduling algorithm
void fcfs(process_t processes[], int num_processes) {
    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].response_time = current_time - processes[i].arrival_time;
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        current_time += processes[i].burst_time;
    }
}

// Function to implement the Shortest Job First scheduling algorithm
void sjf(process_t processes[], int num_processes) {
    int current_time = 0;
    int remaining_time[num_processes];
    int completed[num_processes];

    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].burst_time;
        completed[i] = 0;
    }

    while (1) {
        int min_time = 1000000;
        int min_index = -1;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] < min_time && !completed[i]) {
                min_time = remaining_time[i];
                min_index = i;
            }
        }

        if (min_index == -1) break;

        processes[min_index].response_time = current_time - processes[min_index].arrival_time;
        processes[min_index].waiting_time = current_time - processes[min_index].arrival_time;
        processes[min_index].turnaround_time = processes[min_index].burst_time + processes[min_index].waiting_time;
        current_time += processes[min_index].burst_time;
        remaining_time[min_index] = 0;
        completed[min_index] = 1;
    }
}

// Function to implement the Round Robin scheduling algorithm
void round_robin(process_t processes[], int num_processes) {
    int current_time = 0;
    int completed[num_processes];
    int remaining[num_processes];

    for (int i = 0; i < num_processes; i++) {
        completed[i] = 0;
        remaining[i] = processes[i].burst_time;
    }

    int time_quantum = 2;

    while (1) {
        int all_complete = 1;

        for (int i = 0; i < num_processes; i++) {
            if (remaining[i] > 0) {
                all_complete = 0;

                if (remaining[i] > time_quantum) {
                    processes[i].waiting_time += current_time - processes[i].arrival_time;
                    processes[i].response_time = (processes[i].response_time == -1) ? current_time - processes[i].arrival_time : processes[i].response_time;
                    current_time += time_quantum;
                    remaining[i] -= time_quantum;
                } else {
                    processes[i].waiting_time += current_time - processes[i].arrival_time;
                    processes[i].response_time = (processes[i].response_time == -1) ? current_time - processes[i].arrival_time : processes[i].response_time;
                    current_time += remaining[i];
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    remaining[i] = 0;
                    completed[i] = 1;
                }
            }
        }

        if (all_complete) break;
    }
}

// Define an array of scheduler structs
scheduler_t schedulers[] = {
    {"First Come, First Serve", fcfs},
    {"Shortest Job First", sjf},
    {"Round Robin", round_robin}
};

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate some random process data
    int num_processes = rand() % (MAX_PROCESSES - 5) + 5;
    process_t processes[num_processes];

    for (int i = 0; i < num_processes; i++) {
        processes[i].arrival_time = rand() % 50;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = -1;
    }

    // Print out the generated process data
    printf("Generated Process Data:\n");
    printf("=============================================\n");
    printf("| Process | Arrival | Burst | Waiting | Turnaround | Response |\n");
    printf("|         |  Time   | Time  |  Time   |    Time    |   Time   |\n");
    printf("=============================================\n");

    for (int i = 0; i < num_processes; i++) {
        printf("|    %2d   |   %2d    |   %2d   |          |            |          |\n", i, processes[i].arrival_time, processes[i].burst_time);
    }

    printf("=============================================\n\n");

    // Run each scheduler on the generated process data
    for (int i = 0; i < sizeof(schedulers) / sizeof(scheduler_t); i++) {
        schedulers[i].schedule(processes, num_processes);

        // Print out the results for each scheduler
        printf("%s Results:\n", schedulers[i].name);
        printf("=============================================\n");
        printf("| Process | Arrival | Burst | Waiting | Turnaround | Response |\n");
        printf("|         |  Time   | Time  |  Time   |    Time    |   Time   |\n");
        printf("=============================================\n");

        float total_wait = 0;
        float total_turnaround = 0;
        float total_response = 0;

        for (int j = 0; j < num_processes; j++) {
            printf("|    %2d   |   %2d    |   %2d   |   %2d    |     %2d     |    %2d    |\n", j, processes[j].arrival_time, processes[j].burst_time, processes[j].waiting_time, processes[j].turnaround_time, processes[j].response_time);

            total_wait += processes[j].waiting_time;
            total_turnaround += processes[j].turnaround_time;
            total_response += processes[j].response_time;
        }

        printf("=============================================\n");
        printf("Average Waiting Time: %f\n", total_wait / num_processes);
        printf("Average Turnaround Time: %f\n", total_turnaround / num_processes);
        printf("Average Response Time: %f\n", total_response / num_processes);
        printf("\n");
    }

    return 0;
}