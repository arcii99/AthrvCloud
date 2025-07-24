//FormAI DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 50 // maximum number of tasks in the scheduler
#define MAX_NAME_LENGTH 20 // maximum length of task name

/* 
 * Task data structure 
*/
typedef struct {
    char name[MAX_NAME_LENGTH]; // name of task
    int priority; // priority of task (1-10)
    int duration; // duration in seconds
} Task;

/* 
 * Scheduler data structure 
*/
typedef struct {
    Task tasks[MAX_TASKS]; // array of tasks
    int numTasks; // number of tasks in the scheduler
} Scheduler;

/* Function prototypes */
void addTask(Scheduler *scheduler, Task task);
void removeTask(Scheduler *scheduler, int taskIndex);
void printTasks(Scheduler *scheduler);
void runScheduler(Scheduler *scheduler);

/* 
 * Main function 
*/
int main() {
    // create a new scheduler
    Scheduler scheduler = { .numTasks = 0 };

    // create some sample tasks
    Task task1 = { .name = "Task 1", .priority = 5, .duration = 10 };
    Task task2 = { .name = "Task 2", .priority = 8, .duration = 5 };
    Task task3 = { .name = "Task 3", .priority = 3, .duration = 15 };

    // add tasks to the scheduler
    addTask(&scheduler, task1);
    addTask(&scheduler, task2);
    addTask(&scheduler, task3);

    // print out the initial list of tasks
    printf("Initial list of tasks:\n");
    printTasks(&scheduler);

    // remove a task from the scheduler
    removeTask(&scheduler, 1);
    printf("Task 2 has been removed.\n");

    // print out the final list of tasks
    printf("\nFinal list of tasks:\n");
    printTasks(&scheduler);

    // run the scheduler
    runScheduler(&scheduler);

    return 0;
}

/* 
 * Adds a task to the scheduler 
*/
void addTask(Scheduler *scheduler, Task task) {
    // make sure there is room for the new task
    if (scheduler->numTasks < MAX_TASKS) {
        // add the task to the array
        scheduler->tasks[scheduler->numTasks] = task;
        scheduler->numTasks++;
    } else {
        printf("Scheduler is full, cannot add task.\n");
    }
}

/* 
 * Removes a task from the scheduler 
*/
void removeTask(Scheduler *scheduler, int taskIndex) {
    // shift all tasks after the removed one down by one
    for (int i = taskIndex; i < scheduler->numTasks - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }

    // decrement the number of tasks in the scheduler
    scheduler->numTasks--;
}

/* 
 * Prints out the tasks in the scheduler 
*/
void printTasks(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->numTasks; i++) {
        printf("%d. %s - Priority: %d, Duration: %d seconds\n", i+1, scheduler->tasks[i].name, scheduler->tasks[i].priority, 
        scheduler->tasks[i].duration);
    }
}

/* 
 * Runs the scheduler 
*/
void runScheduler(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->numTasks; i++) {
        // wait for the duration of the task
        printf("Running task %s for %d seconds...\n", scheduler->tasks[i].name, scheduler->tasks[i].duration);
        sleep(scheduler->tasks[i].duration);
    }
}