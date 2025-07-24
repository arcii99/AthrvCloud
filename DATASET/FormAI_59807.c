//FormAI DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#define MAX_QUEUE_SIZE 10

// Queue struct with head and tail index
typedef struct {
    int head;
    int tail;
    int queue_array[MAX_QUEUE_SIZE];
} Queue;

// Function to add element to queue
void enqueue(Queue* q, int value) {
    if((q->tail + 1) % MAX_QUEUE_SIZE == q->head) {
        printf("Queue is full!\n");
    }else {
        q->queue_array[q->tail] = value;
        q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
        printf("%d added to queue\n", value);
    }
}

// Function to remove element from queue
int dequeue(Queue* q) {
    int removed_value;
    if(q->head == q->tail) {
        printf("Queue is empty!\n");
        return -1;
    }else {
        removed_value = q->queue_array[q->head];
        q->head = (q->head + 1) % MAX_QUEUE_SIZE;
        return removed_value;
    }
}

int main() {
    Queue q = {0, 0, {}};
    printf("Queue implementation in C\n");

    // Add elements to queue
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 9);
    enqueue(&q, 11);
    enqueue(&q, 13);
    enqueue(&q, 15);
    enqueue(&q, 17);

    // Remove elements from queue
    printf("%d removed from queue\n", dequeue(&q));
    printf("%d removed from queue\n", dequeue(&q));

    // Add element to queue after removing elements
    enqueue(&q, 19);

    // Remove remaining elements from queue
    printf("%d removed from queue\n", dequeue(&q));
    printf("%d removed from queue\n", dequeue(&q));
    printf("%d removed from queue\n", dequeue(&q));
    printf("%d removed from queue\n", dequeue(&q));

    // Try removing element from empty queue
    printf("%d removed from queue\n", dequeue(&q));
    return 0;
}