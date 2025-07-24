//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct task {
    int id;
    int time;
    char* name;
};

void init_tasks(struct task* tasks, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i+1;
        tasks[i].time = rand() % 11 + 1; // set time to between 1 and 11
        tasks[i].name = "TASK";
    }
}

void print_tasks(struct task* tasks, int num_tasks) {
    printf("TASKS:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf(" - %s %d (%d seconds)\n", tasks[i].name, tasks[i].id, tasks[i].time);
    }
}

void run_task(struct task task) {
    printf("Running %s %d (%d seconds)\n", task.name, task.id, task.time);
}

void schedule_tasks(struct task* tasks, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        run_task(tasks[i]);
    }
}

int main() {
    int num_tasks = 5;
    struct task tasks[num_tasks];
    srand(1234); // set seed for random number generator
    init_tasks(tasks, num_tasks);
    print_tasks(tasks, num_tasks);
    printf("Starting task scheduler...\n");
    schedule_tasks(tasks, num_tasks);
    printf("All tasks completed.\n");
    return 0;
}