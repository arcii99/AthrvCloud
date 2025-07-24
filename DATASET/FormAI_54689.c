//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define TASK_COUNT 3
#define TIME_QUANTUM 3

int task_count = TASK_COUNT;
int time_quantum = TIME_QUANTUM;
int current_task = 0;
int task_completed_count = 0;
int task_indices[TASK_COUNT] = {0, 1, 2};
int task_durations[TASK_COUNT] = {8, 4, 2};
int task_remaining_times[TASK_COUNT] = {8, 4, 2};

// Switches to the next task in round-robin fashion
void switch_task() {
    current_task = (current_task + 1) % task_count;
}

// Handles timer interrupt
void timer_handler(int signum) {
    task_remaining_times[current_task] -= time_quantum;
    printf("Task %d executed for %d seconds. Remaining time: %d seconds\n", 
           current_task, time_quantum, task_remaining_times[current_task]);
    if (task_remaining_times[current_task] <= 0) {
        printf("Task %d completed\n", current_task);
        task_completed_count++;
        task_remaining_times[current_task] = task_durations[current_task];
        switch_task();
    }
}

// Sets a timer to handle time interrupts
void set_timer() {
    struct itimerval timer;
    timer.it_value.tv_sec = time_quantum;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = time_quantum;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
}

// Shuffles the task indices
void shuffle_task_indices() {
    for (int i = task_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = task_indices[i];
        task_indices[i] = task_indices[j];
        task_indices[j] = temp;
    }
}

int main() {
    printf("Task Scheduler ready\n\n");
    shuffle_task_indices();
    signal(SIGALRM, timer_handler);
    set_timer();
    while (task_completed_count < task_count) {
        if (task_remaining_times[task_indices[current_task]] <= 0) {
            switch_task();
            continue;
        }
    }
    printf("\nAll tasks completed\n");
    return 0;
}