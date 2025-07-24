//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 1000

int task_count = 0;

typedef struct {
    int id;
    int priority;
    int arrival_time;
    int execution_time;
    bool executed;
} Task;

Task tasks[MAX_TASKS];

void add_task(int priority, int arrival_time, int execution_time){
    tasks[task_count].id = task_count;
    tasks[task_count].priority = priority;
    tasks[task_count].arrival_time = arrival_time;
    tasks[task_count].execution_time = execution_time;
    tasks[task_count].executed = false;
    task_count++;
}

int compare_tasks(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;
    if(task_a->priority != task_b->priority){
        return task_b->priority - task_a->priority;
    } else if(task_a->arrival_time != task_b->arrival_time){
        return task_a->arrival_time - task_b->arrival_time;
    } else {
        return task_a->id - task_b->id;
    }
}

void execute_task(Task* task){
    printf("Executing task %d with execution time %d\n", task->id, task->execution_time);
    task->executed = true;
}

int main() {
    add_task(3, 0, 5);
    add_task(5, 2, 2);
    add_task(1, 1, 4);
    add_task(2, 0, 3);
    add_task(4, 3, 1);
    add_task(6, 6, 4);
    add_task(0, 4, 3);
    
    qsort(tasks, task_count, sizeof(Task), compare_tasks);
    
    int current_time = 0;
    int next_task_index = 0;
    while(next_task_index < task_count){
        bool found_task_to_execute = false;
        for(int i = next_task_index; i < task_count; i++){
            if(tasks[i].arrival_time <= current_time && !tasks[i].executed){
                execute_task(&tasks[i]);
                current_time += tasks[i].execution_time;
                found_task_to_execute = true;
                next_task_index++;
                break;
            }
        }
        if(!found_task_to_execute){
            current_time++;
        }
    }
    
    return 0;
}