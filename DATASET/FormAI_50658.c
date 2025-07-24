//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define room types
enum RoomType {
    ENTRANCE, KITCHEN, LIVING_ROOM, BEDROOM, BATHROOM, BASEMENT, ATTIC, EXIT
};

// Define async function for room transitions
void transition(enum RoomType currentRoom, enum RoomType nextRoom) {
    printf("\nYou enter the %s.\n", nextRoom == BASEMENT ? "dark and creepy basement" :
                                    nextRoom == ATTIC ? "dusty and old attic" :
                                    nextRoom == KITCHEN ? "spooky kitchen" :
                                    nextRoom == LIVING_ROOM ? "haunted living room" :
                                    nextRoom == BEDROOM ? "creepy bedroom" :
                                    nextRoom == BATHROOM ? "chilling bathroom" :
                                    nextRoom == EXIT ? "exit" : "entrance");

    // Add random delay for suspense
    int sleepTime = (int) (rand() % 4) + 1;
    printf("\nYou hesitate for %d seconds...", sleepTime);
    sleep(sleepTime);

    // Update current room
    currentRoom = nextRoom;
}

int main() {
    srand(time(NULL)); // Initialize random seed
    printf("Welcome to the haunted house simulator!\n");

    // Initialize current room as entrance
    enum RoomType currentRoom = ENTRANCE;

    // Continuously prompt user for next room
    while (currentRoom != EXIT) {
        enum RoomType nextRoom;
        printf("\nYou are currently in the %s. Where would you like to go next?\n", 
            currentRoom == ENTRANCE ? "entrance" :
            currentRoom == KITCHEN ? "kitchen" :
            currentRoom == LIVING_ROOM ? "living room" :
            currentRoom == BEDROOM ? "bedroom" :
            currentRoom == BATHROOM ? "bathroom" :
            currentRoom == BASEMENT ? "basement" :
            currentRoom == ATTIC ? "attic" : "");

        // Handle user input
        char input[10];
        fgets(input, 10, stdin);

        switch (input[0]) {
            case 'k':
                nextRoom = KITCHEN;
                break;
            case 'l':
                nextRoom = LIVING_ROOM;
                break;
            case 'b':
                nextRoom = BEDROOM;
                break;
            case 'r':
                nextRoom = BATHROOM;
                break;
            case 'a':
                nextRoom = ATTIC;
                break;
            case 's':
                nextRoom = BASEMENT;
                break;
            default:
                printf("\nInvalid input. Try again.");
                continue;
        }

        // Call transition function asynchronously
        #pragma omp parallel
        #pragma omp single
        transition(currentRoom, nextRoom);
    }

    printf("\nYou have escaped the haunted house!");
    return 0;
}