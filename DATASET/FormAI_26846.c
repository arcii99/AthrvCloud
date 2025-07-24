//FormAI DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

#define MAX_TASKS 100 //maximum number of tasks that can be created

typedef struct {
    int id;
    int priority;
    int deadline; //deadline in seconds
    int (*function_ptr)(void); //pointer to the function that needs to be executed
}task_t;

task_t task_list[MAX_TASKS];
int n_tasks = 0;

void add_task(int id, int priority, int deadline, int (*function_ptr)(void)) {
    if(n_tasks == MAX_TASKS) {
        printf("Error: Task list full. Cannot create more tasks.\n");
        return;
    }
    task_t task = {id, priority, deadline, function_ptr};
    task_list[n_tasks++] = task;
}

int task1() {
    printf("Executing Task 1\n");
    return 0;
}

int task2() {
    printf("Executing Task 2\n");
    return 0;
}

int task3() {
    printf("Executing Task 3\n");
    return 0;
}

int main() {
    add_task(1, 1, 2, task1); //add task with id=1, priority=1, deadline=2 seconds, function_ptr=task1
    add_task(2, 2, 5, task2); //add task with id=2, priority=2, deadline=5 seconds, function_ptr=task2
    add_task(3, 3, 10, task3); //add task with id=3, priority=3, deadline=10 seconds, function_ptr=task3
    
    //schedule tasks. We will execute the tasks in order of priority
    int i;
    for(i=1; i<=3; i++) { //i will represent the current priority level
        int j;
        for(j=0; j<n_tasks; j++) {
            if(task_list[j].priority == i) {
                printf("Executing task %d\n", task_list[j].id);
                int ret_val = task_list[j].function_ptr(); //execute the function associated with the task
                if(ret_val != 0) { //if the function returns an error code, we need to handle it appropriately
                    printf("Error executing task %d. Error code: %d\n", task_list[j].id, ret_val);
                }
            }
        }
    }
    return 0;
}