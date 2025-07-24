//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 500 // maximum number of bags allowed
#define MAX_TIME 100 // maximum time for simulation in seconds

// Define constants representing the state of the bag in the system
#define IN_TRANSIT  0
#define IN_QUEUE    1
#define IN_PROCESS  2
#define COMPLETE    3

// Define struct representing a bag in the simulation
typedef struct Bag {
    int id;             // unique identifier of the bag
    int state;          // current state of the bag
    int startTime;      // time when the bag enters the system
    int queueTime;      // time when the bag enters the queue
    int processingTime; // time required to process the bag
    int completeTime;   // time when the processing of the bag is complete
} Bag;

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to simulate the baggage handling system
void simulate() {

    // Declare variables
    int currentTime = 0;
    int numBags = 0;
    Bag bags[MAX_BAGS];

    // Seed the random number generator
    srand(time(NULL));

    // Run the simulation for MAX_TIME seconds
    while (currentTime < MAX_TIME) {

        // Generate new bags
        if (randomInt(0, 100) < 30 && numBags < MAX_BAGS) {
            Bag b;
            b.id = numBags;
            b.state = IN_TRANSIT;
            b.startTime = currentTime;
            b.queueTime = -1;
            b.processingTime = randomInt(2, 5);
            b.completeTime = -1;
            bags[numBags] = b;
            numBags++;
        }

        // Process bags in the queue
        for (int i = 0; i < numBags; i++) {
            if (bags[i].state == IN_QUEUE && currentTime >= bags[i].queueTime + bags[i].processingTime) {
                bags[i].state = COMPLETE;
                bags[i].completeTime = currentTime;
            }
        }

        // Move bags from transit to queue
        for (int i = 0; i < numBags; i++) {
            if (bags[i].state == IN_TRANSIT && randomInt(0, 100) < 70) {
                bags[i].state = IN_QUEUE;
                bags[i].queueTime = currentTime;
            }
        }

        // Print state of bags at current time
        printf("Current Time: %d\n", currentTime);
        printf("  ID  State    Start Queue Process Complete\n");
        for (int i = 0; i < numBags; i++) {
            printf("%4d  %4d  %6d %5d %7d %7d\n", bags[i].id, bags[i].state, bags[i].startTime, bags[i].queueTime, bags[i].processingTime, bags[i].completeTime);
        }
        printf("\n");

        // Increment time
        currentTime++;
    }
}

// Main function to run the simulation
int main() {
    simulate();
    return 0;
}