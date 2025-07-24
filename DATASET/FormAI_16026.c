//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE 5    // maximum number of bags that can be in one queue
#define MAX_BAGS 50     // maximum number of bags that can be in the system
#define TERMINALS 5     // number of terminals in the airport
#define PROB_LOST_BAG 25    // percent probability of losing a bag
#define PROB_DAMAGED_BAG 10 // percent probability of damaging a bag

/* Bag struct representing a baggage at the airport */
struct Bag {
    int id;             // unique identifier
    int terminal;       // terminal number
    int baggageClaim;   // baggage claim number
    int weight;         // weight of the baggage
    int lost;           // 1 if lost, 0 otherwise
    int damaged;        // 1 if damaged, 0 otherwise
};

/* Queue struct representing a line of bags at one terminal */
struct Queue {
    struct Bag queue[QUEUE_SIZE];
    int rear;
    int front;
    int count;
};

/* Global variables */
struct Queue checkIn[TERMINALS];     // Check-in queues for each terminal
struct Queue security[TERMINALS];    // Security checkpoint queues for each terminal
struct Queue gate[TERMINALS];        // Boarding gate queues for each terminal
struct Queue baggageClaim[TERMINALS];// Baggage claim queues for each terminal
struct Bag bags[MAX_BAGS];
int numBags = 0;        // total number of bags in the system

/* Function to generate random integers within a range */
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to check whether a bag is lost or damaged based on given probability */
void checkBagStatus(struct Bag* bag, int probLost, int probDamaged) {
    if (randomInt(1, 100) <= probLost) {
        bag->lost = 1;
    }
    if (randomInt(1, 100) <= probDamaged) {
        bag->damaged = 1;
    }
}

/* Function to print the information about a bag */
void printBag(struct Bag bag) {
    printf("Bag ID: %d, Terminal: %d, Baggage Claim: %d, Weight: %d, Lost: %s, Damaged: %s\n", bag.id, bag.terminal, bag.baggageClaim, bag.weight, bag.lost ? "YES" : "NO", bag.damaged ? "YES" : "NO");
}

/* Function to add a bag to a queue */
void enqueue(struct Bag* bag, struct Queue* queue) {
    if (queue->count == QUEUE_SIZE) {
        printf("Queue is full, cannot add bag.\n");
        return;
    }
    queue->queue[queue->rear] = *bag;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->count++;
}

/* Function to remove a bag from a queue */
void dequeue(struct Bag* bag, struct Queue* queue) {
    if (queue->count == 0) {
        printf("Queue is empty, cannot remove bag.\n");
        return;
    }
    *bag = queue->queue[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->count--;
}

/* Function to simulate baggage check-in for one terminal */
void checkInSimulation(int terminal) {
    int numBags = randomInt(1, 10);     // number of bags to be checked in for this terminal
    int i;
    for (i = 1; i <= numBags; i++) {
        struct Bag bag;
        bag.id = ++numBags;
        bag.terminal = terminal;
        bag.baggageClaim = randomInt(1, TERMINALS);
        bag.weight = randomInt(20, 50);
        checkBagStatus(&bag, PROB_LOST_BAG, PROB_DAMAGED_BAG);
        printf("Checking in Bag %d at Terminal %d.\n", bag.id, terminal);
        enqueue(&bag, &checkIn[terminal]);
    }
}

/* Function to simulate security check for one terminal */
void securitySimulation(int terminal) {
    int numBags = randomInt(1, 10);     // number of bags to be checked at security for this terminal
    int i;
    for (i = 1; i <= numBags; i++) {
        struct Bag bag;
        dequeue(&bag, &checkIn[terminal]); // get the next bag from check-in queue
        checkBagStatus(&bag, PROB_LOST_BAG, PROB_DAMAGED_BAG);
        printf("Checking security for Bag %d at Terminal %d.\n", bag.id, terminal);
        enqueue(&bag, &security[terminal]);
    }
}

/* Function to simulate boarding process for one terminal */
void boardingSimulation(int terminal) {
    int numBags = randomInt(1, 10);     // number of bags to be checked at boarding for this terminal
    int i;
    for (i = 1; i <= numBags; i++) {
        struct Bag bag;
        dequeue(&bag, &security[terminal]); // get the next bag from security queue
        checkBagStatus(&bag, PROB_LOST_BAG, PROB_DAMAGED_BAG);
        printf("Sending Bag %d to boarding gate from Terminal %d.\n", bag.id, terminal);
        enqueue(&bag, &gate[terminal]);
    }
}

/* Function to simulate baggage claim for one terminal */
void baggageClaimSimulation(int terminal) {
    int numBags = randomInt(1, 10);     // number of bags to be claimed at baggage claim for this terminal
    int i;
    for (i = 1; i <= numBags; i++) {
        struct Bag bag;
        dequeue(&bag, &baggageClaim[terminal]); // get the next bag from baggage claim queue
        printf("Claiming Bag %d at Baggage Claim %d.\n", bag.id, terminal);
        printBag(bag);
    }
}

/* Function to run the simulation for all terminals */
void runSimulation() {
    int i;
    for (i = 1; i <= 24; i++) { // run the simulation for one day (24 hours)
        printf("Hour %d\n\n", i);
        int j;
        for (j = 1; j <= TERMINALS; j++) {
            checkInSimulation(j);
            securitySimulation(j);
            boardingSimulation(j);
            baggageClaimSimulation(j);
        }
    }
}

/* Main function */
int main() {
    srand(time(NULL));

    runSimulation();

    return 0;
}