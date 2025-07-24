//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Define constants
#define NUM_FLIGHTS 50
#define MAX_BAGS 3
 
// Define struct for baggage
typedef struct {
    int flightNum;
    int bagNum;
} Baggage;
 
// Define struct for baggage queue
typedef struct {
    Baggage* data;
    int size;
    int capacity;
    int front;
    int rear;
} BaggageQueue;
 
// Function prototypes
void enqueue(BaggageQueue*, Baggage);
Baggage dequeue(BaggageQueue*);
int isFull(BaggageQueue*);
int isEmpty(BaggageQueue*);
int randRange(int, int);
 
int main() {
    // Seed random number generator
    srand(time(NULL));
 
    // Create baggage queues for each flight
    BaggageQueue queues[NUM_FLIGHTS];
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        queues[i].data = (Baggage*)malloc(MAX_BAGS * sizeof(Baggage));
        queues[i].size = 0;
        queues[i].capacity = MAX_BAGS;
        queues[i].front = -1;
        queues[i].rear = -1;
    }
 
    // Simulate arrival of bags to airport
    printf("Simulating arrival of bags to airport:\n");
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        int numBags = randRange(1, MAX_BAGS);
        printf("Flight %d has %d bags.\n", i + 1, numBags);
        for (int j = 0; j < numBags; j++) {
            Baggage bag = {i + 1, j + 1};
            enqueue(&queues[i], bag);
        }
    }
 
    // Simulate retrieval of bags from airport
    printf("\nSimulating retrieval of bags from airport:\n");
    while (1) {
        // Randomly select a flight
        int flightNum = randRange(1, NUM_FLIGHTS);
        Baggage bag = dequeue(&queues[flightNum - 1]);
        if (bag.flightNum == 0 && bag.bagNum == 0) {
            // Queue is empty, end simulation
            break;
        }
        printf("Retrieved bag %d from flight %d.\n", bag.bagNum, bag.flightNum);
    }
 
    // Free memory
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        free(queues[i].data);
    }
 
    return 0;
}
 
// Function to add a baggage to the queue
void enqueue(BaggageQueue* queue, Baggage bag) {
    if (isFull(queue)) {
        printf("Queue is full, cannot add baggage.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = bag;
    queue->size++;
}
 
// Function to remove a baggage from the queue
Baggage dequeue(BaggageQueue* queue) {
    Baggage emptyBag = {0, 0};
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot remove baggage.\n");
        return emptyBag;
    }
    Baggage bag = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    queue->size--;
    return bag;
}
 
// Function to check if queue is full
int isFull(BaggageQueue* queue) {
    return queue->size == queue->capacity;
}
 
// Function to check if queue is empty
int isEmpty(BaggageQueue* queue) {
    return queue->size == 0;
}
 
// Function to generate random number within a range
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}