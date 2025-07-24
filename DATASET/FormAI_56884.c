//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE 100
#define NUM_TASKS 10
#define MAX_DELAY 5

typedef struct {
    int id;
    int delay; // seconds
    void (*func)();
} task_t;

int queue_front = 0;
int queue_rear = 0;
task_t task_queue[QUEUE_SIZE];

void enqueue_task(int id, int delay, void (*func)()) {
    if ((queue_rear + 1) % QUEUE_SIZE == queue_front) {
        printf("Error: task queue is full!\n");
        return;
    }
    task_queue[queue_rear].id = id;
    task_queue[queue_rear].delay = delay;
    task_queue[queue_rear].func = func;
    queue_rear = (queue_rear + 1) % QUEUE_SIZE;
}

task_t dequeue_task() {
    if (queue_front == queue_rear) {
        printf("Error: task queue is empty!\n");
        exit(1);
    }
    task_t task = task_queue[queue_front];
    queue_front = (queue_front + 1) % QUEUE_SIZE;
    return task;
}

void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

void task3() {
    printf("Task 3 running...\n");
}

void task4() {
    printf("Task 4 running...\n");
}

void task5() {
    printf("Task 5 running...\n");
}

void task6() {
    printf("Task 6 running...\n");
}

void task7() {
    printf("Task 7 running...\n");
}

void task8() {
    printf("Task 8 running...\n");
}

void task9() {
    printf("Task 9 running...\n");
}

void task10() {
    printf("Task 10 running...\n");
}

int main() {
    srand(time(NULL));
    printf("Task Scheduler Demo\n");

    // Add tasks to the queue with random delays
    for (int i = 0; i < NUM_TASKS; i++) {
        int delay = rand() % MAX_DELAY + 1;
        switch (i % NUM_TASKS) {
            case 0:
                enqueue_task(i+1, delay, task1);
                break;
            case 1:
                enqueue_task(i+1, delay, task2);
                break;
            case 2:
                enqueue_task(i+1, delay, task3);
                break;
            case 3:
                enqueue_task(i+1, delay, task4);
                break;
            case 4:
                enqueue_task(i+1, delay, task5);
                break;
            case 5:
                enqueue_task(i+1, delay, task6);
                break;
            case 6:
                enqueue_task(i+1, delay, task7);
                break;
            case 7:
                enqueue_task(i+1, delay, task8);
                break;
            case 8:
                enqueue_task(i+1, delay, task9);
                break;
            case 9:
                enqueue_task(i+1, delay, task10);
                break;
            default:
                break;
        }
        printf("Task %d added with delay of %d seconds\n", i+1, delay);
    }

    // Run the tasks in the queue
    while (queue_front != queue_rear) {
        task_t task = dequeue_task();
        printf("Running task %d in %d seconds...\n", task.id, task.delay);
        sleep(task.delay);
        task.func();
    }

    printf("All tasks complete!\n");
    return 0;
}