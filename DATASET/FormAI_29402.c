//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_SIZE_TASK_NAME 20
#define MAX_QUEUE_SIZE 10

// Struct for holding task information
typedef struct {
    char name[MAX_SIZE_TASK_NAME];
    int priority;
    void (*function)(void);
} Task;

// Struct for holding queue information
typedef struct {
    Task queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Global Variables
int time_elaps = 0; // variable to hold time elapsed
Queue task_q; // queue to hold tasks

// Function to initialize the queue with default values
void queue_init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to add a task to the queue
int enqueue(Queue *q, Task t) {
    // Check if queue is full
    if (q->size == MAX_QUEUE_SIZE) {
        return -1;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    strncpy(q->queue[q->rear].name, t.name, MAX_SIZE_TASK_NAME);
    q->queue[q->rear].priority = t.priority;
    q->queue[q->rear].function = t.function;
    q->size++;
    return 0;
}

// Function to remove task from the queue
Task dequeue(Queue *q) {
    // Check if queue is empty
    if (q->size == 0) {
        Task empty_task = {"EMPTY", 0, NULL};
        return empty_task;
    }
    Task t = q->queue[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return t;
}

// Function to print tasks in the queue
void print_queue(Queue *q) {
    printf("Queue Contents:\n");
    if (q->size == 0) {
        printf("Empty\n");
    }
    else {
        for (int i = 0; i < q->size; i++) {
            printf("%s (Priority %d)\n", q->queue[(q->front + i) % MAX_QUEUE_SIZE].name, q->queue[(q->front + i) % MAX_QUEUE_SIZE].priority);
        }
    }
    printf("\n");
}

// Function for task 1
void task1(void) {
    printf("Task 1 completed at time %d\n", time_elaps);
}

// Function for task 2
void task2(void) {
    printf("Task 2 completed at time %d\n", time_elaps);
}

// Function for task 3
void task3(void) {
    printf("Task 3 completed at time %d\n", time_elaps);
}

// Function to create and add tasks to the queue
void create_tasks(void) {
    Task t1 = {"Task 1", 3, task1};
    Task t2 = {"Task 2", 1, task2};
    Task t3 = {"Task 3", 2, task3};
    enqueue(&task_q, t1);
    enqueue(&task_q, t2);
    enqueue(&task_q, t3);
}

// Function to execute and remove tasks from the queue
void execute_tasks(void) {
    Task curr_task = dequeue(&task_q);
    curr_task.function();
    time_elaps++;
}

// Main function
int main(void) {
    queue_init(&task_q);
    create_tasks();
    print_queue(&task_q);

    // Loop for executing tasks
    while (task_q.size > 0) {
        execute_tasks();
        print_queue(&task_q);
        usleep(1000000); // sleep for 1 second
    }
    return EXIT_SUCCESS;
}