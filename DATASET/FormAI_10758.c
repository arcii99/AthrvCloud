//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ghost_appeared = 0; // Flag to check if ghost appeared
    int steps = 0; // Steps taken by player
    int ghosts_left = 3; // Number of ghosts that can appear
    srand(time(NULL)); // Generate random seed based on time
    printf("Welcome to the Haunted House Simulator, brave visitor! Explore the house and see if you can survive!\n");
    printf("\n");

    while(ghosts_left > 0) { // Loop until all three ghosts have appeared
        printf("You take a step forward. ");
        steps++;
        
        if(rand() % 10 == 0 && ghost_appeared == 0) { // 10% chance of ghost appearing only if one hasn't appeared yet
            printf("Suddenly, a ghost appears out of nowhere!\n");
            ghost_appeared = 1;
            ghosts_left--;
        } else if(rand() % 6 == 0) { // 20% chance of spooky sound
            printf("You hear a spooky sound in the distance.\n");
        } else {
            printf("The room is quiet. Nothing out of the ordinary.\n");
        }

        printf("\n");

        if(steps == 20) { // Player has taken 20 steps without encountering a ghost
            printf("You have been walking for awhile now and haven't seen anything. You start to feel like you might just make it out alive!\n");
        }
    }

    printf("You have encountered all three ghosts and unfortunately, couldn't make it out alive. Better luck next time!\n");

    return 0;
}