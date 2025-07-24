//FormAI DATASET v1.0 Category: Task Scheduler ; Style: relaxed
/*
 * This program is a simple task scheduler implementation in C.
 * It accepts a list of tasks and executes them in a particular sequence.
 * Each task has a function pointer that points to a function to be executed.
 * The program demonstrates the use of function pointers and structures in C.
 */

#include <stdio.h>
#include <stdlib.h>

/* Task structure */
typedef struct {
    char *name;
    void (*function)(void);
} Task;

/* Task functions */
void task1(void) {
    printf("Executing Task 1...\n");
}

void task2(void) {
    printf("Executing Task 2...\n");
}

void task3(void) {
    printf("Executing Task 3...\n");
}

void task4(void) {
    printf("Executing Task 4...\n");
}

int main(void) {
    /* Initialize tasks */
    Task tasks[] = {
        {"Task 1", task1},
        {"Task 2", task2},
        {"Task 3", task3},
        {"Task 4", task4},
    };

    /* Get number of tasks */
    int task_count = sizeof(tasks) / sizeof(Task);

    /* Execute the tasks in order */
    for(int i = 0; i < task_count; i++) {
        printf("Executing %s...\n", tasks[i].name);
        tasks[i].function();
        printf("%s has completed.\n\n", tasks[i].name);
    }

    printf("All tasks have been completed!\n");

    return 0;
}