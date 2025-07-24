//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// define constants for buffer size and number of bags
#define BUFFER_SIZE 100
#define NUM_BAGS 10

// struct to represent a bag with an ID and weight
typedef struct {
    int id;
    float weight;
} Bag;

int main() {
    // initialize buffer array and index variables
    Bag buffer[BUFFER_SIZE];
    int front = 0, rear = 0;

    // generate random bags with IDs and weights
    Bag bags[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].weight = ((float) rand() / RAND_MAX) * 50.0;
    }

    // print out initial bags and weights
    printf("Initial bags and weights:\n");
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("Bag %d: %.2f kg\n", bags[i].id, bags[i].weight);
    }

    // simulate baggage handling by pushing and popping bags from buffer
    for (int i = 0; i < NUM_BAGS; i++) {
        // check if buffer is full
        if ((rear + 1) % BUFFER_SIZE == front) {
            printf("Error: Buffer is full.\n");
            exit(1);
        }

        // push bag onto buffer
        buffer[rear] = bags[i];
        rear = (rear + 1) % BUFFER_SIZE;

        // sleep for a random amount of time to simulate baggage handling time
        int sleep_time = rand() % 3;
        printf("Transferring bag %d to conveyor belt (%d second(s))...\n", bags[i].id, sleep_time);
        sleep(sleep_time);

        // pop bag from buffer
        Bag popped_bag = buffer[front];
        front = (front + 1) % BUFFER_SIZE;

        // print out popped bag ID and weight
        printf("Bag %d with weight %.2f kg has been transferred to the airplane.\n", popped_bag.id, popped_bag.weight);
    }

    return 0;
}