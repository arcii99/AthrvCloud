//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int ghosts = rand() % 10 + 1; // Generate a random number of ghosts between 1 and 10
    int rooms = rand() % 10 + 1; // Generate a random number of rooms between 1 and 10
    int current_room = 1; // Start in room 1
    printf("Welcome to the haunted house simulator!\n");
    printf("There are %d ghosts in this haunted house.\n", ghosts);
    printf("You are in room %d of %d.\n", current_room, rooms);
    while(current_room <= rooms) { // Loop through all the rooms
        printf("Press enter to enter room %d.\n", current_room+1);
        getchar(); // Wait for the user to press enter
        int ghost_present = rand() % 2; // Generate a random number (0 or 1) to determine if there is a ghost in the room
        if(ghost_present) {
            printf("There is a ghost in this room!\n");
            ghosts--;
            printf("There are now %d ghosts left in the haunted house.\n", ghosts);
        } else {
            printf("There are no ghosts in this room. Phew!\n");
        }
        current_room++; // Move to the next room
        printf("You are in room %d of %d.\n", current_room, rooms);
    }
    if(ghosts == 0) { // If there are no ghosts left, the player has won!
        printf("Congratulations, you made it through the haunted house alive!\n");
    } else { // Otherwise, the player has lost
        printf("Sorry, you were not able to make it through the haunted house alive.\n");
    }
    return 0;
}