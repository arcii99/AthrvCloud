//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initialize_queue(Queue *q) {
    // Set front and rear to -1 to indicate an empty queue
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int is_full(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full\n");
    } else {
        if (is_empty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d\n", q->items[q->front]);
        if (q->front == q->rear) {
            // Queue has only one element, so set front and rear to -1
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n", q->items[i]);
        }
    }
}

int main() {
    Queue q;
    initialize_queue(&q);

    while (1) {
        int choice;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int value;
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}