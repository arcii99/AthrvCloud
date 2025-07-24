//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void task1(void);
void task2(void);
void task3(void);
void execute_tasks(void);

int main() {
    printf("Welcome to the Brave Task Scheduler!\n\n");
    
    // execute tasks every second
    while (1) {
        execute_tasks();
        sleep(1);
    }
    
    return 0;
}

void task1() {
    // generate a random number between 1 and 100 and print it
    int rand_num = rand() % 100 + 1;
    printf("Task 1: Random number generated: %d\n", rand_num);
}

void task2() {
    // get the current time and print it
    time_t curr_time;
    time(&curr_time);
    printf("Task 2: Current time is %s\n", ctime(&curr_time));
}

void task3() {
    // print a message
    printf("Task 3: Hello, World!\n");
}

void execute_tasks() {
    // generate a random number between 1 and 3 to select a task to execute
    int task_num = rand() % 3 + 1;

    // execute the selected task
    switch (task_num)
    {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
    }
}