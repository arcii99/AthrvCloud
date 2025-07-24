//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

void initializeQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(queue *q) {
    if (q->front == 0 && q->rear == MAX_SIZE-1) {
        return 1;
    }
    if (q->rear == q->front-1) {
        return 1;
    }
    return 0;
}

int isEmpty(queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enQueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear+1) % MAX_SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d successfully\n", value);
    }
}

int deQueue(queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front+1) % MAX_SIZE;
        }
    }
    return item;
}

void display(queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements:");
        for (i=q->front; i!=q->rear; i=(i+1)%MAX_SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d\n", q->items[i]);
    }
}

int main() {
    queue q;
    initializeQueue(&q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);

    display(&q);

    printf("Deleted Element: %d\n", deQueue(&q));
    printf("Deleted Element: %d\n", deQueue(&q));

    display(&q);

    enQueue(&q, 5);
    enQueue(&q, 6);

    display(&q);

    if (isFull(&q)) {
        printf("Queue is Full\n");
    } else {
        printf("Queue is not Full\n");
    }

    return 0;
}