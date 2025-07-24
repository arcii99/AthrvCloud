//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

#define MAX_TASKS 50

typedef struct {
    int task_number;
    int priority;
    int start_time;
    int execution_time;
    int end_time;
} Task;

Task tasks[MAX_TASKS];
int no_of_tasks = 0;

int add_task(int task_number, int priority, int start_time, int execution_time) {
    if(no_of_tasks == MAX_TASKS) {
        printf("Cannot add more tasks!\n");
        return -1;
    }
    tasks[no_of_tasks].task_number = task_number;
    tasks[no_of_tasks].priority = priority;
    tasks[no_of_tasks].start_time = start_time;
    tasks[no_of_tasks].execution_time = execution_time;
    tasks[no_of_tasks].end_time = -1;
    no_of_tasks++;
    return 0;
}

void schedule_tasks() {
    int time = 0;
    while(1) {
        int ready_tasks[MAX_TASKS];
        int no_of_ready_tasks = 0;
        for(int i=0; i<no_of_tasks; i++) {
            if(tasks[i].start_time <= time && tasks[i].end_time == -1) {
                ready_tasks[no_of_ready_tasks] = i;
                no_of_ready_tasks++;
            }
        }
        if(no_of_ready_tasks == 0) {
            printf("No tasks to execute!\n");
            return;
        }
        int next_task = 0;
        for(int i=1; i<no_of_ready_tasks; i++) {
            if(tasks[ready_tasks[i]].priority > tasks[ready_tasks[next_task]].priority) {
                next_task = i;
            }
        }
        int task_to_execute = ready_tasks[next_task];
        printf("Executing Task %d...\n", tasks[task_to_execute].task_number);
        for(int i=0; i<tasks[task_to_execute].execution_time; i++) {
            time++;
        }
        tasks[task_to_execute].end_time = time;
        printf("Task %d completed at time %d.\n", tasks[task_to_execute].task_number, time);
    }
}

int main() {
    add_task(1, 10, 0, 5);
    add_task(2, 20, 1, 8);
    add_task(3, 30, 2, 3);
    add_task(4, 40, 3, 6);
    schedule_tasks();
    return 0;
}