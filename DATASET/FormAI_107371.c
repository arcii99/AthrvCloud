//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

struct task {
    int id;
    int priority;
    int executed;
};

struct task_queue {
    int count;
    struct task tasks[MAX_TASKS];
};

void enqueue(struct task_queue *q, struct task t) {
    if (q->count < MAX_TASKS) {
        q->tasks[q->count++] = t;
    } else {
        printf("Task queue is full!\n");
    }
}

struct task dequeue(struct task_queue *q) {
    if (q->count > 0) {
        int min_priority_index = 0;
        for (int i = 1; i < q->count; i++) {
            if (q->tasks[i].priority < q->tasks[min_priority_index].priority) {
                min_priority_index = i;
            }
        }
        struct task t = q->tasks[min_priority_index];
        for (int i = min_priority_index; i < q->count - 1; i++) {
            q->tasks[i] = q->tasks[i+1];
        }
        q->count--;
        return t;
    } else {
        printf("Task queue is empty!\n");
        struct task t = { 0, 0, 0 };
        return t;
    }
}

int main() {
    srand(time(0));
    struct task_queue q = { 0 };
    for (int i = 1; i <= MAX_TASKS; i++) {
        struct task t = { i, rand() % MAX_PRIORITY + 1, 0 };
        enqueue(&q, t);
    }
    while (q.count > 0) {
        struct task t = dequeue(&q);
        printf("Executing task %d with priority %d...\n", t.id, t.priority);
        t.executed = 1;
    }

    return 0;
}