//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_DURATION 10
#define MAX_TASK_PRIORITY 5
#define MAX_TIME_SLICE 2

struct task {
    int id;
    int priority;
    int duration;
    int remaining_time;
};

struct task_queue {
    struct task *tasks[MAX_TASKS];
    int front, end;
};

void init_queue(struct task_queue *q) {
    for (int i = 0; i < MAX_TASKS; i++)
        q->tasks[i] = NULL;
    q->front = 0;
    q->end = -1;
}

void enqueue(struct task_queue *q, struct task *t) {
    if (q->end == MAX_TASKS - 1) {
        fprintf(stderr, "Error: Task queue is full!\n");
        exit(EXIT_FAILURE);
    }
    q->end++;
    q->tasks[q->end] = t;
}

struct task* dequeue(struct task_queue *q) {
    if (q->end < q->front) {
        fprintf(stderr, "Error: Task queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    struct task *t = q->tasks[q->front];
    q->tasks[q->front] = NULL;
    q->front++;

    return t;
}

int is_queue_empty(struct task_queue *q) {
    return (q->end < q->front);
}

void print_task(struct task *t) {
    printf("Task ID: %d, Priority: %d, Duration: %d, Remaining Time: %d\n",
            t->id, t->priority, t->duration, t->remaining_time);
}

void randomly_assign_tasks(struct task_queue *q) {
    srand(time(NULL));
    for (int i = 0; i < MAX_TASKS; i++) {
        struct task *t = malloc(sizeof(struct task));
        t->id = i;
        t->priority = rand() % MAX_TASK_PRIORITY + 1;
        t->duration = rand() % MAX_TASK_DURATION + 1;
        t->remaining_time = t->duration;
        enqueue(q, t);
    }
}

void run_scheduler(struct task_queue *q) {
    int current_time = 0;

    while (!is_queue_empty(q)) {
        struct task *t = dequeue(q);
        t->remaining_time -= MAX_TIME_SLICE;
        current_time += MAX_TIME_SLICE;
        printf("Time: %d, Running ", current_time);
        print_task(t);

        if (t->remaining_time > 0) {
            enqueue(q, t);
        } else {
            free(t);
        }
    }
}

int main() {
    struct task_queue q;
    init_queue(&q);
    randomly_assign_tasks(&q);

    run_scheduler(&q);

    return 0;
}