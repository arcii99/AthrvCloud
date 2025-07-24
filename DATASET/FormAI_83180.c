//FormAI DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_TASKS 100 // maximum number of tasks that can be scheduled

struct task { // data structure to hold a task
    int id;
    int priority;
    void (*func)(void);
};

struct task_queue { // data structure to hold the tasks in a queue
    struct task tasks[MAX_TASKS];
    int num_tasks;
};

struct task_scheduler { // data structure to hold the task scheduler
    struct task_queue queues[10]; // queues for tasks with different priorities
    int num_queues;
    bool running;
};

struct task_scheduler scheduler; // global instance of task scheduler

void add_task_to_queue(struct task_queue *queue, struct task task) { // helper function to add a task to a queue
    if (queue->num_tasks == MAX_TASKS) {
        printf("Queue is full, cannot add task.\n");
        return;
    }
    queue->tasks[queue->num_tasks] = task;
    queue->num_tasks++;
}

void add_task(int priority, void (*func)(void)) { // function to add a task to the scheduler
    if (priority < 0 || priority > 9) {
        printf("Invalid priority, must be between 0 and 9.\n");
        return;
    }
    struct task task = {scheduler.queues[priority].num_tasks, priority, func};
    add_task_to_queue(&scheduler.queues[priority], task);
}

void run_task(struct task task) { // function to run a task
    printf("Running task with ID %d and priority %d.\n", task.id, task.priority);
    task.func();
}

void run_tasks() { // main function to run all tasks in the scheduler
    printf("Starting scheduler...\n");
    time_t start_time = time(NULL);
    while (scheduler.running) {
        for (int i = 0; i < 10; i++) { // iterate over all queues
            struct task_queue *queue = &scheduler.queues[i];
            if (queue->num_tasks > 0) { // if there are tasks in the queue, run the next one
                run_task(queue->tasks[0]);
                for (int j = 1; j < queue->num_tasks; j++) {
                    queue->tasks[j-1] = queue->tasks[j]; // move all tasks forward in the queue
                }
                queue->num_tasks--; // remove the task from the queue
            }
        }
        if (time(NULL) - start_time > 10) { // stop the scheduler after 10 seconds
            scheduler.running = false;
        }
    }
    printf("Scheduler stopped.\n");
}

void paranoid_task() { // example task that demonstrates the paranoid style
    printf("Starting paranoid task...\n");
    int *ptr = (int*)malloc(sizeof(int)); // allocate memory
    if (ptr == NULL) { // check for errors
        printf("Error: failed to allocate memory.\n");
        return;
    }
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < 10; i++) { // generate random numbers
        int random = rand();
        if (random % 2 == 0) { // check for parity
            printf("Random number %d is even.\n", random);
        } else {
            printf("Random number %d is odd.\n", random);
        }
    }
    free(ptr); // free memory
    ptr = NULL; // set pointer to null
    printf("Paranoid task complete.\n");
}

int main() { // example program
    scheduler.num_queues = 10;
    scheduler.running = true;
    add_task(5, paranoid_task);
    run_tasks();
    return 0;
}