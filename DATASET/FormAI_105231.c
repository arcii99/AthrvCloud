//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WAIT_TIME 10

// Struct for Baggage
typedef struct {
    int id;
    bool isBoarding;
} Baggage;

// Declare functions
void loadBaggage(Baggage *bags, int numBags, int *counter);
void unloadBaggage(Baggage *bags, int numBags, int *counter);
int checkBoarding(Baggage *bags, int numBags);
void printBoarding(Baggage *bags, int numBags);

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Declare variables
    int numBags = 0;
    int counter = 0;
    Baggage bags[MAX_BAGS];

    // Start simulation loop
    for (int time = 0; time < MAX_WAIT_TIME; time++) {
        // Randomly generate number of bags to load
        int loadNum = rand() % 10;
        if ((numBags + loadNum) > MAX_BAGS) {
            // If there are too many bags, unload some
            unloadBaggage(bags, numBags, &counter);
        }

        // Load the bags
        loadBaggage(bags, loadNum, &counter);

        // Check and board bags
        int boardingNum = checkBoarding(bags, numBags);

        // Print boarding information
        if (boardingNum > 0) {
            printf("%d bags have boarded at time %d\n", boardingNum, time);
            printBoarding(bags, numBags);
        }

        // Update number of bags
        numBags = numBags - boardingNum + counter;
    }

    return 0;
}

// Load baggage onto conveyor belt
void loadBaggage(Baggage *bags, int numBags, int *counter) {
    for (int i = 0; i < numBags; i++) {
        bags[*counter].id = *counter;
        bags[*counter].isBoarding = false;
        (*counter)++;
    }
}

// Unload baggage from conveyor belt
void unloadBaggage(Baggage *bags, int numBags, int *counter) {
    int unloadNum = rand() % 10;
    for (int i = 0; i < unloadNum; i++) {
        if (*counter == 0) {
            // If there are no bags on the belt, return
            return;
        }
        int index = rand() % (*counter);
        bags[index].isBoarding = true;
        (*counter)--;
        numBags--;
    }
}

// Check and board bags
int checkBoarding(Baggage *bags, int numBags) {
    int boardingNum = 0;
    for (int i = 0; i < numBags; i++) {
        if (bags[i].isBoarding == true) {
            // If bag is already boarded, skip
            continue;
        }
        int boardChance = rand() % 10;
        if (boardChance == 0) {
            // Bag is boarding
            bags[i].isBoarding = true;
            boardingNum++;
        }
    }
    return boardingNum;
}

// Print boarding information
void printBoarding(Baggage *bags, int numBags) {
    printf("Boarding:\n");
    for (int i = 0; i < numBags; i++) {
        if (bags[i].isBoarding == true) {
            printf("Bag %d\n", bags[i].id);
        }
    }
}