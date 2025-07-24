//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define maximum number of tasks
#define MAX_TASKS 10

// task struct
typedef struct {
    int task_id;
    int priority;
    int execution_time;
} Task;

// function to generate a random integer within a range
int random_int(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// function to initialize the task array with random tasks
void init_tasks(Task tasks[], int num_tasks) {
    // set random seed
    srand(time(NULL));
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].task_id = i + 1;
        tasks[i].priority = random_int(1, 5);
        tasks[i].execution_time = random_int(1, 10);
    }
}

// function to print the task array
void print_tasks(Task tasks[], int num_tasks) {
    printf("Task ID | Priority | Execution Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t  | %d\t   | %d\n", tasks[i].task_id, tasks[i].priority, tasks[i].execution_time);
    }
}

// function to swap two tasks in the task array
void swap_tasks(Task *task1, Task *task2) {
    Task temp = *task1;
    *task1 = *task2;
    *task2 = temp;
}

// function to sort the task array based on priority
void sort_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                swap_tasks(&tasks[i], &tasks[j]);
            }
        }
    }
}

// function to schedule the tasks
void schedule_tasks(Task tasks[], int num_tasks) {
    printf("Task execution order:\n");
    printf("Task ID | Priority | Execution Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t  | %d\t   | %d\n", tasks[i].task_id, tasks[i].priority, tasks[i].execution_time);
        printf("Executing Task %d for %d seconds...\n", tasks[i].task_id, tasks[i].execution_time);
    }
}

int main() {
    // create an array of tasks
    Task tasks[MAX_TASKS];

    // initialize the array with random tasks
    init_tasks(tasks, MAX_TASKS);

    // print the tasks before sorting
    printf("Tasks before sorting:\n");
    print_tasks(tasks, MAX_TASKS);

    // sort the tasks based on priority
    sort_tasks(tasks, MAX_TASKS);

    // print the tasks after sorting
    printf("\nTasks after sorting:\n");
    print_tasks(tasks, MAX_TASKS);

    // schedule the tasks
    schedule_tasks(tasks, MAX_TASKS);

    return 0;
}