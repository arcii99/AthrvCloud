//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_QUEUE_SIZE 100

typedef struct {
    int priority;
    void (*function)(void);
} task;

task task_queue[MAX_QUEUE_SIZE];
int queue_size = 0;

void add_task(int priority, void (*task_function)(void)) {
    // add a new task to the queue
    if (queue_size >= MAX_QUEUE_SIZE) {
        printf("Error: Task queue is full\n");
        exit(1);
    }
    
    task new_task;
    new_task.priority = priority;
    new_task.function = task_function;
    
    task_queue[queue_size++] = new_task;
}

void run_next_task() {
    // remove and run the highest priority task
    if (queue_size == 0) {
        printf("No tasks in queue\n");
        exit(1);
    }
    
    int max_index = 0;
    for (int i = 1; i < queue_size; i++) {
        if (task_queue[i].priority > task_queue[max_index].priority) {
            max_index = i;
        }
    }
    
    task next_task = task_queue[max_index];
    for (int i = max_index; i < queue_size - 1; i++) {
        task_queue[i] = task_queue[i + 1];
    }
    queue_size--;
    
    (*next_task.function)();
}

void dummy_task_1() {
    printf("Running task 1\n");
}

void dummy_task_2() {
    printf("Running task 2\n");
}

void dummy_task_3() {
    printf("Running task 3\n");
}

int main() {
    add_task(2, dummy_task_1);
    add_task(1, dummy_task_2);
    add_task(3, dummy_task_3);
    
    run_next_task();
    run_next_task();
    run_next_task();
    
    return 0;
}