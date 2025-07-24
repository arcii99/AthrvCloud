//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    char name[30];
    int priority;
    void (*function_pointer)(void); // function pointer
} Task;

typedef struct TaskQueue {
    Task * tasks;
    int size;
    int capacity;
} TaskQueue;

void task1() {
    printf("Executing Task 1\n");
}

void task2() {
    printf("Executing Task 2\n");
}

void task3() {
    printf("Executing Task 3\n");
}

Task create_task(char name[], int priority, void (*function_pointer)(void)) {
    Task task;
    strcpy(task.name, name);
    task.priority = priority;
    task.function_pointer = function_pointer;
    return task;
}

void init_queue(TaskQueue * task_queue) {
    task_queue->size = 0;
    task_queue->capacity = 5;
    task_queue->tasks = (Task *) malloc(task_queue->capacity * sizeof(Task));
}

void enqueue_task(TaskQueue * task_queue, Task task) {
    if(task_queue->size == task_queue->capacity) {
        task_queue->capacity *= 2;
        task_queue->tasks = (Task *) realloc(task_queue->tasks, task_queue->capacity * sizeof(Task));
    }
    task_queue->tasks[task_queue->size] = task;
    task_queue->size++;
}

Task dequeue_task(TaskQueue * task_queue) {
    if(task_queue->size == 0) {
        Task empty_task = {"", 0, NULL};
        return empty_task;
    }
    int min_priority_index = 0;
    for(int i = 1; i < task_queue->size; i++) {
        if(task_queue->tasks[i].priority < task_queue->tasks[min_priority_index].priority) {
            min_priority_index = i;
        }
    }
    Task min_priority_task = task_queue->tasks[min_priority_index];
    for(int i = min_priority_index+1; i < task_queue->size; i++) {
        task_queue->tasks[i-1] = task_queue->tasks[i];
    }
    task_queue->size--;
    return min_priority_task;
}

int main() {
    srand(time(NULL));
    TaskQueue task_queue;
    init_queue(&task_queue);
    for(int i = 0; i < 10; i++) {
        int random_int = rand() % 10;
        if(random_int < 3) {
            Task task = create_task("Task 1", 1, task1);
            enqueue_task(&task_queue, task);
        }
        else if(random_int < 6) {
            Task task = create_task("Task 2", 2, task2);
            enqueue_task(&task_queue, task);
        }
        else {
            Task task = create_task("Task 3", 3, task3);
            enqueue_task(&task_queue, task);
        }
    }
    while(task_queue.size > 0) {
        Task task_to_execute = dequeue_task(&task_queue);
        task_to_execute.function_pointer();
    }
    return 0;
}