//FormAI DATASET v1.0 Category: Queue ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // maximum size of our queue

typedef struct {
    int front; // front index in array
    int rear; // rear index in array
    int size; // current number of elements in queue
    int queue_array[MAX_QUEUE_SIZE]; // array for queue elements
} Queue;

// function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// function to check if the queue is empty
int isEmpty(Queue *queue){
    return queue->size == 0;
}

// function to check if the queue is full
int isFull(Queue *queue){
    return queue->size == MAX_QUEUE_SIZE;
}

// function to add an element to the queue
void enqueue(Queue *queue, int data){
    if(isFull(queue)){
        printf("Queue is full.\n");
        return;
    }

    if(queue->front == -1) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->queue_array[queue->rear] = data;
    queue->size++;
}

// function to remove an element from the queue
int dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
        return -1;
    }

    int data = queue->queue_array[queue->front];
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else{
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    queue->size--;
    
    return data;
}

// main function to test our queue
int main() {
    Queue queue;
    initializeQueue(&queue);

    // Add some elements to the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    enqueue(&queue, 80);

    // Try to add one more element to the queue, which will return an error message
    enqueue(&queue, 90);
    
    // Remove some elements from the queue
    printf("Removed element: %d\n", dequeue(&queue));
    printf("Removed element: %d\n", dequeue(&queue));
    printf("Removed element: %d\n", dequeue(&queue));

    // Add some more elements to the queue
    enqueue(&queue, 90);
    enqueue(&queue, 100);

    // Remove the remaining elements from the queue
    while(!isEmpty(&queue)) {
        printf("Removed element: %d\n", dequeue(&queue));
    }

    return 0;
}