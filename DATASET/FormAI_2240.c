//FormAI DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a task struct
typedef struct {
    int id;
    int time;
    int priority;
} Task;

// Define a scheduling function that takes an array of tasks and their length
void schedule_tasks(Task tasks[], int num_tasks) {
    int time_elapsed = 0;
    int completed_tasks = 0;
    int i, j;
    Task temp;

    // Schedule tasks in order of priority, then shortest time needed
    for (i = 0; i < num_tasks - 1; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority ||
                (tasks[i].priority == tasks[j].priority && tasks[i].time > tasks[j].time)) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Scheduled tasks:\n");

    // Run through tasks until all are completed
    while (completed_tasks < num_tasks) {
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].time > 0 && tasks[i].time + time_elapsed <= 100) {
                printf("Task %d started at time %d\n", tasks[i].id, time_elapsed);
                // Simulate task by decrementing time needed
                tasks[i].time--;
                if (tasks[i].time == 0) {
                    printf("Task %d completed at time %d\n", tasks[i].id, time_elapsed + 1);
                    completed_tasks++;
                }
            }
        }
        time_elapsed++;
    }
}

int main() {
    // Create task array
    Task tasks[4] = {{1, 10, 2}, {2, 5, 1}, {3, 20, 3}, {4, 15, 2}};

    printf("Initial task order:\n");
    printf("Task id | Time needed | Priority\n");
    for (int i = 0; i < 4; ++i)
        printf("%d\t|\t%d\t|\t%d\n", tasks[i].id, tasks[i].time, tasks[i].priority);

    // Schedule tasks and print results
    schedule_tasks(tasks, 4);

    return 0;
}