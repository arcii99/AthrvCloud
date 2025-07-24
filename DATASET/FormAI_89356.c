//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct process p[num_processes]; // declares an array of processes

    // prompts user to enter process data
    for(int i = 0; i < num_processes; i++) {
        printf("Enter details for process %d:\n", i+1);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].pid = i+1;
    }

    // sorts processes by arrival time
    for(int i = 0; i < num_processes-1; i++) {
        for(int j = i+1; j < num_processes; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                // swap the processes
                struct process temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0; // current time
    int completed = 0; // number of completed processes
    bool visited[num_processes]; // array to keep track of visited processes

    memset(visited, false, sizeof(visited)); // initialize array to false values

    while(completed < num_processes) {
        int min_priority = 100000; // arbitrary high value to find minimum priority
        int index = -1; // index of minimum priority process in queue

        for(int i = 0; i < num_processes; i++) {
            if(p[i].arrival_time <= time && visited[i] == false && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                index = i;
            }
        }

        if(index != -1) {
            p[index].completion_time = time + p[index].burst_time;
            p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
            p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;

            visited[index] = true;
            completed++;

            time = p[index].completion_time;
        }
        else {
            time++;
        }
    }

    // display the results for each process
    printf("\nPID\tBurst time\tArrival time\tPriority\tCompletion time\tWaiting time\tTurnaround time\n");

    for(int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }

    return 0;
}