//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 3
#define MAX_TIME 10

enum TaskStatus {RUNNING, WAITING, COMPLETED};

struct Task {
    int id;
    int priority;
    int estimated_time;
    int elapsed_time;
    enum TaskStatus status;
};

void add_random_task(struct Task tasks[], int n) {
    // adds a random task to the array of tasks
    int i = 0;
    while (tasks[i].status != COMPLETED) {
        i++;
    }
    tasks[i].id = i + 1;
    tasks[i].priority = rand() % MAX_PRIORITY;
    tasks[i].estimated_time = rand() % MAX_TIME + 1;
    tasks[i].elapsed_time = 0;
    tasks[i].status = WAITING;
    printf("Task %d with priority %d and estimated time %d added.\n", tasks[i].id, tasks[i].priority, tasks[i].estimated_time);
}

void execute_task(struct Task *task) {
    task->status = RUNNING;
    printf("Executing task %d...\n", task->id);
    while (task->elapsed_time <= task->estimated_time) {
        printf("Elapsed time: %d seconds\n", task->elapsed_time);
        task->elapsed_time++;
        sleep(1); // wait one second
    }
    task->status = COMPLETED;
    printf("Task %d completed in %d seconds.\n", task->id, task->elapsed_time);
}

void schedule_tasks(struct Task tasks[], int n) {
    // schedules tasks based on their priority
    int i, j;
    for (i = 0; i < n; i++) {
        if (tasks[i].status == WAITING) {
            for (j = i + 1; j < n; j++) {
                if (tasks[j].status == WAITING && tasks[j].priority > tasks[i].priority) {
                    struct Task temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(0)); // initialize random seed
    
    struct Task tasks[MAX_TASKS];
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].status = COMPLETED;
    }
    
    while (1) { // infinite loop
        add_random_task(tasks, MAX_TASKS);
        schedule_tasks(tasks, MAX_TASKS);
        for (i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].status == WAITING) {
                execute_task(&tasks[i]);
                break;
            }
        }
    }
    
    return 0;
}