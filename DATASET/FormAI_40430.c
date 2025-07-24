//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HALLWAY_SIZE 10
#define NUM_ROOMS 5

void printHallway(int* hallway) {
    for (int i = 0; i < HALLWAY_SIZE; i++) {
        if (hallway[i] == 0) {
            printf("|   ");
        } else {
            printf("| %c ", hallway[i]);
        }
    }
    printf("|\n");
}

int main() {
    int hallway[HALLWAY_SIZE] = {0}; // Initialize hallway to all zeros
    srand(time(NULL)); // Seed random number generator with current time
    int start = rand() % HALLWAY_SIZE; // Choose a random starting position for player
    int ghost_room = rand() % NUM_ROOMS + 1; // Choose a random room for the ghost
    int treasure_room = rand() % NUM_ROOMS + 1; // Choose a random room for the treasure

    // Fill the hallway with rooms
    for (int i = 1; i <= NUM_ROOMS; i++) {
        int room_pos = rand() % HALLWAY_SIZE;
        while (hallway[room_pos] != 0) {
            room_pos = rand() % HALLWAY_SIZE;
        }
        hallway[room_pos] = i;
    }

    // Main game loop
    int player_pos = start;
    int player_has_treasure = 0;
    int num_moves = 0;
    printf("Welcome to the haunted house!\n");
    while (1) {
        // Print current state of the game
        printf("Current position: %d\n", player_pos);
        printf("Number of moves: %d\n", num_moves);
        if (player_has_treasure) {
            printf("You have the treasure!\n");
        }
        printHallway(hallway);

        // Check if player is in the same room as the ghost
        if (hallway[player_pos] == ghost_room && !player_has_treasure) {
            printf("Oh no, you got caught by the ghost! Game over.\n");
            break;
        }

        // Check if player is in the treasure room
        if (hallway[player_pos] == treasure_room && !player_has_treasure) {
            printf("Congratulations, you found the treasure!\n");
            player_has_treasure = 1;
        }

        // Check if player has escaped with the treasure
        if (player_has_treasure && player_pos == start) {
            printf("Congratulations, you escaped with the treasure!\n");
            break;
        }

        // Ask player for input
        char input;
        printf("Enter 'l' to move left, 'r' to move right, or 'q' to quit: ");
        scanf(" %c", &input);

        // Move the player
        if (input == 'l' && player_pos > 0) {
            player_pos--;
            num_moves++;
        } else if (input == 'r' && player_pos < HALLWAY_SIZE - 1) {
            player_pos++;
            num_moves++;
        } else if (input == 'q') {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid input, try again.\n");
        }
    }

    return 0;
}