//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>

int queue1[1000000], queue2[1000000], front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue(int x) {
    rear1++;
    queue1[rear1] = x;
}

void dequeue() {
    while (front1 != rear1) {
        front2++;
        queue2[front2] = queue1[front1];
        front1++;
    }
    printf("Dequeued element: %d\n", queue1[front1]);
    front1++;
    while (front2 != rear2) {
        rear1++;
        queue1[rear1] = queue2[front2];
        front2++;
    }
    rear2 = -1;
    front2 = -1;
}

int main() {
    for (int i = 1; i <= 50000; i++) {
        enqueue(i);
    }

    printf("Queue Enqueue operation for 50000 values benchmark completed successfully!\n");

    for (int i = 1; i <= 50000; i++) {
        dequeue();
    }

    printf("Queue Dequeue operation for 50000 values benchmark completed successfully!\n");

    return 0;
}