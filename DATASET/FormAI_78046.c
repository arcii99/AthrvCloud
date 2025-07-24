//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constant variables
#define MAX_BAGS 20
#define MAX_BAG_WEIGHT 50
#define MAX_LOST_THRESHOLD 3
#define MAX_TIME_TO_LOST 5

// Struct to hold baggage information
typedef struct {
    int bagID;
    int weight;
} Baggage;

// Enum to hold the baggage status
typedef enum {
    RECEIVED,
    CHECKED_IN,
    LOADED,
    LOST
} BaggageStatus;

int main() {
    srand(time(NULL)); // Initialize random seed
    BaggageStatus status[MAX_BAGS]; // Array to hold the status of each bag
    Baggage baggage[MAX_BAGS]; // Array to hold each bag's information
    int numBags = rand() % MAX_BAGS + 1; // Generate random number of bags
    int lostCount = 0; // Initialize lost baggage count
    int lostBagIds[MAX_BAGS]; // Array to hold lost bag IDs
    int timeToLost[MAX_BAGS]; // Array to hold time to lost for each bag
    int currentTime = 0; // Initialize current time to 0
    
    // Generate baggage information
    for (int i = 0; i < numBags; i++) {
        baggage[i].bagID = i + 1;
        baggage[i].weight = rand() % MAX_BAG_WEIGHT + 1;
        status[i] = RECEIVED;
        timeToLost[i] = rand() % (MAX_TIME_TO_LOST + 1);
    }
    
    // Baggage handling simulation loop
    while (lostCount < MAX_LOST_THRESHOLD) {
        // Print simulation time and baggage status
        printf("Time: %d minutes\n", currentTime);
        printf("Baggage Status:\n");
        for (int i = 0; i < numBags; i++) {
            printf("Bag %d: ", baggage[i].bagID);
            switch(status[i]) {
                case RECEIVED:
                    printf("Received by airport\n");
                    break;
                case CHECKED_IN:
                    printf("Checked in for flight\n");
                    break;
                case LOADED:
                    printf("Loaded onto flight\n");
                    break;
                case LOST:
                    printf("Lost\n");
                    break;
            }
        }
        
        // Check in bags
        for (int i = 0; i < numBags; i++) {
            if (status[i] == RECEIVED) {
                status[i] = CHECKED_IN;
                printf("Bag %d has been checked in for the flight.\n", baggage[i].bagID);
            }
        }
        
        // Load bags onto flight
        for (int i = 0; i < numBags; i++) {
            if (status[i] == CHECKED_IN) {
                status[i] = LOADED;
                printf("Bag %d has been loaded onto the flight.\n", baggage[i].bagID);
            }
        }
        
        // Check for lost bags
        for (int i = 0; i < numBags; i++) {
            if (status[i] == LOADED) {
                timeToLost[i]--;
                if (timeToLost[i] == 0) {
                    status[i] = LOST;
                    lostBagIds[lostCount] = baggage[i].bagID;
                    lostCount++;
                    printf("Bag %d has been lost.\n", baggage[i].bagID);
                }
            }
        }
        
        // Increment time and add newline
        currentTime++;
        printf("\n");
    }
    
    // Print summary
    printf("Summary:\n");
    printf("Total bags handled: %d\n", numBags);
    printf("Lost bags: %d\n", lostCount);
    if (lostCount > 0) {
        printf("Lost bag IDs:");
        for (int i = 0; i < lostCount; i++) {
            printf(" %d", lostBagIds[i]);
        }
        printf("\n");
    }
    
    return 0;
}