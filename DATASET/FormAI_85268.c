//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define ROOMS 8   // Total number of rooms in the house
#define MIN_GHOSTS 1   // Minimum number of ghosts in a room
#define MAX_GHOSTS 3   // Maximum number of ghosts in a room

// Function prototypes
void printIntro();
void generateRoom(int roomId, int* numGhosts);
void enterRoom(int roomId, int* numGhosts);
void printEnding(int numGhostsTotal);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize game variables
    int numGhostsTotal = 0;
    int numGhosts[ROOMS];
    memset(numGhosts, 0, sizeof(numGhosts));   // Initialize to all 0's
    
    // Print introduction message
    printIntro();
    printf("\n");
    
    // Generate ghosts for each room
    int i;
    for (i = 0; i < ROOMS; i++) {
        generateRoom(i, &numGhosts[i]);
        numGhostsTotal += numGhosts[i];
    }
    
    // Enter each room and count ghosts
    for (i = 0; i < ROOMS; i++) {
        enterRoom(i, &numGhosts[i]);
    }
    
    // Print the ending message
    printEnding(numGhostsTotal);
    
    return 0;
}

// Prints the introduction message
void printIntro() {
    printf("You find yourself standing in front of a haunted house.\n");
    printf("Legend has it that the house is inhabited by %d to %d ghosts.\n", MIN_GHOSTS * ROOMS, MAX_GHOSTS * ROOMS);
    printf("Your mission is to enter the house and count how many ghosts there are.\n");
}

// Generates a random number of ghosts for a given room
void generateRoom(int roomId, int* numGhosts) {
    *numGhosts = MIN_GHOSTS + (rand() % (MAX_GHOSTS - MIN_GHOSTS + 1));
    printf("Room %d has %d ghost%s.\n", roomId+1, *numGhosts, (*numGhosts == 1) ? "" : "s");
}

// Enters a room and counts the ghosts in it
void enterRoom(int roomId, int* numGhosts) {
    printf("You enter room %d...\n", roomId+1);
    printf("You see %d ghost%s!\n", *numGhosts, (*numGhosts == 1) ? "" : "s");
}

// Prints the ending message
void printEnding(int numGhostsTotal) {
    printf("You have counted a total of %d ghost%s in the haunted house.\n", numGhostsTotal, (numGhostsTotal == 1) ? "" : "s");
    printf("Congratulations, you have survived!\n");
}