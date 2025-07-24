//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Define constants for the dimensions of the haunted house
#define LEVELS 3
#define ROOMS 4
#define LENGTH 6

// Define the structure for a room
struct Room {
    int ghosts;
    int treasures;
    int exits[LENGTH];
};

// Function to generate a randrom number between a and b
int getRandomNumber(int a, int b) { 
    return (rand() % (b - a + 1)) + a; 
}

// Function to print the details of a room
void printRoomDetails(struct Room* room) {
    printf("Found %d ghosts and %d treasures in the room.\n", room->ghosts, room->treasures);
    printf("Exits: ");
    for (int i = 0; i < LENGTH; i++) {
        if (room->exits[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Initialize the haunted house
    struct Room hauntedHouse[LEVELS][ROOMS][LENGTH];
    for (int i = 0; i < LEVELS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            for (int k = 0; k < LENGTH; k++) {
                hauntedHouse[i][j][k].ghosts = getRandomNumber(0, 5);
                hauntedHouse[i][j][k].treasures = getRandomNumber(0, 3);
                hauntedHouse[i][j][k].exits[0] = k == 0 ? 0 : 1;
                hauntedHouse[i][j][k].exits[1] = k == (LENGTH-1) ? 0 : 1;
                hauntedHouse[i][j][k].exits[2] = getRandomNumber(0, 1);
                hauntedHouse[i][j][k].exits[3] = getRandomNumber(0, 1);
                hauntedHouse[i][j][k].exits[4] = getRandomNumber(0, 1);
                hauntedHouse[i][j][k].exits[5] = getRandomNumber(0, 1);
            }
        }
    }

    // Initialize the player's starting position
    int currentLevel = getRandomNumber(0, LEVELS-1);
    int currentRoom = getRandomNumber(0, ROOMS-1);
    int currentPos = getRandomNumber(0, LENGTH-1);

    // Game loop
    while (1) {
        printf("\n\n");
        printf("*****************************************\n");
        printf("Current level: %d, current room: %d, current position: %d\n", currentLevel+1, currentRoom+1, currentPos+1);
        struct Room* currentRoomPtr = &(hauntedHouse[currentLevel][currentRoom][currentPos]);
        printRoomDetails(currentRoomPtr);

        // Check if the player has won
        if (currentRoomPtr->treasures > 0) {
            printf("Congratulations! You have found %d treasures and won the game!\n", currentRoomPtr->treasures);
            break;
        }

        // Check if the player has lost
        if (currentRoomPtr->ghosts > 0) {
            printf("Oh no! You have found %d ghosts and lost the game.\n", currentRoomPtr->ghosts);
            break;
        }

        // Get the player's next move
        int nextMove;
        printf("Enter your next move (1-6): ");
        scanf("%d", &nextMove);
        if (nextMove < 1 || nextMove > 6) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (!currentRoomPtr->exits[nextMove-1]) {
            printf("You cannot go in that direction. Please try again.\n");
            continue;
        }

        // Move the player
        switch (nextMove) {
            case 1:
                currentPos--;
                break;

            case 2:
                currentPos++;
                break;

            case 3:
                currentRoom--;
                break;

            case 4:
                currentRoom++;
                break;

            case 5:
                currentLevel--;
                break;

            case 6:
                currentLevel++;
                break;
        }

        // Check if the player is out of bounds
        if (currentLevel < 0 || currentLevel >= LEVELS || currentRoom < 0 || currentRoom >= ROOMS || currentPos < 0 || currentPos >= LENGTH) {
            printf("You fell off the haunted house and lost the game.\n");
            break;
        }
    }

    return 0; 
}