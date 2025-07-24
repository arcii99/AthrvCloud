//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 1000

struct luggage {
    int weight;
    char destination[100];
    bool priority;
};

struct luggage_queue {
    struct luggage items[MAX_CAPACITY];
    int front;
    int rear;
    int size;
};

bool is_full(struct luggage_queue* queue) {
    return (queue->size == MAX_CAPACITY);
}

bool is_empty(struct luggage_queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct luggage_queue* queue, struct luggage item) {
    if (is_full(queue)) {
        printf("Baggage handling system is full! Please try again later.");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_CAPACITY;
    queue->items[queue->rear] = item;
    queue->size++;
}

struct luggage dequeue(struct luggage_queue* queue) {
    if (is_empty(queue)) {
        printf("There are no luggages in the baggage handling system.");
        exit(1);
    }
    struct luggage item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_CAPACITY;
    queue->size--;
    return item;
}

int main() {
    struct luggage_queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;
    struct luggage luggage1, luggage2, luggage3;

    luggage1.weight = 20;
    strcpy(luggage1.destination, "London");
    luggage1.priority = true;
    
    luggage2.weight = 40;
    strcpy(luggage2.destination, "New York");
    luggage2.priority = false;

    luggage3.weight = 15;
    strcpy(luggage3.destination, "Paris");
    luggage3.priority = true;
    
    enqueue(&queue, luggage1);
    enqueue(&queue, luggage2);
    enqueue(&queue, luggage3);

    struct luggage item = dequeue(&queue);
    printf("Dequeued: weight=%d, destination=%s, priority=%d\n", item.weight, item.destination, item.priority);

    return 0;
}