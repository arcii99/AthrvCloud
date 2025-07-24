//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function declarations
void printInstructions();
void enterHouse();
void exploreRoom();
void inspectItem(char* item);
void encounterGhost();
void endGame();

// Global variables
bool hasKey = false;
bool hasFlashlight = false;
bool hasFoundGhost = false;
bool hasEncounteredGhost = false;
int numRoomsExplored = 0;

// Main function
int main() {
    printInstructions();
    enterHouse();

    return 0;
}

// Function to print game instructions
void printInstructions() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have just entered a creepy old house. Your goal is to navigate through the house, explore each room, and collect any useful items you may find.\n");
    printf("Be careful though - there may be some unexpected surprises along the way!\n\n");
}

// Function to enter the house and start exploring rooms
void enterHouse() {
    printf("You have entered the house. You are in a dimly lit entryway with doors leading to various rooms.\n\n");
    numRoomsExplored++;
    exploreRoom();
}

// Function to explore a room
void exploreRoom() {
    // Determine if the room is empty or has an item
    srand(time(NULL));
    int randomNum = rand() % 4;
    bool hasItem = (randomNum == 0 || randomNum == 3) ? true : false;

    printf("You have entered a new room. ");

    if (hasItem) {
        char itemName[50];
        int randomNum = rand() % 3;

        if (randomNum == 0) {
            strcpy(itemName, "key");
        } else if (randomNum == 1) {
            strcpy(itemName, "flashlight");
        } else {
            strcpy(itemName, "book");
        }

        printf("You have found a %s.\n", itemName);
        inspectItem(itemName);
    } else {
        printf("The room is empty.\n");
    }

    // Determine if the room has a ghost
    randomNum = rand() % 10;
    bool hasGhost = (randomNum == 0 || randomNum == 1) ? true : false;

    if (hasGhost) {
        printf("You have encountered a ghost!\n");
        encounterGhost();
    } else {
        printf("You may proceed to the next room.\n\n");
        numRoomsExplored++;

        if (numRoomsExplored == 4) {
            endGame();
        } else {
            exploreRoom();
        }
    }
}

// Function to inspect an item
void inspectItem(char* item) {
    if (strcmp(item, "key") == 0) {
        printf("You have picked up the key.\n");
        hasKey = true;
    } else if (strcmp(item, "flashlight") == 0) {
        printf("You have picked up the flashlight.\n");
        hasFlashlight = true;
    } else {
        printf("You have picked up the book.\n");
    }

    printf("You may proceed to the next room.\n\n");
    numRoomsExplored++;

    if (numRoomsExplored == 4) {
        endGame();
    } else {
        exploreRoom();
    }
}

// Function to handle encountering a ghost
void encounterGhost() {
    if (!hasFoundGhost) {
        printf("The ghost disappears before your eyes.\n");
        hasFoundGhost = true;
    } else {
        if (!hasEncounteredGhost) {
            printf("The ghost appears again and chases you!\n");
            hasEncounteredGhost = true;
        } else {
            printf("The ghost continues to haunt you as you run through the house.\n");
        }

        printf("You escape to the next room.\n\n");
        numRoomsExplored++;

        if (numRoomsExplored == 4) {
            endGame();
        } else {
            exploreRoom();
        }
    }
}

// Function to handle the end of the game
void endGame() {
    printf("Congratulations! You have successfully navigated through the haunted house and escaped alive!\n");
    printf("You explored %d rooms and found the following items:", numRoomsExplored);

    if (hasKey) {
        printf(" key");
    }

    if (hasFlashlight) {
        printf(" flashlight");
    }

    if (!hasKey && !hasFlashlight) {
        printf(" nothing");
    }

    printf(".\n");
}