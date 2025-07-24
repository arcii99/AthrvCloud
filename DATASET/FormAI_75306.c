//FormAI DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_TASKS 10

typedef struct {
    int interval;
    void (*task)();
} Task;

int num_tasks = 0;
Task tasks[MAX_TASKS];

void handle_alarm(int sig) {
    for(int i=0; i<num_tasks; i++) {
        if(tasks[i].interval == 0) {
            tasks[i].task();
            tasks[i].interval = rand() % 10;
        }
        else {
            tasks[i].interval--;
        }
    }
}

void register_task(Task task) {
    if(num_tasks < MAX_TASKS) {
        tasks[num_tasks] = task;
        num_tasks++;
    }
    else {
        printf("Error: Max number of tasks reached\n");
    }
}

void task1() {
    printf("Task 1 has been executed\n");
}

void task2() {
    printf("Task 2 has been executed\n");
}

void task3() {
    printf("Task 3 has been executed\n");
}

void task4() {
    printf("Task 4 has been executed\n");
}

int main(void) {
    srand(time(NULL));
    
    Task t1 = { .interval = 3, .task = &task1 };
    Task t2 = { .interval = 2, .task = &task2 };
    Task t3 = { .interval = 5, .task = &task3 };
    Task t4 = { .interval = 4, .task = &task4 };
    
    register_task(t1);
    register_task(t2);
    register_task(t3);
    register_task(t4);
    
    signal(SIGALRM, handle_alarm);
    alarm(1);
    
    while(1);
    
    return 0;
}