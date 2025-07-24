//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of bags that can be processed
#define MAX_BAGS 100

// Define a structure to store the bag information
struct Bag {
    int id;
    int weight;
    int destination;
};

// Define a structure to store the queue of bags
struct BagQueue {
    struct Bag bags[MAX_BAGS];
    int front;
    int rear;
};

// Function to check if the queue is empty
int isQueueEmpty(struct BagQueue *queue) {
    return queue->front == queue->rear;
}

// Function to check if the queue is full
int isQueueFull(struct BagQueue *queue) {
    return (queue->rear + 1) % MAX_BAGS == queue->front;
}

// Function to add a bag to the queue
void addBagToQueue(struct BagQueue *queue, struct Bag bag) {
    if (isQueueFull(queue)) {
        printf("Error: Queue is full!\n");
        exit(1);
    }

    queue->bags[queue->rear] = bag;
    queue->rear = (queue->rear + 1) % MAX_BAGS;
}

// Function to remove a bag from the queue
struct Bag removeBagFromQueue(struct BagQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        exit(1);
    }

    struct Bag bag = queue->bags[queue->front];
    queue->front = (queue->front + 1) % MAX_BAGS;
    return bag;
}

// Function to print the queue
void printQueue(struct BagQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Bags in queue:\n");
    int index = queue->front;
    while (index != queue->rear) {
        struct Bag bag = queue->bags[index];
        printf("Bag %d, weight: %d kg, destination: %d\n", bag.id, bag.weight, bag.destination);
        index = (index + 1) % MAX_BAGS;
    }
}

int main() {
    // Define a queue to hold the bags
    struct BagQueue queue = { .front = 0, .rear = 0 };

    // Generate some sample bags and add them to the queue
    struct Bag bag1 = { .id = 1, .weight = 23, .destination = 2 };
    addBagToQueue(&queue, bag1);

    struct Bag bag2 = { .id = 2, .weight = 31, .destination = 1 };
    addBagToQueue(&queue, bag2);

    struct Bag bag3 = { .id = 3, .weight = 17, .destination = 3 };
    addBagToQueue(&queue, bag3);

    // Print the initial queue
    printQueue(&queue);

    // Simulate the baggage handling process
    while (!isQueueEmpty(&queue)) {
        // Remove a bag from the queue
        struct Bag bag = removeBagFromQueue(&queue);
        printf("Processing bag %d...\n", bag.id);

        // Check the destination of the bag
        if (bag.destination == 1) {
            printf("Bag %d has been sent to the domestic flight.\n", bag.id);
        } else if (bag.destination == 2) {
            printf("Bag %d has been sent to the international flight.\n", bag.id);
        } else if (bag.destination == 3) {
            printf("Bag %d has been sent to the connecting flight.\n", bag.id);
        } else {
            printf("Error: Invalid destination for bag %d!\n", bag.id);
            exit(1);
        }
    }

    // Print the final queue (should be empty)
    printQueue(&queue);

    return 0;
}