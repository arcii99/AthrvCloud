//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

/* Task struct */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
} Task;

/* Priority queue struct */
typedef struct {
    Task tasks[MAX_TASKS];
    int size;
} PriorityQueue;

/* Function prototypes */
void enqueue(PriorityQueue *queue, Task task);
Task dequeue(PriorityQueue *queue);
void print_queue(PriorityQueue *queue);

int main() {
    PriorityQueue queue = {.size = 0};

    /* Enqueue tasks */
    enqueue(&queue, (Task){"Task 1", 2});
    enqueue(&queue, (Task){"Task 2", 5});
    enqueue(&queue, (Task){"Task 3", 1});
    enqueue(&queue, (Task){"Task 4", 8});
    enqueue(&queue, (Task){"Task 5", 3});
    enqueue(&queue, (Task){"Task 6", 6});

    /* Print queue */
    printf("Task Queue:\n");
    print_queue(&queue);
    printf("\n");

    /* Dequeue tasks */
    printf("Dequeueing tasks:\n");
    while (queue.size > 0) {
        Task task = dequeue(&queue);
        printf("Task: %s Priority: %d\n", task.name, task.priority);
    }

    return 0;
}

/* Enqueue task */
void enqueue(PriorityQueue *queue, Task task) {
    if (queue->size == MAX_TASKS) {
        printf("Queue is full!\n");
        return;
    }

    int i = queue->size;
    while (i > 0 && queue->tasks[i - 1].priority < task.priority) {
        queue->tasks[i] = queue->tasks[i - 1];
        i--;
    }

    queue->tasks[i] = task;
    queue->size++;
}

/* Dequeue task */
Task dequeue(PriorityQueue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return (Task){};
    }

    Task task = queue->tasks[0];
    queue->size--;

    for (int i = 0; i < queue->size; i++) {
        queue->tasks[i] = queue->tasks[i + 1];
    }

    return task;
}

/* Print queue */
void print_queue(PriorityQueue *queue) {
    printf("{ ");
    for (int i = 0; i < queue->size; i++) {
        printf("(%s, %d) ", queue->tasks[i].name, queue->tasks[i].priority);
    }
    printf("}");
}