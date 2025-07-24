//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed for randomization

    // Declaration of Player's Stats
    int sanity = 100;
    int fear = 0;

    printf("You have entered the Haunted House.\n");

    // Loop until Player's sanity reaches 0 or leaves the house
    while(sanity >= 0) {

        // Random event generator
        int event = rand() % 4 + 1;

        switch (event) {
            case 1:
                printf("You hear a bloodcurdling scream.\n");
                fear += 10;
                break;
            case 2:
                printf("You see a ghostly figure in the distance.\n");
                fear += 15;
                break;
            case 3:
                printf("You feel a cold breeze on the back of your neck.\n");
                fear += 5;
                break;
            case 4:
                printf("You hear a faint whisper in your ear.\n");
                fear += 8;
                break;
            default:
                printf("Nothing happens. You carry on.\n");
        }

        // Player's stats update
        sanity -= fear;
        fear -= 5;
        if(fear < 0) {
            fear = 0;
        }

        // Check if Player has lost
        if(sanity <= 0) {
            printf("You have lost your mind. You will never leave this place.\n");
            break;
        }

        // Check if Player has won
        if(fear >= 100) {
            printf("You have overcome your fear. You safely leave the Haunted House.\n");
            break;
        }

        printf("Your sanity: %d / Fear level: %d\n", sanity, fear);
    }

    return 0;
}