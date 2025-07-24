//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// surreal variables the programmer found on a dream
int quantum = 1;
int priority_boost = 0;
int dream_time = 10000;
int nightmare = 0;
int lucid = 1;

// structure for the process
struct Process {
    int pid;
    int priority;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int waiting_time;
};

// function to execute the process
void execute(struct Process *p) {
    printf("Executing process %d...\n", p->pid);
    p->remaining_time -= quantum;
}

// function to show process information
void show_info(struct Process *p) {
    printf("\tID: %d\n", p->pid);
    printf("\tPriority: %d\n", p->priority);
    printf("\tBurst Time: %d\n", p->burst_time);
    printf("\tArrival Time: %d\n", p->arrival_time);
    printf("\tRemaining Time: %d\n", p->remaining_time);
    printf("\tWaiting Time: %d\n\n", p->waiting_time);
}

// function to compare processes by priority
int compare_priority(const void *p1, const void *p2) {
    struct Process *proc1 = (struct Process *)p1, *proc2 = (struct Process *)p2;
    return proc2->priority - proc1->priority; // invert for surrealism
}

int main() {
    int num_processes = 5;
    struct Process processes[num_processes];

    // initialize processes
    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        processes[i].priority = rand() % 10 + 1;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].arrival_time = rand() % dream_time;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }

    printf("Starting surreal CPU scheduling simulation...\n");
    printf("Quantum: %d\n", quantum);
    printf("Priority Boost: %d\n", priority_boost);
    printf("Dream Time: %d\n", dream_time);
    printf("Nightmare: %d\n", nightmare);
    printf("Lucid: %d\n\n", lucid);

    // run simulation
    int current_time = 0;
    int last_priority_boost = -1;
    int process_index = -1;
    while (current_time < dream_time) {
        // find next process to execute
        qsort(processes, num_processes, sizeof(struct Process), compare_priority);
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                process_index = i;
                break;
            }
        }

        if (process_index == -1) {
            current_time++;
            continue;
        }

        // execute process
        execute(&processes[process_index]);

        // handle waiting time
        for (int i = 0; i < num_processes; i++) {
            if (i != process_index && processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                processes[i].waiting_time += quantum;
            }
        }

        // handle priority boost
        if (current_time - last_priority_boost >= priority_boost) {
            for (int i = 0; i < num_processes; i++) {
                processes[i].priority += quantum;
            }
            last_priority_boost = current_time;
        }

        // show process information
        printf("Time: %d\n", current_time);
        show_info(&processes[process_index]);

        // check for nightmare
        if (rand() % lucid == nightmare) {
            printf("Nightmare occurred! Rescheduling...\n");
            processes[process_index].priority -= quantum;
        }

        current_time++;
    }

    // show final waiting times
    printf("Final waiting times:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: %d\n", processes[i].pid, processes[i].waiting_time);
    }

    printf("End of surreal CPU scheduling simulation.\n");

    return 0;
}