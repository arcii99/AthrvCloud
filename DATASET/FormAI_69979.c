//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed for randomization

    // Game introduction
    printf("Welcome to the Haunted House Simulator.\n");
    printf("You enter a spooky old mansion in the middle of a dark forest. Would you like to enter? (yes/no): ");
    
    char choice[5];
    fgets(choice, 5, stdin);
    if (strncmp(choice, "yes", 3) == 0) {
        printf("You cautiously enter the house.\n");
    } else {
        printf("You decide to leave.\n");
        return 0;
    }

    int num_rooms = 10;
    int ghosts = 0;
    int keys = 0;
    int total_ghosts;
    int total_keys;

    // Game loop
    for (int i = 1; i <= num_rooms; i++) {
        int rand_val = rand() % 4; // Random number between 0 and 3

        if (rand_val == 0) { // Empty room
            printf("You enter room %d and find nothing.\n", i);
        } else if (rand_val == 1) { // Ghost room
            int num_ghosts = rand() % 3 + 1; // Random number between 1 and 3
            printf("You enter room %d and encounter %d ghost(s)!\n", i, num_ghosts);
            ghosts += num_ghosts;
        } else if (rand_val == 2) { // Key room
            int num_keys = rand() % 3 + 1; // Random number between 1 and 3
            printf("You enter room %d and find %d key(s)!\n", i, num_keys);
            keys += num_keys;
        } else { // Final room
            total_ghosts = ghosts;
            total_keys = keys;
            printf("You enter the final room and see a ghostly figure.\n");
            break;
        }
    }

    // Game over
    if (total_ghosts > 0 && total_keys > 0) {
        printf("You successfully collected %d key(s) and fought off %d ghost(s)! Congratulations, you escaped the haunted house!\n", total_keys, total_ghosts);
    } else if (total_ghosts > 0) {
        printf("You were scared off by the %d ghost(s) and didn't collect any keys. Better luck next time!\n", total_ghosts);
    } else {
        printf("You searched the entire house and didn't find any keys. Better luck next time!\n");
    }

    return 0;
}