//FormAI DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void task1() {
    printf("This is task 1\n");
}

void task2() {
    printf("This is task 2\n");
}

void task3() {
    printf("This is task 3\n");
}

int main() {
    // Initialize an array of function pointers
    void (*tasks[3])() = {task1, task2, task3};
    
    // Set the initial value of the task number and the number of tasks
    int task_num = 0;
    int num_tasks = 3;
    
    // Loop through the array of function pointers and call each function
    while (1) {
        if (task_num >= num_tasks) {
            task_num = 0;
        }
        tasks[task_num]();
        task_num++;
    }
    
    return 0;
}