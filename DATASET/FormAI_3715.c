//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define TOTAL_BAGS 1000
#define TERMINALS 4
#define CONVEYOR_BELT_SIZE 10

// Function prototypes
void generateBags(int bags[TOTAL_BAGS]);
void initializeConveyorBelt(int conveyorBelt[CONVEYOR_BELT_SIZE]);
void printConveyorBelt(int conveyorBelt[CONVEYOR_BELT_SIZE]);
void conveyorBeltToTerminal(int conveyorBelt[CONVEYOR_BELT_SIZE], int terminal);
void printStatistics(int bags[TOTAL_BAGS]);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create an array to hold the bags
    int bags[TOTAL_BAGS];
    generateBags(bags);
    
    // Initialize the conveyor belt
    int conveyorBelt[CONVEYOR_BELT_SIZE];
    initializeConveyorBelt(conveyorBelt);
    
    // Loop through the bags and simulate the baggage handling process
    for(int i=0; i<TOTAL_BAGS; i++) {
        // Check if the conveyor belt is full
        if(conveyorBelt[CONVEYOR_BELT_SIZE-1] != 0) {
            printf("Conveyor belt is full. Cannot add bag %d.\n", bags[i]);
            continue;
        }
        
        // Add the bag to the conveyor belt
        for(int j=0; j<CONVEYOR_BELT_SIZE; j++) {
            if(conveyorBelt[j] == 0) {
                conveyorBelt[j] = bags[i];
                printf("Bag %d added to conveyor belt at position %d.\n", bags[i], j+1);
                break;
            }
        }
        
        // Randomly move bags from the conveyor belt to a terminal
        int move = rand() % 100;
        if(move < 70) { // 70% chance of moving a bag to a terminal
            int terminal = rand() % TERMINALS + 1;
            conveyorBeltToTerminal(conveyorBelt, terminal);
        }
        
        printConveyorBelt(conveyorBelt);
    }
    
    // Print statistics
    printStatistics(bags);
    
    return 0;
}

/*
 * Generates a random bag number between 1 and 1000 for each bag.
 */
void generateBags(int bags[TOTAL_BAGS]) {
    for(int i=0; i<TOTAL_BAGS; i++) {
        bags[i] = rand() % 1000 + 1;
    }
}

/*
 * Initializes the conveyor belt array to all zeros.
 */
void initializeConveyorBelt(int conveyorBelt[CONVEYOR_BELT_SIZE]) {
    for(int i=0; i<CONVEYOR_BELT_SIZE; i++) {
        conveyorBelt[i] = 0;
    }
}

/*
 * Prints the contents of the conveyor belt array.
 */
void printConveyorBelt(int conveyorBelt[CONVEYOR_BELT_SIZE]) {
    printf("Conveyor belt: [");
    for(int i=0; i<CONVEYOR_BELT_SIZE; i++) {
        if(i != CONVEYOR_BELT_SIZE-1) {
            printf("%d, ", conveyorBelt[i]);
        } else {
            printf("%d]\n", conveyorBelt[i]);
        }
    }
}

/*
 * Moves a bag from the conveyor belt to the specified terminal.
 */
void conveyorBeltToTerminal(int conveyorBelt[CONVEYOR_BELT_SIZE], int terminal) {
    for(int i=0; i<CONVEYOR_BELT_SIZE; i++) {
        if(conveyorBelt[i] != 0) {
            printf("Bag %d moved from conveyor belt to terminal %d.\n", conveyorBelt[i], terminal);
            conveyorBelt[i] = 0;
            break;
        }
    }
}

/*
 * Prints statistics about the baggage handling process.
 */
void printStatistics(int bags[TOTAL_BAGS]) {
    int totalBagsMoved = 0;
    for(int i=0; i<TOTAL_BAGS; i++) {
        if(bags[i] == 0) { // Bag was moved to a terminal
            totalBagsMoved++;
        }
    }
    printf("\nTotal bags moved to a terminal: %d\n", totalBagsMoved);
    printf("Percentage of bags moved to a terminal: %d%%\n", totalBagsMoved * 100 / TOTAL_BAGS);
    printf("Percentage of bags not moved to a terminal: %d%%\n", (TOTAL_BAGS - totalBagsMoved) * 100 / TOTAL_BAGS);
}