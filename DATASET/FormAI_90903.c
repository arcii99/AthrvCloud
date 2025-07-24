//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_NUM 10 // Number of tasks
#define FULL_TIME 1000 // Full time of execution

typedef struct {
    int id; // Task ID
    int time; // Execution time of task
    int priority; // Task priority
} task_t;

void create_task_list(task_t* task_list, int num_tasks);
void print_task_list(task_t* task_list, int num_tasks);
void execute_tasks(task_t* task_list, int num_tasks);

int main() {
    task_t task_list[TASK_NUM];
    
    srand(time(NULL));
    
    create_task_list(task_list, TASK_NUM);
    print_task_list(task_list, TASK_NUM);
    execute_tasks(task_list, TASK_NUM);
    
    return 0;
}

// Randomly generate the task list
void create_task_list(task_t* task_list, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        task_list[i].id = i + 1;
        task_list[i].time = rand() % (FULL_TIME / num_tasks); // Time task will take to execute
        task_list[i].priority = rand() % 5; // Priority of task
    }
}

// Print the task list
void print_task_list(task_t* task_list, int num_tasks) {
    printf("Task list:\n");
    printf("ID\tTime\tPriority\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%d\t%d\n", task_list[i].id, task_list[i].time, task_list[i].priority);
    }
    printf("\n");
}

// Execute the tasks in the task list
void execute_tasks(task_t* task_list, int num_tasks) {
    printf("Executing tasks...\n");
    
    int elapsed_time = 0;
    int remaining_time = FULL_TIME;
    int current_task = 0;
    
    while (remaining_time > 0 && current_task < num_tasks) {
        // Check if task can be executed
        if (task_list[current_task].time <= remaining_time) {
            printf("Task %d is executing\n", task_list[current_task].id);
            elapsed_time += task_list[current_task].time;
            remaining_time -= task_list[current_task].time;
            current_task++;
        }
        else {
            printf("Task %d cannot be executed yet\n", task_list[current_task].id);
            current_task++;
        }
    }
    
    printf("All tasks completed in %d ms\n", elapsed_time);
}