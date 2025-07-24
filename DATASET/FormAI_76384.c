//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10    // maximum number of tasks
#define MAX_DELAY 5     // maximum delay time in seconds

struct Task {
    int id;
    int delay;
    void (*function)(void);
};

typedef struct Task Task;

Task tasks[MAX_TASKS];  // array of tasks

// function prototypes
void task_1(void);
void task_2(void);
void task_3(void);
void task_4(void);
void task_5(void);
void task_6(void);
void task_7(void);
void task_8(void);
void task_9(void);
void task_10(void);
void add_task(int id, int delay, void (*function)(void));
void run_task(Task task);

int main() {
    srand(time(NULL));  // seed the random number generator
    
    // add tasks
    add_task(1, rand() % MAX_DELAY, task_1);
    add_task(2, rand() % MAX_DELAY, task_2);
    add_task(3, rand() % MAX_DELAY, task_3);
    add_task(4, rand() % MAX_DELAY, task_4);
    add_task(5, rand() % MAX_DELAY, task_5);
    add_task(6, rand() % MAX_DELAY, task_6);
    add_task(7, rand() % MAX_DELAY, task_7);
    add_task(8, rand() % MAX_DELAY, task_8);
    add_task(9, rand() % MAX_DELAY, task_9);
    add_task(10, rand() % MAX_DELAY, task_10);
    
    // run tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        run_task(tasks[i]);
    }
    
    return 0;
}

// task functions
void task_1() {
    printf("Task 1\n");
}

void task_2() {
    printf("Task 2\n");
}

void task_3() {
    printf("Task 3\n");
}

void task_4() {
    printf("Task 4\n");
}

void task_5() {
    printf("Task 5\n");
}

void task_6() {
    printf("Task 6\n");
}

void task_7() {
    printf("Task 7\n");
}

void task_8() {
    printf("Task 8\n");
}

void task_9() {
    printf("Task 9\n");
}

void task_10() {
    printf("Task 10\n");
}

// add a task to the array of tasks
void add_task(int id, int delay, void (*function)(void)) {
    Task task;
    task.id = id;
    task.delay = delay;
    task.function = function;
    tasks[id - 1] = task;   // task IDs start from 1, so subtract 1 to get the correct array index
}

// run a task
void run_task(Task task) {
    sleep(task.delay);  // sleep for the specified delay time
    task.function();    // execute the task function
}