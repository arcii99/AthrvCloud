//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include<stdio.h>
#include<stdlib.h>

/*
 * This program is a prime example of a queue implemented in C,
 * or as I like to call it, a Queue'amole! Get it? Because the queue
 * is full of items and a guacamole consists of many different
 * ingredients! 
 * 
 * Anyway, let's get into some code.
 */

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} QueueAmole;

QueueAmole* createQueue() {
    QueueAmole* queue = (QueueAmole*) malloc(sizeof(QueueAmole));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(QueueAmole* queue) {
    if ((queue->front == 0 && queue->rear == MAX_QUEUE_SIZE - 1) || queue->front == queue->rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty(QueueAmole* queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(QueueAmole* queue, int item) {
    if (isFull(queue)) {
        printf("\nUh oh! Queue'amole is full! No more ingredients can be added.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->rear] = item;
        printf("\n%s added to Queue'amole successfully!\n", item);
    }
}

int dequeue(QueueAmole* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nUh oh! Queue'amole is empty! No more ingredients can be removed.\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        }
        printf("\n%s removed from Queue'amole successfully!\n", item);
    }
    return item;
}

int main() {
    QueueAmole* queue = createQueue();

    /*
     * Let's add some ingredients to our Queue'amole!
     * Don't judge me on my taste buds, okay?
     */
    enqueue(queue, "Avocado");
    enqueue(queue, "Onion");
    enqueue(queue, "Lime");
    enqueue(queue, "Cilantro");
    enqueue(queue, "Tomato");
    enqueue(queue, "Salt");
    enqueue(queue, "Pepper");
    enqueue(queue, "Jalapeño");
    enqueue(queue, "Garlic");
    enqueue(queue, "Coriander");

    /*
     * Oops, we added too many ingredients! Time to remove some.
     */
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    /*
     * Let's add one more ingredient, because we can never have
     * too much guacamole, am I right?
     */
    enqueue(queue, "Red Pepper");

    free(queue);

    return 0;
}