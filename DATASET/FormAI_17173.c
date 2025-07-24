//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TASKS 10

int current_time = 0;
int task_queue[TOTAL_TASKS];
int queue_size = 0;

int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void add_task(int task) {
    printf("[+] Task %d added to the queue.\n", task);
    task_queue[queue_size++] = task;
}

int get_next_task() {
    if(queue_size == 0) {
        printf("[!] No tasks remaining in the queue.\n");
        return -1;
    }
    else {
        int task_index = get_random(0, queue_size-1);
        int task = task_queue[task_index];
        for(int i=task_index; i<queue_size-1; i++) {
            task_queue[i] = task_queue[i+1];
        }
        queue_size--;
        printf("[>] Task %d is the next task.\n", task);
        return task;
    }
}

void execute_task(int task) {
    printf("[*] Task %d is being executed...\n", task);
    int time_elapsed = get_random(1, 5);
    current_time += time_elapsed;
    printf("[+] Task %d completed in %d seconds. Time is now %d.\n", task, time_elapsed, current_time);
}

int main() {
    srand(time(NULL));

    printf("[*] Post-apocalyptic task scheduler initialized.\n");

    for(int i=0; i<TOTAL_TASKS; i++) {
        add_task(i+1);
    }

    printf("\n");

    while(queue_size > 0) {
        int next_task = get_next_task();
        if(next_task != -1) {
            execute_task(next_task);
        }
        printf("\n");
    }

    printf("[*] All tasks completed.\n");

    return 0;
}