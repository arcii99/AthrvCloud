//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TIME 60

struct task {
    int id;
    int time;
};

struct task_queue {
    int front;
    int rear;
    struct task tasks[MAX_TASKS];
};

void initialize_queue(struct task_queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_queue_empty(struct task_queue *q) {
    return q->front > q->rear;
}

int is_queue_full(struct task_queue *q) {
    return q->rear == MAX_TASKS - 1;
}

void enqueue(struct task_queue *q, struct task t) {
    if (!is_queue_full(q)) {
        q->rear++;
        q->tasks[q->rear] = t;
    }
}

struct task dequeue(struct task_queue *q) {
    struct task t = q->tasks[q->front];
    q->front++;
    return t;
}

void print_queue(struct task_queue *q) {
    while (!is_queue_empty(q)) {
        struct task t = dequeue(q);
        printf("Task %d - time: %d\n", t.id, t.time);
    }
}

int main() {
    srand(time(NULL));
    struct task_queue q;
    initialize_queue(&q);

    for (int i = 0; i < MAX_TASKS; i++) {
        struct task t;
        t.id = i + 1;
        t.time = rand() % MAX_TIME + 1;
        enqueue(&q, t);
    }

    printf("Task queue:\n");
    print_queue(&q);

    return 0;
}