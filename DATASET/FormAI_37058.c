//FormAI DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Added a new element to the queue: %d\n", data);
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("The queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    printf("Removed element from the queue: %d\n", data);

    return data;
}

void displayQueue(Queue *q) {
    Node *current = q->front;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    displayQueue(q);

    dequeue(q);
    dequeue(q);

    displayQueue(q);

    enqueue(q, 5);
    enqueue(q, 6);

    displayQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    displayQueue(q);

    return 0;
}