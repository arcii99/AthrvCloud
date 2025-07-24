//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define a task struct to hold task details */
typedef struct {
    int id;
    int priority;
    int ready_time;
    int execution_time;
} Task;

/* Comparator function for ordering tasks by priority */
int cmp_priority(const void* a, const void* b) {
    Task* ta = (Task*)a;
    Task* tb = (Task*)b;
    return (tb->priority - ta->priority);
}

/* Comparator function for ordering tasks by ready time */
int cmp_ready_time(const void* a, const void* b) {
    Task* ta = (Task*)a;
    Task* tb = (Task*)b;
    return (ta->ready_time - tb->ready_time);
}

/* Function to print a task */
void print_task(Task task) {
    printf("Task ID: %d\nPriority: %d\nReady time: %d\nExecution time: %d\n\n",
           task.id, task.priority, task.ready_time, task.execution_time);
}

int main() {
    /* Define an array of tasks */
    Task tasks[] = {
        {1, 2, 0, 4},
        {2, 3, 2, 6},
        {3, 1, 4, 3},
        {4, 4, 6, 5},
        {5, 5, 7, 2},
    };
    
    /* Calculate the number of tasks */
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);
    
    /* Sort the tasks by ready time */
    qsort(tasks, num_tasks, sizeof(Task), &cmp_ready_time);
    
    /* Keep track of the current time and whether or not a task is currently executing */
    int current_time = 0;
    bool executing = false;
    Task current_task = {0};
    
    /* Loop through time steps */
    while (current_time < 10) {  /* Run for 10 time units */
        /* Check if there is a task ready to execute */
        if (!executing) {
            /* Find the highest priority ready task */
            for (int i = 0; i < num_tasks; i++) {
                if (tasks[i].ready_time <= current_time) {
                    current_task = tasks[i];
                    executing = true;
                    break;
                }
            }
        }
        
        /* If a task is executing, decrement its execution time */
        if (executing) {
            current_task.execution_time--;
            printf("Executing task %d at time %d\n", current_task.id, current_time);
            if (current_task.execution_time == 0) {
                executing = false;
            }
        }
        
        current_time++;
    }
    
    return 0;
}