//FormAI DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10 // maximum number of tasks
#define MAX_NAME 20 // maximum size of task name

struct Task {
    char name[MAX_NAME];
    int priority;
    time_t start_time;
};

struct TaskScheduler {
    struct Task tasks[MAX_TASKS];
    int size;
};

void addTask(struct TaskScheduler* scheduler, char* name, int priority, int delay) {
    if(scheduler->size == MAX_TASKS) {
        printf("Task Scheduler is full!\n");
        return;
    }

    struct Task task;
    strcpy(task.name, name);
    task.priority = priority;
    task.start_time = time(NULL) + delay;

    scheduler->tasks[scheduler->size++] = task;
}

void removeTask(struct TaskScheduler* scheduler, int index) {
    if(index < 0 || index >= scheduler->size) {
        printf("Invalid index!\n");
        return;
    }

    for(int i = index; i < scheduler->size - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i+1];
    }

    scheduler->size--;
}

void printTask(struct Task task) {
    printf("Name: %s\nPriority: %d\nStart Time: %s", task.name, task.priority, ctime(&task.start_time));
}

void printTasks(struct TaskScheduler scheduler) {
    printf("Task Scheduler:\n");
    for(int i = 0; i < scheduler.size; i++) {
        printf("Task %d:\n", i+1);
        printTask(scheduler.tasks[i]);
        printf("---------------------\n");
    }
}

int main() {
    struct TaskScheduler scheduler;
    scheduler.size = 0;

    addTask(&scheduler, "Task 1", 2, 5);
    addTask(&scheduler, "Task 2", 1, 10);
    addTask(&scheduler, "Task 3", 3, 3);

    printTasks(scheduler);

    // simulate task execution
    while(scheduler.size > 0) {
        time_t now = time(NULL);

        for(int i = 0; i < scheduler.size; i++) {
            if(difftime(now, scheduler.tasks[i].start_time) >= 0) {
                printf("Executing task %s...\n", scheduler.tasks[i].name);

                removeTask(&scheduler, i); // remove task after execution
                i--; // adjust i after removal
            }
        }

        printf("Sleeping for 1 second...\n");
        sleep(1); // sleep for 1 second
    }

    printf("No more tasks in Task Scheduler.\n");

    return 0;
}