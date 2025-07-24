//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 5
#define MAX_NUM 10

// Task structure
typedef struct {
    int id;
    int priority;
    int execution_time;
    bool is_complete;
} Task;

// Function prototypes
void create_task(Task *task, int id);
void schedule_tasks(Task *tasks, int num_tasks);
void sort_tasks(Task *tasks, int num_tasks);
int get_next_task(Task *tasks, int num_tasks, int current_time);
void execute_task(Task *task, int current_time);
void print_task(Task *task);

int main() {
    // Initialize tasks array
    Task tasks[MAX_TASKS];

    // Seed random number generator
    srand(time(0));

    // Create tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        create_task(&tasks[i], i+1);
    }

    // Schedule tasks
    schedule_tasks(tasks, MAX_TASKS);

    return 0;
}

// Function to create a new task with given id
void create_task(Task *task, int id) {
    task->id = id;
    task->priority = rand() % MAX_NUM + 1;
    task->execution_time = rand() % MAX_NUM + 1;
    task->is_complete = false;
}

// Function to schedule tasks using priority and completion time
void schedule_tasks(Task *tasks, int num_tasks) {
    int current_time = 0;
    while (true) {
        // Sort tasks by priority and then by execution time
        sort_tasks(tasks, num_tasks);

        // Get next task to execute
        int next_task_index = get_next_task(tasks, num_tasks, current_time);
        if (next_task_index == -1) {
            // No tasks to execute
            printf("All tasks completed!\n");
            break;
        }

        // Execute task
        execute_task(&tasks[next_task_index], current_time);

        // Update current time
        current_time += tasks[next_task_index].execution_time;
    }
}

// Function to sort tasks by priority and then by execution time
void sort_tasks(Task *tasks, int num_tasks) {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].is_complete || tasks[j].is_complete) {
                // Skip completed tasks
                continue;
            }
            if (tasks[i].priority > tasks[j].priority || 
                (tasks[i].priority == tasks[j].priority && tasks[i].execution_time > tasks[j].execution_time)) {
                // Swap tasks
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

// Function to get the index of the next task to execute
int get_next_task(Task *tasks, int num_tasks, int current_time) {
    for (int i = 0; i < num_tasks; i++) {
        if (!tasks[i].is_complete && current_time >= tasks[i].priority) {
            // Task is ready to be executed
            return i;
        }
    }
    // No tasks ready to be executed
    return -1;
}

// Function to execute a task and mark it as complete
void execute_task(Task *task, int current_time) {
    printf("Task %d started at time %d...\n", task->id, current_time);
    task->is_complete = true;
    printf("Task %d completed in %d seconds.\n", task->id, task->execution_time);
}

// Function to print task information
void print_task(Task *task) {
    printf("Task %d (priority: %d, execution time: %d, %scomplete)\n", task->id, task->priority, task->execution_time, task->is_complete ? "" : "in");
}