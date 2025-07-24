//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

enum states { ready, waiting, running, terminated };

typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int state;
} process;

typedef struct {
    process p[MAX_PROCESSES];
    int size;
} process_queue;

void init_queue(process_queue *q) {
    q->size = 0;
}

void add_process(process_queue *q, process p) {
    q->p[q->size] = p;
    q->size++;
}

process get_highest_priority(process_queue q) {
    int i;
    process highest_priority;
    highest_priority.priority = -1; // initialize to lowest priority possible
    for (i = 0; i < q.size; i++) {
        if (q.p[i].state == ready) {
            if (q.p[i].priority > highest_priority.priority) {
                highest_priority = q.p[i];
            }
        }
    }
    return highest_priority;
}

void print_queue(process_queue q) {
    int i;
    printf("PID\tBurst Time\tArrival Time\tPriority\n");
    for (i = 0; i < q.size; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", q.p[i].pid, q.p[i].burst_time, q.p[i].arrival_time, q.p[i].priority);
    }
}

int main() {
    int i;
    process_queue q;
    init_queue(&q);

    // generate random processes
    srand(time(NULL));
    for (i = 0; i < MAX_PROCESSES; i++) {
        process p;
        p.pid = i;
        p.burst_time = rand() % 20 + 1; // 1-20 ms burst time
        p.arrival_time = rand() % 100;
        p.priority = rand() % 5; // 0-4 priority
        p.state = ready;
        add_process(&q, p);
    }

    printf("Initial process queue:\n");
    print_queue(q);

    printf("\nRunning highest priority first scheduling algorithm:\n");
    while (q.size > 0) {
        process current_process = get_highest_priority(q);
        current_process.state = running;
        printf("\nRunning process with PID %d\n", current_process.pid);
        int j;
        for (j = 0; j < current_process.burst_time; j++) {
            // do nothing for 1 ms
        }
        current_process.state = terminated;
        printf("Process with PID %d terminated\n", current_process.pid);
        for (i = 0; i < q.size; i++) {
            if (q.p[i].state == ready) {
                q.p[i].priority += 1; // aging
            }
        }
        for (i = 0; i < q.size; i++) {
            if (q.p[i].state == terminated) {
                // remove terminated process from queue
                for (j = i; j < q.size - 1; j++) {
                    q.p[j] = q.p[j+1];
                }
                q.size--;
            }
        }
    }

    printf("\nAll processes terminated\n");

    return 0;
}