//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to embark on a spooky adventure.\n");
    printf("Are you ready to enter the Haunted House? [y/n] ");
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y') {
        printf("Great! Let's begin.\n");
        srand(time(NULL)); // Seed the random number generator
        int rooms[5] = {1, 2, 3, 4, 5}; // Array of rooms in the house
        int ghosts[5] = {0}; // Array to track whether each room has a ghost
        int ghostCount = 0; // Counter for the number of rooms with ghosts
        for(int i = 0; i < 3; i++) {
            int randRoom = rand() % 5; // Generate a random number between 0 and 4
            ghosts[randRoom] = 1; // Mark the room as having a ghost
            ghostCount++; // Increment the ghost counter
        }
        printf("You enter the house and find yourself in the foyer.\n");
        while(1) {
            printf("Which room do you want to enter? [1-5] ");
            int roomChoice;
            scanf("%d", &roomChoice);
            if(roomChoice < 1 || roomChoice > 5) {
                printf("Invalid choice.\n");
                continue;
            }
            printf("You enter room %d.\n", roomChoice);
            if(ghosts[roomChoice - 1] == 1) { // Check if the room has a ghost
                printf("Oh no! There's a ghost in this room!\n");
                ghostCount--; // Decrement the ghost counter
                ghosts[roomChoice - 1] = 0; // Mark the room as no longer having a ghost
                if(ghostCount == 0) { // Check if all ghosts have been found
                    printf("Congratulations! You've found all the ghosts.\n");
                    break;
                }
            } else {
                printf("This room is safe.\n");
            }
        }
    } else {
        printf("Okay, come back when you're ready.\n");
    }
    return 0;
}