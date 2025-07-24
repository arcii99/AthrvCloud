//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number */
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to simulate the haunted house */
void haunted_house_simulator() {
    int steps = 0;
    int room = 1;
    int ghost_encounter = 0;
    int has_key = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an old, abandoned house.\n");
    printf("Do you dare to enter? (y/n) ");

    char answer = getchar();
    if (answer == 'n') {
        printf("You chicken out and leave the haunted house.\n");
        return;
    }

    /* Seed the random number generator */
    srand(time(NULL));

    /* Start the simulation */
    while (1) {
        printf("\nYou are in room %d.\n", room);

        /* Check if the ghost appears */
        if (!ghost_encounter && get_random_number(1, 10) == 1) {
            ghost_encounter = 1;
            printf("Suddenly, you hear a strange noise... and a ghost appears!\n");
            printf("What do you want to do? (1) Run (2) Hide (3) Fight ");
            int action = getchar();
            if (action == '1') {
                printf("You start running as fast as you can, but the ghost catches you and you lose.\n");
                return;
            } else if (action == '2') {
                printf("You hide behind a nearby door and the ghost goes away.\n");
            } else {
                printf("You try to fight the ghost, but he is invulnerable and disappears.\n");
            }
        }

        /* Check if the key appears */
        if (!has_key && get_random_number(1, 10) == 1) {
            has_key = 1;
            printf("You see a key lying on the floor! You pick it up.\n");
        }

        /* Check if the player has the key and has reached the final room */
        if (has_key && room == 5) {
            printf("You have reached the final room! You use the key to open the door and escape the haunted house.\n");
            return;
        }

        /* Move to the next room */
        printf("What do you want to do? (1) Move to the next room (2) Search the room ");
        int action = getchar();
        if (action == '1') {
            room++;
            /* Increase the steps counter */
            steps++;

            /* Check if the player has walked too much without finding the key */
            if (steps >= 15 && !has_key) {
                printf("You have walked for too long without finding the key. You lose.\n");
                return;
            }
        } else {
            printf("You start searching the room... ");
            int search_result = get_random_number(1, 10);
            if (search_result == 1) {
                printf("You find a trap door and go down a secret passage... ");
                room--;
            } else if (search_result == 2) {
                printf("You find a spooky diary that tells you about the haunted history of the house. ");
            } else {
                printf("You search the room, but find nothing of interest. ");
            }
        }
    }
}

/* Main function */
int main() {
    haunted_house_simulator();
    return 0;
}