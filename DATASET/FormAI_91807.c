//FormAI DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to hold the Queue
struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initializes the queue
struct queue* init_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Checks if the queue is full
int is_full(struct queue* q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Checks if the queue is empty
int is_empty(struct queue* q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Adds an item to the queue
void enqueue(struct queue* q, int val) {
    if (is_full(q)) {
        printf("Queue is full");
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
        printf("Enqueued item: %d\n", val);
    }
}

// Removes an item from the queue
int dequeue(struct queue* q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("Dequeued item: %d\n", item);
    }
    return item;
}

// Displays the items in the queue
void display(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty");
    }
    else {
        printf("Queue contains the following items:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
}
int main() {
    struct queue* my_queue = init_queue();

    enqueue(my_queue, 10);
    enqueue(my_queue, 20);
    enqueue(my_queue, 30);
    enqueue(my_queue, 40);
    enqueue(my_queue, 50);

    display(my_queue);

    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);

    display(my_queue);

    return 0;
}