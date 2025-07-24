//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random number generator
    srand(time(NULL));
    
    // Initialize variables
    int rooms[10]; // Array to store room details
    int current_room = 0; // Start in room 0
    int ghosts = 0; // Number of ghosts encountered
    int treasure = 0; // Whether treasure has been found or not
    
    // Fill array with room details
    for (int i = 0; i < 10; i++) {
        int ghost_chance = rand() % 10; // Random chance of ghost encounter
        if (ghost_chance < 4) { // Ghost encountered
            rooms[i] = 10 + rand() % 40; // Ghost carries treasure worth 10-50 units
        } else { // No ghost encountered
            rooms[i] = 0;
        }
    }
    
    // Begin simulation
    printf("Welcome to the haunted house! Your goal is to find the hidden treasure and escape before the ghosts get you. Good luck!\n");
    while (current_room < 10) { // Room 10 is the exit
        printf("You are in room %d.\n", current_room);
        if (rooms[current_room] > 0) { // Ghost encounter
            printf("You have encountered a ghost! The ghost is carrying %d units of treasure.\n", rooms[current_room]);
            ghosts++;
            char choice;
            do {
                printf("Do you (a) attack the ghost, (b) try to run away, or (c) bribe the ghost with some of your own treasure?\n");
                scanf(" %c", &choice);
            } while (choice != 'a' && choice != 'b' && choice != 'c');
            switch (choice) {
                case 'a': // Attack the ghost
                    printf("You attack the ghost, but it disappears before you can hit it. You continue on your way.\n");
                    break;
                case 'b': // Run away
                    printf("You try to run away, but the ghost catches you. You lose some of your treasure and continue on your way.\n");
                    treasure -= 10 + rand() % 20; // Lose 10-30 units of treasure
                    break;
                case 'c': // Bribe the ghost
                    if (treasure >= rooms[current_room]) { // Have enough treasure to bribe ghost
                        printf("You give the ghost some of your own treasure in exchange for its treasure. You continue on your way.\n");
                        treasure += rooms[current_room];
                        rooms[current_room] = 0;
                    } else { // Not enough treasure to bribe ghost
                        printf("You don't have enough treasure to bribe the ghost. You try to run away, but the ghost catches you. You lose some of your treasure and continue on your way.\n");
                        treasure -= 10 + rand() % 20; // Lose 10-30 units of treasure
                    }
                    break;
            }
        } else { // No ghost encounter
            printf("This room is empty. You continue on your way.\n");
        }
        if (current_room == 9 && treasure <= 0) { // Can't exit without treasure
            printf("You have reached the exit, but you don't have any treasure! You must go back and find some before you can escape.\n");
        } else if (current_room == 9 && treasure > 0) { // Can exit with treasure
            printf("Congratulations! You have found %d units of treasure and escaped the haunted house, encountering %d ghosts along the way.\n", treasure, ghosts);
            break;
        } else { // Continue exploring
            char direction;
            do {
                printf("Do you want to go (n)orth, (s)outh, (e)ast, or (w)est?\n");
                scanf(" %c", &direction);
            } while (direction != 'n' && direction != 's' && direction != 'e' && direction != 'w');
            switch (direction) {
                case 'n': // Go north
                    current_room++;
                    break;
                case 's': // Go south
                    current_room--;
                    break;
                case 'e': // Go east
                    current_room += 2;
                    break;
                case 'w': // Go west
                    current_room -= 2;
                    break;
            }
        }
    }
    return 0;
}