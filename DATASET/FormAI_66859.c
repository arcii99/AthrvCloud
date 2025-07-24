//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TOTAL_BAGS 100 // Total number of bags to simulate
#define MAX_WEIGHT 50 // Maximum weight of luggage in kg
#define MAX_DELAY 10 // Maximum delay time in seconds

typedef struct {
    int id;
    int weight;
    bool isCarried;
} Bag;

void addBag(Bag bags[], int id, int weight) {
    for (int i = 0; i < TOTAL_BAGS; i++) {
        if (!bags[i].isCarried) {
            bags[i].id = id;
            bags[i].weight = weight;
            bags[i].isCarried = true;
            break;
        }
    }
}

void removeBag(Bag bags[], int id) {
    for (int i = 0; i < TOTAL_BAGS; i++) {
        if (bags[i].id == id) {
            bags[i].id = 0;
            bags[i].weight = 0;
            bags[i].isCarried = false;
            break;
        }
    }
}

void printStatus(Bag bags[], int totalWeight) {
    int carriedBags = 0;
    double averageWeight = 0.0;

    for (int i = 0; i < TOTAL_BAGS; i++) {
        if (bags[i].isCarried) {
            carriedBags++;
            averageWeight += (double)bags[i].weight;
        }
    }
    if (carriedBags == 0) {
        averageWeight = 0;
    } else {
        averageWeight /= carriedBags;
    }
    printf("Total weight: %d kg\n", totalWeight);
    printf("Number of carried bags: %d\n", carriedBags);
    printf("Average weight of carried bags: %.2f kg\n", averageWeight);
}

int main() {
    Bag bags[TOTAL_BAGS];
    int totalWeight = 0;
    srand(time(0)); // Seed for random number generator

    // Initialize bags as not carried
    for (int i = 0; i < TOTAL_BAGS; i++) {
        bags[i].isCarried = false;
    }

    // Add bags to the system randomly with random weights
    for (int i = 1; i <= TOTAL_BAGS; i++) {
        int weight = rand() % MAX_WEIGHT + 1;
        addBag(bags, i, weight);
        totalWeight += weight;
    }

    // Delay the system randomly for realistic simulation
    int delayTime = rand() % MAX_DELAY + 1;
    printf("System is delayed for %d seconds.\n", delayTime);
    sleep(delayTime);

    // Carry some random bags with a weight limit
    int weightLimit = rand() % (MAX_WEIGHT * 2) + 1;
    printf("Bags are being carried with a weight limit of %d kg.\n", weightLimit);
    for (int i = 0; i < TOTAL_BAGS; i++) {
        if (!bags[i].isCarried && totalWeight + bags[i].weight <= weightLimit) {
            bags[i].isCarried = true;
            totalWeight += bags[i].weight;
        }
    }
    printStatus(bags, totalWeight);

    // Delay the system again for realistic simulation
    delayTime = rand() % MAX_DELAY + 1;
    printf("System is delayed for %d seconds.\n", delayTime);
    sleep(delayTime);

    // Remove some random bags from the system
    int removalCount = rand() % (TOTAL_BAGS / 2) + 1;
    printf("Removing %d bags from the system.\n", removalCount);
    for (int i = 0; i < removalCount; i++) {
        int randomIndex = rand() % TOTAL_BAGS;
        if (bags[randomIndex].isCarried) {
            totalWeight -= bags[randomIndex].weight;
        }
        removeBag(bags, bags[randomIndex].id);
    }
    printStatus(bags, totalWeight);

    return 0;
}